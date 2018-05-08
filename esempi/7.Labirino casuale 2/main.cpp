// main.cpp

#include "../../lib_ita/draw.h"

// larghezza e altezza di celle del labirinto
#define Xtot 40
#define Ytot 20

// percentuale di "fittezza" del labirinto
#define DENSITA 70

// matrice di booleani che rappresenta le posizioni gia occupate
bool matrix[Xtot][Ytot];

// funzione che ritorna vero il DENSITA % di volte che viene lansciata
bool random(){ if (rand()%100 < DENSITA) return true; else return false; }

// struttura di ogni singolo nodo
struct Node{
	// puntatori ai nodi sucessivi
	Node* up = NULL;
	Node* down = NULL;
	Node* right = NULL;
	Node* left = NULL;
	// coordinate per non uscire dalle limite massimo
	int x,y;
	// metodo per semplificare il settaggio delle coordinate
	void set_coord(int x, int y){
		this->x = x; this->y = y;
	}
};

// funzione ricorsiva che stampa il labirinto partendo dal nodo principale
void show_node(Node* node){
	// stampa il centro del nodo
	stampa_a_posizione(LC,node->x*2,node->y*2);
	// controlla se i puntatori del nodo puntano ad altri nodi
	if (node->up != NULL){stampa_a_posizione(LV,node->x*2,node->y*2-1);show_node(node->up);}
	if (node->left != NULL){stampa_a_posizione(LO,node->x*2-1,node->y*2);show_node(node->left);}
	if (node->down != NULL){stampa_a_posizione(LV,node->x*2,node->y*2+1);show_node(node->down);}
	if (node->right != NULL){stampa_a_posizione(LO,node->x*2+1,node->y*2);show_node(node->right);}
}

// funzione ricorsiva che dato un nodo e le sue coordinate controlla le puo' creare
// altri nodi correlati e lo fa a seconda della probabilita precedentmente impostata
void new_node(Node* node, int x, int y){
	// imposta le coordinate del nodo
	node->set_coord(x,y);
	// controlla se 
	if (x<=0 || y<=0 || Xtot<x || Ytot<y || matrix[x][y] == 1) return;
	// imposta occupata la posizione attuale nella matrice
	matrix[x][y] = true;
	// prova ad aggiungere i nuovi nodi
	if (random()){if (matrix[x-1][y] == 0){node->left = new Node;	new_node(node->left,x-1,y);}}
	if (random()){if (matrix[x][y-1] == 0){node->up = new Node;new_node(node->up,x,y-1);}}
	if (random()){if (matrix[x+1][y] == 0){node->right = new Node;new_node(node->right,x+1,y);}}
	if (random()){if (matrix[x][y+1] == 0){node->down = new Node;new_node(node->down,x,y+1);}}
}

int main(){
	// transla tutte le coordinate verso: basso-destra
	sposta_vai_a(8,5);
	// ingrandisci le dimenzioni del terminale
	terminale_massimizza_fullscreen();
	// comincia un ciclo infinito
	while(true){
		// imposta il seme di casualita'
		casuale_inizializza();
		// azzera l'intera matrice a falso
		for (int y=0; y<Ytot; y++){for (int x=0; x<Xtot; x++){matrix[x][y]=false;}}
		// genera il principale del albero
		Node* head = new Node;
		// genera l'albero partendo dal primo nodo che verra piazzato al centro della matrice
		new_node(head, Xtot/2,Ytot/2);
		// stampa il labirino utilizzando il nodo principale
		show_node(head);
		// attende un secondo
		attendi_secondi(1);
		// pulisce il terminale
		terminale_pulisci();
	}
	
	return 0;
}
