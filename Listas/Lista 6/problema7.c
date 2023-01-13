#include <stdio.h>
void teste(int n, int *b, int *k);

int main(){

	int b=0,k=0;
	int n;

	printf("Insira n: ");
	scanf("%d", &n);
	printf("\n");


	teste(n, &b, &k);

	printf("%d^%d = %d\n\n", b,k,n);

	return 0;
}

void teste(int n, int *b, int *k){
	int i,aux=1,contador=0;

	*k=0;
	*b = 2;

	while(aux<n){

		while(aux<n){
			(*k)++;
			aux = 1;
			for(i=0;i<(*k);i++){
				aux *= (*b);
			}
		}		
		if(aux>n){
			(*k)=1;
			aux = 1;
			(*b)++;
		}
	}
}