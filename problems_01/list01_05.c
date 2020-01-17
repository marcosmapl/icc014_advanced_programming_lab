/*
UNIVERSIDADE FEDERAL DO AMAZONAS - UFAM
CIÊNCIA DA COMPUTAÇÂO
ICC014 - LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - 2019/01
TRABALHO PRÁTICO 01 - EXERCICIO 05

ALUNO - MARCOS AVNER PIMENTA DE LIMA

Soma de elementos de uma matriz

Faça um programa que leia as dimensões M e N de uma matriz, leia a matriz de elementos inteiros e calcule recursivamente o SOMATÓRIO dos elementos dessa matriz.

Considere que o tamanho máximo de M e N é 20.

EXEMPLO
ENTRADA
5 4
12 13 14 15
13 14 15 16
14 15 16 17
15 16 17 18
16 17 18 19

SAÍDA
310
*/
#include <stdio.h>

unsigned int soma(unsigned int n) {
	unsigned int e;
	if (!n)
		return 0;
	else {
		scanf("%u",&e);
		return e + soma(n-1);
	}

}

int main()
{
	unsigned char m,n;
	scanf("%hhu",&m);
	scanf("%hhu",&n);

	printf("%u\n", soma(m*n));
	return 0;
}
