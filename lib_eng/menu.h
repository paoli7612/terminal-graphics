
//####################  MENU  ####################

#include "geometry.h"

#define MAX_VOICE 10
#define LENGTH_MAX_VOICE 256

char _menu[MAX_VOICE][LENGTH_MAX_VOICE];
int _menu_distance_voice = 1;
int _menu_voice_appended = 0;
int _menu_x;
int _menu_y;

void menu_change_keys(int less, int more, int enter){
	_menu_less = less;
	_menu_more = more;
	_menu_enter = enter;
}

void menu_set_distance(int distance){
	_menu_distance_voice = distance;
}

void menu_add_voice(const char* new_voice){
	int c;
	int length_voice = strlen(new_voice);
	for (c=0; c<length_voice; c++){
		_menu[_menu_voice_appended][c] = new_voice[c];
	}
	_menu_voice_appended++;
}

void menu_set_pos(int x, int y){
	_menu_x = x;
	_menu_y = y;
}

void menu_draw(){
	int n;
	for (n=0; n<_menu_voice_appended; n++){
		draw_word_pos(_menu[n],_menu_x,_menu_y+n*_menu_distance_voice);
	}
}

void menu_draw_pos(int x, int y){
	menu_set_pos(x,y);
	menu_draw();
}

int menu_use(int current_choice){
	char key;
	current_choice-=1;
	while (TRUE){
		draw_word_pos("->",_menu_x-2,_menu_y+current_choice*_menu_distance_voice);
		key = getch();
		if (key == _menu_enter) {menu_scelected = current_choice+1; return menu_scelected;}
		draw_word_pos("  ",_menu_x-2,_menu_y+current_choice*_menu_distance_voice);
		if (key == _menu_less) {if (current_choice>=1) current_choice--; }
		if (key == _menu_more) {if (current_choice<_menu_voice_appended-1) current_choice++; }
	}
}
