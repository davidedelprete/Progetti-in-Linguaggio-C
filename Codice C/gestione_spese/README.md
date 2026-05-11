# Gestione Spese con Lista Collegata Singola in C

## Obiettivo
Il modulo implementa un gestore di spese da terminale basato su menu.
La logica applicativa comprende inserimento di nuove voci, rimozione, statistiche e salvataggio su file CSV.

## Struttura del Codice
- `main.c` contiene il ciclo del menu e coordina le operazioni richieste dall'utente.
- `lista.h` definisce la struttura `spesa` e i prototipi pubblici.
- `lista.c` implementa le operazioni sulla lista, la validazione input e la persistenza su file.

## Logica Implementata
- Le spese sono memorizzate in una lista collegata singola.
- L'inserimento crea un nodo con `malloc` e lo collega in coda.
- La rimozione cerca una voce per descrizione e libera il nodo con `free`.
- Le statistiche calcolano conteggio, totale e media dei costi.
- Il salvataggio scrive i dati in `lista-spese.csv` con controllo sull'apertura del file.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c lista.c -o app
```

Esecuzione su sistemi Unix-like:

```bash
./app
```

Esecuzione su Windows:

```bash
app.exe
```
