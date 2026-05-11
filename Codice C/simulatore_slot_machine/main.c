#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

/* Menu principale: mostra le opzioni disponibili e restituisce la scelta utente. */
static int menu(void) {
	int scelta = 0;
	printf("1 GIOCA\n");
	printf("2 INSERISCI CREDITO\n");
	printf("3 SALVA CREDITO SU FILE\n");
	printf("4 CARICA CREDITO DA FILE\n");
	printf("5 ESCI DAL GIOCO\n");
	printf("SCELTA DELL'UTENTE:");
	scelta = legginumero();
	return (int) scelta;
}

/* Flusso applicativo: gestisce input utente e richiama le funzioni principali del gioco. */
int main(void) {
	int credito;
	printf("BENVENUTO IN QUESTA SLOT MACHINE\n");
	printf("CONTROLLA IL CREDITO RESIDUO PRIMA DI GIOCARE\n");
	credito = 0;

	while(1) {
		int sceltamenu = menu();
		switch(sceltamenu) {
			case(1) :
				credito = gioca(credito);
				printf("IL CREDITO RESIDUO È: %d\n", credito);
				break;
			case(2) :
				printf("INSERISCI IL CREDITO DA AGGIUNGERE:\n");
				credito = legginumero();
				if (inserisci(credito) != 0) {
					printf("ERRORE NEL SALVATAGGIO DEL CREDITO.\n");
				}
				break;
			case(3) :
				if (inserisci(credito) == 0) {
					printf("CREDITO SALVATO CORRETTAMENTE.\n");
				}
				break;
			case(4) :
				if (recupera(&credito) == 0) {
					printf("CREDITO CARICATO: %d\n", credito);
				}
				break;
			case(5):
				exit(EXIT_SUCCESS);
			default:
				printf("SCELTA NON VALIDA, RIPROVA.\n");
				break;
		}
	}
}
