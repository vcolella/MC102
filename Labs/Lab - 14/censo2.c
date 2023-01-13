/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo simular registros durante o censo, guardando informacoes quanto a UF(estado), cidade, tamanho da populacao, numero de homens,
numero de mulheres, porcentagem de homens, e porcentagem de mulheres. O programa possibilita o cadastro de novos registros, exclusao, listagem, atualizacao
e validacao.*/
#include <stdio.h>
#include <string.h>

void cadastro(int contador);/*Realiza o armazenamento das informacoes*/
void exclusao(char estadoE[], char municipioE[]);/*Invalida um registro do censo*/
void listagem(char campo, int limite1, int limite2);/*Exibe valores, de acordo com as especificacoes desejadas*/
void atualizacao(char estadoA[], char municipioA[]);/*Altera as informacoes de um registro ja existente*/
void validacao();/*Exibe registros onde as porcentagens sao incompativeis com os numeros populacionais*/
void imprime(int contador);/*Exibie um registro*/


typedef struct Censo/*Variavel do tipo Censo*/
{
    int validez;/*Mostra se um registro esta valido*/
    char estado[3];/*UF*/
    char municipio[100];
    long int populacao;/*Populacao*/
    long int H,M;/*Numero de homens e mulheres*/
    float pH,pM;/*Percentual de homens e mulheres*/
} Censo;

Censo Registro[1000];/*Vetor Registro do tipo Censo, para guardar cada entrada*/

int main()
{
    char operacao;
    int contador = 0;

    scanf(" %c", &operacao);/*Analisa qual a operacao desejada*/

    while(operacao!='f' && operacao!='F')/*Enquanto a entrada nao eh f ou F*/
    {
        if(operacao=='c' || operacao=='C')/*Caso seja uma operacao de cadastro*/
        {
            int n,i;
            scanf("%d", &n);/*Analisa o numero de entradas a serem registradas*/

            for(i=0; i<n; i++)
            {
                cadastro(contador);/*Chama funcao cadastro para arquivar informacoes*/
                contador++;/*Aumenta variavel contador*/
            }
        }
        else if(operacao=='e' || operacao=='E')/*Caso seja uma operacao de exclusao*/
        {
            int n,i;
            char estadoE[3], municipioE[100];/*Strings a serem comparadas com os registros existentes*/

            scanf("%d", &n);/*Numero de entradas a serem lidas*/

            for(i=0; i<n; i++)
            {
                scanf("%s %s", estadoE, municipioE);
                exclusao(estadoE, municipioE);/*Chama funcao exclusao, com strings a serem comparadas com os registros*/

                if(strcmp(estadoE,Registro[contador].estado)==0 && strcmp(municipioE,Registro[contador].municipio)==0)/*Caso o registro a ser invalidado coincide com o ultimo, diminui o contador, demodo a tornar reutilizavel a variavel Registro[contador]*/
                {
                    contador--;
                }
            }
        }
        else if(operacao=='l' || operacao=='L')/*Caso seja uma operacao de listagem*/
        {
            char campo;
            int limite1,limite2;

            scanf(" %c %d %d", &campo,&limite1,&limite2);

            listagem(campo,limite1,limite2);/*Chama funcao listagem para exibir valores, de acordo com campo e limites estabelecidos*/
        }
        else if(operacao=='a' || operacao=='A')/*Caso seja uma operacao de atualizacao*/
        {
            int i,n;

            scanf("%d", &n);
            for(i=0;i<n;i++)
            {
                getchar();
                char estadoA[3],municipioA[100];
                scanf("%s %s", estadoA,municipioA);/*Le quais os dados a serem procurados*/
                atualizacao(estadoA,municipioA);/*Chama funcao atualizacao*/
            }

        }
        else if(operacao=='v' || operacao=='V')/*Caso seja uma operacao de validacao*/
        {
            validacao();/*Chama funcao validacao*/
        }
        else
        {
            printf("Comando invalido. Entre com outro comando, ou 'F' para terminar.\n");/*Caso a entrada seja estranha*/
        }
        scanf(" %c", &operacao);
    }
    return 0;
}

void cadastro(int contador)/*Analisa os valores inseridos e arquiva-os em registros*/
{
    scanf(" %s", Registro[contador].estado);
    scanf(" %s", Registro[contador].municipio);
    scanf("%ld", &Registro[contador].populacao);
    scanf("%ld", &Registro[contador].H);
    scanf("%ld", &Registro[contador].M);
    scanf("%f", &Registro[contador].pH);
    scanf("%f", &Registro[contador].pM);
    Registro[contador].validez = 1;/*Valida o registro*/
}

void exclusao(char estadoE[], char municipioE[])/*Compara strings com registros e invalida caso haja coincidencia*/
{
    int i;

    for(i=0; i<1000; i++)
    {
        if(strcmp(Registro[i].estado,estadoE)==0 && strcmp(Registro[i].municipio,municipioE)==0)
        {
            if(Registro[i].validez == 1)
            {
                Registro[i].validez = 0;/*Invalida o registro*/
            }
        }
    }
}

void listagem(char campo, int limite1, int limite2)/*Exibie valores de acordo com parametros especificados*/
{
    int i;
    for(i=0; i<1000; i++)
    {
        if(campo=='p' || campo=='P')/*Caso o parametro seja populacao*/
        {
            if(Registro[i].populacao>=limite1 && Registro[i].populacao<=limite2 && Registro[i].validez==1)
            {
                imprime(i);
            }
        }
        else if(campo=='h' || campo=='H')/*Caso o parametro seja numero de homens*/
        {
            if(Registro[i].H>=limite1 && Registro[i].H<=limite2 && Registro[i].validez==1)
            {
                imprime(i);
            }
        }
        else if(campo=='m' || campo=='M')/*Caso o parametro seja numero de mulheres*/
        {
            if(Registro[i].M>=limite1 && Registro[i].M<=limite2 && Registro[i].validez==1)
            {
                imprime(i);
            }
        }
    }
    printf("\n");
}

void atualizacao(char estadoA[], char municipioA[])/*Realiza a atualizacao de registros*/
{
    int i;

    for(i=0; i<1000; i++)
    {
        if(strcmp(Registro[i].estado,estadoA)==0 && strcmp(Registro[i].municipio,municipioA)==0)/*Caso o registro corresponda com UF e Municio inseridos*/
        {
            if(Registro[i].validez == 1)/*Caso o registro esteja valido*/
            {
                getchar();
                cadastro(i);/*Realiza novamente a operacao de cadastro, alterando todos os campos do registro
                            ou mantendo-os iguais*/
            }
        }
    }
}

void validacao()/*Valida registros*/
{
    int i;
    float a,b,c;

    for(i=0;i<1000;i++)
    {
        if(Registro[i].validez==1)/*Caso o registro esteja valido*/
        {
           c = Registro[i].populacao;/*Transforma os valores em float para comparacao*/
           a = Registro[i].H;
           b = Registro[i].M;

           if(((a/c)*100>Registro[i].pH+0.1)||((a/c)*100<Registro[i].pH-0.1))/*Valida a porcentagem da populacao masculina*/
           {
               imprime(i);/*Exibe registro com porcentagem invalida*/
           }
           else if(((b/c)*100>Registro[i].pM+0.1)||((b/c)*100<Registro[i].pM-0.1))/*Valida a porcentagem da populacao feminina*/
           {
               imprime(i);
           }
        }
    }
    printf("\n");
}

void imprime(int contador)/*Exibe um registro*/
{
    printf("%s %s %ld %ld %ld %.1f %.1f\n", Registro[contador].estado, Registro[contador].municipio, Registro[contador].populacao, Registro[contador].H, Registro[contador].M, Registro[contador].pH, Registro[contador].pM);
}
