
//####################  SLIDER  ####################

#include "menu.h"

void slider_change_keys_horizontal(int less, int more, int enter){
	_slider_horizontal_less = less;
	_slider_horizontal_more = more;
	_slider_horizontal_enter = enter;
}

void slider_change_keys_vertical(int less, int more, int enter){
	_slider_vertical_less = less;
	_slider_vertical_more = more;
	_slider_vertical_enter = enter;
}

void slider_change_keys(int less, int more, int enter, int vert_horiz){
	if (vert_horiz){slider_change_keys_horizontal(less,more,enter);}
	else{slider_change_keys_vertical(less,more,enter);}
}

void slider_draw_horizontal(int x, int y, int n_choice, int current_choice){
	draw_char_pos(17,x,y);
	draw_char_pos(16,x+n_choice+1,y);
	draw_line_horizontal_single(x+1,x+n_choice,y);
	draw_char_pos('*',current_choice+x,y);
}

void slider_draw_vertical(int x, int y, int n_choice, int current_choice){
	draw_char_pos(30,x,y);
	draw_char_pos(31,x,y+n_choice+1);
	draw_line_vertical_single(y+1,y+n_choice,x);
	draw_char_pos('*',x,current_choice+y);
}

void slider_draw(int x, int y, int n_choice, int current_choice, int vert_oriz){
	if (vert_oriz){slider_draw_horizontal(x,y,n_choice,current_choice);}
	else{slider_draw_vertical(x,y,n_choice,current_choice);}
}

int slider_usa_vertical(int x, int y, int n_choice, int current_choice){
	int key;
	while (TRUE){
		draw_char_pos('*',x,y+current_choice);
		go_to(x-1,y+n_choice+3);
		printf(" %d ",current_choice);
		key = getch();
		printf("    ");
		draw_char_pos(lv,x,y+current_choice);
		if (key == _slider_vertical_less) {if (current_choice>1) current_choice--; }
		if (key == _slider_vertical_more) {if (current_choice<n_choice) current_choice++; }
		if (key == _slider_vertical_enter) {draw_char_pos('*',x,y+current_choice); return current_choice;}
	}
}

int slider_usa_horizontal(int x, int y, int n_choice, int current_choice){
	int key;
	while (TRUE){
		draw_char_pos('*',x+current_choice,y);
		go_to(x+n_choice+3,y);
		printf(" %d ",current_choice);
		key = getch();
		printf("    ");
		if (key == _slider_horizontal_enter) {return current_choice;}
		draw_char_pos(lo,x+current_choice,y);
		if (key == _slider_horizontal_more) {if (current_choice>1) current_choice--; }
		if (key == _slider_horizontal_less) {if (current_choice<n_choice) current_choice++; }
	}
}

int slider_usa(int x, int y, int n_choice, int current_choice, int vert_oriz){
	if (vert_oriz){return slider_usa_horizontal(x,y,n_choice,current_choice);}
	else{return slider_usa_vertical(x,y,n_choice,current_choice);}
}

int slider_draw_e_usa_vertical(int x, int y, int n_choice, int current_choice){
	slider_draw_vertical(x,y,n_choice,current_choice);
	slider_usa_vertical(x,y,n_choice,current_choice);
}

int slider_draw_e_usa_horizontal(int x, int y, int n_choice, int current_choice){
	slider_draw_horizontal(x,y,n_choice,current_choice);
	slider_usa_horizontal(x,y,n_choice,current_choice);
}

int slider_draw_e_usa(int x, int y, int n_choice, int current_choice, int vert_oriz){
	if (vert_oriz){return slider_draw_e_usa_horizontal(x,y,n_choice,current_choice);}
	else{ return slider_draw_e_usa_vertical(x,y,n_choice,current_choice);}
}
