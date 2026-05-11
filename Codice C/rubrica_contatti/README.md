# Rubrica Telefonica con Array Statico in C

## Obiettivo
Il progetto implementa una rubrica telefonica essenziale con struttura dati statica.
Le funzionalità incluse sono inizializzazione, inserimento contatti, stampa completa e ricerca per nome.

## Struttura del Codice
- `main.c` mostra un esempio di utilizzo delle funzioni di rubrica.
- `rubrica.h` definisce le strutture dati e i prototipi pubblici.
- `rubrica.c` contiene la logica di inserimento, stampa e ricerca.

## Logica Implementata
- La rubrica usa un array statico di contatti con capacità massima prefissata.
- Un contatore tiene traccia del numero di contatti effettivamente inseriti.
- L'inserimento verifica la capienza disponibile prima di salvare il record.
- La ricerca confronta i nomi con `strcmp` e restituisce il numero associato oppure `NULL`.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c rubrica.c -o rubrica_app
```

Esecuzione su sistemi Unix-like:

```bash
./rubrica_app
```

Esecuzione su Windows:

```bash
rubrica_app.exe
```
