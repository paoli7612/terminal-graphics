
//#################### TERMINAL ####################

#include "base.h"

#define TEMINAL_WIDTH 80  // da 0 a 79

void terminal_clear(){
	system("CLS");
}

void terminal_quit(){
	system("exit");
}

void terminal_set_title(const char* title){
	HWND hWnd = GetConsoleWindow();
  	SetConsoleTitle(title);
}

void terminal_max_size(){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, 1000, 1000, TRUE);
}

void terminal_fullscreen(){
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
