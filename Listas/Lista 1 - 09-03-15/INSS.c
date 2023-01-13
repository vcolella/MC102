#include <stdio.h>

int main(){

    char s,a;
    int I,C;

    printf("Digite M Ou F para sexo, a idade do individuo e o tempo de contribuicao: ");
    scanf("%c %d %d", &s, &I, &C);

    if(s=='M' && ((I>=65 && C>=10) || (I>=63 && C>=15))){
        a = 'y';
    }

    else if(s=='F' && ((I>=63 && C>=10) || (I>=61 && C>=15))){
        a = 'y';
    }
    else{
        a = 'n';
    }

    switch(a){

        case 'n':
            printf("\nNao aposentavel.\n");
            break;

        case 'y':
            printf("\nAposentavel.\n");
    }

    return 0;

}
