#include "../../lib_ita/draw.h"
#include <math.h>

int main(){
	int n = 5;
	while (true){
		int c = 0;
		cambia_colore(BIANCO);
		vai_a(5, 0);
		printf("Muovi con le freccie e premi invio per confermare");
		n = slider_stampa_e_usa(5,1,20,n,ORIZZONTALE);
		terminale_pulisci();
		for(int y=-20; y<20; y++){
			for (int x=-20; x<20; x++){
				if (pow(x, 2) + pow(y,2) < n*10){
					cambia_colore(c);
					vai_a(x+20, y+15);
					stampa_carattere(CARATTERE_PIENO);
					c = (c+1)%12;
				}
			}
		}
	}



		
}
