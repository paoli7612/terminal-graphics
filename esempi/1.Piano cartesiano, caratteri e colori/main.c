#include "../../lib/draw.h"

int main(){
	
	// imposta il seme di casualita ( utlizza l'ora attuale di sistema)
	casuale_inizializza();
	
	// imposta la larghezza e altezza del terminale al massimo consentito
	terminale_massimizza();
	
	// inizializza le variabili per ricordarsi la propria posizione sul piano cartesiano
	int x,y;
	
	
	for (y=0; y<65; y++){	// Per tutte le y da 0 a 49
		for (x=0; x<TERMINALE_LARGHEZZA_TOTALE; x++){	// Per tutte le x da 0 alla larghezza massima del terminale
			
			cambia_colore_casuale();		// cambia il colore a caso
			stampa_a_posizione(219,x,y);	// stampa il carattere pieno alla posizione x,y
			
		}
	}
	
	// attendi un invio di conferma
	attendi_invio();
	
	// termina il programma
	return 0;
}s
