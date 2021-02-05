
//####################   BASE   ####################

#include "define.h"

void cambia_colore(int nuovo_colore){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  nuovo_colore);
}

void casuale_inizializza(){
	srand(time(NULL));
}

void cambia_colore_casuale(){
	int nuovo_colore = rand()%15+1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  nuovo_colore);
}

void vai_a(const int x, const int y){
	COORD coord;
	coord.X = x+_x_spostamento;
	coord.Y = y+_y_spostamento;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void sposta_vai_a(const int x, const int y){
	_x_spostamento = x;
	_y_spostamento = y;
}

void stampa_carattere(const char carattere){
	cout << carattere;
}

void stampa_a_posizione(const char c, const int x, const int y){
	vai_a(x,y);
	stampa_carattere(c);
}

void stampa_stringa_a_posizione(const char *c, const int x, const int y){
	vai_a(x,y);
	cout << c;
}

char attendi_tasto(){
	tasto_premuto = getch();
	return tasto_premuto;
}

void attendi_secondi(const int secondi){
	sleep(secondi);
}

void attendi_invio(){
	getchar();
}
