#include <stdio.h>

int main(){
    int t=0,i,n;

    printf("Digite n: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        t += i;
        printf("\n%d",t);
    }

    printf("\nTotal: %d", t);
    return 0;
}
