/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo calcular o tamanho
de um tesouro e a sequencia de ilhas invadidas,
dadas as quantidades de tesouro em cada ilha e
o limite de tesouro que o navio pode comportar sem afundar.
Entra-se com os tesouros nas ilhas 1,2,3 e 4, respectivamente,
e o programa calcula o melhor trajeto (maior tesouro total) bem como
a sequencia de ilhas invadidas.*/

#include <stdio.h>

int main(){


    int i1,i2,i3,i4,t; /*tesouro nas ilhas 1,2,3 e 4*/
    int L; /*t->tesouro , L->limite*/

    scanf("%d %d %d %d %d", &i1, &i2, &i3, &i4, &L);

    if((((i1+i3+i2+i4)>L) || ((i1+i3+i2+i4)==(i1+i3)) || ((i1+i3+i2+i4)==(i1+i3+i4)))){

        if(((((i1+i3+i4)>L) ||  ((i1+i3+i4)==(i1+i3)) || (((i1+i3+i4)<(i2+i3)) && ((i2+i3)<=L)) || (((i1+i3+i4)<(i2+i4)) && ((i2+i4)<=L))) && (((i2+i3+i4)>L) ||  (((i2+i3+i4)<=(i1+i3)) && ((i1+i3)<=L)) || (((i2+i3+i4)<=(i1+i4)) && ((i1+i4)<=L)) || (((i2+i3+i4)==(i2+i3) && ((i2+i3)<=L)))))){



                if((((i2+i4)>L) || ((i1+i3)>=(i2+i4))) && (((i2+i3)>L) || ((i1+i3)>=(i2+i3)))  && (((i1+i4)>L) || ((i1+i3)>=(i1+i4))) && ((i1+i3)<=L) && (L>0)){

                    t = i1+i3;
                    printf("Tesouro: %d\n",t);
                    printf("Caminho: 1, 3, F.\n");
                }

                else if((((i1+i4)>(i1+i3)) || ((i1+i3)>L)) && (((i2+i3)>L) || ((i1+i4)>=(i2+i3))) && (((i2+i4)>L) || ((i1+i4)>=(i2+i4))) && ((i1+i4)<=L) && (L>0)){

                    t = i1 + i4;
                    printf("Tesouro: %d\n",t);
                    printf("Caminho: 1, 4, F.\n");
                }

                else if((((i2+i4)>L) || ((i2+i3)>=(i2+i4))) && ((i2+i3)<=L) && (L>0)){

                    t = i2 + i3;
                    printf("Tesouro: %d\n",t);
                    printf("Caminho: 2, 3, F.\n");
                }

                else if((((i2+i4)>(i1+i3)) || ((i1+i3)>L)) && (((i2+i4)>(i1+i4)) || ((i1+i4)>L)) && (((i2+i4)>(i2+i3)) || ((i2+i3)>L)) && ((i2+i4)<=L) && (L>0)){

                    t = i2 + i4;
                    printf("Tesouro: %d\n",t);
                    printf("Caminho: 2, 4, F.\n");
                }

                else {

                    t = 0;
                    printf("Tesouro: %d\n",t);
                    printf("Caminho: F.\n");
                }
        }

        else if((((i2+i3+i4)>(i1+i3+i4)) || ((i1+i3+i4)>L)) && ((i2+i3+i4)<=L)){

            t = i2 + i3 + i4;
            printf("Tesouro: %d\n",t);
            printf("Caminho: 2, 3, 4, F.\n");
        }

        else if((((i1+i3+i4)>=(i2+i3+i4)) || ((i2+i3+i4)>L)) && ((i1+i3+i4)<=L)){

            t = i1 + i3 + i4;
            printf("Tesouro: %d\n",t);
            printf("Caminho: 1, 3, 4, F.\n");
        }
    }

    else if((L>0) && ((i1+i3+i2+i4)<=L)){

        t = i1 + i3 + i2 + i4;
        printf("Tesouro: %d\n",t);
        printf("Caminho: 1, 3, 2, 4, F.\n");
    }



return 0;
}
