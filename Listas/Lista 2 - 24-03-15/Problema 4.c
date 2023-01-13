#include <stdio.h>

int main(){
    int n,i,d=1;

    printf("Digite um n: ");
    scanf("%d", &n);

    for(i=2;i<=(n/2);i++){

        d++;

        if(n%d == 0){
            printf("%d ", d);
        }
    }
    return 0;
}
