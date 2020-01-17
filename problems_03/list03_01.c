/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 03 - CHALLENGE 01
STUDENT - MARCOS AVNER PIMENTA DE LIMA

Medal board

Someone left the Olympic medals table out of order. Your program should put it in the correct order. The order of the countries in the medal table is given by the number of gold medals. If there is a tie in gold medals, the nation that has the most silver medals is ahead. If there is a tie in gold and silver medals, the country is better placed with more bronze medals. If two or more countries tie the three types of medals, your program must show them in alphabetical order.

Use SelectionSort to sort

Input

The input is given by the number of participating countries N (0 ≤ N ≤ 50) followed by the list of countries with their gold medals O (0 ≤ O ≤ 100), silver P (0 ≤ P ≤ 100) and bronze B 0 ≤ B ≤ 100).

Output

The output should be the list of countries, with their gold, silver and bronze medals, in the correct order of the medal table, with the most winning nations appearing first.

EXAMPLES
INPUT
8
Belgica 2 2 2
Brasil 7 6 6
Franca 10 18 14
Italia 8 12 8
Australia 8 11 10
Colombia 3 2 3
Suica 3 2 2
Tailandia 2 2 2

OUTPUT
Franca 10 18 14
Italia 8 12 8
Australia 8 11 10
Brasil 7 6 6
Colombia 3 2 3
Suica 3 2 2
Belgica 2 2 2
Tailandia 2 2 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ilhas Menores Distantes dos Estados Unidos [maior nome de um país]
#define PAIS_NOME_SIZE 43

void swapMedal(unsigned char *m1, unsigned char *m2) { 
  unsigned char temp = *m1; 
  *m1 = *m2; 
  *m2 = temp; 
}

int main() {
	unsigned char n, i, j, k;
	unsigned char *ouros, *pratas, *bronzes;
	char **paises, *swap;
	
	scanf("%hhu", &n);
	paises = (char **)malloc(n * sizeof(*paises));
	ouros = (unsigned char *)malloc(n * sizeof(ouros));
	pratas = (unsigned char *)malloc(n * sizeof(pratas));
	bronzes = (unsigned char *)malloc(n * sizeof(bronzes));
	
	for (i = 0; i < n; i++) {
		paises[i] = (char *)malloc(PAIS_NOME_SIZE * sizeof(char));
		scanf(" %s %hhu %hhu %hhu", paises[i], &ouros[i], &pratas[i], &bronzes[i]);
	}

  for (i = 0; i < (n - 1); i++) {
    k = i;
    for (j = i; j < n; j++) {
      if (ouros[j] > ouros[k])
        k = j;
      else if (ouros[j] == ouros[k]) {
        if (pratas[j] > pratas[k])
          k = j;
        else if (pratas[j] == pratas[k]) {
          if (bronzes[j] > bronzes[k])
            k = j;
          else if (bronzes[j] == bronzes[k]) {
            if (strcmp(paises[j],paises[k]) < 0) {
              k = j;
            }
          }
        }
      }
    }
    swapMedal(&ouros[i], &ouros[k]);
    swapMedal(&bronzes[i], &bronzes[k]);
    swapMedal(&pratas[i], &pratas[k]);
    
    swap = paises[i];
    paises[i] = paises[k];
    paises[k] = swap;
  }

  for (i = 0; i < n; i++) {
    printf("%s %hhu %hhu %hhu\n",paises[i], ouros[i], pratas[i], bronzes[i]);
  }
	
	for (i = 0; i < n; i++) {
		free(paises[i]);
	}
	free(paises);
	free(ouros);
	free(pratas);
	free(bronzes);
	
	return 0;
}