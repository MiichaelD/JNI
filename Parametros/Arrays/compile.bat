@echo off

echo 			Compilando java...
javac %1.java 

javah -jni %1

echo 			Compilando C...

cl %2.c /I "C:\Program Files\Java\jdk1.6.0_25\include" /I "C:\Program Files\Java\jdk1.6.0_25\include\win32" /MD /LD


echo 			COMPILACION COMPLETA!!!


if "%3" == "exe" java %1