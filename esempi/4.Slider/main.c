#include "../../lib_ita/draw.h"

/*
	<*------>		
	<-*----->		
	<--*---->		
	<---*--->		
	<----*-->
	<-----*->
	<------*>
	
	N.B Per ogni programma si puo' creare un numero infinito di slider
*/

int main(){
	
	int s;
	
	// stampa ed usa uno slider orizzontale alla posizione (5,5), di lunghezza 10, partendo dalla scelta 5
	s = slider_stampa_e_usa(5,5,10,5,ORIZZONTALE);
	
	// pulisci tutto lo schermo
	terminale_pulisci();
	
	// stampa il risultato dello slider
	printf("%d",s);
	
	return 0;
}
