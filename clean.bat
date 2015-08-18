:: solution directory
DEL /F /Q *.sdf
DEL /F /Q *.suo
RMDIR /S /Q ipch

:: project directories
FOR /F "tokens=*" %%G IN ('DIR /B /A:D /S bin') DO RMDIR /S /Q "%%G"
FOR /F "tokens=*" %%G IN ('DIR /B /A:D /S obj') DO RMDIR /S /Q "%%G"
FOR /F "tokens=*" %%G IN ('DIR /B /A:-D /S *.user') DO DEL /F /Q "%%G"