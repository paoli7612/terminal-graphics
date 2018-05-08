#include "../../lib_ita/draw.h"

/*______________________________________________________________________________________________________________________
|	Esempio di un semplice carattere che si muove a seconda delle frecce che 											|
|	premiamo da tastiera																								|
|______________________________________________________________________________________________________________________*/ 


int main(){
	// definisce le variabili che conterranno la posizione x e y del nostro "sprite"
	int x = 10, y=10;
	// definisce il carattere che assumera il nostro "sprite" (il suo aspetto"
	char c = '+';
	// definisce la variabile che permettera' al ciclo while di ripetersi o meno a seconda del valore che contiene
	int ciclo = VERO;
	
	// stampa a monitor le istruzioni
	vai_a(1,1); printf("Utilizzare %c%c%c%c per muoversi",FRECCIA_SU, FRECCIA_GIU, FRECCIA_SINISTRA, FRECCIA_DESTRA);
	vai_a(1,2); printf("Premere ESC per uscire");
	
	
	// comincio un ciclo che terminera solo quando la variabile "ciclo" diventera' 0/falsa
	while (ciclo){ 
		// stampa lo sprite alla sua posizione attuale
		stampa_a_posizione(c,x,y);
		// attene che l'utente preme un tasto
		attendi_tasto();
		// cancello lo sprite alla sua posizione attuale
		stampa_a_posizione(SPAZIO,x,y);
		// controllo che tasto e' stato premuto
		switch(tasto_premuto){
			case K_SU:{y--;break;}		// se e' stata premuta la freccia in su: decrementa la coordinata y
			case K_GIU:{y++;break;}		// se e' stata premuta la freccia in giu: incrementa la coordinata y
			case K_SINISTRA:{x--;break;}// se e' stata premuta la freccia a sinistra: decrementa la coordinata x
			case K_DESTRA:{x++;break;} 	// se e' stata premuta la freccia a destra: incrementa la coordinata x
			case K_ESC:{ciclo=FALSO; break;}	// se è stato premuto il tasto ESCAPE della tastiera: porta "ciclo" a FALSO 
		}										// ...di conseguenza il ciclo viene interrotto		
	}	
}

/* N.B
 lo "sprite" viene cancellto alla sua posizione prima di essere mosso in modo che sul terminale non rimangano le sue "impronte"
 e che quindi il suo aspetto non venga stampato piu' di una volta.
 Nel caso che pero' il tasto premuto non sia una delle frecce, il carattere viene stampato per nulla, questa soluzione e'
 stata utilizzata semplicemente per non complicare il programma, avendo il bisogno di salvarsi le coordinate precedenti.
 */
