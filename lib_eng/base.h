
//####################   BASE   ####################

#include "define.h"

void change_color(int new_color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  new_color);
}

void random_init(){
	srand(time(NULL));
}

void change_color_random(){
	int new_color = rand()%15+1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  new_color);
}

void go_to(int x, int y){
	COORD coord;
	coord.X = x+_x_offset;
	coord.Y = y+_y_offset;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void change_go_to(int x,int y){
	_x_offset = x;
	_y_offset = y;
}

void draw_char(char c){
	printf("%c", c);
}

void draw_char_pos(char c, int x, int y){
	go_to(x,y);
	draw_char(c);
}

void draw_word_pos(const char *c, int x, int y){
	int p;
	int length = strlen(c);
	go_to(x,y);
	for (p=0; p<length; p++){
		printf("%c",c[p]);
	}
}

char wait_key(){
	key_pressed = getch();
	return key_pressed;
}

void wait_seconds(int seconds){
	sleep(seconds);
}

void wait_enter(){
	getchar();
}
