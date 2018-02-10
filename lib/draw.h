// ____________________________________________________
// |##################################################|
// |####################   DRAW   ####################|
// |##################################################|

#include "slider.h"

//_______________BASE_________________________
//cambia il colore di cio che verra stampato da quel punto in poi
void cambia_colore(int);

//sposta il cursore di scrittura alle coordinate date
void vai_a(int,int);

//modifica in maniera permanente i valori che riceve il "vai_a"
//...(transla cio che verra stampato a monitor da quel momento in poi)
void sposta_vai_a(int,int);

//stampa il carattere dato / il valore ASCII del numero dato
void stampa_carattere(int);

//sposta il cursore di scrittura e stampa il carattere
void stampa_a_posizione(int,int,int);

//blocca il programma finche non viene premuto un tasto
//...il tasto premuto viene salvato in "tasto_premuto"
char attendi_tasto();

//blocca il programma finche non viene premuto invio
void attendi_invio();

//blocca il programma per TOT secondi
void attendi_secondi(int);

//inizializza la casualita impostando il seme di casualita
//... utilizzando l'ora di sistema
void casuale_inizializza();

//cambia il colore prendendone uno casualmente
//... per evitare la monotonia e' necessario
//... lanciare casuale_inizializza
void cambia_colore_casuale();
//____________________________________________


//___________________TERMINAL_________________
//cancella tutte le scritte dal terminale
void terminale_pulisci();

//chiude il terminale
void terminale_chiudi();

//reimposta la grandezza e la posizione del terminale
//...i valori vengono calcolati in pixel
void terminale_grandezza();

//massimizza la grandeszza de terminale al massimo consentito
void terminale_massimizza();

//massimizza la grandezza oltre al massimo consentito
void terminale_massimizza_fullscreen();
//____________________________________________


//___________________GEOMETRY_________________
// rettangoli					linee
//     (x1,y1)______(x2,y1)   (x,y1)  
//       |             |		|
//       | 		       |		|		(x1,y)_______(x2,y)
//       |			   |		|
//       |			   |		|
//     (x1,y2)______(x2,y2)   (x,y2) 

// la differenza tra singolo e doppio e' dovuta al tipo
//...di caratteri del codice ASCII utilizzati

void disegna_linea_verticale_doppia(int,int,int);		
void disegna_linea_orizzontale_doppia(int,int,int);		
void disegna_linea_verticale_singola(int,int,int);		
void disegna_linea_orizzontale_singola(int,int,int);	
void disegna_linea(int,int,int,int,int);						
void disegna_rettangolo_doppio(int,int,int,int);			
void disegna_rettangolo_singolo(int,int,int,int);			
void disegna_rettangolo(int,int,int,int,int);				

// disegna il carattere pieno in ogni posizione
//... del rettangolo ottenendo un area uniforme
void disegna_rettangolo_pieno();
void cancella_rettangolo_pieno();

// durante la cancellazione non c'e' bisogno di specificare
//...singolo o doppio poiche cancella qualcunque cosa ci sia
//...in quelle posizioni mettendoci degli spazi
void cancella_linea_verticale(int,int,int);				
void cancella_linea_orizzontale(int,int,int);			
void cancella_linea(int,int,int,int);					
void cancella_rettangolo(int,int,int,int);				
//____________________________________________

//____________________SLIDER__________________
void slider_cambia_tasti_orizzontale(int,int,int);
void slider_cambia_tasti_verticale(int,int,int);
void slider_stampa_orizzontale(int,int,int,int);
void slider_stampa_verticale(int,int,int,int);
int slider_usa_verticale(int,int,int,int);
int slider_usa_orizzontale(int,int,int,int);
int slider_stampa_e_usa_vericale(int,int,int,int);
int slider_stampa_e_usa_orizzontale(int,int,int,int);
void slider_cambia_tasti(int,int,int,int);
void slider_stampa(int,int,int,int,int);
int slider_usa(int,int,int,int,int);
int slider_stampa_e_usa(int,int,int,int,int);
//____________________________________________

//_____________________MENU___________________
void menu_cambia_tasti(int,int,int);
void menu_imposta_distanza(int);
void menu_aggiungi_voce(const char*);
void menu_imposta_posizione(int,int);
void menu_stampa();
void menu_stampa_a_posizione(int,int);
int menu_usa(int);
//____________________________________________

