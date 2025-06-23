clear
NUM_CASES=3;

RED="\e[1;31m"
GREEN="\e[1;32m"
ENDCOLOR="\e[1;\e[0m"

case=1
gcc main.c -o out/main -lm

while [ $case -le $NUM_CASES ]
do
	rm ./cases/$case.m.out
	./out/main < cases/$case.in >> cases/$case.m.out
	
	if diff -q cases/$case.m.out cases/$case.out >/dev/null; then
    	echo -e "${GREEN}"
    	figlet "CORRECT"
		echo -e "O $case ESTÁ CORRETO ${ENDCOLOR}"
	else
		echo -e "${RED}"
    	figlet "INCORRECT"
		echo -e "O $case ESTÁ INCORRETO ${ENDCOLOR}"
	fi
	case=$(( case+1 ))
done
