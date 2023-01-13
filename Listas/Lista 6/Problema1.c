#include <stdio.h>

void ordenaPreco(struct Produto vet[], int n);
void ordenaQuant(struct Produto vet[], int n);
void BubbleSort(int vet[], int tam);

struct Produto{
	char nome[80];
	double preco;
	int quantidade;
};

int main(){
	int n;
	printf("Digite o numero de itens a serem cadastrados: ");
	scanf("%d", &n);

	struct Produto item[n];
	int i;

	for(i=0;i<n;i++){
		puts(item[i].nome,"Babaca");
		item[i].preco = i;
		item[i].quantidade = 2*i;
	}

	ordenaQuant(item,n);
	ordenaPreco(item,n);

	for(i=0;i<n;i++){
		printf("%lf\n", item[i].preco);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\n", item[i].quantidade);
	}
}

void ordenaQuant(struct Produto vet[], int n){
	BubbleSort(vet.quantidade,n);
}

void ordenaPreco(struct Produto vet[], int n){
	BubbleSort(vet.preco, n);
}

void BubbleSort(int vet[], int tam){
	int i,j, aux;
	for(i=tam‐1; i>0; i‐‐){
		for(j=0; j < i; j++){
			if( vet[j] > vet[j+1] ){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
}