
//#################### GEOMETRY ####################

#include "terminal.h"

void draw_line_vertical_single(int y1, int y2, int x){
	int y;
	for (y=y1; y<=y2; y++)
		draw_char_pos(lv,x,y);
}

void draw_line_horizontal_single(int x1, int x2, int y){
	int x;
	for (x=x1; x<=x2; x++)
		draw_char_pos(lo,x,y);
}

void draw_line_vertical_doubble(int y1, int y2, int x){
	int y;
	for (y=y1; y<=y2; y++)
		draw_char_pos(LV,x,y);
}

void draw_line_horizontal_doubble(int x1, int x2, int y){
	int x;
	for (x=x1; x<=x2; x++)
		draw_char_pos(LO,x,y);
}

void draw_line(int p1, int p2, int c, int vert_horiz, int sing_doub){
	if (vert_horiz){if (sing_doub){draw_line_horizontal_single(p1,p2,c);}
		else {draw_line_horizontal_doubble(p1,p2,c);}}
	else{if (sing_doub){draw_line_vertical_single(p1,p2,c);}
		else {draw_line_vertical_doubble(p1,p2,c);}}
}

void draw_rect_single(int x1, int y1, int x2, int y2){
	// LATI ORIZZONTALI
	draw_line_horizontal_single(x1+1,x2-1,y1); // LATO ALTO
	draw_line_horizontal_single(x1+1,x2-1,y2); // LATO BASSO
	// LATI VERTICALI
	draw_line_vertical_single(y1+1,y2-1,x1); // LATO SINISTRO
	draw_line_vertical_single(y1+1,y2-1,x2); // LATO DESTRO
	// ANGOLI
	draw_char_pos(as,x1,y1); // ANGOLO ALTO SINISTRA
	draw_char_pos(ad,x2,y1); // ANGOLO ALTO DESTRA
	draw_char_pos(bs,x1,y2); // ANGOLO BASSO SINISTRA
	draw_char_pos(bd,x2,y2); // ANGOLO BASSO DESTRA
}

void draw_rect_doubble(int x1, int y1, int x2, int y2){
	// LATI ORIZZONTALI
	draw_line_horizontal_doubble(x1,x2,y1); // LATO ALTO
	draw_line_horizontal_doubble(x1,x2,y2); // LATO BASSO
	// LATI VERTICALI
	draw_line_vertical_doubble(y1+1,y2-1,x1); // LATO SINISTRO
	draw_line_vertical_doubble(y1+1,y2-1,x2); // LATO DESTRO
	// ANGOLI
	draw_char_pos(AS,x1,y1); // ANGOLO ALTO SINISTRA
	draw_char_pos(AD,x2,y1); // ANGOLO ALTO DESTRA
	draw_char_pos(BS,x1,y2); // ANGOLO BASSO SINISTRA
	draw_char_pos(BD,x2,y2); // ANGOLO BASSO DESTRA
}

void draw_rect(int x1, int y1, int x2, int y2, int sing_doub){
	if (sing_doub){draw_rect_single(x1,y1,x2,y2);}
	else {draw_rect_doubble(x1,y1,x2,y2);}
}

void del_line_vertical(int y1, int y2, int x){
	int y;
	for (y=y1; y<=y2; y++)
		draw_char_pos(SPACE,x,y);
}

void del_line_horizontal(int x1, int x2, int y){
	int x;
	for (x=x1; x<=x2; x++)
		draw_char_pos(SPACE,x,y);
}

void del_line(int p1, int p2, int c, int vert_horiz){
	if (vert_horiz){del_line_horizontal(p1,p2,c);}
	else {del_line_vertical(p1,p2,c);}
}

void del_rect(int x1, int y1, int x2, int y2){
	del_line_vertical(y1,y2,x1);
	del_line_vertical(y1,y2,x2);
	del_line_horizontal(x1,x2,y1);
	del_line_horizontal(x1,x2,y2);
}

void draw_rect_fill(int x1, int y1, int x2, int y2){
	int x,y;
	for (y=y1; y<=y2; y++){
		for (x=x1; x<=x2; x++){
			draw_char_pos(FULL_CHAR,x,y);
		}
	}
}

void del_rect_fill(int x1, int y1, int x2, int y2){
	int x,y;
	for (y=y1; y<=y2; y++){
		for (x=x1; x<=x2; x++){
			draw_char_pos(SPACE,x,y);
		}
	}
}
