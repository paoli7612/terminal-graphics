// ____________________________________________________
// |##################################################|
// |####################   DRAW   ####################|
// |##################################################|

#include "slider.h"

//_______________BASE_________________________
//cambia il colore di cio che verra stampato da quel punto in poi
void cambia_colore(const int colore);

//sposta il cursore di scrittura alle coordinate date
void vai_a(const int x, const int y);

//modifica in maniera permanente i valori che riceve il "vai_a"
//...(transla cio che verra stampato a monitor da quel momento in poi)
void sposta_vai_a(const int x_offset, const int y_offset);

//stampa il carattere dato / il valore ASCII del numero dato
void stampa_carattere(const char carattere);

//sposta il cursore di scrittura e stampa il carattere
void stampa_a_posizione(const char carattere, const int x, const int y);

//blocca il programma finche non viene premuto un tasto
//...il tasto premuto viene salvato in "tasto_premuto"
char attendi_tasto();

//blocca il programma finche non viene premuto invio
void attendi_invio();

//blocca il programma per TOT secondi
void attendi_secondi(const int secondi);

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

void disegna_linea_verticale_doppia(int y1, int y2, int x);
void disegna_linea_orizzontale_doppia(int x1, int x2, int y);
void disegna_linea_verticale_singola(int y1, int y2, int x);
void disegna_linea_orizzontale_singola(int x1, int x2, int y);
void disegna_linea(int p1, int p2, int c, int vert_oriz, int sing_dopp);
void disegna_rettangolo_doppio(int x1, int y1, int x2, int y2);
void disegna_rettangolo_singolo(int x1, int y1, int x2, int y2);
void disegna_rettangolo(int x1, int y1, int x2, int y2, int sing_dopp);

// disegna il carattere pieno in ogni posizione
//... del rettangolo ottenendo un area uniforme
void disegna_rettangolo_pieno(int x1, int y1, int x2, int y2);
void cancella_rettangolo_pieno(int x1, int y1, int x2, int y2);

// durante la cancellazione non c'e' bisogno di specificare
//...singolo o doppio poiche cancella qualcunque cosa ci sia
//...in quelle posizioni mettendoci degli spazi
void cancella_linea_verticale(int y1, int y2, int x);
void cancella_linea_orizzontale(int x1, int x2, int y);
void cancella_linea(int p1, int p2, int c, int vert_oriz);
void cancella_rettangolo(int x1, int y1, int x2, int y2);
//____________________________________________

//____________________SLIDER__________________
void slider_cambia_tasti_orizzontale(int meno, int piu, int conferma);
void slider_cambia_tasti_verticale(int meno, int piu, int conferma);
void slider_stampa_orizzontale(int x, int y, int numero_scelte, int scelta_attuale);
void slider_stampa_verticale(int x, int y, int numero_scelte, int scelta_attuale);
int slider_usa_verticale(int x, int y, int numero_scelte, int scelta_attuale);
int slider_usa_orizzontale(int x, int y, int numero_scelte, int scelta_attuale);
int slider_stampa_e_usa_vericale(int x, int y, int numero_scelte, int scelta_attuale);
int slider_stampa_e_usa_orizzontale(int x, int y, int numero_scelte, int scelta_attuale);
void slider_cambia_tasti(int meno, int piu, int conferma, int vert_oriz);
void slider_stampa(int x, int y, int numero_scelte, int scelta_attuale, int vert_oriz);
int slider_usa(int x, int y, int numero_scelte, int scelta_attuale, int vert_oriz);
int slider_stampa_e_usa(int x, int y, int numero_scelte, int scelta_attuale, int vert_oriz);
//____________________________________________

//_____________________MENU___________________
void menu_cambia_tasti(int meno, int piu, int conferma);
void menu_imposta_distanza(int distanza);
void menu_aggiungi_voce(const char* voce);
void menu_imposta_posizione(int x, int y);
void menu_stampa();
void menu_stampa_a_posizione(int x, int y);
int menu_usa(int scelta_attuale);
//____________________________________________
