#include <stdio.h>

/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo adicionar e remover elementos em conjuntos A e B, exibindo-os em ordem crescente. Alem disso o programa tambem
compara os conjuntos e aponta se sao iguais ou diferentes entre si.*/

/* Considerou-se que o numero maximo de elementos de um conjunto eh 1000*/

void Adicionar(int elemento, char conjunto);/*Adiciona elementos no conjunto*/
void Remover(int elemento, char conjunto);/*Remove elementos do conjunto*/
void BubbleSort(int vet[], int tam);/*Ordena o conjunto em ordem crescente, pelo metodo de BubbleSort*/
void Analise(char operacao, char conjunto, int N);/*Determina quais elementos serao adicionados ou removidos ao conjunto*/
void Imprime(int vetor[]);/*Exibe o conjunto*/
int Igualdade();/*Verifica a igualdade entre dois conjuntos*/
int Frequencia(char conjunto, int elemento);/*Conta a frequencia dos valores de um conjunto*/

int vetA[1000],vetB[1000];/*Variaveis globais, conjunto A, conjunto B*/


int main()
{
    char operacao, conjunto;
    int N,k;
    for(k=0; k<1000; k++)/*Valor inicial de todos os elementos do conjunto igual a -1*/
    {
        vetA[k] = -1;
        vetB[k] = -1;
    }
    scanf(" %c", &operacao);

    while (operacao!='F' && operacao!='f')/*Enquanto o usuario nao encerrar o programa*/
    {
        if(operacao == 'A' || operacao == 'R')/*Se for uma operacao de adicao ou remocao*/
        {
            scanf(" %c %d", &conjunto, &N);
            Analise(operacao, conjunto, N);
        }
        else if(operacao=='p')/*Se for uma operacao de exibicao*/
        {
            scanf(" %c", &conjunto);
            if(conjunto=='A')
            {
                BubbleSort(vetA, 1000);
                Imprime(vetA);
            }
            if(conjunto=='B')
            {
                BubbleSort(vetB, 1000);
                Imprime(vetB);
            }
        }
        else if(operacao=='e')/*Se for uma operacao de verificacao de Igualdade*/
        {
            if(Igualdade()==0)/*Caso Igualdade() retorne 0, os conjuntos sao iguais*/
            {
                printf("Conjuntos sao iguais.\n");
            }
            else/*Do contrario*/
            {
                printf("Conjuntos sao diferentes.\n");
            }
        }

        else/*Caso o comando inserido nao seja reconhecido*/
        {
            printf("Comando invalido. Entre com outro comando, ou 'F' para terminar.\n");
        }
        scanf(" %c", &operacao);
    }
    return 0;
}



void Analise(char operacao, char conjunto, int N)
{
    int i,vetor[N];

    for(i=0; i < N; i++)
    {
        scanf("%d", &vetor[i]);/*Armazena elementos inseridos*/
    }
    if(operacao == 'A')
    {
        for(i=0; i < N; i++)
        {
            if(Frequencia(conjunto, vetor[i]) == 0)/*Caso o elemento nao exista no conjunto (frequencia do valor eh zero), adicione-o*/
            {
                Adicionar(vetor[i],conjunto);
            }
        }
    }
    else if(operacao == 'R')
    {
        for(i=0; i<N; i++)
        {
            if(Frequencia(conjunto, vetor[i]) == 1)/*Caso o elemento exista no conjunto (frequencia do valor eh maior que zero), remova-o*/
            {
                Remover(vetor[i],conjunto);
            }
        }
    }
}

void Adicionar(int elemento, char conjunto)
{
    if(conjunto == 'A')/*Caso seja no conjunto A*/
    {
        int i;
        for(i=0; i<1000; i++)
        {
            if(vetA[i] == -1)/*Procura um indice vazio e atribui o valor do elemento*/
            {
                vetA[i] = elemento;
                i = 1000;/*Encerra o for*/
            }
        }

    }

    else if(conjunto == 'B')
    {
        int i;
        for(i=0;i<1000;i++)
        {
            if(vetB[i] == -1)
            {
                vetB[i] = elemento;
                i = 1000;
            }
        }
    }

}

void Remover(int elemento, char conjunto)
{
    int i;
    if(conjunto == 'A')/*Caso seja conjunto A*/
    {
        for(i=0; i<1000; i++)
        {
            if(vetA[i] == elemento)/*Verifica qual indice do conjunto eh igual ao elemento, e reseta o valor para -1 (tal que o valor nao sera exibido)*/
            {
                vetA[i] = -1;
            }
        }
    }

    else if(conjunto == 'B')
    {
        for(i=0; i<1000; i++)
        {
            if(vetB[i] == elemento)
            {
                vetB[i] = -1;
            }
        }
    }
}

void BubbleSort(int vet[], int tam)
{
    int i,j, aux;
    for(i=tam-1; i>0; i--)
    {
        for(j=0; j < i; j++)
        {
            if( vet[j] > vet[j+1] )
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

void Imprime(int vetor[])/*Imprime o vetor*/
{
    int i;
    for(i=0; i<1000; i++) /*Verifica quais elementos sao diferentes de -1, e os exibe*/
    {
        if(vetor[i] != -1)
        {
            printf("%d ", vetor[i]);
        }

    }
    printf("\n");
}

int Igualdade()/*Compara vetA e vetB. Caso iguais, retorna 0*/
{
    int i,alerta=0;
    BubbleSort(vetA, 1000);
    BubbleSort(vetB, 1000);
    for(i=0; i<1000; i++) /*Compara os elementos ja em ordem de vetA e vet B. Se todos os indices sao iguais, os conjuntos sao iguais e a funcao retorna 0*/
    {
        if(vetA[i] != vetB[i])
        {
            alerta++;
            i = 1000;
        }
    }
    return alerta;
}

int Frequencia(char conjunto, int elemento)
{
    int t,freq=0;

    if(conjunto == 'A')
    {
        for(t=0;t<1000;t++)
        {
            if(vetA[t] == elemento)
            {
                freq = 1;/*O elemento esta no conjunto*/
            }
        }
    }

    if(conjunto == 'B')
    {
        for(t=0;t<1000;t++)
        {
            if(vetB[t] == elemento)
            {
                freq = 1;/*O elemento esta no conjunto*/
            }
        }
    }


    return freq;/*Se o elemento nao esta no conjunto, freq=0*/
}

