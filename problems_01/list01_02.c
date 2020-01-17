/*
UNIVERSIDADE FEDERAL DO AMAZONAS - UFAM
CIÊNCIA DA COMPUTAÇÂO
ICC014 - LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - 2019/01
TRABALHO PRÁTICO 01 - EXERCICIO 02

ALUNO - MARCOS AVNER PIMENTA DE LIMA

Jogo - Contando

Existem n pessoas que estão em uma linha, em um famoso jogo chamado "contando". Quando o jogo começa, a pessoa mais à esquerda diz "1" em voz alta, em seguida, a segunda pessoa (as pessoas estão numerados de 1 a n, da esquerda para a direita) diz "2" em voz alta. Isto é seguido pela terceira pessoa dizendo "3", e assim por diante. Quando a n-ésima pessoa (ou seja, a pessoa mais a direita) diz "n" em voz alta, a próxima vez vai para a sua pessoa imediatamente à esquerda (ou seja, a (n-1)-ésima pessoa), que deve dizer "n + 1" em voz alta, então a (n-2)-ésima pessoa deve dizer "n + 2" em voz alta, e assim por diante. Depois que a pessoa mais à esquerda falou de novo, a contagem vai para a direita novamente. Há um senão (caso contrário, o jogo seria muito chato!): Se uma pessoa dizer um número que é múltiplo de 7, ou sua representação decimal contém o dígito 7, ele deve bater palmas em vez disso! 

Entrada
Haverá um número ilimitado de casos de teste na entrada. Cada caso de teste contém três inteiros n, m e k (2 ≤ n ≤ 100, 1 ≤ m ≤ n, 1 ≤ k ≤ 100) em uma única linha. O último caso de teste é seguido por uma linha com n = m = k = 0, e que não deverá ser processado por se tratar do critério de parada.

Saída
Para cada linha, imprima o número real que está sendo contado, quando a m-ésima pessoa bate palmas pela k-ésima vez. 

EXEMPLO
Entrada
4 1 1
4 1 2
4 3 1
4 3 2
4 3 3
4 3 4
0 0 0

Saída
7
37
17
21
27
35
*/
#include <stdio.h>

char temSete(unsigned int x) 
{ 
    while (x > 0) { 
        if (x % 10 == 7) 
            break; 
        x = x / 10; 
    }  
    return (x > 0); 
}

char ehMultiploSete(unsigned int x) {
	return !(x % 7);
} 

int main()
{
	unsigned int n, k, m, pos = 1;
	unsigned int i, number = 1;
	char step = 1;

	scanf("%d %d %d", &n, &m, &k);
	while (n) {
		while (k) {
			if ((temSete(number) || ehMultiploSete(number))  && (pos == m)) {
				k--;
			}
			if (pos == 1) {
				step = 1;
			}
			if (pos == n) {
				step = -1;
			}
			number++;
			pos += step;
		}
		printf("%d\n", number-1);
		number = 1;
		pos = 1;
		step = 1;
		scanf("%d %d %d", &n, &m, &k);
	}
	return 0;
}
