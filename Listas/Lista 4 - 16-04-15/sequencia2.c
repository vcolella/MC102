#include <stdio.h>

#define N    100
#define VMAX 10

void  LeSequencia(int x[], int n);
void  ImprimeSequencia(int x[], int n);
void  Frequencia(int x[], int n, int freq[]);
void  OrdenaPorSelecao(int x[], int n);

void LeSequencia(int x[], int n)
{
  int i;

  for (i=0; i < n; i++){
    scanf("%d",&x[i]);
  }

}

void ImprimeSequencia(int x[], int n)
{
  int i;

  for (i=0; i < n; i++) 
    printf("%d ",x[i]);

  printf("\n");

}

void OrdenaPorSelecao(int x[], int n)
{
  int y,i,j,jm;

  /* 

     1. Fixa-se um extremo (inicio ou fim) do vetor de tamanho n. 
     2. Percorre o resto do vetor comparando o elemento da posiçao
        fixa com os demais, trocando os menores (maiores) pelo
        elemento da posiçao fixa, de modo a garantir que o menor
        (maior) elemento seja SELECIONADO para a posiçao fixa.
     3. Reduz o tamanho do vetor excluindo o extremo com o elemento
        selecionado, e repete o processo ate que o tamanho seja 1.
   
     No exemplo abaixo, estamos usando o inicio como extremo e
     selecionando o menor. 

  for (i=0; i < n-1; i++) 
    for (j=i+1; j < n; j++) {
      if (x[i] > x[j]){
	y    = x[i]; 
	x[i] = x[j];
	x[j] = y;
      }
    }

    Outra opçao seria reduzir o numero de trocas deixando mais
    evidente o processo de selecao.

     1. Fixa-se um extremo (inicio ou fim) do vetor de tamanho n. 
     2. Percorre o vetor para encontrar o indice do menor (maior) elemento. 
     3. Troca-se o elemento do extremo fixo pelo menor elemento. 
     4. Reduz o tamanho do vetor excluindo o extremo com o elemento
        selecionado, e repete o processo ate que o tamanho seja 1.

     No exemplo abaixo, estamos usando o inicio como extremo e
     selecionando o menor. 

  */

  for (i=0; i < n; i++) {
    /* seleciona o indice do menor */
    jm = i;  
    for (j=i+1; j < n; j++) {
      if (x[jm] > x[j]){
	jm = j;
      }
    }
    /* troca o menor elemento pelo elemento do inicio */
    if (jm != i) {
      y     = x[jm];
      x[jm] = x[i];
      x[i]  = y; 
    }
  }
}

/* Calcula em fre[] o numero de ocorrencias de cada elemento x[i] em
   x[], sabendo que os elementos de x[] estao entre 0 e vmax. */

void Frequencia(int x[], int n, int freq[])
{
  int i, j;

  for (j=0; j <= VMAX; j++) 
    freq[j]=0;

  for(i=0; i < n; i++) {
    j = x[i];
    freq[j]++;
  }
}

int main()
{
  int   x[N],Freq[VMAX+1];
  int   n;

  scanf("%d",&n);
  LeSequencia(x,n);
  OrdenaPorSelecao(x,n);
  ImprimeSequencia(x,n);
  printf("\n");
  Frequencia(x,n,Freq);
  ImprimeSequencia(Freq,VMAX+1);

  return(0);
}
