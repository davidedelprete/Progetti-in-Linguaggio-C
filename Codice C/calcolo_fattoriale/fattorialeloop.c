#include <stdio.h>

/* Programma principale: calcola il fattoriale con un ciclo. */
int main(void) {
	/* Dichiarazione variabili:
	   - number: numero inserito dall'utente
	   - i: contatore del ciclo
	   - fact: risultato del fattoriale */
	int i, number;
	long long fact = 1;

	/* Richiesta dell'input all'utente. */
	printf("Enter a number: ");
	if (scanf("%d", &number) != 1) {
		/* Gestione input non valido (non intero). */
		printf("Input non valido.\n");
		return 1;
	}

	/* Verifica che il numero sia non negativo. */
	if (number < 0) {
		printf("Il fattoriale non e' definito per numeri negativi.\n");
		return 1;
	}

	/* Calcolo del fattoriale tramite ciclo for:
	   n! = 1 * 2 * ... * n */
	for(i = 1; i <= number; i++) {
		fact = fact*i;
	}

	/* Stampa del risultato finale. */
	printf("Factorial of %d is %lld\n", number, fact);
	return 0;
}
