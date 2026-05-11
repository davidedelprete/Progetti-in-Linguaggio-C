#include <stdio.h>
#include "rubrica.h"

/* Programma principale: inizializza, inserisce, stampa e cerca contatti. */
int main(void) {
	struct rubrica mia_rubrica;
	const char *numero;

	/* Inizializza la struttura prima di usarla. */
	inizializza_rubrica(&mia_rubrica);

	/* Inserimento di alcuni contatti di esempio. */
	inserisci(&mia_rubrica, "pippo", "1234");
	inserisci(&mia_rubrica, "pluto", "5678");
	inserisci(&mia_rubrica, "paperino", "91011");

	/* Stampa della rubrica completa. */
	stampa_rubrica(&mia_rubrica);

	/* Ricerca del contatto "pippo" e stampa del risultato. */
	numero = cerca(&mia_rubrica, "pippo");
	if (numero != NULL) {
		printf("Cerco il telefono di pippo: %s\n", numero);
	} else {
		printf("Contatto non trovato\n");
	}

	return 0;
}
