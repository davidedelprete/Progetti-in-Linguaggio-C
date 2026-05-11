#ifndef RUBRICA_H
#define RUBRICA_H

#define MAX_NUM_CONTATTI 1024
#define MAX_LUNGHEZZA_NOME 64
#define MAX_LUNGHEZZA_NUMERO 16

/* Struttura che rappresenta un singolo contatto della rubrica. */
struct contatto {
	int id;
	char nome[MAX_LUNGHEZZA_NOME];
	char numero[MAX_LUNGHEZZA_NUMERO];
};

/* Struttura che rappresenta l'intera rubrica con array statico di contatti. */
struct rubrica {
	int num_inseriti;
	struct contatto db[MAX_NUM_CONTATTI];
};

/* Inizializza la rubrica portando il numero di elementi a zero. */
void inizializza_rubrica(struct rubrica *r);

/* Inserisce un contatto nella rubrica se c'e' spazio disponibile. */
int inserisci(struct rubrica *r, const char *nome, const char *numero);

/* Stampa tutti i contatti inseriti fino a questo momento. */
void stampa_rubrica(const struct rubrica *r);

/* Cerca un contatto per nome e restituisce il numero oppure NULL. */
const char *cerca(const struct rubrica *r, const char *nome);

#endif
