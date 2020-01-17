/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 02 - CHALLENGE 04
STUDENT - MARCOS AVNER PIMENTA DE LIMA

MULTIPLY

IMAGINE A VERY PRIMITIVE LANGUAGE WITH ONLY 3 FUNCTIONS:
	1 - ZERO(INT NUM), RETURN TRUE IF "NUM" EQUALS ZERO, OR FALSE, OTHERWISE.
	2 - INCR(INT NUM), INCREMENTS "NUM" BY 1.
	3 - DECR(INT NUM), DECREMENTS "NUM" BY 1.

YOU HAVE TO CODIFY A RECURSIVE "MULTIPLY" FUNCTION, AS DESCRIBED BELOW:
	INT MULTIPLY(INT A, INT B);
THE FUNCTION MUST RETURN THE VALUE OF A * B, (E.G.: 6 * 4 = 4+4+4+4+4+4 = 24).

EVERY INPUT CONSISTS OF TWO NUMBER, SEPARATED BY <SPACE>.
YOUR PROGRAM MUST KEEP READING LINES OF TWO NUMBERS, AND FOR EACH ONE SHOW THE RESULT OF MULTIPLY(A,B).
THE LAST LINE CONSIST TWO ZEROS, "0 0", INGNORE IT.

YOU CAN USE THE FUNCTIONS OF OTHER CHALLENGES.
YOU CAN'T USE OTHER OPERATOR OR FUNCTIONS IN THIS CHALENGE!!!

EXAMPLES
INPUT
1 2
2 4
1 1
0 0 

OUTPUT
2
8
1

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

int sum(int a, int b) {
	if (zero(a))
		return b;
	else
		return sum(decr(a),incr(b));
}

int multiply(int a, int b) {
	if (zero(a))
		return 0;
	if (zero(b))
		return 0;
	return sum(a,multiply(a,decr(b)));
}

void read() {
	int a,b;
	scanf("%d %d", &a, &b);
	if (zero(a))
		if (zero(b))
			return;
	printf("%d\n", multiply(a,b));
	read();
}

int main() {
	read();
	return 0;
}