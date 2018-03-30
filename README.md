# Terminal-Graphics

**Semplice libreria grafica per trasformare quei semplici programmini in c/c++ e renderli graficamente migliori**

Questa libreria è stata scritta per essere utilizzata dal devc++ e il suo compliatore (incluso se scaricato dal sito ufficiale) mingGW64. Il codice potrebbe funzionare tranquillamente anche in altri ambienti ma NON è garantito.
per scaricare DevC++ [clicca qui](https://www.npmjs.com/package/selenium-standalone).

Contiene le funzioni per: 
- Terminale: Massimizzare la larghezza consentita anche col mouse o massimizzarlo a schermo intero
- Colori: É possibile utilizzare tutti e 15 i colori del terminale
- Movimento: Il terminale è effettivamente un piano cartesiano e poter saltare da un punto al altro permette di poter muovere delle figure senza dover riscrivere tutto il resto

## Come utilizzarla

Per utilizzare la libreria è necessario importare il file principale "draw.h" il quale includerà da solo gli altri sorgenti.
Se quindi tenete la cartella lib nella stessa direcktory del vostro soregente bastera iniziare con:

 `#include "lib/draw.h"`



Se per esempio invece la cartella "lib" e la cartella che contiene il vostro sorgente sono a loro volta parallele nella stessa direcktory il codice diventa:

 `#include "../lib/draw.h`

## Semplicità
Tenendo conto che ogni nome di variabile o funzione è stato scritto in italiano per semplificarne l'apprendimento, l'intera libreria è stata scritta utilizzano il minor numero di comandi diversi possibili; non sono quindi incluse classi e strutture che avrebbero semplificato il lavoro per un semplice fatto di apprendere pian piano i concetti base del linguaggio.
Inoltre ogni singola funzione è spiegata nel codice, se quindi aprite il file principale "draw.h" vedrete l'inizializzazzione di tutte le funzioni con le rispettive spiegazioni.

## Esempi
![alt text](https://github.com/paoli7612/terminal-graphics/blob/master/img/examples/labirintoCasuale.PNG)
![alt text](https://github.com/paoli7612/terminal-graphics/blob/master/img/examples/battagliaNavale_menuPrincipale.PNG)

## define.h
L'ultimo file della catena "define.h" contiene le costanti per la semplificazione del passaggio di parametri alle funzioni della libreria, inoltre include alcune delle librerie base; ciò rende quindi futile includerle anche nei vostri sorgenti ma non sarà fonte di errore.
Le librerie gia include sono:
     - stdio.h
     - stdlib.
     - windows.h
     - time.h
     - unistd.h
     - conio.h
