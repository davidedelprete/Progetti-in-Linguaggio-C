#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* =========================================================
   Funzione principale:
   - inizializza la lista
   - mostra il menu in ciclo
   - chiama la funzione corretta in base alla scelta
   ========================================================= */
int main(void) {
	struct spesa *head = NULL;
	struct spesa *tmp = NULL;

	while(1) {
		unsigned int num = gestiscimenu();

		/* =====================================================
		   Smistamento delle operazioni richieste dall'utente.
		   ===================================================== */
		switch(num){
			case 1: 
				gestisciaggiunta(&head);
				break;
			case 2: 
				gestiscirimozione(&head);
				break;
			case 3: 
				gestiscistatistiche(head);
				break;
			case 4:
				if (gestiscisalva(head) == 0) {
					printf("Dati salvati su file lista-spese.csv\n");
				}
				break;
			case 5:
				/* =============================================
				   Liberazione della memoria prima di uscire.
				   ============================================= */
				while(head != NULL) {
					tmp = head;
					head = head -> next;
					free(tmp);
				}
				return(EXIT_SUCCESS);
			default:
				printf("[ERRORE] il numero inserito non è valido\n");
		}
		printf("\n");
	}
}
