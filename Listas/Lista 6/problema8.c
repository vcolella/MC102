#include <stdio.h>

void primo(int m, int *p1, int *p2);

int main(){
	printf("Digite um inteiro: ");
	int m,p1,p2;
	scanf("%d", &m);
	p1 = m;
	p2 = m;
	primo(m,&p1,&p2);

	printf("\nO maior primo menor que %d eh %d e o menor primo maior que %d eh %d .", m, p1, m, p2);
	
	return 0;
}

void primo(int m, int *p1, int *p2){
	
	int contador=0;
	while(contador!=1){
		for(i=2;i<=n/2;i++){
			if((*p1)%i==0){
				contador++;
			}
		}
	}
	cont
}

