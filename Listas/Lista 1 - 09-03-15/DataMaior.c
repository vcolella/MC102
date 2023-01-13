#include <stdio.h>

int main(){

    int d1,m1,a1;
    int d2,m2,a2;

    printf("Please insert the first date using the format day/month/year: ");
    scanf("%d/%d/%d", &d1, &m1, &a1);
    printf("\nPlease insert the second date using the format day/month/year: ");
    scanf("%d/%d/%d", &d2, &m2, &a2);

    if(a2==a1){
        if(m2==m1){
            if(d2==d1){
                printf("\nAmbas as datas sao iguais.");
            }

            else if(d2<d1){
                printf("\n%d/%d/%d eh maior.", d1,m1,a1);
            }

            else{
                printf("\n%d/%d/%d eh maior.", d2,m2,a2);
            }
        }

        else if(m2<m1){
            printf("\n%d/%d/%d eh maior.", d1,m1,a1);
        }

        else{
            printf("\n%d/%d/%d eh maior.", d2,m2,a2);
        }
    }
    else if(a2<a1){
            printf("\n%d/%d/%d eh maior.", d1,m1,a1);
    }
    else{
        printf("\n%d/%d/%d eh maior.", d2,m2,a2);
    }
    return 0;
}
