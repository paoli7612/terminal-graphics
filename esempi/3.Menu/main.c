#include "../../lib/draw.h"

/*______________________________________________________________________________________________________________________
|	Un menu viene salvato come una matrice "alta" quanto il numero di voci												|
|	e "larga" quanto la lunghezza massima delle voci. Cio che ci interessa												|
|	e' unicamente il fatto che ogni voce ha un numero (a partire dal 1) e 												|
|	che durante la scelta del'utente noi otteniamo quel numero, e non il 												|
|	testo della voce.																									|
|																														|
|	La funzione "usa" ci permettere di ottenere il risultato in due modi;												|
|	a seconda di come siamo piu'comodi possiamo:																		|
|																														|
|	A) farci restituire il valore direttamente dalla funzione 				-> 	int s = menu_usa(x);					|
|																														|
|	B) lanciando la funzione come se fosse di tipo "void" e prenderci il												|
|	valore della scelta dalla variabile (gia creata) chiamata "menu_scelto	-> menu_usa(x);		int s = menu_scelto;	|
|																														|
|	N.B. Puo essere creato un solo menu per programma, (le voci aggiunte rimangono) ma si puo ristampare a piacere		|
|______________________________________________________________________________________________________________________*/ 

int main(){
	// imposta la distanza tra le voci del menu
	menu_imposta_distanza(2);
	
	// aggiunge le voci al menu (un massimo di 10 voci larghe 256)
	menu_aggiungi_voce("SINGLEPLAYER");
	menu_aggiungi_voce("MULTYPLAYER");
	menu_aggiungi_voce("OPTIONS");
	menu_aggiungi_voce("EXIT");
	
	// stampa il menu sullo schermo
	menu_stampa_a_posizione(5,5);	
	
	// attendi che l'utente abbia scelto la voce
	menu_usa(1);	// 1 -> la voce a cui far partire l'utente
	
	// pulisci tutto lo schermo
	terminale_pulisci();
	
	// stampa il numero della voce che l'utente ha scelto
	printf("%d",menu_scelto);	
	
	return 0;
}
