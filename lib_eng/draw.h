// ____________________________________________________
// |##################################################|
// |####################   DRAW   ####################|
// |##################################################|

#include "slider.h"

//_______________BASE_________________________
//change the color to write
void change_color(int colore);

//change position of cursor
void go_to(int x, int y);

//change oggset of "go_to"
void change_go_to(int x_offset, int y_offset);

//print char of input
void draw_char(char c);

//go_to + draw_char
void draw_char_pos(char c, int x, int y);

//wait while user use keyboard
char wait_key();

//wait while user click enter
void wait_enter();

//wait while seconds
void wait_seconds(int seconds);

//init seed random at actual time
void random_init();

//change random color
void change_color_random();
//____________________________________________


//___________________TERMINAL_________________
//clear all from terminal
void terminal_clear();

//close terminal
void terminal_quit();

//set title of terminal
void terminal_set_title(const char* title)

//resize terminal to max size
void terminal_max_size();

//resize terminal in fullscreen
void terminal_fullscreen();
//____________________________________________


//___________________GEOMETRY_________________
// rettangoli					linee
//     (x1,y1)______(x2,y1)   (x,y1)
//       |             |		     |
//       | 		         |		     |		(x1,y)_______(x2,y)
//       |			       |		     |
//       |			       |		     |
//     (x1,y2)______(x2,y2)   (x,y2)

void draw_line_vertical_doubble(int y1, int y2, int x);
void draw_line_horizontal_doubble(int x1, int x2, int y);
void draw_line_vertical_single(int y1, int y2, int x);
void draw_line_horizontal_single(int x1, int x2, int y);
void draw_line(int p1, int p2, int c, int vert_horiz, int sing_doub);
void draw_rect_doubble(int x1, int y1, int x2, int y2);
void draw_rect_single(int x1, int y1, int x2, int y2);
void draw_rect(int x1, int y1, int x2, int y2, int sing_doub);

void draw_rect_fill(int x1, int y1, int x2, int y2);
void del_rect_fill(int x1, int y1, int x2, int y2);

void del_line_vertical(int y1, int y2, int x);
void del_line_horizontal(int x1, int x2, int y);
void del_line(int p1, int p2, int c, int vert_horiz);
void del_rect(int x1, int y1, int x2, int y2);
//____________________________________________

//____________________SLIDER__________________
void slider_change_keys_horizontal(int less, int more, int enter);
void slider_change_keys_vertical(int less, int more, int enter);
void slider_draw_horizontal(int x, int y, int n_choice, int current_choice);
void slider_draw_vertical(int x, int y, int n_choice, int current_choice);
int slider_use_horizontal(int x, int y, int n_choice, int current_choice);
int slider_use_vertical(int x, int y, int n_choice, int current_choice);
int slider_draw_and_use_horizontal(int x, int y, int n_choice, int current_choice);
int slider_draw_and_use_vertical(int x, int y, int n_choice, int current_choice);
void slider_change_keys(int less, int more, int enter, int vert_horiz);
void slider_draw(int x, int y, int n_choice, int current_choice, int vert_horiz);
int slider_use(int x, int y, int n_choice, int current_choice, int vert_horiz);
int slider_draw_and_use(int x, int y, int n_choice, int current_choice, int vert_horiz);
//____________________________________________

//_____________________MENU___________________
void menu_change_keys(int less, int more, int enter);
void menu_set_distance(int distance);
void menu_add_voice(const char* voce);
void menu_set_pos(int x, int y);
void menu_draw();
void menu_draw_pos(int x, int y);
int menu_use(int current_choice);
//____________________________________________
