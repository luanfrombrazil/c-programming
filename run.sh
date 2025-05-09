clear
NUM_CASES=1;

RED="\e[1;31m"
GREEN="\e[1;32m"
ENDCOLOR="\e[1;\e[0m"

case=1
gcc main.c -o out/main -lm

while [ $case -le $NUM_CASES ]
do
	rm m$case.out
	./out/main < cases/$case.in >> cases/m$case.out
	
	if diff -q cases/m$case.out cases/$case.out >/dev/null; then
    	echo -e "${GREEN}"
    	figlet "CORRECT"
		echo -e "\t    TIME TO SUBMIT! ${ENDCOLOR}"
	else
		echo -e "${RED}"
    	figlet "INCORRECT"
		echo -e "\t     JUST FUCKING FIX IT ${ENDCOLOR}"
	fi
	case=$(( case+1 ))
done