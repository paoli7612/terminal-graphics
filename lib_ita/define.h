
//####################  DEFINE  ####################

#define VERO 1
#define FALSO 0

#define ORIZZONTALE VERO
#define VERTICALE FALSO

#define SINGOLO VERO
#define DOPPIO FALSO

//----LIBRERIE-----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	
#include <windows.h>
#include <unistd.h>
#include <time.h>

//-----------------------------------------------

//----COLORI-------------------------------------
#define BLU_SCURO 1						// scuri
#define VERDE_SCURO 2
#define AZZURRO_SCURO 3
#define ROSSO_SCURO 4
#define VIOLA_SCURO 5
#define GIALLO_SCURO 6
#define BIANCO_SCURO 7 //default
//
#define GRIGIO 8						// chiari
#define BLU 9
#define VERDE 10
#define AZZURRO 11
#define ROSSO 12
#define VIOLA 13
#define GIALLO 14
#define BIANCO 15
//-----------------------------------------------

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
//
#define SPAZIO 0 // carattere vuoto/spazio
#define CARATTERE_PIENO 219 // carattere pieno
//
#define FRECCIA_SU 24
#define FRECCIA_GIU 25
#define FRECCIA_SINISTRA 27
#define FRECCIA_DESTRA 26
//-----------------------------------------------

//----TASTIERA-----------------------------------
#define K_SU 72
#define K_GIU 80
#define K_SINISTRA 75
#define K_DESTRA 77
#define K_Q 113
#define K_W 119
#define K_E 101
#define K_R 114
//_______________________________________________
#define K_INVIO 13
#define K_ESC 27
#define K_DEL 8
//-----------------------------------------------

/*
	const char A = 97;
	const char B = 98;
	const char C = 99;
	const char D = 100;
	const char E = 101;
	const char F = 102;
	const char G = 103;
	const char H = 104;
	const char I = 105;
	const char J = 106;
	const char K = 107;
	const char L = 108;
	const char M = 109;
	const char N = 110;
	const char O = 111;
	const char P = 112;
	const char Q = 113;
	const char R = 114;
	const char S = 115;
	const char T = 116;
	const char U = 117;
	const char V = 118;
	const char W = 119;
	const char X = 120;
	const char Y = 121;
	const char Z = 122;
*/

char tasto_premuto;
int menu_scelto;

//----TASTI DA UTILIZZARE-----------------------
//SLIDER
int _slider_orizzontale_meno = K_DESTRA;
int _slider_orizzontale_piu = K_SINISTRA;
int _slider_orizzontale_conferma = K_INVIO;

int _slider_verticale_meno = K_SU;
int _slider_verticale_piu = K_GIU;
int _slider_verticale_conferma = K_INVIO;


//MENU
int _menu_piu = K_GIU;
int _menu_meno = K_SU;
int _menu_conferma = K_INVIO;

//SPOSTAMENTO DEL (vai_a)
int _x_spostamento = 0;
int _y_spostamento = 0;


































