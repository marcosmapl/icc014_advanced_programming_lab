/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 03 - CHALLENGE 02
STUDENT - MARCOS AVNER PIMENTA DE LIMA

Sorting Santa's List of Children

Santa Claus is in the final preparations for the delivery of gifts to the children of the whole world because Christmas is coming again. Looking at his new lists of children who were going to win gifts this year he realized that the trainee elf (who had been responsible for making the lists) had not put the names in alphabetical order.

Since Santa is a very organized man, he wants every child list to have, in its end, the total number of children who were well behaved this year and a total of those who were not. So he can compare the number of children who behave this year with those of previous years.

To help the good old man, your duty is to create a program that reads all the names on the list and prints the same names in alphabetical order. At the bottom of the list, you should print the total number of children who were and were not behaved this year.

Use QuickSort to sort names

Input

The entry is composed of several names. The first N value (0 ≤ N ≤ 100) indicates how many names in the list. The following N lines contain a special character corresponding to the behavior of the child (+ indicates that the child was well behaved, - indicates that the child was not well behaved). After the special character, it follows the name of the child with a maximum of 20 characters.

Output

For each list of children, you should print the names in alphabetical order. After printing the children's names, you should show the total number of children who have behaved well or ill during the year.

EXAMPLE
INPUT
16
+ Tininha
+ Dudinha
- Carlinhos
- Marquinhos
+ Joaozinho
+ Bruninha
- Leandrinho
- Fernandinha
+ Rafinha
- Pedrinho
+ Aninha
- Tamirinha
- Gaguinho
- Zezinho
- Luquinhas
+ Julhinha

OUTPUT
Aninha
Bruninha
Carlinhos
Dudinha
Fernandinha
Gaguinho
Joaozinho
Julhinha
Leandrinho
Luquinhas
Marquinhos
Pedrinho
Rafinha
Tamirinha
Tininha
Zezinho

Se comportaram: 7 | Nao se comportaram: 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHILD_NAME_SIZE 20

/* Implementacao do quicksort em si. */
void qSortInterno(char **v, char inicio, char fim) {
	char *pivot, *temp;
	char i,j;

	if(fim > inicio) { /* tem mais de 1 elemento */
		i = inicio;
		j = fim;
		pivot = v[(i+j)/2];
		
		do {
      	
			while(strcmp(v[i],pivot) < 0) i++; /* procura por algum item do lado errado  >= pivot */
      	while(0 < strcmp(v[j],pivot)) j--; /* procura por algum item do lado errado <= pivot */

      	if(i<= j) { /* deixa o igual para garantir que ao final i<j */
				/* troca os nomes posicionados errados */
        		temp = v[i];
        		v[i] = v[j];
        		v[j] = temp;
        		i++; j--;
      	}
		} while (i <= j);
    	qSortInterno(v,inicio, j);
    	qSortInterno(v, i,fim);
	}
}

/* Funcao qickSort a ser chamada em outros pontos do programa. Serve apenas para disparar a chamada revursiva */
void quickSort(char **v, char n) {
	qSortInterno(v, 0, n-1);
}

int main() {
	char n, i, c, good = 0, bad = 0;
	char **v, *t;

	scanf("%hhd", &n);   
	v = (char **) malloc(sizeof(char *) * n);
  
	for (i = 0; i < n; i++) {
   	// '+' = 43, '-' = 45
    	v[i] = (char *)malloc(sizeof(char) * CHILD_NAME_SIZE);
    	scanf(" %c %s", &c, v[i]);
    	
		if (c == 43)
      	good++;
    	else
      	bad++;
  	}

	/* ordena os nomes usando quicksort */
  	quickSort(v, n);

	/* imprime os nomes e os libera da memória */
  	for (i = 0; i < n; i++) {
		printf("%s\n", v[i]);
   	free(v[i]);
  	}
  	free(v);
  	printf("\nSe comportaram: %d | Nao se comportaram: %d\n", good, bad);
  	return 0;
}