#comilamos
#./compilar.sh

#leemos clase qe qeremos ejecutar:
args=("$@")
if [ $# -eq 0 ]; then
echo "PLEASE TYPE THE JAVA CLASS NAME:"
read jclass
#ejecutamos
java -Djava.library.path=. $jclass
else

java -Djava.library.path=. $@
fi
