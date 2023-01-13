#include <stdio.h>

int mdc(int m, int n);

int main()
{
    char c='S';
    while(c=='S')
    {
        int m,n;
        printf("Digite m e n naturais, com o maior numero primeiro, caso haja: ");
        scanf("%d %d", &m, &n);
        printf("\nO Maximo Divisor comum dos dois numeros eh: %d", mdc(m,n));
        printf("\nDigite 'S' para repetir: ");
        scanf(" %c", &c);
    }

    printf("\nEncerrando...");
    return 0;
}

int mdc(int m, int n)
{
    if(n==0)
    {
        return m;
    }

    else
    {
        return mdc(n,m%n);
    }

}
