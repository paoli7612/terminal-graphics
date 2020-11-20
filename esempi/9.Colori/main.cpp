#include "../../lib_ita/draw.h"
#include <math.h>

int main(){
	int n = 5;
	while (true){
		n = slider_stampa_e_usa(5,5,10,n,ORIZZONTALE);
		terminale_pulisci();
		for(int y=-20; y<20; y++){
			for (int x=-20; x<20; x++){
				if (pow(x, 2) + pow(y,2) < n*10){
					vai_a(x+20, y+15);
					stampa_carattere(CARATTERE_PIENO);
				}
			}
		}
	}



		
}
