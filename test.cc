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

//----CARATTERI GEOMETRICI-----------------------
#define LO 205 // lato doppio orizzontale
#define LV 186 // lato doppio verticale
#define LC 206 // croce doppia
#define AS 201 // angolo doppio alto sinistra
#define AD 187 // angolo doppio alto destra
#define BS 200 // angolo doppio basso sinistra
#define BD 188 // angolo doppio basso destra
//
#define lo 196 // lato singolo orizzontale
#define lv 179 // lato singolo verticale
#define lc 197 // croce singola
#define as 218 // angolo singolo alto sinistra
#define ad 191 // angolo singolo alto destra
#define bs 192 // angolo singolo basso sinistra
#define bd 217 // angolo singolo basso destra

#define CARATTERE_PIENO 219 // carattere pieno


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
	void pulisci()
	{
		system("CLS");
	}
	void chiudi()
	{
		system("exit");
	}
	void imposta_titolo(const char *titolo)
	{
		HWND hWnd = GetConsoleWindow();
		SetConsoleTitle(titolo);
	}
	void massimizza()
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, 0, 0, 1000, 1000, true);
	}
	void fullscreen()
	{
		HWND hWnd = GetConsoleWindow();
	    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	    COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
	    SMALL_RECT DisplayArea = {0,0,0,0};

	    SetConsoleScreenBufferSize(hOut, NewSBSize);

	    DisplayArea.Right = NewSBSize.X;
	    DisplayArea.Bottom = NewSBSize.Y;

	    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);

	    ShowWindow(hWnd, SW_MAXIMIZE);
	}
}

namespace tastiera {
	const char A = 97, B = 98, C = 99, D = 100,
	E = 101, F = 102, G = 103, H = 104, I = 105,
	J = 106, K = 107, L = 108, M = 109, N = 110,
	O = 111, P = 112, Q = 113, R = 114, S = 115,
	T = 116, U = 117, V = 118, W = 119, X = 120,
	Y = 121, Z = 122;

	struct FRECCIA {
		const int SU = 24,
			GIU = 25,
			DESTRA = 26,
			SINISTRA = 27;
	};
}

enum bordo_t { SINGOLO, DOPPIO };
enum dir_t { VERTICALE, ORIZZONTALE};
namespace disegna {
	void linea(pos_t, const int, const dir_t, const bordo_t);
	
	void _char_at_pos(const pos_t pos, const char c)
	{
		vai_a(pos);
		cout << c;
	}
	
	namespace _linea
	{
		void verticale_singola(pos_t pos, const int l)
		{
			for (int i=0; i<l; i++)
			{
				_char_at_pos(pos, lv);
				pos.y++;
			}		
		}
		void verticale_doppia(pos_t pos, const int l)
		{
			for (int i=0; i<l; i++)
			{
				_char_at_pos(pos, LV);
				pos.y++;
			}		
		}
		void orizzontale_singola(pos_t pos, const int l)
		{
			for (int i=0; i<l; i++)
			{
				_char_at_pos(pos, lo);
				pos.x++;
			}		
		}
		void orizzontale_doppia(pos_t pos, const int l)
		{
		for (int i=0; i<l; i++)
			{
				_char_at_pos(pos, LO);
				pos.x++;
			}		
		}
	}
	
	namespace _rettangolo
	{
		void doppio(const pos_t angolo1, const pos_t angolo2)
		{
			linea(angolo1, angolo2.x-angolo1.x, ORIZZONTALE, DOPPIO);
			linea(angolo1, angolo2.y-angolo1.y, VERTICALE, DOPPIO);
		}
		
		void singolo(pos_t pos)
		{
			
		}
	}

	void linea(pos_t pos, const int l, const dir_t dir, const bordo_t bordo)
	{
		if (dir == VERTICALE)
		{
			if (bordo == DOPPIO)
				_linea::verticale_doppia(pos, l);
			else if (bordo == SINGOLO)
				_linea::verticale_singola(pos, l);
		}
		else if (dir == ORIZZONTALE) 
		{
			if (bordo == DOPPIO)
				_linea::orizzontale_doppia(pos, l);
			else if (bordo == SINGOLO)
				_linea::orizzontale_singola(pos, l);
		}
	}

}

int main(int argc, char **argv)
{
	disegna::_rettangolo::doppio({2, 2}, {5, 5});	
	return 0;
}
