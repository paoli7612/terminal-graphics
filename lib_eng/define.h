
//####################  DEFINE  ####################

#define TRUE 1
#define FALSE 0

#define HORIZONTAL TRUE
#define VERTICAL FALSE

#define SINGLE TRUE
#define DOUBBLE FALSE

//----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

//-----------------------------------------------

//----COLORS-------------------------------------
#define BLUE_DARK 1						// dark
#define GREEN_DARK 2
#define LIGHTBLUE_DARK 3
#define RED_DARK 4
#define PURPLE_DARK 5
#define YELLOW_DARK 6
#define WHITE_DARK 7 //default
//
#define GREY 8						// light
#define BLUE 9
#define GREEN 10
#define LIGHTBLUE 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15
//-----------------------------------------------

//----GEOMETRY CHAR------------------------------
#define LO 205 // border doubble horizontal
#define LV 186 // border doubble vertical
#define LC 206 // cross doubble
#define AS 201 // angle doubble up left
#define AD 187 // angle doubble up right
#define BS 200 // angle doubble down left
#define BD 188 // angle doubble down right
//
#define lo 196 // border single horizontal
#define lv 179 // border single vertical
#define lc 197 // cross single
#define as 218 // angle single up left
#define ad 191 // angle single up right
#define bs 192 // angle single down left
#define bd 217 // angle single down right
//
#define SPACE 0 // carattere vuoto/spazio
#define FULL_CHAR 219 // carattere pieno
//
#define ARROW_UP 24
#define ARROW_DOWN 25
#define ARROW_LEFT 27
#define ARROW_RIGHT 26
//-----------------------------------------------

//----KEYBOARD-----------------------------------
#define K_UP 72
#define K_DOWN 80
#define K_LEFT 75
#define K_RIGHT 77
#define K_Q 113
#define K_W 119
#define K_E 101
#define K_R 114
//_______________________________________________
#define K_ENTER 13
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

char key_pressed;
int menu_scelected;

//SLIDER
int _slider_horizontal_less = K_RIGHT;
int _slider_horizontal_more = K_LEFT;
int _slider_horizontal_enter = K_ENTER;

int _slider_vertical_less = K_UP;
int _slider_vertical_more = K_DOWN;
int _slider_vertical_enter = K_ENTER;

//MENU
int _menu_less = K_UP;
int _menu_more = K_DOWN;
int _menu_enter = K_ENTER;

//OFFSET (go_to)
int _x_offset = 0;
int _y_offset = 0;
