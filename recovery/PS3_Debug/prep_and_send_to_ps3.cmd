@echo off


:: esc0rtd3w / 100% BeasTm0de


:main

color 0e

set nameOld=iLLiCiT-Recovery.sprx
set nameNew=GTA.sprx

:: PREPARE SPRX
if exist "%nameNew%" (
	if exist "%nameOld%" (
	del /f /q "%nameNew%"
	ren "%nameOld%" "%nameNew%"
	)
)

if exist "%nameOld%" ren "%nameOld%" "%nameNew%"


set ip=192.168.1.135
set tempFile="%temp%\ps3ftp_temp.txt"
set sprxFile=%nameNew%

set localPath=%cd%
set remotePath=/dev_hdd0/tmp/
set gameUnmount=http://192.168.2.76/mount.ps3/unmount
set gameMount=http://192.168.2.76/mount.ps3/dev_hdd0/GAMES/Grand%20Theft%20Auto%20V

:ip
cls
echo Current IP: %ip%
echo.
echo.
echo Enter PS3 IP Address and press ENTER:
echo.
echo.

::set /p ip=
goto local


:local
cls
echo Current IP: %ip%
echo.
echo Current Local Path: %localPath%
echo.
echo.
echo Enter Local Path and press ENTER:
echo.
echo.

::set /p localPath=
goto sprx


:sprx
set sprxFileTemp=99
cls
echo Current IP: %ip%
echo.
echo Current Local Path: %localPath%
echo.
echo Current SPRX Filename: %sprxFile%
echo.
echo.
echo 1) iLLiCiT.sprx
echo 2) GTAmenu.sprx
echo 3) GTA.sprx
echo 4) SerenV2.sprx
echo 5) Custom
echo.
echo.
echo Type or Choose SPRX Filename and press ENTER:
echo.
echo.

::set /p sprxFileTemp=

::if %sprxFileTemp% gtr 5 goto sprx
::if %sprxFileTemp%==1 set sprxFile=iLLiCiT.sprx
::if %sprxFileTemp%==2 set sprxFile=GTAmenu.sprx
::if %sprxFileTemp%==3 set sprxFile=GTA.sprx
::if %sprxFileTemp%==4 set sprxFile=SerenV2.sprx
::if %sprxFileTemp%==5 goto sprxCustom
goto remote


:remote
cls
echo Current IP: %ip%
echo.
echo Current Local Path: %localPath%
echo.
echo Current SPRX Filename: %sprxFile%
echo.
echo Current Remote Path: %remotePath%
echo.
echo.
echo Enter Remote Path and press ENTER:
echo.
echo.

::set /p remotePath=
goto upload


:upload
cls
color 0a
echo Current IP: %ip%
echo.
echo Current Local Path: %localPath%
echo.
echo Current SPRX Filename: %sprxFile%
echo.
echo Current Remote Path: %remotePath%
echo.
echo.
echo Uploading SPRX to PS3 Console....
echo.
echo.
echo.
echo Sending %sprxFile% to %ip%@%remotePath%....
echo.
echo.
echo cd "%localPath%">%tempFile%
echo user ps3>>%tempFile%
echo ps3>>%tempFile%
echo bin>>%tempFile%
echo cd %remotePath%>>%tempFile%
echo put "%cd%\%sprxFile%">>%tempFile%
echo quit>>%tempFile%
ftp -n -s:%tempFile% %ip%
del /f /q %tempFile%

goto end


:: ONLY LAND HERE IF CUSTOM SPRX NAME
:sprxCustom
cls
echo Current IP: %ip%
echo.
echo Current Local Path: %localPath%
echo.
echo Current SPRX Filename: %sprxFile%
echo.
echo.
echo Type SPRX Filename and press ENTER:
echo.
echo.

set /p sprxFile=

goto remote


::pause


::goto main



:end


echo.
echo.
::echo Launching Game With Webman....
echo.
echo.
::start "" "%ProgramFiles%\Internet Explorer\iexplore.exe" %gameUnmount%
::ping -n 4 127.0.0.1
::start "" "%ProgramFiles%\Internet Explorer\iexplore.exe" %gameMount%
::ping -n 6 127.0.0.1
::taskkill /f /im iexplore.exe

::pause
