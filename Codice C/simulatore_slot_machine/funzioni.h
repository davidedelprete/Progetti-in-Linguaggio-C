#ifndef FUNZIONI_H
#define FUNZIONI_H

/* Struttura dati: nodo della lista usata per memorizzare gli esiti della giocata. */
typedef struct slot {
    int n;
    struct slot *next;
} Slot;

/* Legge un intero positivo da tastiera con controlli base. */
int legginumero(void);

/* Esegue una giocata e restituisce il credito aggiornato. */
int gioca(int credito);

/* Salva il credito su file. Restituisce 0 su successo, -1 su errore. */
int inserisci(int n);

/* Carica il credito da file. Restituisce 0 su successo, -1 su errore. */
int recupera(int *credito);

#endif

