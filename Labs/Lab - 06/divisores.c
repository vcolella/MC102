/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo calcular uma matriz,
a partir de um numero N indicando sua ordem (NxN).
Na matriz, os elementos sao representados com '*' quando
i (linha) eh divisor de j (coluna) e vice-versa,
com '+' quando i e j nao sao divisores entre si e pelo
menos um deles eh primo, e '-' para os demais casos.*/


#include <stdio.h>


int main(){

    int N, i, j, a=0, s=0;
    int c,d,controle1 = 0, controle2 = 0; /*c,d, sao variaveis do loop, controle q e controle 2 indicam quantos divisores o numero tem*/

    scanf("%d", &N);

    for(i = 1;i <= N;i++){/*Primeiro loop para linha*/

        for(j = 1;j <= N;j++){/*Segundo loop para coluna*/

            for(c = 1;c <= i;c++){/*Este loop armazena os divisores de i em controle1*/
                if(i%c == 0){
                    controle1++;
                }
            }

            for(d = 1;d <= j;d++){/*Este loop armazena os divisores de j em controle2*/
                if(j%d == 0){
                    controle2++;
                }
            }

            if((i%j == 0) || (j%i == 0) || (j==i) || (i==1) || (j==1)){/*Se i e j sao divisores entre si*/
                printf("*");
                a++;
                controle1 = 0;
                controle2 = 0;
            }

            else if((i%j != 0) && (j%i != 0) && (j!=i) && ((controle1==2) || (controle2==2))){/*Se i e j NAO sao divisores entre si, e um deles eh primo*/
                printf("+");
                s++;
                controle1 = 0;
                controle2 = 0;
            }

            else if((i%j != 0) && (j%i != 0) && (j!=i) && (i!=1) && (j!=1) && (controle1!=2) && (controle2!=2)){/*Demais casos*/
                printf("-");
                controle1 = 0;
                controle2 = 0;
            }

        }

        printf("\n");/*Passa para proxima linha da matriz*/
    }
    printf("%d\n", a+s);/*Exibe soma de '+' e '*'*/
    return 0;
}


