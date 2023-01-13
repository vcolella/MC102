#include <stdio.h>

int main(){

    int prato;

    printf("Menu do dia: Prato 1, Prato 2, Prato 3, Prato 4. Digite o numero do seu prato ou '0' para sair.\n");

    while(prato!=0){

        scanf("%d", &prato);

        if(prato==1 || prato==2 || prato==3 || prato==4){
            printf("Seu prato eh o numero %d.\n", prato);
        }

        else if(prato!=1 && prato!=2 && prato!=3 && prato!=4 && prato!=0){
            printf("Nao temos o prato %d hoje, por favor escolha outro ou 's' para sair.\n", prato);
        }
    }
    return 0;
}
