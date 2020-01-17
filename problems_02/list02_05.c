/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 02 - CHALLENGE 05
STUDENT - MARCOS AVNER PIMENTA DE LIMA

NOT EQUAL

IMAGINE A VERY PRIMITIVE LANGUAGE WITH ONLY 3 FUNCTIONS:
	1 - ZERO(INT NUM), RETURN TRUE IF "NUM" EQUALS ZERO, OR FALSE, OTHERWISE.
	2 - INCR(INT NUM), INCREMENTS "NUM" BY 1.
	3 - DECR(INT NUM), DECREMENTS "NUM" BY 1.

YOU HAVE TO CODIFY A RECURSIVE "NOT EQUAL" FUNCTION, AS DESCRIBED BELOW:
	BOOL NOTEQUAL(INT A, INT B);
THE FUNCTION MUST RETURN TRUE IF A IS NOT EQUAL B, OR FALSE, OTHERWISE.

EVERY INPUT CONSISTS OF TWO NUMBER, SEPARATED BY <SPACE>.
YOUR PROGRAM MUST KEEP READING LINES OF TWO NUMBERS, AND FOR EACH ONE SHOW "SIM" IF NOTEQUAL(A,B) IS TRUE, OR "NAO", IF FALSE.
THE LAST LINE CONSIST TWO ZEROS, "0 0", INGNORE IT.

YOU CAN USE THE FUNCTIONS OF OTHER CHALLENGES.
YOU CAN'T USE OTHER OPERATOR OR FUNCTIONS IN THIS CHALENGE!!!

EXAMPLES
INPUT
1 1
1 2
2 1
0 0

OUTPUT
NAO
SIM
SIM

*/
#include<stdio.h>
bool zero(int num){
	return num == 0;
}

int incr(int num){
	return num + 1;
}

int decr(int num){
	return num - 1;
}

bool notEqual(int a, int b) {
	if (zero(a)) {
		if (zero(b))
			return 0;
		else
			return 1;
	}
	return (notEqual(decr(a), decr(b)));
}

void read() {
	int a,b;
	scanf("%d %d", &a, &b);
	if (zero(a))
		if (zero(b))
			return;
	if (notEqual(a,b))
		printf("SIM\n");
	else
		printf("NAO\n");
	read();
}

int main() {
	read();
	return 0;
}