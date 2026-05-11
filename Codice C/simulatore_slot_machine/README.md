# Simulatore di Slot Machine con Gestione Credito in C

## Obiettivo
Il programma simula una slot machine testuale con gestione del credito utente.
Le operazioni disponibili sono giocata, inserimento credito, salvataggio su file e recupero da file.

## Struttura del Codice
- `main.c` gestisce il menu e coordina le operazioni principali.
- `funzioni.h` dichiara struttura dati e prototipi pubblici.
- `funzioni.c` implementa logica di gioco, file I/O e utilità di input.

## Logica Implementata
- Ogni giocata genera quattro simboli pseudo-casuali.
- I simboli vengono memorizzati in una lista collegata per il calcolo del punteggio.
- Le combinazioni rilevanti modificano il credito secondo regole fissate nel codice.
- Il credito può essere salvato e caricato dal file `credito.txt`.
- La memoria allocata per la lista della giocata viene sempre liberata prima del ritorno.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c funzioni.c -o slotmachine
```

Esecuzione su sistemi Unix-like:

```bash
./slotmachine
```

Esecuzione su Windows:

```bat
slotmachine.exe
```
