
//#################### GEOMETRY ####################

#include "terminal.h"

void disegna_linea_verticale_singola(int y1, int y2, int x){	
	int y;
	for (y=y1; y<=y2; y++)
		stampa_a_posizione(lv,x,y);
}

void disegna_linea_orizzontale_singola(int x1, int x2, int y){	
	int x;
	for (x=x1; x<=x2; x++)
		stampa_a_posizione(lo,x,y);
}

void disegna_linea_verticale_doppia(int y1, int y2, int x){		
	int y;
	for (y=y1; y<=y2; y++)
		stampa_a_posizione(LV,x,y);
}

void disegna_linea_orizzontale_doppia(int x1, int x2, int y){	
	int x;
	for (x=x1; x<=x2; x++)
		stampa_a_posizione(LO,x,y);
}

void disegna_linea(int p1, int p2, int c, int vert_oriz, int sing_dopp){	
	if (vert_oriz){if (sing_dopp){disegna_linea_orizzontale_singola(p1,p2,c);}
		else {disegna_linea_orizzontale_doppia(p1,p2,c);}}
	else{if (sing_dopp){disegna_linea_verticale_singola(p1,p2,c);}
		else {disegna_linea_verticale_doppia(p1,p2,c);}}
}

void disegna_rettangolo_singolo(int x1, int y1, int x2, int y2){ 		
	// LATI ORIZZONTALI
	disegna_linea_orizzontale_singola(x1+1,x2-1,y1); // LATO ALTO
	disegna_linea_orizzontale_singola(x1+1,x2-1,y2); // LATO BASSO
	// LATI VERTICALI
	disegna_linea_verticale_singola(y1+1,y2-1,x1); // LATO SINISTRO
	disegna_linea_verticale_singola(y1+1,y2-1,x2); // LATO DESTRO
	// ANGOLI
	stampa_a_posizione(as,x1,y1); // ANGOLO ALTO SINISTRA
	stampa_a_posizione(ad,x2,y1); // ANGOLO ALTO DESTRA
	stampa_a_posizione(bs,x1,y2); // ANGOLO BASSO SINISTRA
	stampa_a_posizione(bd,x2,y2); // ANGOLO BASSO DESTRA
}

void disegna_rettangolo_doppio(int x1, int y1, int x2, int y2){ 		
	// LATI ORIZZONTALI
	disegna_linea_orizzontale_doppia(x1,x2,y1); // LATO ALTO
	disegna_linea_orizzontale_doppia(x1,x2,y2); // LATO BASSO
	// LATI VERTICALI
	disegna_linea_verticale_doppia(y1+1,y2-1,x1); // LATO SINISTRO
	disegna_linea_verticale_doppia(y1+1,y2-1,x2); // LATO DESTRO
	// ANGOLI
	stampa_a_posizione(AS,x1,y1); // ANGOLO ALTO SINISTRA
	stampa_a_posizione(AD,x2,y1); // ANGOLO ALTO DESTRA
	stampa_a_posizione(BS,x1,y2); // ANGOLO BASSO SINISTRA
	stampa_a_posizione(BD,x2,y2); // ANGOLO BASSO DESTRA
}

void disegna_rettangolo(int x1, int y1, int x2, int y2, int sing_dopp){		
	if (sing_dopp){disegna_rettangolo_singolo(x1,y1,x2,y2);}
	else {disegna_rettangolo_doppio(x1,y1,x2,y2);}
}

void cancella_linea_verticale(int y1, int y2, int x){			
	int y;
	for (y=y1; y<=y2; y++)
		stampa_a_posizione(SPAZIO,x,y);
}

void cancella_linea_orizzontale(int x1, int x2, int y){			
	int x;
	for (x=x1; x<=x2; x++)
		stampa_a_posizione(SPAZIO,x,y);
}

void cancella_linea(int p1, int p2, int c, int vert_oriz){				
	if (vert_oriz){cancella_linea_orizzontale(p1,p2,c);}
	else {cancella_linea_verticale(p1,p2,c);}
}

void cancella_rettangolo(int x1, int y1, int x2, int y2){				
	cancella_linea_verticale(y1,y2,x1);
	cancella_linea_verticale(y1,y2,x2);
	cancella_linea_orizzontale(x1,x2,y1);
	cancella_linea_orizzontale(x1,x2,y2);
}

void disegna_rettangolo_pieno(int x1, int y1, int x2, int y2){
	int x,y;
	for (y=y1; y<=y2; y++){
		for (x=x1; x<=x2; x++){
			stampa_a_posizione(CARATTERE_PIENO,x,y);
		}
	}	
}

void cancella_rettangolo_pieno(int x1, int y1, int x2, int y2){
	int x,y;
	for (y=y1; y<=y2; y++){
		for (x=x1; x<=x2; x++){
			stampa_a_posizione(SPAZIO,x,y);
		}
	}	
}
