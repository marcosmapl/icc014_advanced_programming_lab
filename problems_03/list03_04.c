/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 03 - CHALLENGE 04
STUDENT - MARCOS AVNER PIMENTA DE LIMA

Bucket Sort

Assume that we want to sort a set of K's of whole keys. Assume also that the keys to be sorted are distributed over a known range (for example, from 1 to N). Set up M compartments (buckets) where each compartment is responsible for saving a range of keys to be sorted. From the implementation point of view, the compartments form a vector of dimension M where each element of this vector is a list of integers (which will store the keys). To know which index of the vector each key should be placed, use the following formula: index = (key * M) / (N + 1).

Consider which index takes only the whole part of the calculation (note that it is not rounding, but simply picking up the whole part). For example, if key = 130; M = 30 and N = 999, the calculation would give 3.9, but the index would equal 3 (take only the whole part). If another value matches the same index, you must include it in the linked list but in an ordered way (use whatever sort method you want). After the last element in the list of K keys to be sorted has been included in the list of buckets, you must concatenate all the lists associated with the enclosures for final sorting.

Read the values ​​of M, K, N, and K values ​​(between 1 and N). As an output, the lists of each compartment should be printed, NULL if it does not exist, and the final list sorted.

For more information on bucket sort see an animation at: https://www.cs.usfca.edu/~galles/visualization/BucketSort.html

EXAMPLE
INPUT
10 11 999
986 123 324 222 435 765 900 45 100 203 500

OUTPUT
0 45
1 100 123
2 203 222
3 324
4 435
5 500
6 NULL
7 765
8 NULL
9 900 986
45 100 123 203 222 324 435 500 765 900 986

*/

#include <stdio.h>
#include <stdlib.h>	

typedef struct No
{
	int key;
	struct No *prox;
} No;

void freeList(No *head) {
	No *ant;
	if (head->prox == NULL) {
		return;
	}
	head = head->prox;
	do {
		ant = head;
		head = head->prox;
		free(ant);
	} while (head);
}

void insertBefore(No *head, int key) {
	No *novo;
	novo = (No *)malloc(sizeof(No));
	// encadeamento
	novo->prox = head->prox;
	head->prox = novo;
	// troca chaves
	novo->key = head->key;
	head->key = key;
}

void insertAfter(No *ant, int key) {
	No *novo;
	novo = (No *)malloc(sizeof(No));
	// encadeamento
	novo->prox = ant->prox;
	ant->prox = novo;

	novo->key = key;
}

void inserirChave(No *head, int key) {
	No *ant, *prox;

	if (head->key == 0) {
		head->key = key;
		return;
	} else if (key < head->key) {
		insertBefore(head, key);
		return;
	}
	
	ant = head;
	prox = ant->prox;
	while ((prox != NULL) && (prox->key < key)) {
		ant = prox;
		prox = prox->prox;
	}
	insertAfter(ant, key);
	return;
}

// n - intervalo de chaves
// m - buckets
// k - key
int main() {
	unsigned int m, n, k, i, bucket;
	int key;
	No *v, *item, *ant;
	
	scanf("%u %u %u", &m, &k, &n);
	n++;
	
	// cria e inicializa o vertor de buckets
	v = (No *)malloc(sizeof(No) * m);
	for (i = 0; i < k; i++) {
		scanf("%d", &key);
		bucket = (int)((key * m)/n);
		inserirChave(&v[bucket], key);	
	}
	
	for (i = 0; i < m; i++) {
		item = &v[i];
		printf("%d", i);
		while (item) {
			if (item->key)
				printf(" %d", item->key);
			else
				printf(" NULL");
			item = item->prox;
		}
		printf("\n");
	}

	for (int i = 0; i < m; ++i)	{
		item = &v[i];		
		while (item) {
			if (item->key)
				printf("%d ", item->key);			
			item = item->prox;
		}
	}
	printf("\n");

	for (int i = 0; i < m; ++i) {
		freeList(&v[i]);
	}
	
	free(v);
	return 0;
}