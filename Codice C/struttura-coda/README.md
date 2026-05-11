# Gestione Pacchetti con Due Code FIFO in C

## Obiettivo
Il progetto simula la gestione di pacchetti mediante due code FIFO implementate con liste collegate.
L'instradamento avviene in base alla lunghezza del pacchetto, con separazione in due code distinte.

## Struttura del Codice
- `main.c` gestisce menu, acquisizione input e chiamate alle funzioni di coda.
- `coda.h` definisce i tipi nodo e i prototipi pubblici.
- `coda.c` implementa inserimento, rimozione, stampa, svuotamento e calcolo delle lunghezze.

## Logica Implementata
- I pacchetti con lunghezza minore o uguale a 750 sono inseriti nella coda 1.
- I pacchetti con lunghezza maggiore di 750 sono inseriti nella coda 2.
- Le operazioni di inserimento e rimozione rispettano la politica FIFO.
- Il programma può stampare lo stato delle code e calcolare il totale delle lunghezze.
- La memoria allocata viene liberata con funzioni dedicate di svuotamento.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c coda.c -o main
```

Esecuzione su sistemi Unix-like:

```bash
./main
```

Esecuzione su Windows:

```powershell
main.exe
```
