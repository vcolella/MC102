/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo simular registros durante o censo, guardando informacoes quanto a UF(estado), cidade, tamanho da populacao, numero de homens,
numero de mulheres, porcentagem de homens, e porcentagem de mulheres. O programa possibilita o cadastro de novos registros, exclusao, listagem, atualizacao
e validacao. Alem disso, esta versao do programa censo usa alocacao dinamica.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Censo/*Variavel do tipo Censo*/
{
    int validez;/*Mostra se um registro esta valido*/
    char estado[3];/*UF*/
    char municipio[100];
    long int populacao;/*Populacao*/
    long int H,M;/*Numero de homens e mulheres*/
    float pH,pM;/*Percentual de homens e mulheres*/
} Censo;

void cadastro(Censo *Registro, int contador);/*Realiza o armazenamento das informacoes*/
void exclusao(Censo *Registro, char estadoE[], char municipioE[], int contador);/*Invalida um registro do censo*/
void listagem(Censo *Registro, char campo, int limite1, int limite2, int contador);/*Exibe valores, de acordo com as especificacoes desejadas*/
void atualizacao(Censo *Registro, char estadoA[], char municipioA[], int contador);/*Altera as informacoes de um registro ja existente*/
void validacao(Censo *Registro, int contador);/*Exibe registros onde as porcentagens sao incompativeis com os numeros populacionais*/
void imprime(Censo *Registro, int contador);/*Exibie um registro*/





int main()
{
    Censo *Registro;/*Inicializa ponteiro dos registros*/
    char operacao;
    int contador = 0;
    float alocado = 10;
    Registro = (Censo *)malloc(alocado*sizeof(Censo));/*Aloca tamanho inicial do registro*/

    scanf(" %c", &operacao);/*Analisa qual a operacao desejada*/

    while(operacao!='f' && operacao!='F')/*Enquanto a entrada nao eh f ou F*/
    {
        if(operacao=='c' || operacao=='C')/*Caso seja uma operacao de cadastro*/
        {
            int n,i;
            scanf("%d", &n);/*Analisa o numero de entradas a serem registradas*/
            while(alocado<(contador+n)){/*Caso espaco alocado seja insuficiente*/
                    alocado *= 2;
                    Registro = (Censo *)realloc(Registro, (alocado)*sizeof(Censo));/*Realoca dados para memoria de novo tamanho (dobro da antiga)*/
            }
            for(i=0; i<n; i++)
            {
                cadastro(Registro,contador);/*Chama funcao cadastro para arquivar informacoes*/
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
                exclusao(Registro,estadoE,municipioE,contador);/*Chama funcao exclusao, com strings a serem comparadas com os registros*/


                if(contador<(alocado/4) && alocado>=20){/*Caso o numero de registros preenchidos seja menor que um quarto do alocado E o numero de posicoes alocadas seja maior ou igual a 20 (para ficar no minimo 10), diminui alocado pela metade*/
                    int x,y=0;
                    alocado /= 2;
                    Censo *copia;/*Cria ponteiro para armazenar registros validos*/
                    copia = (Censo *)malloc(alocado*sizeof(Censo));/*Aloca nova memoria, com metade do tamanho da antiga*/
                    for(x=0;x<contador;x++){
                        if(Registro[x].validez == 1){/*Passa todos os valores a serem salvos para copia*/
                            strcpy(copia[y].estado,Registro[x].estado);
                            strcpy(copia[y].municipio,Registro[x].municipio);
                            copia[y].populacao = Registro[x].populacao;
                            copia[y].H = Registro[x].H;
                            copia[y].M = Registro[x].M;
                            copia[y].pH = Registro[x].pH;
                            copia[y].pM = Registro[x].pM;
                            copia[y].validez = Registro[x].validez;
                            y++;
                        }
                    }
                    contador--;
                    free(Registro);/*Libera antiga alocacao*/
                    Registro = copia;/*Redefini Registro como o ponteiro copia*/
                }
            }
        }

        else if(operacao=='l' || operacao=='L')/*Caso seja uma operacao de listagem*/
        {
            char campo;
            int limite1,limite2;

            scanf(" %c %d %d", &campo,&limite1,&limite2);

            listagem(Registro,campo,limite1,limite2,contador);/*Chama funcao listagem para exibir valores, de acordo com campo e limites estabelecidos*/
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
                atualizacao(Registro,estadoA,municipioA,contador);/*Chama funcao atualizacao*/
            }
        }
        else if(operacao=='v' || operacao=='V')/*Caso seja uma operacao de validacao*/
        {
            validacao(Registro,contador);/*Chama funcao validacao*/
        }
        else
        {
            printf("Comando invalido. Entre com outro comando, ou 'F' para terminar.\n");/*Caso a entrada seja estranha*/
        }
        scanf(" %c", &operacao);
    }
    return 0;
}

void cadastro(Censo *Registro, int contador)/*Analisa os valores inseridos e arquiva-os em registros*/
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

void exclusao(Censo *Registro, char estadoE[], char municipioE[], int contador)/*Compara strings com registros e invalida caso haja coincidencia*/
{
    int i;

    for(i=0; i<contador; i++)
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

void listagem(Censo *Registro, char campo, int limite1, int limite2, int contador)/*Exibie valores de acordo com parametros especificados*/
{
    int i;
    for(i=0; i<contador; i++)
    {
        if(campo=='p' || campo=='P')/*Caso o parametro seja populacao*/
        {
            if(Registro[i].populacao>=limite1 && Registro[i].populacao<=limite2 && Registro[i].validez==1)
            {
                imprime(Registro,i);
            }
        }
        else if(campo=='h' || campo=='H')/*Caso o parametro seja numero de homens*/
        {
            if(Registro[i].H>=limite1 && Registro[i].H<=limite2 && Registro[i].validez==1)
            {
                imprime(Registro,i);
            }
        }
        else if(campo=='m' || campo=='M')/*Caso o parametro seja numero de mulheres*/
        {
            if(Registro[i].M>=limite1 && Registro[i].M<=limite2 && Registro[i].validez==1)
            {
                imprime(Registro,i);
            }
        }
    }
    printf("\n");
}

void atualizacao(Censo *Registro, char estadoA[], char municipioA[], int contador)/*Realiza a atualizacao de registros*/
{
    int i;

    for(i=0; i<contador; i++)
    {
        if(strcmp(Registro[i].estado,estadoA)==0 && strcmp(Registro[i].municipio,municipioA)==0)/*Caso o registro corresponda com UF e Municio inseridos*/
        {
            if(Registro[i].validez == 1)/*Caso o registro esteja valido*/
            {
                getchar();
                cadastro(Registro, i);/*Realiza novamente a operacao de cadastro, alterando todos os campos do registro
                            ou mantendo-os iguais*/
            }
        }
    }
}

void validacao(Censo *Registro, int contador)/*Valida registros*/
{
    int i;
    float a,b,c;

    for(i=0;i<contador;i++)
    {
        if(Registro[i].validez==1)/*Caso o registro esteja valido*/
        {
           c = Registro[i].populacao;/*Transforma os valores em float para comparacao*/
           a = Registro[i].H;
           b = Registro[i].M;

           if(((a/c)*100>Registro[i].pH+0.1)||((a/c)*100<Registro[i].pH-0.1))/*Valida a porcentagem da populacao masculina*/
           {
               imprime(Registro,i);/*Exibe registro com porcentagem invalida*/
           }
           else if(((b/c)*100>Registro[i].pM+0.1)||((b/c)*100<Registro[i].pM-0.1))/*Valida a porcentagem da populacao feminina*/
           {
               imprime(Registro,i);
           }
        }
    }
    printf("\n");
}

void imprime(Censo *Registro, int contador)/*Exibe um registro*/
{
    printf("%s %s %ld %ld %ld %.1f %.1f\n", Registro[contador].estado, Registro[contador].municipio, Registro[contador].populacao, Registro[contador].H, Registro[contador].M, Registro[contador].pH, Registro[contador].pM);
}
