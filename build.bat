:: Nos colocamos en el directorio del motor
cd MagmaEngine

:: Construimos las dependencias del motor
call build.bat

mkdir .\executables\assets

:: Volvemos al directorio del juego
cd ..

xcopy assets .\MagmaEngine\executables\assets /E /Y

:: COMPILAR LA SOLUCIÓN DEL JUEGO ::
msbuild .\TheRiseOfSuxalote.sln -p:Configuration=Debug -noLogo -verbosity:minimal -maxCpuCount
msbuild .\TheRiseOfSuxalote.sln -p:Configuration=Release -noLogo -verbosity:minimal -maxCpuCount

:: Copia dll del juego a executables
copy .\libraries\TheRiseOfSuxalote\x64\Debug\TheRiseOfSuxalote_d.dll .\MagmaEngine\executables
copy .\libraries\TheRiseOfSuxalote\x64\Release\TheRiseOfSuxalote.dll .\MagmaEngine\executables

echo ========-----========__Fin_del_Script__========-----========
