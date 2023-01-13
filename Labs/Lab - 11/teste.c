#include <stdio.h>

int Inverte(int numero);
int mdc(int a, int b);

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);

    printf("%d",mdc(a,b));
    /*int numero;
    scanf("%d", &numero);
    int t=1;
    int digitos=1;

    while(numero/t > 0)
    {
        t *=10;
        digitos++;
    }

    int n=0,i,j=1;

    for(i=1;i<digitos+1;i++)
    {
        n += (numero%(10*j)/j)*((t/10)/j);
        j*=10;
    }

    printf("%d", n);*/
    return 0;
}
/*
int Inverte(int numero)
{
    int t=1;
    int digitos=1;

    while(numero/t > 0)
    {
        t *=10;
        digitos++;
    }

    int n=0,i,j=1;

    for(i=1;i<digitos+1;i++)
    {
        n += (numero%(10*j)/j)*(t/10/j);
        j*=10;
    }
    return n;
}
*/
int mdc(int a, int b)
{
    if(b==0)
    {
        return a;
    }

    else
    {
        return mdc(b,a%b);
    }
}
