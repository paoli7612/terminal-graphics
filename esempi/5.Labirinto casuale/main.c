#include "../../lib/draw.h"

#define WIDTH 10
#define HEIGHT 10

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

void stampa_cella(int,int,int[4]);

int main(){
	casuale_inizializza();
	int mat[WIDTH][HEIGHT][4];
	int x,y,p;
		
	for (y=0; y<HEIGHT; y++){
		for (x=0; x<WIDTH; x++){
			if (y == 0){mat[x][y][UP] = VERO;}
			else{mat[x][y][UP] = mat[x][y-1][DOWN];}
			if (x == 0){mat[x][y][LEFT] = VERO;}
			else{mat[x][y][LEFT] = mat[x-1][y][RIGHT];}
			if (y == HEIGHT-1){mat[x][y][DOWN] = VERO;}
			else{mat[x][y][DOWN] = rand()%2;}
			if (x == WIDTH-1){mat[x][y][RIGHT] = VERO;}
			else{mat[x][y][RIGHT] = rand()%2;}
		}
	}
	
	for (y=0; y<HEIGHT; y++){
		for (x=0; x<WIDTH; x++){
			for (p=0; p<4; p++){
				stampa_cella(x*4,y*4,mat[x][y]);
			}
		}
	}
		
	vai_a(2,HEIGHT*4+10);
	return 0;
}

void stampa_cella(int x, int y, int p[4]){
	stampa_a_posizione(CARATTERE_PIENO,x,y);
	stampa_a_posizione(CARATTERE_PIENO,x+3,y);
	stampa_a_posizione(CARATTERE_PIENO,x,y+3);
	stampa_a_posizione(CARATTERE_PIENO,x+3,y+3);
	if (p[UP]){
		stampa_a_posizione(CARATTERE_PIENO,x+1,y);
		stampa_a_posizione(CARATTERE_PIENO,x+2,y);		
	}
	if (p[DOWN]){
		stampa_a_posizione(CARATTERE_PIENO,x+1,y+3);
		stampa_a_posizione(CARATTERE_PIENO,x+2,y+3);			
	}
	if (p[LEFT]){
		stampa_a_posizione(CARATTERE_PIENO,x,y+1);
		stampa_a_posizione(CARATTERE_PIENO,x,y+2);			
	}
	if (p[RIGHT]){
		stampa_a_posizione(CARATTERE_PIENO,x+3,y+1);
		stampa_a_posizione(CARATTERE_PIENO,x+3,y+2);			
	}
	int i;
	for (i=0; i<4; i++){
		if (p[i] == FALSO) return; 
	}
	stampa_a_posizione(CARATTERE_PIENO,x+1,y+1);
	stampa_a_posizione(CARATTERE_PIENO,x+2,y+1);
	stampa_a_posizione(CARATTERE_PIENO,x+1,y+2);
	stampa_a_posizione(CARATTERE_PIENO,x+2,y+2);
}
