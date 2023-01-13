/*
Victor C. G. C. Pereira
R.A.:157462
 
Este programa tem por objetivo simular o trajeto de um submarino, indicando se havera ou nao colisao com o fundo do mar,
a partir de pontos de referencia fornecidos na entrada.*/

#include <stdio.h>

typedef struct Ponto{/*Estrutura dos pontos*/
	float x, y;
}Ponto;

typedef struct Submarino{/*Estrutura do submarino*/
	int W,H,passo;
	Ponto pos;
	Ponto intersec;
}Submarino;

float determinante(Submarino *submarino, Ponto *pontos, int i);/*Calcula o determinante*/
void posicaoSub(char comando, Submarino *submarino);/*Atualiza a posicao do submarino, bem como o passo atual*/
int Intersec(int L, Ponto *pontos, Submarino *submarino, Ponto *V);/*Calcula se ocorre colisao em cada comando, e caso haja, armazena o ponto de colisao em V*/

int main(){

	FILE *arq1;

	char nomeArq[100];
	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArq);
	arq1 = fopen(nomeArq, "r");


	int L,i;
	char comando;
	Submarino submarino;

	fscanf(arq1,"%d %d %d", &L, &submarino.W, &submarino.H);/*Le as dimensoes do submarino e o numero de pontos a serem fornecidos*/

    submarino.pos.x = submarino.W;/*Posicao inicial do submarino*/
    submarino.pos.y = -submarino.H;
    submarino.passo = 0;

	Ponto pontos[L+1];/*Declaracao de todos os pontos*/
	Ponto V;

	pontos[0].x = 0;
	pontos[0].y = -3 * submarino.H;
	for(i=1;i<=L;i++){
		fscanf(arq1,"%f %f", &pontos[i].x, &pontos[i].y);/*Le os pontos fornecidos*/
	}

	for(i=0;i<15;i++){

		fscanf(arq1," %c", &comando);/*Le um comando*/

		posicaoSub(comando, &submarino);/*Atualiza a posicao do submarino*/

		if(Intersec(L, pontos, &submarino, &V) == 1){/*Caso haja colisao*/
                printf("Colidiu em (%.2f,%.2f) no passo %d.\n", V.x, V.y, submarino.passo);
                return 0;
        }

        else if(submarino.passo == 15){/*Caso nao haja colisao*/
                printf("Alcancou a posicao (%.2f,%.2f).\n", submarino.pos.x, submarino.pos.y);
                return 0;
        }
	}
}

int Intersec(int L, Ponto pontos[], Submarino *submarino,Ponto *V){

    int i=0, flag;
    float det,T1,T2;

    for(i=1;i<L+1;i++){/*Analisa se interseciona com algum segmento do mapeamento*/

    	flag = 1;

	    det = determinante(submarino, pontos, i);

	    if(det == 0){/*Nao ocorre colisao*/
	        flag = 0;
	    }

	    

	    T1 = (((pontos[i].x - pontos[i-1].x)*(pontos[i-1].y - (*submarino).pos.y)) - ((pontos[i-1].x - ((*submarino).pos.x - (*submarino).W))*(pontos[i].y - pontos[i-1].y)))/det;

	    T2 = (((*submarino).W)*(pontos[i-1].y-(*submarino).pos.y))/det;

	    if((T1>0 && T1<1)&&(T2>0 && T2<1)&&flag==1){/*Caso ocorra colisao, identifica o ponto V*/
	        (*V).x = ((*submarino).pos.x - (*submarino).W) + T1*((*submarino).W);
	        (*V).y = (*submarino).pos.y;
	        return 1;
	    }
    }
    return 0;
}


float determinante(Submarino *submarino, Ponto pontos[], int i){/*Calcula determinante*/
	float det;

	det = -(((*submarino).W)*((pontos[i].y) - (pontos[i-1].y)));

	return det;
}

void posicaoSub(char comando, Submarino *submarino){/*Atualiza posicao e passo atual do submarino*/

    switch(comando){

        case 'd':
            (*submarino).pos.x++;
            break;

        case 'e':
            (*submarino).pos.x--;
            break;

        case 'b':
            (*submarino).pos.y--;
            break;

        case 'c':
            (*submarino).pos.y++;
            break;
    }
    (*submarino).passo++;
}
