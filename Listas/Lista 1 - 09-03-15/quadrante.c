#include <stdio.h>

int main(){

    int x,y;
    printf("Digite uma coordenada (x,y), respectivamente: ");
    scanf("%d %d", &x, &y);

    if(x>0 && y>0){
        printf("A coordenada (%d,%d) esta no primeiro quadrante.", x,y);
    }

    else if(x<0 && y>0){
        printf("A coordenada (%d,%d) esta no segundo quadrante.", x,y);
    }

    else if(x<0 && y<0){
        printf("A coordenada (%d,%d) esta no terceiro quadrante.", x,y);
    }

    else if(x>0 && y<0){
        printf("A coordenada (%d,%d) esta no quarto quadrante.", x,y);
    }

    else if(x==0 && y!=0){
        printf("A coordenada (%d,%d) esta sob o eixo y.", x,y);
    }

    else if(x!=0 && y==0){
        printf("A coordenada (%d,%d) esta sob o eixo x.", x,y);
    }

    else if(x==0 && y==0){
        printf("A coordenada (%d,%d) esta na origem do sistema.", x,y);
    }

    return 0;
}
