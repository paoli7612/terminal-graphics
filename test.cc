#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

struct pos_t { unsigned short x, y; };
typedef int color_t;
char tasto_premuto;

pos_t spostamento = {0, 0};

void vai_a(const pos_t pos)
{
	COORD coord;
	coord.X = pos.x + spostamento.x;
	coord.Y = pos.y + spostamento.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cambia_colore(const color_t colore) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colore);
}
void casuale_inizializza()
{
	srand(time(NULL));
}
void cambia_colore_casuale()
{
	color_t nuovo_colore = rand()%15+1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  nuovo_colore);
}
void sposta_vai_a(const pos_t pos)
{
	spostamento = pos;	
}
void stampa_a_posizione(const string testo, const pos_t pos)
{
	vai_a(pos);
	std::cout << testo;
}
char attendi_tasto()
{
	tasto_premuto = getch();
	return tasto_premuto;
}
void attendi_secondi(const int secondi)
{
	sleep(secondi);
}
void attendi_invio()
{
	getchar();
}
namespace terminale {

int main(int argc, char **argv)
{	

	return 0;
}
