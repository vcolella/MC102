/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo indicar a linha e coluna de um registro onde uma dada sequencia de caracteres
se encontra. Para tanto, avalia-se na entrada a sequencia de caracteres e o numero de linhas do registro. Assume-se
que o numero de colunas sera sempre 5:Ra, Nome, Curso, Telefone e Estado. Assume-se ainda que cada linha tem no maximo 129
caracteres.*/
#include <stdio.h>


int tamanho(char string[]);/*Retorna o tamanho de uma string, menos o caracter '\0'.*/
int avanca(char linha[], int j);/*Retorna o proximo indice onde linha[j]==',' , de modo
que nao seja exibida mais de uma vez a mesma coluna de uma linha.*/

int main()
{
    int n,i,j;/*n eh o numero de linhas*/
    char string[101],linha[130],lixo[130];/*string guarda a string a ser procurada, linha guarda os caracteres
                                            da linha, e lixo guarda a linha que da nome as colunas (lixo serve apenas
                                            para ler a proxima linha*/

    scanf("%[^\n]", string);/*Le a string ate \n*/
    scanf("%d", &n);
    getchar();
    scanf("%[^\n]", lixo);/*Le o lixo a ser descartado*/
    getchar();

    for(i=0; i<n; i++)/*Repeticao para cada linha*/
    {
        int virgula=0,g=0,flag=0;
        scanf("%[^\n]", linha);/*Le a linha*/
        getchar();

        for(j=0;j<=tamanho(linha);j++)
        {
            if(flag==1)/*Caso a coluna ja tenha sido exibida*/
            {
                j = avanca(linha,j);
                flag = 0;
            }
            if(linha[j]!=string[g])/*Caso um caracter da linha nao corresponda com a string*/
            {
                g = 0;
            }
            if(linha[j]==',')/*Caso o caracter seja ',' , avanca para a proxima coluna*/
            {
                virgula++;
                g = 0;
            }

            else if(linha[j]==string[g] && g<tamanho(string))/*Caso o caracter da linha corresponda a string*/
            {
                g++;
            }
            if(g==tamanho(string))
            {
                switch (virgula)
                {
                case 0:
                    printf("Linha %d, Coluna \"RA\"\n", i+1);/*Caso a string esteja na coluna RA*/
                    g = 0;
                    flag = 1;
                    break;
                case 1:
                    printf("Linha %d, Coluna \"Nome\"\n", i+1);/*Caso a string esteja na coluna Nome*/
                    g = 0;
                    flag = 1;
                    break;
                case 2:
                    printf("Linha %d, Coluna \"Curso\"\n", i+1);/*Caso a string esteja na coluna Curso*/
                    g = 0;
                    flag = 1;
                    break;
                case 3:
                    printf("Linha %d, Coluna \"Telefone\"\n", i+1);/*Caso a string esteja na coluna Telefone*/
                    g = 0;
                    flag = 1;
                    break;
                case 4:
                    printf("Linha %d, Coluna \"Estado\"\n", i+1);/*Caso a string esteja na coluna Estado*/
                    g = 0;
                    flag = 1;
                    break;
                }

            }
        }
    }
    return 0;
}

int tamanho(char string[])/*Retorna o tamanho da string, menos o caracter '\0'*/
{
    int tamanho=0;

    while(string[tamanho]!='\0')
    {
        tamanho++;
    }

    return tamanho;
}

int avanca(char linha[], int j)/*Retorna o indice para o qual linha[j]==','*/
{
    while(linha[j]!=',' && j<=tamanho(linha))
    {
        j++;
    }
    return j;
}
