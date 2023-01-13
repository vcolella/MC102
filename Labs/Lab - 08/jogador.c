/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo calcular para apostas a porcentagem de acerto por jogo,
e o numero medio de apostas por jogo, dado um cacife C inicial e um objetivo O
final. O programa usa dois metodos: Sequencial e Martingale.*/

#include <stdio.h>


/* Entrada: cacife inicial e o objetivo do jogador
   Saida: caso o jogador atinja seu objetivo utilizando a estratégia sequencial, retorna o numero de jogadas realizadas,
          caso contrario, retorna esse valor negativo */
int Sequencial(int cacife, int objetivo);
 /* Entrada: cacife inicial e o objetivo do jogador
   Saida: caso o jogador atinja seu objetivo utilizando a estratégia Martingale, retorna o numero de jogadas realizadas,
          caso contrario, retorna esse valor negativo */
int Martingale(int cacife, int objetivo);
int ganhou();/*Retorna 0 ou 1, de modo pseudo-aleatorio*/
int modulo(int x);/*Retorna o modulo de um valor*/

int main(){
    long int C, O, N,i,a=0,b=0,St=0,Mt=0,contadorA=0,contadorB=0; /*Declaracao das variaveis usadas em main*/

    scanf("%ld %ld %ld", &C, &O, &N);/*Coleta os dados do usuario*/

    for(i=1;i<=N;i++){
        a = Sequencial(C,O);/*Invoca o numero de apostas Sequencial*/

        St += modulo(a);/*Acumula total de apostas Sequencial*/

        if(a>0){
            contadorA++;/*Acumula numero de vitorias Sequencial*/
        }
    }

    printf("Sequencial: %ld, %ld\n", (contadorA*100/N), (St/N));/*Exibe estatistica para Sequencial*/

    for(i=1;i<=N;i++){
        b = Martingale(C,O);/*Invoca o numero de apostas Martingale*/

        Mt += modulo(b);/*Acumula total de apostas Martingale*/

        if(b>0){
            contadorB++;/*Acumula numero de vitorias Martingale*/
        }
    }
    printf("Martingale: %ld, %ld\n", (contadorB*100/N), (Mt/N));/*Exibe estatistica para Martingale*/

    return 0;
}

int ganhou(){
    /* Codigo que gera uma sequencia pseudo-randomica,*/
    static unsigned long long int seed = 123456789;
    seed = (1103515245 * seed + 12345) % 2147483648;
    /* Teste da probabilidade de ganhar a aposta*/
    return seed >= 2147483648/2;
}

int Sequencial(int cacife, int objetivo){
    int apostas=0,g;/*Apostas:numero de apostas total. g:vitoria ou derrota*/
    while(cacife>0 && cacife<objetivo){
        g = ganhou();/*atribui valor a g*/
        if(g==1){
            cacife++;/*Aumenta o cacifie em caso de aposta ganha*/
        }
        else if(g==0){
            cacife--;/*Diminui o cacife em caso de derrota*/
        }
        apostas++;/*Aumenta total de apostas*/
    }
    if(cacife==0){
        apostas = -apostas;/*Atribui valor negativo em caso de derrota*/
    }

    else if(cacife==objetivo){
        apostas = apostas;/*Mantem valor positivo em caso de vitoria*/
    }
    return(apostas);/*Retorna total de apostas com sinal + ou -. */
}

int Martingale(int cacife, int objetivo){
    int apostas=0,g, perdas=1;/*Perdas: valor da aposta*/
    while(cacife>0 && cacife<objetivo){
        g = ganhou();
        if(cacife>=perdas){
            if(g==1){/*Em caso de vitoria*/
                cacife+=perdas;/*Soma o valor da aposta ao cacife*/
                perdas = 1;/*Reestabelece o valor da aposta para 1*/
            }
            else if(g==0){/*Em caso de derrota*/
                cacife -= perdas;/*Subtrai o valor da aposta do cacife*/
                perdas *= 2;/*Dobra o valor da aposta*/
            }
            apostas++;/*Aumenta total de apostas*/
        }
        else if(cacife<perdas){/*Caso a proxima aposta seja maior que o cacife*/
            perdas = cacife;/*O valor da aposta eh o total do cacife*/
            if(g==1){
                cacife+=perdas;/*Soma o valor da aposta ao cacife em caso de vitoria*/
                perdas = 1;/*Reestabelece o valor da aposta para 1*/
            }
            else if(g==0){
                cacife = 0;/*Zera o cacife em caso de derrota*/
            }
            apostas++;/*Aumenta total de apostas*/
        }
    }
    /*Mesma logica usada em Sequencial*/
    if(cacife==0){
        apostas = -apostas;
    }

    else if(cacife==objetivo){
        apostas = apostas;
    }
    return (apostas);
}

int modulo(int x){
    if(x>=0){
        x=x;/*Se x>=0, sinal permanece positivo*/
    }
    else if(x<0){
        x=-x;/*Se x<0, o sinal eh invertido*/
    }
    return x;/*retorna x*/
}
