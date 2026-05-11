#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"

/* =========================================================
   Inserisce un elemento in coda alla lista collegata.
   ========================================================= */
void add_to_linked_list(struct spesa **head, struct spesa *elem) {
	struct spesa *prec, *succ;
	prec = succ = *head;
	if(*head == NULL) {
		*head = elem;
		elem -> next = NULL;
	} else {
		while(succ != NULL) {
			prec = succ;
			succ = succ -> next;
		}
		prec -> next = elem;
		elem -> next = NULL;
	}
}

/* =========================================================
   Legge un numero reale non negativo da input.
   Se l'input non e' valido, termina il programma con errore.
   ========================================================= */
double legginumero(void) {
	char in[50], *ptr_resto = NULL;
	double n;
	while (1) {
		if (scanf("%49s", in) != 1) {
			printf("[ERRORE] input non valido.\n");
			continue;
		}
		n = strtod(in, &ptr_resto);
		if(in == ptr_resto || *ptr_resto != '\0') {
			printf("[ERRORE] il valore inserito non e' un numero\n");
			continue;
		}
		if(n < 0) {
			printf("[ERRORE] il numero inserito non puo' essere negativo\n");
			continue;
		}
		return n;
	}
}

/* =========================================================
   Mostra il menu principale e restituisce la scelta.
   ========================================================= */
unsigned int gestiscimenu(void) {
	printf("1) Aggiungi voce di spesa\n2) Rimuovi voce di spesa\n3) Visualizza statistiche\n4) Salva su file\n5) Esci\n");
	return (unsigned int) legginumero();
}

/* =========================================================
   Crea un nuovo nodo chiedendo costo e descrizione all'utente.
   ========================================================= */
struct spesa *creanuovo(void) {
	double costo;
	char descr[50];
	struct spesa *elem = NULL;

	printf("Inserire gli euro spesi\n");
	costo = legginumero();
	printf("Inserire una descrizione alla voce di spesa\n");
	scanf("%49s", descr);

	elem = malloc(sizeof(struct spesa));
	if(elem == NULL) {
		printf("[ERRORE] Creazione nuovo elemento non riuscita \n");
		exit(EXIT_FAILURE);
	}
	strncpy(elem -> descrizione, descr, 50);
	elem -> descrizione[49] = '\0';
	elem -> costo = costo;
	elem -> next = NULL;
	return elem;
}

/* =========================================================
   Gestisce l'operazione di aggiunta di una nuova spesa.
   ========================================================= */
void gestisciaggiunta(struct spesa **head) {
	struct spesa *nuovo = NULL;
	
	nuovo = creanuovo();
	add_to_linked_list(head, nuovo);
}

/* =========================================================
   Salva tutte le voci di spesa correnti su file CSV.
   ========================================================= */
int gestiscisalva(const struct spesa *head) {
	FILE *fp;
	const struct spesa *p = head;
	fp = fopen("lista-spese.csv", "a");
	if(fp == NULL) {
		printf("[ERRORE] impossibile aprire lista-spese.csv in scrittura.\n");
		return -1;
	}
	while (p != NULL) {
		fprintf(fp, "%s, %.2f\n", p -> descrizione, p -> costo);
		p = p -> next;
	}
	fclose(fp);
	return 0;
}

/* =========================================================
   Mostra alcune statistiche semplici sulla lista delle spese:
   numero di voci, totale e media.
   ========================================================= */
void gestiscistatistiche(struct spesa *head) {
	struct spesa *p = head;
	int conteggio = 0;
	double totale = 0.0;

	while(p != NULL) {
		conteggio++;
		totale += p -> costo;
		p = p -> next;
	}

	if(conteggio == 0) {
		printf("Nessuna spesa presente.\n");
		return;
	}

	printf("Numero voci: %d\n", conteggio);
	printf("Totale speso: %.2f euro\n", totale);
	printf("Media per voce: %.2f euro\n", totale / conteggio);
}

/* =========================================================
   Rimuove una voce cercando per descrizione.
   Se non trova corrispondenze, avvisa l'utente.
   ========================================================= */
void gestiscirimozione(struct spesa **head) {
	char descr[50];
	struct spesa *corrente = *head;
	struct spesa *precedente = NULL;

	if(*head == NULL) {
		printf("La lista e' vuota, niente da rimuovere.\n");
		return;
	}

	printf("Inserire la descrizione della voce da rimuovere\n");
	scanf("%49s", descr);

	while(corrente != NULL && strcmp(corrente -> descrizione, descr) != 0) {
		precedente = corrente;
		corrente = corrente -> next;
	}

	if(corrente == NULL) {
		printf("Voce non trovata.\n");
		return;
	}

	if(precedente == NULL) {
		*head = corrente -> next;
	} else {
		precedente -> next = corrente -> next;
	}

	free(corrente);
	printf("Voce rimossa correttamente.\n");
}
