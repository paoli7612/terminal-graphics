#include "../../lib_ita/draw.h"

int main(){
	
	// Cambia colore in rosso
	cambia_colore(ROSSO);
	// Disegna linea orizzontale singola da (5,6) a (20,6)
	disegna_linea_orizzontale_singola(5,20,6); 	// oppure -> disegna_linea( 5, 20, 6, ORIZZONTALE, SINGOLO);
	 	 
	// Cambia colore in verde
	cambia_colore(VERDE);
	// Disegna rettangolo doppio con punti di riferimento (0,0) e (10,10)
	disegna_rettangolo_doppio(0,0,10,10);		// oppure -> disegna_rettangolo(0, 0, 10, 10, DOPPIO);
		
	// Cambia colore in giallo
	cambia_colore(GIALLO);
	// Disegna linea verticale doppia da (8,15) a (15,15)
	disegna_linea_verticale_doppia(8,15,15);	// oppure -> disegna_linea( 8, 15, 15, VERTICALE, DOPPIO);
		
	// Cambia colore in viola
	cambia_colore(VIOLA);
	// Disegna rettangolo singolo con punti di riferimento (11,11) e (30,30)
	disegna_rettangolo_singolo(11,11,30,30);	// oppure -> disegna_rettangolo( 11, 11, 30, 30, SINGOLO);
	
	// Attendi l'invio di conferma del utente
	attendi_invio();
	return 0;
}
