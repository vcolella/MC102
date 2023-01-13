/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo mapear a cadeia hierarquica de uma empresa de N funcionarios, com respeito a um 
funcionario K. O programa exibe o funcionario K e seus superiores, por ordem de hierarquia, ate o presidente (funcionario 0)*/

#include <stdio.h>

void LeMatriz(int N, int matriz[N][N]);/*Armazena a matriz hierarquica*/
int MeuChefe(int N, int matriz[N][N], int K, int i);/*Encontra chefe do funcionario em analise*/

int main(){

	int N,K;

	scanf("%d %d", &N, &K);/*Armazena numero de funcionarios e funcionario a ser analizado*/

	int matriz[N][N];

	LeMatriz(N,matriz);/*Armazena a matriz hierarquica*/

	printf("%d ", K);/*Exibe primeiro funcionario da hierarquia K*/

	MeuChefe(N,matriz,K,0);/*Inicia processo de mapeamento de hierarquia*/
	
	printf("\n");
	
	return 0;
}

void LeMatriz(int N, int matriz[N][N]){

	int i,j;

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d", &matriz[i][j]);

}

int MeuChefe(int N, int matriz[N][N], int K, int i){

	if(i == N)/*Apos o presidente ser encontrado, encerra o mapeamento*/
		return 0;

	if(matriz[i][K] == 1 && i<N){/*Caso seja encontrada a linha do funcionario i chefe do funcionario K em questao*/
		printf("%d ", i);
		return MeuChefe(N, matriz, i, 0);/*Reinicia processo para encontrar chefe do chefe, a partir da linha 0*/
	}
	else
		return MeuChefe(N, matriz, K, i+1);/*Passa para proxima linha*/
}

