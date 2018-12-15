echo off
 
echo Compilando Java...
javac HelloWorld.java

echo Creando encabezado...
javah -jni HelloWorld

echo Compilando C...
::gcc-3 -mno-cygwin -I%jdk_1_6%/include -I%jdk_1_6%/include/win32 -Wl,--add-stdcall-alias -shared -o HelloWorld.dll HelloWorld.c
::gcc-4 -mno-cygwin -I"C:\Program Files\Java\jdk1.6.0_25\include" -I"C:\Program Files\Java\jdk1.6.0_25\include\win32" -Wl,--add-stdcall-alias -shared -o HelloWorld.dll HelloWorld.c
gcc-4 -I"/cygdrive/c/Program Files/Java/jdk1.6.0_25/include" -I"/cygdrive/c/Program Files/Java/jdk1.6.0_25/include/win32" -Wl,--add-stdcall-alias -shared -o HelloWorld.dll HelloWorld.c
pause