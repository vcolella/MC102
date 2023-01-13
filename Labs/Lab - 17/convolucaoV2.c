/*
Victor C. G. C. Pereira
R.A.:157462

Este programa tem por objetivo aplicar "filtros" a imagens, usando o metodo de convolucao. Para tanto, o programa le uma imagem do tipo .pgm P2,
le uma matriz e um divisor, e assim cria uma nova imagem com pixels baseados na original.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Imagem{
	char tipo[3];/*Armazena tipo de .pgm, neste laboratorio sera sempre P2*/
	int x,y;/*Numero de colunas, numero de linhas*/
	int max;/*Valor maximo para cada pixel, neste laboratorio sera sempre 255*/
	int pixel[600][600];/*Informacao dada:imagem nunca tera mais de 240000 pixels*/
}Imagem;

typedef struct Matriz{
	int D;/*Divisor*/
	int valor[9];/*Valores da matriz, de a ate i*/
}Matriz;

Imagem *LeImagem(char *arquivo);/*Le o arquivo da imagem original, e retorna ponterio do tipo Imagem*/
Matriz LeMatriz(char *arquivo);/*Le o arquivo da matriz, e retorna uma matriz*/
Imagem *Convolucao(Imagem *img, Matriz mtz);/*Realiza o processo de convolucao e retorna ponteiro do tipo Imagem*/
void ExibeImagem(Imagem *novaimg);/*Exibe a imagem*/

int main(int argc, char *argv[]){

	Imagem *img;
	img = LeImagem(argv[1]);/*Recebe ponteiro para imagem lida do arquivo1.txt */

	
	Matriz mtz = LeMatriz(argv[2]);/*Recebe matriz lida no arquivo2.txt*/

	Imagem *novaimg;

	novaimg = Convolucao(img, mtz); /*Recebe ponteiro para nova imagem*/

	ExibeImagem(novaimg);/*Exibe a nova imagem*/

	return 0;
}

Imagem *LeImagem(char *arquivo){

	Imagem *img;

	img = (Imagem *)malloc(1*sizeof(Imagem));/*Aloca memoria para uma imagem de tamanho maximo 240000 px*/

	FILE *arq1 = fopen(arquivo,"r");/*Abre arquivo 1 para leitura da imagem*/

	fscanf(arq1,"%s %d %d %d", (*img).tipo, &(*img).x, &(*img).y, &(*img).max);/*Le cabecalho*/

	int y=0,x=0;
	while(y<(*img).y){
		if(x == (*img).x){
			x = 0;
			y++;
		}

		fscanf(arq1,"%d",&(*img).pixel[x][y]);/*Le valor do pixel*/
		x++;
	}
	fclose(arq1);/*Fecha arquivo 1*/
	return img;/*Retorna ponteiro da imagem lida*/
}

Matriz LeMatriz(char *arquivo){
	
	Matriz mtz;

	FILE *arq2 = fopen(arquivo,"r");/*Abre arquivo 2 para leitura da matriz*/

	fscanf(arq2,"%d", &mtz.D);/*Le o divisor*/
	int i;
	for(i=0;i<9;i++){
		fscanf(arq2,"%d",&mtz.valor[i]);/*Le valores da matriz*/
	}
	fclose(arq2);/*Fecha arquivo 2*/
	return mtz;/*Retorna a matriz lida (com divisor) */
}

Imagem *Convolucao(Imagem *img, Matriz mtz){
	
	Imagem *novaimg;
	
	novaimg = (Imagem *)malloc(1*sizeof(Imagem));/*Aloca memoria para nova imagem*/
	
	*novaimg = *img;/*Copia dados da imagem original para nova imagem*/
	
	int x,y;

	for(y=1;y<(*img).y-1;y++)
		for(x=1;x<(*img).x-1;x++){
			(*novaimg).pixel[x][y] = (mtz.valor[0]*(*img).pixel[x-1][y-1] + mtz.valor[1]*(*img).pixel[x][y-1] + mtz.valor[2]*(*img).pixel[x+1][y-1] + mtz.valor[3]*(*img).pixel[x-1][y] + mtz.valor[4]*(*img).pixel[x][y] + mtz.valor[5]*(*img).pixel[x+1][y] + mtz.valor[6]*(*img).pixel[x-1][y+1] + mtz.valor[7]*(*img).pixel[x][y+1] + mtz.valor[8]*(*img).pixel[x+1][y+1])/mtz.D;/*Resultado da convolucao*/
			
			if((*novaimg).pixel[x][y] < 0)/*Caso o valor seja negativo*/
				(*novaimg).pixel[x][y] = 0;
			else if((*novaimg).pixel[x][y] > 255)/*Caso valor ultrapasse o maximo (no caso, 255)*/
				(*novaimg).pixel[x][y] = 255;
		}
	return novaimg;/*Retorna ponteiro para nova imagem*/
}

void ExibeImagem(Imagem *novaimg){
	int x,y;

	FILE *fp = fopen("teste.pgm","w+");/*Cria arquivo tipo .pgm para gravar dados para posterior comparacao*/
	fprintf(fp,"%s\n%d %d\n%d\n", (*novaimg).tipo, (*novaimg).x, (*novaimg).y, (*novaimg).max);
	for(y=0;y<(*novaimg).y;y++){
		for(x=0;x<(*novaimg).x;x++)
			fprintf(fp,"%4d",(*novaimg).pixel[x][y]);
	fprintf(fp,"\n");
	}
	fclose(fp);
}


