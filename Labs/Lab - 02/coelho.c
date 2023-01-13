/*
Victor Colella Gomes Castro Pereira
RA: 157462

Coelho.c : O programa lê, da entrada padrão,
5 números inteiros X0,Y0, X1,Y1 e P (pulo), e devolve o número mínimo
de pulos efetuados. */


#include <stdio.h>
#include <math.h>

int main(){

    float x0,x1,y0,y1; /*coordenadas dos pontos*/

    float Vx,Vy; /*tamanho dos vetores*/

    int P; /*tamanho do pulo*/

    float Pt; /*número total de pulos*/

    scanf("%f %f %f %f %d", &x0, &y0, &x1, &y1, &P); /*entrada de dados*/

    Vx = x1 - x0; /*calcula vetor em x*/
    Vx = pow(Vx, 2); /*eleva ao quadrado*/

    Vy = y1 - y0; /*calcula vetor em y*/
    Vy = pow(Vy, 2);


    Pt = sqrt(Vx + Vy) / P; /*calcula numero total de pulos*/

    printf("O coelho precisa de %.2f saltos para chegar em %.2f,%.2f partindo de %.2f,%.2f.", Pt, x1, y1, x0, y0); /*saida de dados*/

    return 0;


}
