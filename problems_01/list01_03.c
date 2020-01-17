/*
UNIVERSIDADE FEDERAL DO AMAZONAS - UFAM
CIÊNCIA DA COMPUTAÇÂO
ICC014 - LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - 2019/01
TRABALHO PRÁTICO 01 - EXERCICIO 03

ALUNO - MARCOS AVNER PIMENTA DE LIMA

Professor ligado!

Um certo professor, que sempre passa uma lista de presença para ser assinada pelos alunos, resolveu conferir as assinaturas e notou que alguns alunos assinavam diferente em algumas aulas e desconfiou que alguém poderia estar assinando por eles. Como o professor possui muitos alunos e pouco tempo, ele pediu sua ajuda para validar as assinaturas. Uma assinatura é considerada falsa se houver mais de uma diferença entre a original e a que estiver sendo checada. Considere diferença uma troca de maiúscula para minúscula ou o contrário.

Vamos considerar que a entrada possui diversos casos de testes. A primeira linha de cada caso inicia com um inteiros N representando a quantidade de alunos de sua turma. As próximas N linhas serão da seguinte forma:

<Nome do aluno>  <Assinatura original>

A seguir haverá um inteiro M representando a quantidade de alunos que compareceram a uma aula. M linhas seguem, no seguinte formato:

<Nome do aluno> <Assinatura na aula>

Todos os alunos possuem apenas o primeiro nome na lista, nenhum nome se repete e todos os nomes contêm no máximo 20 letras (a-z A-Z). A entrada termina com N = 0, a qual NÃO deve ser processada.

Para cada caso, exiba uma única linha, a quantidade de assinaturas falsas encontradas.

EXEMPLO
ENTRADA
4
Chaves ChAvEs
Kiko kikO
Nhonho NHONHO
Chiquinha CHIquinHa
3
Chaves ChAvEs
Kiko kIKO
Chiquinha CHIquinHA
2
Jadson jadsON
Crishna Crishna
2
Crishna CRISHNA
Jadson JADson
0

SAIDA
1
2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 21

unsigned short diferencas(char *a, char *b) {
	unsigned short dif = 0, i = 0;
	while (a[i] && b[i]) {
		if(a[i] != b[i])
			dif++;
		i++;
	}
	return dif;
}

int main() {
	char **nomes, **assinaturas;
	char nome_aula[NAME_SIZE], assinatura_aula[NAME_SIZE];
	unsigned int alunos, sign, i;
	unsigned int falsos = 0;
	
	scanf("%d", &alunos);
	while (alunos) {
		
		// cria vetor de ponteiros para os alunos e assinaturas (base)
		nomes = (char **)malloc(alunos * sizeof(char *));
		assinaturas = (char **)malloc(alunos * sizeof(char *));	
		// leitura dos nomes e assinaturas dos alunos
		for (i = 0; i < alunos; i++) {
			nomes[i] = (char *)malloc(NAME_SIZE);
			assinaturas[i] = (char *)malloc(NAME_SIZE);
			scanf(" %s %s", nomes[i], assinaturas[i]);
		}

		// lê a quantidade de presenças na aula
		scanf("%d", &sign);
		// para cada presença busca a assinatura da base, e efetua a comparação com a assinatura da aula
		for (;sign; sign--) {
			scanf(" %s %s", nome_aula, assinatura_aula);
			// precorre a base de assinaturas
			for (i = 0; i < alunos; ++i) {
				// se encontrou o aluno pelo nome
				if(strcmp(nomes[i], nome_aula) == 0) {
					// verifica a quantidade de diferenças entre assinaturas
					if (diferencas(assinaturas[i], assinatura_aula)) {					
						falsos++;
					}
				}
			}
		}		
	
		//liberando base de assinaturas
		for (i = 0; i < alunos; i++) {
			free(nomes[i]);
			free(assinaturas[i]);
		}
		free(nomes);
		free(assinaturas);

		printf("%d\n", falsos);
		falsos = 0;
		scanf("%d", &alunos);
	}
	
	return 0;
}
