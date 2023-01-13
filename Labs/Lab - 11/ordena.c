#include <stdio.h>

/*
Victor C. G. C. Pereira
R.A.:157462

Este programa organiza um conjunto A de n inteiros de acordo com a seguinte regra.
Para dois valores X e Y, X deve preceder Y se:
1. O maximo divisor comum (mdc) entre x e um inteiro M for maior do que o mdc entre y e M, onde M eh um inteiro positivo fornecido na entrada.
2. Caso ate o item anterior nao estiver decidido entao x deve preceder y se, e somente se, x lido da direita para esquerda for menor do que y lido da direita para esquerda,
isto eh, o numero formado pelos digitos de x invertidos deve ser menor que o numero formado pelos digitos de y invertidos.
3. Caso ate o item anterior nao estiver decidido entao o menor elemento lido na sua forma natural, da esquerda para a direita, deve preceder o maior.*/

int mdc(int a, int b);/*Usa o método de Euclides, através de recursao, para encontrar o mdc de dois numeros a e b*/
void Ordena(unsigned long int conjunto[], int tam, int M);/*Seleciona em quais casos ocorre a troca de indices*/
int Inverte(int numero);/*Inverte a ordem do nuemero*/
void Troca(unsigned long int conjunto[], int j);/*Troca a ordem dos indices do conjunto*/

int main()
{
    int n,M,i;
    scanf("%d %d", &n, &M);
    unsigned long int A[n];/*Usa-se unsigned long int para aumentar a quantidade de valores armazenaveis (ate bem mais de um milhao*/
    for(i=0;i<n;i++)
    {
        scanf("%lu", &A[i]);/*Guarda os inteiros*/
    }
    Ordena(A,n,M);
    for(i=0;i<n;i++)
    {
        printf("%lu ", A[i]);/*Exibe os valores ja ordenados*/
    }
    printf("\n");
    return 0;
}

int mdc(int a, int b)/*Usa o método de Euclides, através de recursao, para encontrar o mdc de dois numeros a e b*/
{
    if(b==0)
    {
        return a;
    }

    else
    {
        return mdc(b,a%b);/*Quando a%b (resto da divisao) for zero, o mdc foi encontrado*/
    }
}

void Ordena(unsigned long int conjunto[],int tam,int M)/*Seleciona em quais casos ocorre a troca de indices*/
{
    int i,j;
    for(i=tam-1; i>0; i--)
    {
        for(j=0; j < i; j++)
        {
            if( mdc(conjunto[j],M) < mdc(conjunto[j+1],M) )/*Regra 1*/
            {
                Troca(conjunto,j);
            }

            else if((mdc(conjunto[j],M) == mdc(conjunto[j+1],M)) && (Inverte(conjunto[j]) > Inverte(conjunto[j+1])))/*Regra 2*/
            {
                Troca(conjunto,j);
            }
            else if((Inverte(conjunto[j]) == Inverte(conjunto[j+1])) && (conjunto[j] > conjunto[j+1]))/*Regra 3*/
            {
                Troca(conjunto,j);
            }
        }

    }
}

void Troca(unsigned long int conjunto[], int j)/*Troca a ordem dos indices do conjunto*/
{
    int aux;
    aux = conjunto[j];
    conjunto[j] = conjunto[j+1];
    conjunto[j+1] = aux;
}

int Inverte(int numero)/*Inverte a ordem do nuemero*/
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
