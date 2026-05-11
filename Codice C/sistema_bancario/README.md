# Gestione Movimenti Economici in C

## Obiettivo
Il progetto gestisce movimenti economici mensili con archiviazione su file CSV.
Le funzionalità comprendono inserimento dati, analisi del saldo complessivo, prenotazione di un appuntamento e raccolta di recensione testuale.

## Struttura del Codice
- `main.c` contiene il menu principale e il flusso applicativo.
- `bank.h` dichiara struttura dati e prototipi delle funzioni.
- `bank.c` implementa input numerico, salvataggio CSV, analisi e funzioni accessorie.

## Logica Implementata
- I movimenti inseriti da tastiera sono memorizzati in lista concatenata.
- Il salvataggio scrive mese e saldo nel file `bank-account.csv`.
- L'analisi legge il CSV, calcola il totale e classifica la situazione economica.
- La gestione memoria è lineare: ogni nodo allocato viene liberato in uscita.
- Le funzioni di appuntamento e recensione usano controlli di validità sugli input.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c bank.c -o bank_app
```

Esecuzione su sistemi Unix-like:

```bash
./bank_app
```

Esecuzione su Windows:

```powershell
.\bank_app.exe
```
