/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo calcular a partir
do perimetro de uma cidade, se havera paz, ataque,
ou deve-se pensar. Para isso ele analiza se o numero
do perimetro eh triangular E perfeito, triangular ou
perfeito, ou nenhum dos dois.*/

#include <stdio.h>

int main(){

    unsigned long int n,p=0,t=0,i,j=1;

    scanf("%lu", &n);



    for(i=1;i<n;++i){

            if(n%i == 0){

                p += i;
            }

    }

    while(t<n){

        t +=  j;
        j++;
    }

    if((t==n) && (p==n)){
        printf("Paz");
    }

    else if((t!=n) && (p!=n)){
        printf("Atacar");
    }

    else if((t==n && p!=n) || (t!=n && p==n)){
        printf("Pensar");
    }

return 0;

}
