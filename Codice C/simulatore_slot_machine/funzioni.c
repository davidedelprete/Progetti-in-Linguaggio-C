#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

/* Gestione file: legge il credito salvato e lo restituisce. */
int recupera(int *credito) {
	int rc = 0;
	FILE *fp;
	if (credito == NULL) {
		return -1;
	}
	if ((fp = fopen("credito.txt", "r")) == NULL) {
		printf("NESSUN FILE credito.txt PRESENTE NELLA CARTELLA\n");
		return -1;
	}
	if (fscanf(fp, "%d", &rc) != 1) {
		printf("ERRORE NELLA LETTURA DEL CREDITO\n");
		fclose(fp);
		return -1;
	}
	fclose(fp);
	*credito = rc;
	return 0;
}

/* Gestione file: salva il credito corrente in formato testuale. */
int inserisci(int n) {
	FILE *fp;
	if((fp = fopen("credito.txt", "w")) == NULL){
		printf("IMPOSSIBILE APRIRE IL FILE CREDITO.TXT\n");
		return -1;
	}
	fprintf(fp, "%d\n", n);
	fclose(fp);
	return 0;
}

/* Input utente: accetta solo interi positivi e ripete la richiesta in caso di errore. */
int legginumero(void) {
	int n;
	while(1) {
		if (scanf("%d", &n) != 1) {
			int c;
			printf("ERRORE! INSERIRE SOLO NUMERI.\n");
			while ((c = getchar()) != '\n' && c != EOF) {
				/* svuota il buffer di input */
			}
			continue;
		}
		if (n > 0) {
			return n;
		}
		if (n <= 0) {
			printf("ERRORE! LA CIFRA INSERITA DEVE ESSERE MAGGIORE DI ZERO\n");
			printf("INSERIRE UNA CIFRA VALIDA\n");
		}
	}
}

/* Calcolo del punteggio: conta i simboli e aggiorna il credito. */
static int calcola_punteggio(Slot *head, int credito) {
	Slot *curr = head;
	int pA = 0, pB = 0, pC = 0, pX = 0;
	while(curr) {
		if(curr -> n == 1) {
			pA++;
		}
		if(curr -> n == 2) {
			pB++;
		}
		if(curr -> n == 3) {
			pC++;
		}
		if(curr -> n == 4) {
			pX++;
		}
		curr = curr -> next;
	}
	if(pA == 2 || pB == 2 || pC == 2) {
		printf("COPPIA\n");
		credito++;
	}
	if(pA == 3 || pB == 3 || pC == 3) {
		printf("TRIS\n");
		credito = credito + 3;
	}
	if(pX == 3) {
		printf("TRIS DI X\n");
		credito = credito - 3;
	}
	return credito;
}

/* Inserimento in lista: aggiunge il nuovo simbolo in testa. */
static void aggiungi_alla_lista(Slot **head, Slot *el) {
	el -> next = *head;
	*head = el;
 	return;
}

/* Crea un nuovo nodo con il simbolo estratto. */
static Slot* crea_nodo(int numb) {
	Slot *el = NULL;
	el = malloc(sizeof(Slot));
	if (el == NULL) {
		return NULL;
	}
	el -> n = numb;
	el -> next = NULL;
	return el;
}

/* Gioco: scala il costo della partita, genera i simboli e restituisce il nuovo credito. */
int gioca(int credito) {
	if(credito == 0) {
		printf("CREDITO INSUFFICIENTE, INSERISCI CREDITO PRIMA DI GIOCARE.\n");
		return credito;
	}
	credito = credito - 1;
	int nuovo_credito = 0;
	Slot *head = NULL;
	Slot* nuovo = NULL;
	int x = 0;
	static int seed_inizializzato = 0;

	/* Inizializzazione del generatore pseudo-casuale una sola volta. */
	if (seed_inizializzato == 0) {
		srand(12345);
		seed_inizializzato = 1;
	}

	/* Estrae 4 simboli, li salva in lista e li stampa a schermo. */
	for(int i = 0; i < 4; i++){
		x = 1 + rand()%4;
		nuovo = crea_nodo(x);
		if (nuovo == NULL) {
			printf("MEMORIA INSUFFICIENTE\n");
			while (head != NULL) {
				Slot *tmp = head;
				head = head->next;
				free(tmp);
			}
			return credito;
		}
		aggiungi_alla_lista(&head, nuovo);
		if(x == 4){
			printf("X");
		}
		if(x == 3){
			printf("C");
		}
		if(x == 2){
			printf("B");
		}
		if(x == 1){
			printf("A");
		}
	}
	printf("\n");
	nuovo_credito = calcola_punteggio(head, credito);

	/* Deallocazione: libera la memoria dei nodi prima di uscire dalla funzione. */
	while (head != NULL) {
		Slot *tmp = head;
		head = head->next;
		free(tmp);
	}

	return nuovo_credito;
}

