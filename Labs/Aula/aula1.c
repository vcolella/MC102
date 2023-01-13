#include <stdio.h>

typedef struct ponto{
	float x,y,z;
}Ponto;

typedef struct -poligono{
	Ponto *vertice;
	int n;
}Poligono;

Poligono LePoligono(){
	Poligono P;
	int i;

	scanf("%d", &P.n);
	P.vertice = (Ponto*)calloc(P.n, sizeof(Ponto));
	for(i=0;i<P.n;i++){
		scanf("%f %f %f", &P.vertice[i].x, &P.vertice[i].y, &P.vertice[i].z);
	}
	return P;
}

void EscalaPoligono(Poligono P, float sx, float sy, float sz){
	int i;
	for(i=0;i<P.n;i++){
		P.vertice[i].x *= sx;
		P.vertice[i].y *= sy;
		P.vertice[i].z *= sz;
	}
}

int main(){
	Poligono P;

	P = LePoligono();

	EscalaPoligono(P,2,2,2);

	return 0;
}