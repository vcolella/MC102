#include <stdio.h>

/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo adicionar e remover elementos em conjuntos A e B, exibindo-os em ordem crescente. Alem disso o programa tambem
compara os conjuntos e aponta se sao iguais ou diferentes entre si, podendo ainda verificar se um elemento existe em um dos conjuntos,
mostrar a Intersecao entre os conjuntos, a diferenca entre os conjuntos, a uniao dos conjunto, e indicar se um conjunto eh subconjunto do outro.*/

/* Considerou-se que o numero maximo de elementos de um conjunto eh 1000*/

void Adiciona(int elemento, char conjunto);/*Adiciona elementos no conjunto*/
void Remove(int elemento, char conjunto);/*Remove elementos do conjunto*/
void BubbleSort(int vet[], int tam);/*Ordena o conjunto em ordem crescente, pelo metodo de BubbleSort*/
void Analise(char operacao, char conjunto, int N);/*Determina quais elementos serao adicionados ou removidos ao conjunto*/
void Imprime(int vetor[]);/*Exibe o conjunto*/
int Igualdade();/*Verifica a igualdade entre dois conjuntos*/
int Frequencia(char conjunto, int elemento);/*Conta a frequencia dos valores de um conjunto*/
void Pertence(int elemento, char conjunto);/*Verifica se um elemento pertence a um conjunto*/
void Subconjunto(char conjunto1, char conjunto2);/*Verifica se o conjunto1 eh subconjunto de conjunto2*/
void Intersecao();/*Exibe os elementos comuns entre o conjunto A e B*/
void Uniao();/*Exibe os elementos do conjunto A e do conjunto B, sem repeti-los*/
void Diferenca(char conjunto1);/*Exibe os conjuntos de A nao presentes em B, e vice-versa*/

int vetA[1000],vetB[1000],vetU[2000],vetD[1000];/*Variaveis globais, conjunto A, conjunto B, conjunto Uniao, conjunto Diferenca*/


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
        else if(operacao=='P')/*Se for uma operacao de Pertencer*/
        {
            int elemento;
            scanf("%d %c", &elemento, &conjunto);
            Pertence(elemento, conjunto);
        }
        else if(operacao=='S')/*Se for uma operacao de Subconjunto*/
        {
            char conjunto2;
            scanf(" %c %c", &conjunto, &conjunto2);
            Subconjunto(conjunto, conjunto2);
        }
        else if(operacao=='I')/*Se for uma operacao de Intersecao*/
        {
            Intersecao();
        }
        else if(operacao=='U')/*Se for uma operacao de Uniao*/
        {
            Uniao();
        }
        else if(operacao=='D')/*Se for uma operacao de Diferenca*/
        {
            char conjunto2;
            scanf(" %c %c", &conjunto, &conjunto2);/*conjunto2 serve apenas para ler a segunda letra, mas ele nao eh usado, supondo que
            a segunda letra eh sempre diferente da primeira*/
            Diferenca(conjunto);
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
                Adiciona(vetor[i],conjunto);
            }
        }
    }
    else if(operacao == 'R')
    {
        for(i=0; i<N; i++)
        {
            if(Frequencia(conjunto, vetor[i]) == 1)/*Caso o elemento exista no conjunto (frequencia do valor eh maior que zero), remova-o*/
            {
                Remove(vetor[i],conjunto);
            }
        }
    }
}

void Adiciona(int elemento, char conjunto)
{
    if(conjunto == 'A')/*Caso seja no conjunto A*/
    {
        int i;
        for(i=0; i<1000; i++)
        {
            if(vetA[i] == -1)/*Procura um indice vazio e atribui o valor do elemento*/
            {
                vetA[i] = elemento;
                break;/*Encerra o for*/
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
                break;
            }
        }
    }

    else if(conjunto == 'U')
    {
        int i;
        for(i=0;i<2000;i++)
        {
            if(vetU[i] == -1)
            {
                vetU[i] = elemento;
                break;
            }
        }
    }

}

void Remove(int elemento, char conjunto)
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

    else if(conjunto == 'D')
    {
        for(i=0; i<1000; i++)
        {
            if(vetD[i] == elemento)
            {
                vetD[i] = -1;
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
    BubbleSort(vetor,1000);
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
            break;
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

    else if(conjunto == 'B')
    {
        for(t=0;t<1000;t++)
        {
            if(vetB[t] == elemento)
            {
                freq = 1;/*O elemento esta no conjunto*/
            }
        }
    }
    else if(conjunto == 'U')
    {
        for(t=0;t<2000;t++)
        {
            if(vetU[t] == elemento)
            {
                freq = 1;/*O elemento esta no conjunto*/
            }
        }
    }
    return freq;/*Se o elemento nao esta no conjunto, freq=0*/
}

void Pertence(int elemento, char conjunto)
{
    if(Frequencia(conjunto, elemento) == 1)/*Caso o elemento seja encontrado no conjunto, Frequencia() retorna 1*/
    {
        printf("Elemento %d pertence ao conjunto.\n", elemento);
    }
    else if(Frequencia(conjunto, elemento)==0)/*Do contrario, Frequencia() retorna 0*/
    {
        printf("Elemento %d nao pertence ao conjunto.\n", elemento);
    }
}

void Subconjunto(char conjunto1, char conjunto2)
{
    int i,x = 1;
    if(conjunto1=='A')
    {
        for(i=0;i<1000;i++)
        {
            if(Frequencia(conjunto2,vetA[i])==0)
            {
                printf("Conjunto nao eh subconjunto.\n");
                x = 0;/*Impede a funcao de printar a outra mensagem*/
                break;/*Sai do loop*/
            }
        }
        if(x==1)
        {
            printf("Conjunto eh subconjunto.\n");
        }
    }
    else if(conjunto1=='B')
    {
        for(i=0;i<1000;i++)
        {
            if(Frequencia(conjunto2,vetB[i])==0)
            {
                printf("Conjunto nao eh subconjunto.\n");
                x = 0;/*Impede a funcao de printar a outra mensagem*/
                break;/*Sai do loop*/
            }
        }
        if(x==1)
        {
            printf("Conjunto eh subconjunto.\n");
        }
    }
}


void Intersecao()
{
    int i,vetInt[1000];
    char A='A',B='B';
    for(i=0;i<1000;i++)
    {
        vetInt[i] = -1;
    }
    for(i=0;i<1000;i++)
    {
        if((Frequencia(A,vetA[i]) == Frequencia(B,vetA[i])) && (Frequencia(A,vetA[i])==1))/*Se vetA[i] também está em vetB, e a Frequencia de vetA[i] em A é 1*/
        {
            vetInt[i] = vetA[i];
        }
    }
    Imprime(vetInt);
}

void Uniao()
{
    int i;
    char conjunto = 'U';
    for(i=0;i<2000;i++)
    {
        vetU[i]= -1;
    }
    for(i=0; i < 1000; i++)
    {
        if(Frequencia(conjunto, vetA[i]) == 0)/*Caso o elemento nao exista no conjunto (frequencia do valor eh zero), adicione-o*/
        {
                Adiciona(vetA[i],conjunto);
        }
        if(Frequencia(conjunto, vetB[i]) == 0)/*Caso o elemento nao exista no conjunto (frequencia do valor eh zero), adicione-o*/
        {
                Adiciona(vetB[i],conjunto);
        }

    }
    BubbleSort(vetU,2000);
    for(i=0; i<2000; i++) /*Verifica quais elementos sao diferentes de -1, e exibe-os. Nao eh possivel usar a minha funcao Imprime porque
    o vetor vetU eh maior que 1000*/
    {
        if(vetU[i] != -1)
        {
            printf("%d ", vetU[i]);
        }

    }
    printf("\n");
}

void Diferenca(char conjunto1)
{
    int i;
    char conjunto = 'D';/*Conjunto Diferenca*/
    if(conjunto1=='A')/*Caso a primeira letra seja A*/
    {
        for(i=0;i<1000;i++)
        {
            vetD[i]=vetA[i];/*Copia todos os elementos do conjunto A para o conjunto Diferenca*/
        }
        for(i=0;i<1000;i++)
        {
            Remove(vetB[i],conjunto);/*Remove os elementos do conjunto B do conjunto Diferenca*/
        }
        Imprime(vetD);
    }
    else if(conjunto1=='B')/*Caso a primeira letra seja B*/
    {
        for(i=0;i<1000;i++)
        {
            vetD[i]=vetB[i];/*Copia todos os elementos do conjunto B para o conjunto Diferenca*/
        }
        for(i=0;i<1000;i++)
        {
            Remove(vetA[i],conjunto);/*Remove os elementos do conjunto A do conjunto Diferenca*/
        }
        Imprime(vetD);/*Exibe o conjunto Diferenca*/
    }
}
