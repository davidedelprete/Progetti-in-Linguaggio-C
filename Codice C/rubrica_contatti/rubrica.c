#include <stdio.h>
#include <string.h>
#include "rubrica.h"

/* Inizializzazione: all'avvio la rubrica non contiene contatti. */
void inizializza_rubrica(struct rubrica *r) {
	r->num_inseriti = 0;
}

/* Inserimento: aggiunge un nuovo contatto in coda all'array. */
int inserisci(struct rubrica *r, const char *nome, const char *numero) {
	struct contatto *p = NULL;
	if(r -> num_inseriti >= MAX_NUM_CONTATTI) {
		printf("Rubrica piena\n");
		return -1;
	}
	p = &r -> db[r -> num_inseriti];
	p -> id = r -> num_inseriti;
	strncpy(p -> nome, nome, MAX_LUNGHEZZA_NOME - 1);
	p -> nome[MAX_LUNGHEZZA_NOME - 1] = '\0';
	strncpy(p -> numero, numero, MAX_LUNGHEZZA_NUMERO - 1);
	p -> numero[MAX_LUNGHEZZA_NUMERO - 1] = '\0';
	r -> num_inseriti++;
	return 0;
}

/* Stampa: mostra tutti i contatti presenti in rubrica. */
void stampa_rubrica(const struct rubrica *r) {
	int i;
	for(i = 0; i < r -> num_inseriti; i++) {
		printf("[%d] %s \t%s\n", r -> db[i].id, r -> db[i].nome, r -> db[i].numero);
	}
}

/* Ricerca: confronta i nomi e restituisce il numero del contatto trovato. */
const char *cerca(const struct rubrica *r, const char *nome) {
	int i;
	for(i = 0; i < r -> num_inseriti; i++) {
		if(strcmp(r -> db[i].nome, nome) == 0) {
			return r -> db[i].numero;
		}
	}
	return NULL;
}
