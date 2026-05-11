# Confronto tra Insertion Sort e Merge Sort in C

## Obiettivo
Il progetto affronta il problema dell'ordinamento crescente di una sequenza di interi.
L'analisi compara due approcci distinti, Insertion Sort e Merge Sort, applicati a copie dello stesso array iniziale.

## Struttura del Codice
- `main.c` inizializza i dati, richiama gli algoritmi e mostra i risultati.
- `sort.h` dichiara le funzioni pubbliche `insertion_sort` e `merge_sort`.
- `sort.c` contiene l'implementazione completa degli algoritmi e delle funzioni di supporto.

## Logica Implementata
- Insertion Sort ordina in modo iterativo, inserendo progressivamente ogni elemento nella porzione già ordinata.
- Merge Sort divide ricorsivamente l'array in sottoarray, quindi li ricompone in ordine mediante una fusione controllata.
- La fusione usa memoria dinamica temporanea con controllo su `malloc` e rilascio finale con `free`.
- Il programma stampa anche gli step di avanzamento dell'algoritmo iterativo per favorire la lettura didattica.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc main.c sort.c -o sort
```

Esecuzione su sistemi Unix-like:

```bash
./sort
```

Esecuzione su Windows:

```powershell
.\sort.exe
```
