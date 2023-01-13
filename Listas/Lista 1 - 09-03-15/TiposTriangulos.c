#include <stdio.h>

int main(){

    float a,b,c;
    printf("Digite tres valores para os lados do triangulo: ");
    scanf("%f %f %f", &a, &b, &c);

    if((a!=b)&&(a!=c)&&(b!=c)){
        printf("\nEste triangulo eh escaleno.\n");
    }
    else if ((a==b)&&(a==c)&&(b==c)){
        printf("\nEste triangulo eh equilatero.\n");
    }
    else{
        printf("\nEste triangulo eh isoceles.\n");
    }
    return 0;
}
