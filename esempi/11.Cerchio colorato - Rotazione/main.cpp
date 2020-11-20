#include "../../lib_ita/draw.h"
#include <math.h>

int main(){
	int n = 15;
	casuale_inizializza();
	
	int c[41][41];
	for (int y=0; y<41; y++)
		for (int x=0; x<41; x++)
			c[y][x] = (rand()%6) + 7;
	
	while (true){
		cambia_colore(BIANCO);
		for(int y=-20; y<20; y++){
			for (int x=-20; x<20; x++){
				if (pow(x, 2) + pow(y,2) < n*10){
					cambia_colore(c[y+20][x+15]);
					vai_a(x+20, y+15);
					stampa_carattere(CARATTERE_PIENO);
				}
			}
		}
		
		for (int y=0; y<41; y++)
			for (int x=0; x<41; x++){
				c[y][x] = c[y][(x+1)%41];
			}
	}



		
}
