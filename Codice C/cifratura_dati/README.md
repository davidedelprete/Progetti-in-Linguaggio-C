# Cifratura e Decifratura XOR in C

## Obiettivo
Il programma realizza una trasformazione reversibile di un messaggio testuale mediante operatore XOR.
La chiave di cifratura è ricavata da un seed intero fornito dall'utente.

## Struttura del Codice
- `main.c` gestisce menu, input utente, cifratura, salvataggio e recupero dati.
- `key.h` dichiara la funzione per la generazione della chiave.
- `key.c` implementa la generazione della chiave pseudo-casuale a partire dal seed.

## Logica Implementata
- Il menu consente di impostare il seed, acquisire il messaggio, cifrare, salvare e decifrare.
- La cifratura applica XOR byte per byte tra messaggio e chiave.
- Il risultato cifrato viene mostrato e salvato in formato esadecimale.
- La fase di recupero legge il file, converte i byte esadecimali e ricostruisce il testo originale.
- La gestione del file include controlli di apertura e validazione del contenuto.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c key.c -o app
```

Esecuzione su sistemi Unix-like:

```bash
./app
```

Esecuzione su Windows:

```powershell
.\app.exe
```
