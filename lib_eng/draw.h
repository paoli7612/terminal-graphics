// ____________________________________________________
// |##################################################|
// |####################   DRAW   ####################|
// |##################################################|

#include "slider.h"

//_______________BASE_________________________
//cambia il colore di cio che verra stampato da quel punto in poi
void change_color(int colore);

//sposta il cursore di scrittura alle coordinate date
void go_to(int x, int y);

//modifica in maniera permanente i valori che riceve il "vai_a"
//...(transla cio che verra stampato a monitor da quel momento in poi)
void change_go_to(int x_offset, int y_offset);

//stampa il carattere dato / il valore ASCII del numero dato
void draw_char(char c);

//sposta il cursore di scrittura e stampa il carattere
void draw_char_pos(char c, int x, int y);

//blocca il programma finche non viene premuto un tasto
//...il tasto premuto viene salvato in "tasto_premuto"
char wait_key();

//blocca il programma finche non viene premuto invio
void wait_enter();

//blocca il programma per TOT secondi
void wait_seconds(int secondi);

//inizializza la casualita impostando il seme di casualita
//... utilizzando l'ora di sistema
void random_init();

//cambia il colore prendendone uno casualmente
//... per evitare la monotonia e' necessario
//... lanciare casuale_inizializza
void change_color_random();
//____________________________________________


//___________________TERMINAL_________________
//cancella tutte le scritte dal terminale
void terminal_clear();

//chiude il terminale
void terminal_quit();

//reimposta la grandezza e la posizione del terminale
//...i valori vengono calcolati in pixel
void terminal_resize();

//massimizza la grandeszza de terminale al massimo consentito
void terminal_max_size();

//massimizza la grandezza oltre al massimo consentito
void terminal_fullscreen();
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

void draw_line_vertical_doubble(int y1, int y2, int x);
void draw_line_horizontal_doubble(int x1, int x2, int y);
void draw_line_vertical_single(int y1, int y2, int x);
void draw_line_horizontal_single(int x1, int x2, int y);
void draw_line(int p1, int p2, int c, int vert_horiz, int sing_doub);
void draw_rect_doubble(int x1, int y1, int x2, int y2);
void draw_rect_single(int x1, int y1, int x2, int y2);
void draw_rect(int x1, int y1, int x2, int y2, int sing_doub);

// disegna il carattere pieno in ogni posizione
//... del rettangolo ottenendo un area uniforme
void draw_rect_fill(int x1, int y1, int x2, int y2);
void del_rect_fill(int x1, int y1, int x2, int y2);

// durante la cancellazione non c'e' bisogno di specificare
//...singolo o doppio poiche cancella qualcunque cosa ci sia
//...in quelle posizioni mettendoci degli spazi
void del_line_vertical(int y1, int y2, int x);
void del_line_horizontal(int x1, int x2, int y);
void del_line(int p1, int p2, int c, int vert_horiz);
void del_rect(int x1, int y1, int x2, int y2);
//____________________________________________

//____________________SLIDER__________________
void slider_change_keys_horizontal(int less, int more, int enter);
void slider_change_keys_vertical(int less, int more, int enter);
void slider_draw_horizontal(int x, int y, int n_choice, int current_choice);
void slider_draw_vertical(int x, int y, int n_choice, int current_choice);
int slider_use_horizontal(int x, int y, int n_choice, int current_choice);
int slider_use_vertical(int x, int y, int n_choice, int current_choice);
int slider_draw_and_use_horizontal(int x, int y, int n_choice, int current_choice);
int slider_draw_and_use_vertical(int x, int y, int n_choice, int current_choice);
void slider_change_keys(int less, int more, int enter, int vert_horiz);
void slider_draw(int x, int y, int n_choice, int current_choice, int vert_horiz);
int slider_use(int x, int y, int n_choice, int current_choice, int vert_horiz);
int slider_draw_and_use(int x, int y, int n_choice, int current_choice, int vert_horiz);
//____________________________________________

//_____________________MENU___________________
void menu_change_keys(int less, int more, int enter);
void menu_set_distance(int distanza);
void menu_add_voice(const char* voce);
void menu_set_pos(int x, int y);
void menu_draw();
void menu_draw_pos(int x, int y);
int menu_use(int current_choice);
//____________________________________________
