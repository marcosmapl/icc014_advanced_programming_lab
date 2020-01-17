/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 02 - CHALLENGE 06
STUDENT - MARCOS AVNER PIMENTA DE LIMA

ARRAY SUM

IMAGINE A VERY PRIMITIVE LANGUAGE WITH ONLY 3 FUNCTIONS:
	1 - ZERO(INT NUM), RETURN TRUE IF "NUM" EQUALS ZERO, OR FALSE, OTHERWISE.
	2 - INCR(INT NUM), INCREMENTS "NUM" BY 1.
	3 - DECR(INT NUM), DECREMENTS "NUM" BY 1.

YOU HAVE SUM ALL ELEMENTS OF AN ARRAY, IN A RECURSIVE WAY.
YOUR PROGRAM MUST READ THE NUMBER OF ELEMENTS IN THE ARRAY, IN THE FIRST LINE.
AFTER IT, READ N ELEMENTS, ONE BY LINE, AND AT THE END SHOW THE SUM OF ALL THEM.

YOU CAN USE THE FUNCTIONS OF OTHER CHALLENGES.
YOU CAN'T USE OTHER OPERATOR OR FUNCTIONS IN THIS CHALENGE!!!

EXAMPLES
INPUT
10
12
45
34
67
44
56
43
1
87
90

OUTPUT
479

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

int sumElementsOfArray(int n) {
	int x;
	if (zero(n))
		return 0;
	scanf("%d", &x);
	return sum(x, sumElementsOfArray(decr(n)));
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", sumElementsOfArray(n));
	return 0;
}