#include <iostream>

using namespace std;

#include "../lib_ita/draw.h"

int main(int argc, char** argv)
{
	terminale_massimizza();
	
	for (int i=0; i<10; i++)
	{
		disegna_rettangolo_pieno(2, 2, 10, 10);
		attendi_secondi(1);
		cancella_rettangolo_pieno(2, 2, 10, 10);
		disegna_rettangolo_singolo(2, 2, 10, 10);
		attendi_secondi(1);
	}
	
	return 0;
}
