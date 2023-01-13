#include <stdio.h>

int primo(int num);

int main()
{
    int n,i,a,b;

    printf("Digite um numero n: ");
    scanf("%d", &n);

    for(i=n;i>=2;i--)
    {
        printf("teste");
        if(primo(i)==1)
        {
            a = i;
            break;
        }
    }
    i = n;
    while(primo(i)==0)
    {
        i++;
        printf("teste");
        if(primo(i)==1)
        {
            b = i;
            break;
        }
    }
    printf("\nO maior primo antes de %d eh %d e o menor depois de %d eh %d.", n, a, n, b);

    return 0;
}

int primo(int num)
{
    int i, count=0, yes = 1, no = 0;
    for(i=2;i<=num/2;i++){
        if(num%i==0){
         count++;
            break;
        }
    }
   if(count==0 && num!= 1)
   {
       return yes;
   }
   else
   {
       return no;
   }
}
