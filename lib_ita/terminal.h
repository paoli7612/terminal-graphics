
//#################### TERMINAL ####################

#include "base.h"

#define TERMINALE_LARGHEZZA_TOTALE 80  // da 0 a 79 

void terminale_pulisci(){
	system("CLS");
}

void terminale_chiudi(){
	system("exit");
}

void terminale_imposta_titolo(const char* titolo){
	HWND hWnd = GetConsoleWindow();
  	SetConsoleTitle(titolo);
}

void terminale_massimizza(){
	HWND console = GetConsoleWindow(); 
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, 1000, 1000, true);
}

void terminale_massimizza_fullscreen(){
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
