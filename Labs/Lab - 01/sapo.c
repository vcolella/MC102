/*
Victor Colella Gomes Castro Pereira
RA: 157462

Sapo.c : O programa lê, da entrada padrão,
5 números inteiros X0,Y0, X1,Y1 e P (pulo).*/


#include <stdio.h>

int main(){

    int x0,x1,y0,y1; /*coordenadas dos pontos*/

    int Vx,Vy; /*tamanho dos vetores*/

    int P; /*tamanho do pulo*/

    int Pt; /*número total de pulos*/

    scanf("%d %d %d %d %d", &x0, &y0, &x1, &y1, &P); /*entrada de dados*/

    Vx = x1 - x0; /*calcula vetor em x*/

    Vy = y1 - y0; /*calcula vetor em y*/

    Pt = (Vx / P) + (Vy / P); /*calcula numero total de pulos*/

    printf("O sapo precisa de %d pulos para chegar em %d,%d partindo de %d,%d.", Pt, x1, y1, x0, y0); /*saida de dados*/

    return 0;


}
