#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define Xt 88
#define Ot 79
#define xMenu 5
#define Xtot 60
#define Ytot 17

using namespace std;

int colori[5] = {7,7,7,7,7};

void PulisciSchermo(){
	system("cls");
}

void gotoxy(int x, int y){
   COORD coord;
   coord.X = x+5;
   coord.Y = y+2;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

int* controllaSoluzioni(int mat[3][3]){
	int result[2];
	result[0] = -1;
	result[1] = -1;
	for (int a=0; a<3; a++){
		if (mat[a][0] == mat[a][1] && mat[a][2]==0 && mat[a][0]==Ot)
			result[1] = 2;
		if (mat[a][1] == mat[a][2] && mat[a][0]==0 && mat[a][1]==Ot)
			result[1] = 0;
		if (mat[a][2] == mat[a][0] && mat[a][1]==0 && mat[a][2]==Ot)
			result[1] = 1;
		if (result[1] != -1){
			result[0] = a;
			return result;
		}	
					
		if (mat[0][a] == mat[1][a] && mat[2][a]==0 && mat[a][0]==Ot)
			result[0] = 2;
		if (mat[1][a] == mat[2][a] && mat[0][a]==0 && mat[a][0]==Ot)
			result[0] = 0;
		if (mat[2][a] == mat[0][a] && mat[1][a]==0 && mat[a][0]==Ot)
			result[0] = 1;
		if (result[0] != -1){
			result[1] = a;
			return result;
		}
		
		if (mat[0][0]==mat[1][1] && mat[2][2]==0 && mat[0][0]==Ot){
			result[0]=2;
			result[1]=2;
			return result;
		}
		
		if (mat[0][0]==mat[2][2] && mat[1][1]==0 && mat[0][0]==Ot){
			result[0]=1;
			result[1]=1;
			return result;
		}
		
		if (mat[2][2]==mat[1][1] && mat[0][0]==0 && mat[2][2]==Ot){
			result[0]=0;
			result[1]=0;
			return result;
		}
	}	
	
	for (int a=0; a<3; a++){
		if (mat[a][0] == mat[a][1] && mat[a][2]==0 && mat[a][0]==Xt)
			result[1] = 2;
		if (mat[a][1] == mat[a][2] && mat[a][0]==0 && mat[a][1]==Xt)
			result[1] = 0;
		if (mat[a][2] == mat[a][0] && mat[a][1]==0 && mat[a][2]==Xt)
			result[1] = 1;
		if (result[1] != -1){
			result[0] = a;
			return result;
		}	
					
		if (mat[0][a] == mat[1][a] && mat[2][a]==0 && mat[0][a]==Xt)
			result[0] = 2;
		if (mat[1][a] == mat[2][a] && mat[0][a]==0 && mat[1][a]==Xt)
			result[0] = 0;
		if (mat[2][a] == mat[0][a] && mat[1][a]==0 && mat[2][0]==Xt)
			result[0] = 1;
		if (result[0] != -1){
			result[1] = a;
			return result;
		}
		
		if (mat[0][0]==mat[1][1] && mat[2,2]==0 && mat[0][0]==Xt){
			result[0]=2;
			result[1]=2;
			return result;
		}
		
		if (mat[0][0]==mat[2][2] && mat[1][1]==0 && mat[0][0]==Xt){
			result[0]=1;
			result[1]=1;
			return result;
		}
		
		if (mat[2][2]==mat[1][1] && mat[0][0]==0 && mat[2][2]==Xt){
			result[0]=0;
			result[1]=0;
			return result;
		}
	}	
	
	return result;
}

int angoliDisponibili(int mat[3][3]){
	int angs=0;
	if (mat[0][0]!=0)
		angs++;
	if (mat[2][2]!=0)
		angs++;
	if (mat[0][2]!=0)
		angs++;
	if (mat[2][0]!=0)
		angs++;
	return angs;
}

int* selezionaUnAngolo(){
	int result[2];
	srand(time(NULL));
	int x = rand()%2;
	int y = rand()%2;
	result[0]=x*2;
	result[1]=y*2;
	return result;
}

int* selezionaPosizionaCas(){
	int result[2];
	srand(time(NULL));
	int x = rand()%3;
	int y = rand()%3;
	result[0]=x;
	result[1]=y;
	return result;
}

int matPiena(int mat[3][3]){
	for (int y=0; y<3; y++)
		for (int x=0; x<3; x++)
			if (mat[x][y]==0)
				return 0;
	return 1;
}

void StampaGriglia(){
	SetColor(7);
	int Xp = 5;
	int a;
	for (a=0; a<Xtot; a++){
		gotoxy(a,0);
		printf("%c",196);
		gotoxy(a,Ytot);
		printf("%c",196);
	}
	for (a=0; a<Ytot; a++){
		gotoxy(0,a);
		printf("%c",179);
		gotoxy(Xtot,a);
		printf("%c",179);
	}
	gotoxy(0,0);
	printf("%c",218);
	gotoxy(Xtot,0);
	printf("%c",191);
	gotoxy(0,Ytot);
	printf("%c",192);
	gotoxy(Xtot,Ytot);
	printf("%c",217);	
	gotoxy(Xtot/2-3,0);
	printf("2 GIOCATORI");
	gotoxy(Xtot/2-4,Ytot);
	printf("T. PAOLI");
	
	SetColor(colori[4]);
	for (int y=1; y<12; y++){
		gotoxy(4,y);
		printf("%c",186);
		gotoxy(8,y);
		printf("%c",186);
	}
	for (int x=1; x<12; x++){
		gotoxy(x,4);
		printf("%c",205);
		gotoxy(x,8);
		printf("%c",205);
	}
	gotoxy(4,4);
	printf("%c",206);
	
	gotoxy(4,8);
	printf("%c",206);
	
	gotoxy(8,4);
	printf("%c",206);
	
	gotoxy(8,8);
	printf("%c",206);
	
}

void StampaSelettore(int x, int y){
	gotoxy(x-1,y-1);
	printf("%c",218);
	gotoxy(x-1,y+1);
	printf("%c",192);
	gotoxy(x+1,y-1);
	printf("%c",191);
	gotoxy(x+1,y+1);
	printf("%c",217);
}

void CancellaSelettore(int x, int y){
	gotoxy(x-1,y-1);
	printf(" ");
	gotoxy(x-1,y+1);
	printf(" ");
	gotoxy(x+1,y-1);
	printf(" ");
	gotoxy(x+1,y+1);
	printf(" ");
}

void StampaMenu(){
	SetColor(7);
	int a;
	for (a=0; a<Xtot; a++){
		gotoxy(a,0);
		printf("%c",205);
		gotoxy(a,Ytot);
		printf("%c",205);
	}
	for (a=0; a<Ytot; a++){
		gotoxy(0,a);
		printf("%c",186);
		gotoxy(Xtot,a);
		printf("%c",186);
	}
	gotoxy(0,0);
	printf("%c",201);
	gotoxy(Xtot,0);
	printf("%c",187);
	gotoxy(0,Ytot);
	printf("%c",200);
	gotoxy(Xtot,Ytot);
	printf("%c",188);	
	gotoxy(Xtot/2-2,0);
	printf("TRIS");
	gotoxy(Xtot/2-4,Ytot);
	printf("T. PAOLI");
	gotoxy(xMenu,3);
	printf("MULTIGIOCATORE");
	gotoxy(xMenu,5);
	printf("GIOCATORE SINGOLO");
	gotoxy(xMenu,7);
	printf("IMPOSTAZIONI");
	gotoxy(xMenu,9);
	printf("ESCI");
}

void StampaCursore(int x, int y){
	SetColor(7);
	int x1 = x+16;
	gotoxy(x,y);
	printf("<");
	gotoxy(x1,y);
	printf(">");
	for (int a=x+1; a<x1; a++){
		gotoxy(a,y);
		printf("-");	
	}
	
}

void StampaColoriAttuali(int x){
	for (int y=3; y<=11; y+=2){
		gotoxy(x,y);
		SetColor(colori[(y-3)/2]);
		printf("%c%c",219,219);
		SetColor(15);
	}
}

void StampaOpzioni(){
	system("CLS");
	SetColor(7);
	int a;
	for (a=0; a<Xtot; a++){
		gotoxy(a,0);
		printf("%c",196);
		gotoxy(a,Ytot);
		printf("%c",196);
	}
	for (a=0; a<Ytot; a++){
		gotoxy(0,a);
		printf("%c",179);
		gotoxy(Xtot,a);
		printf("%c",179);
	}
	gotoxy(0,0);
	printf("%c",218);
	gotoxy(Xtot,0);
	printf("%c",191);
	gotoxy(0,Ytot);
	printf("%c",192);
	gotoxy(Xtot,Ytot);
	printf("%c",217);	
	gotoxy(Xtot/2-3,0);
	printf("OPZIONI");
	gotoxy(Xtot/2-4,Ytot);
	printf("T. PAOLI");
	
	StampaColoriAttuali(49);
	SetColor(7);
	gotoxy(xMenu,3);
	printf("Colore giocatoreX");
	StampaCursore(xMenu + 20, 3);
	
	gotoxy(xMenu,5);
	printf("Colore giocatoreO");
	StampaCursore(xMenu + 20, 5);

	gotoxy(xMenu,7);
	printf("Colore selettore");
	StampaCursore(xMenu + 20, 7);

	gotoxy(xMenu,9);
	printf("Colore vittoria");
	StampaCursore(xMenu + 20, 9);

	gotoxy(xMenu,11);
	printf("Colore griglia");
	StampaCursore(xMenu + 20, 11);

	gotoxy(xMenu,13);
	printf("FATTO");
	for (int pos=0; pos<5; pos++){
		gotoxy(25+colori[pos],pos*2+3);
		printf("-");
		gotoxy(25+colori[pos],pos*2+3);
		printf("*");
	}
	
}

void StampaSelettoreMenu(int y){
	SetColor(7);
	gotoxy(3,y);
	printf("->");
	gotoxy(3,y-2);
	printf("  ");
	gotoxy(3,y+2);
	printf("  ");
}

void SinistraCursore(int pos){
	if (colori[pos]-1>0){
		gotoxy(25+colori[pos],pos*2+3);
		printf("-");
		colori[pos]--;
		gotoxy(25+colori[pos],pos*2+3);
		printf("*");
		StampaColoriAttuali(49);
	}
}

void DestraCursore(int pos){
	if (colori[pos]+1<=15){
		gotoxy(25+colori[pos],pos*2+3);
		printf("-");
		colori[pos]++;
		gotoxy(25+colori[pos],pos*2+3);
		printf("*");
		StampaColoriAttuali(49);
	}
}

int selezionaMenu(){
	char tasto;
	int y = 2;
	while (true){
		StampaSelettoreMenu(y+1);
		tasto = getch();
		if (tasto == 72) //su
			if (y-2 > 0)
				y -= 2;
		if (tasto == 80)//giu
			if (y+2 <10) 
				y += 2;
		if (tasto == 13)//Invio
			return y/2;			
		}
}

void selezionaOpzioni(){
	char tasto;
	int y = 2;
	int pos;
	while (true){
		StampaSelettoreMenu(y+1);
		tasto = getch();
		pos = y/2-1;
		if (tasto == 72) //su
			if (y-2 > 0)
				y -= 2;
		if (tasto == 80)//giu
			if (y+2 <14) 
				y += 2;
		if (tasto == 75) //sinistra
			if (y <= 10)
				SinistraCursore(pos);
		if (tasto == 77) //destra
			if (y <= 10)
				DestraCursore(pos);
		if (tasto == 13)//Invio
			if (y > 10)
				return;			
		}
}

int CambiaTurno(int turno){
	if (turno == Xt)
		return Ot;
	else
		return Xt;
}

int* selezionaPosizione(){
	int xs=2;
	int ys=2;
	char tasto;
	while (true){
		SetColor(colori[2]);
		StampaSelettore(xs,ys);
		tasto = getch();
		CancellaSelettore(xs,ys);
		if (tasto == 75) //sinistr
			if (xs-4 > 0)
				xs -= 4;
		if (tasto == 77) //destra
			if (xs+4 < 12)
				xs += 4;
		if (tasto == 72) //su
			if (ys-4 > 0)
				ys -= 4;
		if (tasto == 80)//giu
			if (ys+4 <12) 
				ys += 4;
		if (tasto == 13){//Invio
				int risultato[2];
				risultato[0] = (xs-2)/4;
				risultato[1] = (ys-2)/4;
				return risultato;
				}
		if (tasto == 27){//ESC
				int risultato[2];
				risultato[0] = -1;
				risultato[1] = -1;
				return risultato;
				}				
			}
}	

void EvidenziaVittoriaVerticale(int a){
	SetColor(colori[3]);
	int x,y;
	x = a*4+2;
	for (y=0; y<3; y++)
		StampaSelettore(x,y*4+2);	
}

void EvidenziaVittoriaOrizzontale(int a){
	SetColor(colori[3]);
	int x,y;
	y = a*4+2;
	for (x=0; x<3; x++)
		StampaSelettore(x*4+2,y);	
}

void EvidenziaVittoriaDiagonale(int salita){
	SetColor(colori[3]);
	int a,b;
	for (a=0; a<3; a++){
		b = a*4+2;
		if (salita == 1)
			StampaSelettore(b,b);
		else
			StampaSelettore(b,12-b);
			
	}	
}

int ControllaVittoria(int mat[3][3]){
	int a;
	for (a=0; a<3; a++){
		if (mat[a][0]==mat[a][1] && mat[a][1]==mat[a][2] && mat[a][0]!=0){
			EvidenziaVittoriaVerticale(a);
			return mat[a][0];
		}
		if (mat[0][a]==mat[1][a] && mat[2][a]==mat[1][a] && mat[0][a]!=0){
			EvidenziaVittoriaOrizzontale(a);
			return mat[0][a];
		}
	}
	if (mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2] && mat[0][0]!=0){
		EvidenziaVittoriaDiagonale(1);
		return mat[0][0];
	}
		
	if (mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0] && mat[2][0]!=0){
		EvidenziaVittoriaDiagonale(0);
		return mat[0][2];
	}
	return 0;
}

void StampaTurno(int turno){
	gotoxy(14,3);
	if (turno == Xt)
		SetColor(colori[0]);
	else
		SetColor(colori[1]);
	printf("Tocca a %c",turno);
}

void StampaRisultati(int vittoria){
	gotoxy(14,3);
	printf("                  ");
	gotoxy(14,5);
	printf("Vince %c",vittoria);
}

int PosizioneOccupata(int PosizioneSelezionata[2], int mat[3][3]){
	if (mat[PosizioneSelezionata[0]][PosizioneSelezionata[1]] != 0)
		return 1;
	else
		return 0;
}

void StampaMatrice(int mat[3][3]){
	int x,y;
	for (y=0; y<3; y++)
		for (x=0; x<3; x++){
			gotoxy(x*4+2,y*4+2);
			if (mat[x][y]==Xt)
				SetColor(colori[0]);
			else if (mat[x][y]==Ot)
				SetColor(colori[1]);
			printf("%c",mat[x][y]);
		}
}

int ControllaUscita(int PosizioneSelezionata[2]){
	if (PosizioneSelezionata[0] == -1 )
		return 1;
	else return 0;
}

int* selezionaPosizioneCPU(int mat[3][3], int mossa){
	int result[2];
	if (mossa>3){
		int* sol = controllaSoluzioni(mat);	
		if (sol[0] != -1 && sol[1] != -1)
			return sol;
	}
	if (angoliDisponibili(mat))
		return selezionaUnAngolo();
	else return selezionaPosizionaCas();
		
}

int PartitaPlrVsCPU(int turno){
	PulisciSchermo();
		int x,y;
		int mat[3][3];
		int mossa = 0;
		for (y=0; y<3; y++)
			for (x=0; x<3; x++)
				mat[x][y]=0;
		StampaGriglia();
		while (mossa <= 9)
		{
			if (matPiena(mat)){
				getchar();
				return 0;

			}
			StampaTurno(turno);
			int* PosizioneSelezionata;
			if (turno == Ot)
				PosizioneSelezionata = selezionaPosizioneCPU(mat, mossa);
			else
				PosizioneSelezionata = selezionaPosizione();
			if (ControllaUscita(PosizioneSelezionata))
				return 0;
			if (not PosizioneOccupata(PosizioneSelezionata, mat))
				{
					mat[PosizioneSelezionata[0]][PosizioneSelezionata[1]]=turno;
					StampaMatrice(mat);
					turno = CambiaTurno(turno);
					if (mossa > 3){
						int vittoria = ControllaVittoria(mat);
						if (vittoria){
							StampaRisultati(vittoria);			
							gotoxy(14,7);
							printf("Premere un tasto per continuare");
							getchar();
							return vittoria;
						}
					}					
					mossa++;
				}	
		}
}

int PartitaPlrVsPlr(int turno){
		PulisciSchermo();
		int x,y;
		int mat[3][3];
		int mossa = 0;
		for (y=0; y<3; y++)
			for (x=0; x<3; x++)
				mat[x][y]=0;
		StampaGriglia();
		while (mossa < 9)
		{
			StampaTurno(turno);
			int *PosizioneSelezionata = selezionaPosizione();
			if (ControllaUscita(PosizioneSelezionata))
				return 0;
			if (not PosizioneOccupata(PosizioneSelezionata, mat))
				{
					mat[PosizioneSelezionata[0]][PosizioneSelezionata[1]]=turno;
					StampaMatrice(mat);
					turno = CambiaTurno(turno);
					if (mossa > 3){
						int vittoria = ControllaVittoria(mat);
						if (vittoria){
							StampaRisultati(vittoria);			
							gotoxy(14,7);
							printf("Premere un tasto per continuare");
							getchar();
							return vittoria;
						}
					}					
					mossa++;
				}	
		}
}

void Opzioni(){
	StampaOpzioni();
	selezionaOpzioni();
}

int main(){
	int Termine = 1;
	while (Termine){
		StampaMenu();
		int mod = selezionaMenu();
		switch (mod){
			case (1):{
				int vittoria = Xt;
				while (vittoria)
					vittoria = PartitaPlrVsPlr(CambiaTurno(vittoria));
				PulisciSchermo();
				break;
			}
			case (2):{
				PartitaPlrVsCPU(Ot);
				PulisciSchermo();
				break;
			}
			case (3):{
				Opzioni();
				PulisciSchermo();
				break;
			}
			case (4):
				Termine = 0;
		}
	}
	system("CLS");	
	return 0;
}
