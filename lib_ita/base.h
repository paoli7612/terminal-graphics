
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

void vai_a(int x, int y){ 
	COORD coord;
	coord.X = x+_x_spostamento;
	coord.Y = y+_y_spostamento;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 

void sposta_vai_a(int x,int y){
	_x_spostamento = x;
	_y_spostamento = y;
}

void stampa_carattere(char carattere){ 
	printf("%c",carattere);
} 

void stampa_a_posizione(char c, int x, int y){
	vai_a(x,y);
	stampa_carattere(c);
}

void stampa_stringa_a_posizione(const char *c, int x, int y){
	int p;
	int lunghezza = strlen(c);
	vai_a(x,y);
	for (p=0; p<lunghezza; p++){
		printf("%c",c[p]);
	}
}

char attendi_tasto(){
	tasto_premuto = getch();
	return tasto_premuto;
}

void attendi_secondi(int secondi){
	sleep(secondi);
}

void attendi_invio(){
	getchar();
}
