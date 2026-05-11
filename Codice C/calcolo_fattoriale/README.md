# Calcolo del Fattoriale in C

## Obiettivo
La cartella contiene due implementazioni del calcolo di `n!` per interi non negativi.
L'impostazione didattica consente di confrontare in modo diretto approccio iterativo e approccio ricorsivo.

## Struttura del Codice
- `fattorialeloop.c` implementa il calcolo con ciclo `for`.
- `fattorialericorsivo.c` implementa il calcolo con una funzione ricorsiva dedicata.

## Logica Implementata
- Entrambi i programmi leggono un intero da input e verificano la validità del dato.
- In caso di numero negativo, il programma segnala che il fattoriale non è definito.
- La versione iterativa moltiplica progressivamente i valori da `1` a `n`.
- La versione ricorsiva usa il caso base `0! = 1` e il passo `n! = n * (n - 1)!`.

## Compilazione ed Esecuzione
Compilazione:

```bash
gcc fattorialeloop.c -o fattorialeloop
gcc fattorialericorsivo.c -o fattorialericorsivo
```

Esecuzione su sistemi Unix-like:

```bash
./fattorialeloop
./fattorialericorsivo
```

Esecuzione su Windows:

```bash
fattorialeloop.exe
fattorialericorsivo.exe
```
