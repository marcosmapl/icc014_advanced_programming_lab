/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 02 - CHALLENGE 08
STUDENT - MARCOS AVNER PIMENTA DE LIMA

SOCCER GAME

CONSIDER A SOCCER MATCH BETWEEN TWO TEAMS "A" AND "B".
THE MATCH FINAL SCORE IS "M x N", WHERE "M" AND "N" ARE THE NUMBER OF GOALS SCORED BY "A" AND "B", RESPESCTIVELY.
IMPLEMENT A RECURSIVE PROGRAM THAT READS AN UNDETERMINED NUMBER OF SCORES AND PRINT ALL POSSIBLE SUCESSIONS OF GOALS.

THE LAST MATCH SCORE IS A LINE WITH "-1 -1". IGNORE IT!

EXAMPLES
INPUT
3 1
2 3
-1 -1

OUTPUT
AAAB
AABA
ABAA
BAAA

AABBB
ABABB
ABBAB
ABBBA
BAABB
BABAB
BABBA
BBAAB
BBABA
BBBAA
*/
#include<stdio.h>
#include<stdlib.h>

void scores(int a, int b, char *v, int i) {
	if ((a == 0) && (b == 0)) {
		printf("%s\n", v);
		return;
	}
	if (a > 0) {
		v[i] = 'A';
		scores(a-1, b, v, i+1);
	}
	if (b > 0) {
		v[i] = 'B';
		scores(a, b-1, v, i+1);	
	}
}

int main() {
	int a, b;
	char *v = NULL;
	scanf("%d %d", &a, &b);
		
	if ((a < 0) && (b < 0)) {
		free(v);
		return 0;
	} else if ((a > 0) && (b > 0)) {
		v = (char *)malloc(sizeof(char) * a * b);
		scores(a, b, v, 0);
	}
	
	printf("\n");	
	main();	
}