/*
UNIVERSIDADE FEDERAL DO AMAZONAS - UFAM
CIÊNCIA DA COMPUTAÇÂO
ICC014 - LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - 2019/01
TRABALHO PRÁTICO 01 - EXERCICIO 04

ALUNO - MARCOS AVNER PIMENTA DE LIMA

Alternância de bit

Ler uma quantidade indeterminada de um valor inteiro de 16 bits (unsigned short int) e, em seguida, ler um número de bit (entre 0 e 15) e alterne somente esse bit, ou seja, se esse bit for 1, troque para 0; se o bit for 0, troque para 1. Imprima esse novo inteiro com o bit trocado. O último valor, que não deverá produzir saída, tem o valor de 65535.

EXEMPLO
ENTRADA
444 3
444 15
65535

SAÍDA
436
33212

Explicação

444 = 0000 0001 1011 1100
436 = 0000 0001 1011 0100

444     = 0000 0001 1011 1100
33212 = 1000 0001 1011 1100

*/
#include <stdio.h>

int main()
{
	unsigned short n;
	unsigned short b;

	scanf("%hu",&n);
	while (n < 65535) {

		scanf("%hu",&b);

		b = 1 << b;
		n ^= b;

		printf("%hu\n", n);	
		scanf("%hu",&n);
	}
	
	return 0;
}
