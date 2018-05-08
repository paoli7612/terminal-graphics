
//####################  SLIDER  ####################

#include "menu.h"

void slider_cambia_tasti_orizzontale(int meno, int piu, int conferma){
	_slider_orizzontale_meno = meno;
	_slider_orizzontale_piu = piu;
	_slider_orizzontale_conferma = conferma;
}

void slider_cambia_tasti_verticale(int meno, int piu, int conferma){
	_slider_verticale_meno = meno;
	_slider_verticale_piu = piu;
	_slider_verticale_conferma = conferma;
}

void slider_cambia_tasti(int meno, int piu, int conferma, int vert_oriz){
	if (vert_oriz){slider_cambia_tasti_orizzontale(meno,piu,conferma);}
	else{slider_cambia_tasti_verticale(meno,piu,conferma);}
}

void slider_stampa_orizzontale(int x, int y, int numero_scelte, int scelta_attuale){
	stampa_a_posizione(17,x,y);
	stampa_a_posizione(16,x+numero_scelte+1,y);
	disegna_linea_orizzontale_singola(x+1,x+numero_scelte,y);
	stampa_a_posizione('*',scelta_attuale+x,y);
}

void slider_stampa_verticale(int x, int y, int numero_scelte, int scelta_attuale){
	stampa_a_posizione(30,x,y);
	stampa_a_posizione(31,x,y+numero_scelte+1);
	disegna_linea_verticale_singola(y+1,y+numero_scelte,x);
	stampa_a_posizione('*',x,scelta_attuale+y);
}

void slider_stampa(int x, int y, int numero_scelte, int scelta_attuale, int vert_oriz){
	if (vert_oriz){slider_stampa_orizzontale(x,y,numero_scelte,scelta_attuale);}
	else{slider_stampa_verticale(x,y,numero_scelte,scelta_attuale);}
}

int slider_usa_verticale(int x, int y, int numero_scelte, int scelta_attuale){
	int key;
	while (1){
		stampa_a_posizione('*',x,y+scelta_attuale);
		vai_a(x-1,y+numero_scelte+3);
		printf(" %d ",scelta_attuale);
		key = getch();
		printf("    ");
		stampa_a_posizione(lv,x,y+scelta_attuale);
		if (key == _slider_verticale_meno) {if (scelta_attuale>1) scelta_attuale--; } 
		if (key == _slider_verticale_piu) {if (scelta_attuale<numero_scelte) scelta_attuale++; }
		if (key == _slider_verticale_conferma) {stampa_a_posizione('*',x,y+scelta_attuale); return scelta_attuale;}		
	}		
}

int slider_usa_orizzontale(int x, int y, int numero_scelte, int scelta_attuale){
	int key;
	while (1){
		stampa_a_posizione('*',x+scelta_attuale,y);
		vai_a(x+numero_scelte+3,y);
		printf(" %d ",scelta_attuale);
		key = getch();
		printf("    ");
		if (key == _slider_orizzontale_conferma) {return scelta_attuale;}
		stampa_a_posizione(lo,x+scelta_attuale,y);
		if (key == _slider_orizzontale_piu) {if (scelta_attuale>1) scelta_attuale--; } 
		if (key == _slider_orizzontale_meno) {if (scelta_attuale<numero_scelte) scelta_attuale++; }	
	}		
}

int slider_usa(int x, int y, int numero_scelte, int scelta_attuale, int vert_oriz){
	if (vert_oriz){return slider_usa_orizzontale(x,y,numero_scelte,scelta_attuale);}
	else{return slider_usa_verticale(x,y,numero_scelte,scelta_attuale);}
}

int slider_stampa_e_usa_verticale(int x, int y, int numero_scelte, int scelta_attuale){
	slider_stampa_verticale(x,y,numero_scelte,scelta_attuale);
	slider_usa_verticale(x,y,numero_scelte,scelta_attuale);
}

int slider_stampa_e_usa_orizzontale(int x, int y, int numero_scelte, int scelta_attuale){
	slider_stampa_orizzontale(x,y,numero_scelte,scelta_attuale);
	slider_usa_orizzontale(x,y,numero_scelte,scelta_attuale);
}

int slider_stampa_e_usa(int x, int y, int numero_scelte, int scelta_attuale, int vert_oriz){
	if (vert_oriz){return slider_stampa_e_usa_orizzontale(x,y,numero_scelte,scelta_attuale);}
	else{ return slider_stampa_e_usa_verticale(x,y,numero_scelte,scelta_attuale);}
}
