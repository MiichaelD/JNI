echo "			COMPILING"
#leemos clase qe qeremos ejecutar:
args=("$@")
if [ $# -ne 3 ]; then
  if [ $# -ne 0 ]; then
    echo "calling this Bash with:
    arg0	-	.java file name to compile
    arg1	-	.c file name to compile
    arg2	-	library name you will generate"
  elif [ {args[0]} = -help ]; then
    echo "calling this Bash with:
    arg0	-	.java file name to compile
    arg1	-	.c file name to compile
    arg2	-	library name you will generate"
  fi
else
  if [ ! -e ${args[0]}.java ]; then
    echo  ${args[0]}.java doesn\'t exist
    exit
  fi
  if [ ! -e ${args[1]}.c ]; then
    echo ${args[1]}.c doesn\'t exist
    exit
  fi
  echo "Compiling java..."
  javac ${args[0]}.java
  echo "Creating C  headers..."
  javah -jni ${args[0]}
  echo "Generating Dynamic Library..."
  gcc ${args[1]}.c -shared -o lib${args[2]}.so
  echo "DONE :)"
fi


if [ $# -eq 0 ]; then
  echo "PLEASE TYPE THE .java FILE NAME:"
  read jJava
  if [ ! -e $jJava.java ]; then
    echo $jJava.java doesn\'t exist
    exit
  fi
  echo "Compiling java..."
  javac $jJava.java
  echo "Creating C  headers..."
  javah -jni $jJava
  echo "PLEASE TYPE THE .c FILE NAME:"
  read cFile
  if [ ! -e $cFile.c ]; then
    echo $cFile.c doesn\'t exist
    exit
  fi
  echo "PLEASE TYPE THE DYNAMIC LIBRARY NAME:"
  read lib
  echo "Generating Dynamic Library..."
  gcc $cFile.c -shared -o lib$lib.so
  echo "DONE :)"
fi
#terminamos