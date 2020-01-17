/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 02 - CHALLENGE 02
STUDENT - MARCOS AVNER PIMENTA DE LIMA

MAX

IMAGINE A VERY PRIMITIVE LANGUAGE WITH ONLY 3 FUNCTIONS:
	1 - ZERO(INT NUM), RETURN TRUE IF "NUM" EQUALS ZERO, OR FALSE, OTHERWISE.
	2 - INCR(INT NUM), INCREMENTS "NUM" BY 1.
	3 - DECR(INT NUM), DECREMENTS "NUM" BY 1.

YOU HAVE TO CODIFY A RECURSIVE "MAX" FUNCTION, AS DESCRIBED BELOW:
	BOOL MAX(INT A, INT B);
THE FUNCTION MUST RETURN TRUE IF "A>B", OR FALSE, OTHERWISE.

EVERY INPUT CONSISTS OF TWO NUMBER, SEPARATED BY <SPACE>.
YOUR PROGRAM MUST KEEP READING LINES OF TWO NUMBERS, AND FOR EACH ONE SHOW "SIM" FOR "A>B", OR "NAO", OTHERWISE.
THE LAST LINE CONSIST TWO ZEROS, "0 0", INGNORE IT.

YOU CAN'T USE OTHER OPERATOR OR FUNCTIONS IN THIS CHALENGE!!!

EXAMPLES
INPUT
1 2
2 1
1 1
0 0 

OUTPUT
NAO
SIM
NAO

*/
#include <stdio.h>
bool zero(int num){
	return num == 0;
}

int incr(int num){
	return num + 1;
}

int decr(int num){
	return num - 1;
}

bool max(int a, int b) {
	if (zero(b)) {
		if (zero(a))
			return 0;
		else
			return 1;
	}
	else if (zero(a))
		return 0;
	else return max(decr(a),decr(b));
}

void read() {
	int a,b;	
	scanf("%d %d", &a, &b);
	if (zero(a))
		if (zero(b))
			return;
	if(max(a,b))
			printf("SIM\n");
		else
			printf("NAO\n");
	read();
}

int main() {
	read();
	return 0;
}