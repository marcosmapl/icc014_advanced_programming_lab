/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 02 - CHALLENGE 10
STUDENT - MARCOS AVNER PIMENTA DE LIMA

SYMMETRICAL/OPPOSITE/COMPLEMENTARY

CHANGE YOUR FUNCTIONS "MIN", "MAX", "EQUAL" AND "NOTEQUAL" TO SUPPORT NEGATIVE NUMBERS.

IMPLEMENT A "SYMMETRIC" FUNCTION, WHICH TAKES AN INTERGER ARGUMENT AND RETURNS ITS SYMMETRIC VALUE.
YOUR PROGRAM, MUST READ AN UNDETERMINED NUMBER OF INTEGER VALUES AND PRINT THE CORRESPONDING SYMMETRIC.
THE LAST VALUE MUST BE EQUAL ZERO, INGNORE IT.

NOW YOU CAN USE LOGICAL OPERATORS "AND(&&)", "OR(||)" AND "NOT(!)".

EXAMPLES
INPUT
1
2
0

OUTPUT
-1
-2
*/
#include <stdio.h>
int zero(int num){
	return num == 0;
}

int incr(int num){
	return num + 1;
}

int decr(int num){
	return num - 1;
}

int simetrico_interno(int x, int y, int a, int b) {
	if (zero(x))
		return a;
	if (zero(y))
		return b;
	return simetrico_interno(incr(x), decr(y), incr(a), decr(b));
}

int simetrico(int x) {
	return simetrico_interno(x, x, 0, 0);	
}

int main() {
	int x;
	scanf("%d", &x);
	if (zero(x)) {
		return 0;
	}
	printf("%d\n", simetrico(x));
	main();
}