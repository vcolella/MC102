#include <stdio.h>

float potencia(float x, int n);

int main(){
    float a,b;
    printf("Digite a base e o expoente: ");
    scanf("%f %f",&a,&b);
    printf("\nO valor desta potencia eh %.4f", potencia(a,b));
    return 0;
}

float potencia(float x, int n){
    float p=1;

    while(n!=0){
        p *= x;
        n--;
    }
    return (p);
}
