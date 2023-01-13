/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo calcular o seno e o cosseno de um número
usando a serie de Maclaurin, para um limite de interacoes. Alem disso o programa calcula
a raiz quadrada aproximada de um numero com o Metodo de Newton, com um numero limite de interacoes.
Digite S para seno, C para cosseno, R para raiz quadrada e F ou f para sair. Inserida a letra, digite o
numero x e o numero de iteracoes a serem aplicadas.*/


#include <stdio.h>

int fatorial(int a);
float potencia(float x, int n);
double seno(double x, int n);
double cosseno(double x, int n);
double raizQuadrada(double x, int n);



int main(){

    char t;

    while(t!='F' && t!='f'){

        scanf(" %c", &t);

        if(t=='S'){
            double y;
            int z;
            scanf("%lf %d", &y,&z);
            printf("O valor aproximado de seno no ponto %.4f eh %.4f.\n", y, seno(y,z));
        }

        else if(t=='C'){
            double y;
            int z;
            scanf("%lf %d", &y,&z);
            printf("O valor aproximado de cosseno no ponto %.4f eh %.4f.\n", y, cosseno(y,z));
        }

        else if(t=='R'){
            double y;
            int z;
            scanf("%lf %d", &y,&z);
            printf("O valor aproximado da raiz de %.4f eh %.4f.\n", y, raizQuadrada(y,z));
        }


        else if(t!='S' && t!='C' && t!='R' && t!='f' && t!='F'){
            printf("Comando invalido. Entre com outro comando, ou 'F' para terminar.\n");
        }

    }
    return 0;
}


int fatorial(int a){
    int i,f = a;

    for(i=1;i<a;i++){
        f *= (a-i);
    }

    return (f);

}

float potencia(float x, int n){
    float p=1;

    while(n!=0){
        p *= x;
        n--;
    }
    return (p);
}


double seno(double x, int n){
    double s=0;
    int a,i;

    for(i=0;i<=n;i++){
        a = (2*i)+1;
        s += (potencia(-1,i) * potencia(x,a))/fatorial(a);
    }
    return (s);
}


double cosseno(double x, int n){
    double s=1;
    int a,i;

    for(i=1;i<=n;i++){
        a = 2*i;
        s += (potencia(-1,i) * potencia(x,a))/fatorial(a);
    }
    return (s);
}


double raizQuadrada(double x, int n){
    double s=1;
    int i;

    for(i=1;i<=n;i++){
        s -= (potencia(s,2) - x)/(2*s);
    }
    return (s);
}


