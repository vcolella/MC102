/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo calcular as
raízes reais, dados tres coeficientes não nulos
a,b e c, ou informar se não há raízes reais.*/




#include <stdio.h>
#include <math.h>

int main(){

    float a,b,c,x1,x2,delta;

    scanf("%f %f %f", &a, &b, &c);

    delta = pow(b,2) - (4*a*c);

    if (delta < 0){

        printf("A equacao fornecida nao possui raiz.\n");
    }

    else if (delta == 0){

        x1= (-b)/(2*a);
        printf("A equacao fornecida possui a raiz %.4f\n.", x1);
    }

    else {

        x1 = ((-b) - sqrt(delta)) / (2*a);
        x2 = ((-b) + sqrt(delta)) / (2*a);

        if(x1>x2){

            printf("A equacao fornecida possui as raizes %.4f e %.4f.\n", x2, x1);
        }

        else{
            printf("A equacao fornecida possui as raizes %.4f e %.4f.\n", x1, x2);

            }
    }

    return (0);
}
