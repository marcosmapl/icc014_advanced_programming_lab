/*
UNIVERSIDADE FEDERAL DO AMAZONAS - UFAM
CIÊNCIA DA COMPUTAÇÂO
ICC014 - LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - 2019/01
TRABALHO PRÁTICO 01 - EXERCICIO 01

ALUNO - MARCOS AVNER PIMENTA DE LIMA

Primos gêmeos

Uma das questões pesquisadas sobre os números primos é de como eles se distribuem nos naturais, com que frequência isso ocorre e qual a distância que existem entre eles. Por exemplo, existem vários pares de números primos que se diferem em duas unidades: (3, 5), (5, 7), (11, 13), (17, 19), (29,31), (41, 43), (59, 61), (71, 73), (101, 103), (107, 109), etc. Pares de números primos com essa propriedades são denominados de primos gêmeos. Não se sabe ainda se existe infinitos pares de números primos gêmeos.

Fazer um programa que leia dois números inteiros, X e Y, com 0 < X < Y < 1001, e escreva todos os pares de primos gêmeos no intervalo [X, Y].

O formato de ENTRADA consiste em dois números inteiros
400 600

O formato de SAÍDA consiste em colocar os dois primos gêmeos entre parêntesis e sem espaço entre os parênteses. Da seguinte forma:
(419,421)(431,433)(461,463)(521,523)(569,571)

*/
#include <stdio.h>

int isPrimo(unsigned short n) {
	unsigned short i = 2, mid = 0;
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	mid = (n/2)+1;
	for (; i <= mid; i++) {
		if (!(n%i))
			return 0;
	}
	return 1;
}

int main()
{
	unsigned short floor,ceil;	

	scanf("%hu", &floor);
	scanf("%hu", &ceil);
	ceil -= 2;

	while (floor < ceil) {
		if (isPrimo(floor) && isPrimo(floor+2))
			printf("(%d,%d)", floor, floor+2);
		floor++;
			
	}

	return 0;
}
