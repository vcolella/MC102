#include <stdio.h>

int main(){

    float T;
    char t;

    printf("Digite F/f para Fahrenheit's ou C/c para Celsius: ");
    scanf("%c", &t);
    printf("\nDigite uma temperatura: ");
    scanf("%f", &T);

    if((t=='C')||(t=='c')){
        T = ((9/5)*T)+32;
        printf("\nSua temperatura eh de %.2f F.\n", T);
    }

    else if((t=='F')||(t=='f')){
        T = (5/9)*(T-32);
        printf("\nSua temperatura eh de %.2f C.\n", T);
    }

    else{
        printf("Entrada invalida. Terminando...");
    }

return 0;
}
