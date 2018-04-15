#include "../../lib/draw.h"

#define WIDTH 40
#define HEIGHT 15

// costanti per segnare le direzioni della casella
// rappresentano le posizioni del array tridimensionale (quello da 4)
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// dichiara l'esistenza della funzione per stampare ogni cella
// richiedera la x, la y e il sotto array da 4 posizioni
void stampa_cella(int,int,int[4]);

int main(){
	// ingrandisci il terminale
	terminale_massimizza_fullscreen();
	// transla il piano cartesiano in basso di 5 e a destra di 3
	sposta_vai_a(3,5);
	// imposta il seme di casualita per non ottenere sempre gli stessi risultati
	casuale_inizializza();
	// dichiara la matrice (larghezza, altezza, 4(UP,DOWN,LEFT,RIGHT))
	int mat[WIDTH][HEIGHT][4];
	// dichiara le variabili che che rappresenteranno i contatori sui tre livelli dell array tridimensionale
	int x,y,p;
	// scorre l'intera matrice
	for (y=0; y<HEIGHT; y++){
		for (x=0; x<WIDTH; x++){
			// se siamo sulla prima colonna
			if (y == 0){mat[x][y][UP] = VERO;}
			else{mat[x][y][UP] = mat[x][y-1][DOWN];}
			// se siamo sulla prima riga
			if (x == 0){mat[x][y][LEFT] = VERO;}
			else{mat[x][y][LEFT] = mat[x-1][y][RIGHT];}
			// se siamo sull'ultima colonna
			if (y == HEIGHT-1){mat[x][y][DOWN] = VERO;}
			else{mat[x][y][DOWN] = rand()%2;}
			// se siamo sul ultima riga
			if (x == WIDTH-1){mat[x][y][RIGHT] = VERO;}
			else{mat[x][y][RIGHT] = rand()%2;}
		}
	}
	// scorre la matrice per stamparla
	for (y=0; y<HEIGHT; y++){
		for (x=0; x<WIDTH; x++){
			for (p=0; p<4; p++){
				stampa_cella(x*4,y*4,mat[x][y]);
			}
		}
	}
	// si allontana dal disegno (in caso venga stampato il messaggio finale del devc++)
	vai_a(2,HEIGHT*4+10);
	// attende che l'utente prema invio (per non far chiudere subito il prompt)
	attendi_invio();

	return 0;
}

void stampa_cella(int x, int y, int p[4]){
	/*___________________________
		   0--0
		   |  |	
		   0--0
		
	0: angoli
	-- UP / DOWN
	| RIGHT / LEFT
	_____________________________*/	
	// stampa gli angoli
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
