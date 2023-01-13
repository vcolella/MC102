#include <stdio.h>
#include <stdlib.h>
typedef struct Censo/*Variavel do tipo Censo*/
{
    int validez;/*Mostra se um registro esta valido*/
    char estado[3];/*UF*/
    char municipio[100];
    long int populacao;/*Populacao*/
    long int H,M;/*Numero de homens e mulheres*/
    float pH,pM;/*Percentual de homens e mulheres*/
} Censo;

int main(){
	int a = 8;

	a /= 4;
	printf("%d",a);


	return 0;
}
