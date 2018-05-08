
//####################  MENU  ####################

#include "geometry.h"

#define VOCI_MAX 10
#define LUNGHEZZA_VOCI_MAX 256

char _menu[VOCI_MAX][LUNGHEZZA_VOCI_MAX];
int _menu_distanza_voci = 1;
int _menu_voci_aggiunte = 0;
int _menu_x;
int _menu_y;

void menu_cambia_tasti(int meno, int piu, int conferma){
	_menu_meno = meno;
	_menu_piu = piu;
	_menu_conferma = conferma;
}

void menu_imposta_distanza(int distanza_voci){
	_menu_distanza_voci = distanza_voci;
}

void menu_aggiungi_voce(const char* nuova_voce ){
	int c;
	int lunghezza_voce = strlen(nuova_voce);
	for (c=0; c<lunghezza_voce; c++){
		_menu[_menu_voci_aggiunte][c] = nuova_voce[c];
	}
	_menu_voci_aggiunte++;
}

void menu_imposta_posizione(int x, int y){
	_menu_x = x;
	_menu_y = y;
}

void menu_stampa(){
	int n;
	for (n=0; n<_menu_voci_aggiunte; n++){
		stampa_stringa_a_posizione(_menu[n],_menu_x,_menu_y+n*_menu_distanza_voci);
	}
}

void menu_stampa_a_posizione(int x, int y){
	menu_imposta_posizione(x,y);
	menu_stampa();
}

int menu_usa(int scelta_attuale){
	char key;
	scelta_attuale-=1;
	while (1){
		stampa_stringa_a_posizione("->",_menu_x-2,_menu_y+scelta_attuale*_menu_distanza_voci);
		key = getch();
		if (key == _menu_conferma) {menu_scelto = scelta_attuale+1; return menu_scelto;}	
		stampa_stringa_a_posizione("  ",_menu_x-2,_menu_y+scelta_attuale*_menu_distanza_voci);
		if (key == _menu_meno) {if (scelta_attuale>=1) scelta_attuale--; } 
		if (key == _menu_piu) {if (scelta_attuale<_menu_voci_aggiunte-1) scelta_attuale++; }
	}
}

