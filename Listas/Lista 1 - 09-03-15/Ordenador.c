#include <stdio.h>

int main(){

    int a,b,c;
    printf("Digite tres numeros inteiros separados por espaco: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("\n");

    if((a>c)&&(b>c)){

        if(a<b){
            printf("Em ordem crescente: %d %d %d", c,a,b);
        }
        else{
            printf("Em ordem crescente: %d %d %d", c,b,a);
        }
    }
    else if((a>b)&&(c>b)){

        if(a<c){
            printf("Em ordem crescente: %d %d %d", b,a,c);
        }
        else{
            printf("Em ordem crescente: %d %d %d", b,c,a);
        }
    }
    else if((b>a)&&(c>a)){

        if(b<c){
            printf("Em ordem crescente: %d %d %d", a,b,c);
        }
        else{
            printf("Em ordem crescente: %d %d %d", a,c,b);
        }
    }

    else{
        printf("I dunno what u talkin' about.");
    }

return 0;
}
