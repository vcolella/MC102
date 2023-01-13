#include <stdio.h>

#define N    100
#define VMAX 10

void  LeSequencia(int x[], int n);
void  ImprimeSequencia(int x[], int n);
void  OrdenaPorPermutacao(int x[], int n); /* bubble sort */
int   BuscaBinaria(int x[], int n, int elem); /* busca binaria */

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

void OrdenaPorPermutacao(int x[], int n)
{
  int y,i,j;

  /* 

     1. Fixa-se um extremo (inicio ou fim) do vetor para receber o
        maior (menor) elemento.  

     2. Percorre o vetor comparando elementos em posicoes
        consecutivas, trocando eles se necessario, de modo que o maior
        (menor) seja colocado no extremo fixo.

     3. Reduz o tamanho do vetor, excluindo o extremo fixo, e repete o
        processo ate que o tamanho seja 1.
   
     No exemplo abaixo, estamos fixando a ultima posicao do vetor e
     colocando o maior elemento nela a cada percurso.

  */

  for (i=n-1; i > 0; i--) 
    for (j=0; j < i; j++) {
      if (x[j] > x[j+1]){
	y      = x[j]; 
	x[j]   = x[j+1];
	x[j+1] = y;
      }
    }
}

/* Retorna a posicao do elemento, caso ele seja encontrado, ou -1 no
   caso contrario. */

int BuscaBinaria(int x[], int n, int elem){
  int posIni=0, posFim=n-1, posMeio;

  while(posIni <= posFim){ //enquanto o vetor tiver pelo menos 1 elemento
    posMeio = (posIni+posFim)/2;
    if(vet[posMeio] == elem)
      return posMeio;
    else if(vet[posMeio] > elem)
      posFim = posMeio - 1;
    else
      posIni = posMeio + 1;
  }
  return -1;
}


int main()
{
  int   x[N];
  int   n;

  scanf("%d",&n);
  LeSequencia(x,n);
  OrdenaPorPermutacao(x,n);
  ImprimeSequencia(x,n);
  printf("\n");

  return(0);
}
