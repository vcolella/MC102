#include <stdio.h>

int main(){

    int ano;
    printf("Digite um ano: ");
    scanf("%d", &ano);

    if(ano%400 == 0){
        printf("\nO ano %d eh bissexto ! :D\n", ano);
    }

    else if((ano%4 == 0)&&(ano%100 != 0)){
        printf("\nO ano %d eh bissexto ! :D\n", ano);
    }

    else{
        printf("\nO ano %d nao eh bissexto. :(\n", ano);
    }
return 0;
}
