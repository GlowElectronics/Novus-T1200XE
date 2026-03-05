@echo off
setlocal

echo ============================================
echo ATmega328P Fuse Programming - 5V / 16MHz
echo ============================================
echo.

:: ---- CONFIGURATION ----
set MCU=m328p
set PROGRAMMER=usbasp
set LFUSE=0xFF
set HFUSE=0xDE
set EFUSE=0xFD
:: ------------------------

echo Checking programmer connection...

avrdude -c %PROGRAMMER% -p %MCU% -v > avrdude_check.txt 2>&1

if errorlevel 1 (
    echo ERROR: Programmer or MCU not detected.
    type avrdude_check.txt
    pause
    exit /b 1
)

echo Reading device signature...

findstr /C:"Device signature" avrdude_check.txt > nul

if errorlevel 1 (
    echo ERROR: Unable to read device signature.
    type avrdude_check.txt
    pause
    exit /b 1
)

findstr /C:"Device signature" avrdude_check.txt

echo.
echo Writing fuses...
echo.

avrdude -c %PROGRAMMER% -p %MCU% ^
-U lfuse:w:%LFUSE%:m ^
-U hfuse:w:%HFUSE%:m ^
-U efuse:w:%EFUSE%:m

if errorlevel 1 (
    echo ERROR: Fuse programming failed.
    pause
    exit /b 1
)

echo.
echo Verifying fuse values...
echo.

avrdude -c %PROGRAMMER% -p %MCU% ^
-U lfuse:r:lfuse_read.txt:h ^
-U hfuse:r:hfuse_read.txt:h ^
-U efuse:r:efuse_read.txt:h

if errorlevel 1 (
    echo ERROR: Fuse readback failed.
    pause
    exit /b 1
)

set /p LF_READ=<lfuse_read.txt
set /p HF_READ=<hfuse_read.txt
set /p EF_READ=<efuse_read.txt

echo.
echo Expected LFUSE: %LFUSE%  Read: %LF_READ%
echo Expected HFUSE: %HFUSE%  Read: %HF_READ%
echo Expected EFUSE: %EFUSE%  Read: %EF_READ%
echo.

if /I not "%LF_READ%"=="%LFUSE%" (
    echo ERROR: Low fuse mismatch!
    pause
    exit /b 1
)

if /I not "%HF_READ%"=="%HFUSE%" (
    echo ERROR: High fuse mismatch!
    pause
    exit /b 1
)

if /I not "%EF_READ%"=="%EFUSE%" (
    echo ERROR: Extended fuse mismatch!
    pause
    exit /b 1
)

echo ============================================
echo SUCCESS: Fuses programmed and verified!
echo ============================================

del lfuse_read.txt
del hfuse_read.txt
del efuse_read.txt
del avrdude_check.txt

pause
exit /b 0