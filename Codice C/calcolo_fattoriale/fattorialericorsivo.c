#include <stdio.h>

/* Funzione ricorsiva che calcola il fattoriale.
   Caso base: 0! = 1
   Passo ricorsivo: n! = n * (n-1)! */
long long factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return (long long)n * factorial(n - 1);
}

/* Programma principale: legge un numero e usa la funzione ricorsiva. */
int main(void) {
	/* Dichiarazione variabili:
	   - number: numero inserito dall'utente
	   - fact: risultato del fattoriale */
	int number;
	long long fact;

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

	/* Calcolo del fattoriale tramite ricorsione. */
	fact = factorial(number);

	/* Stampa del risultato finale. */
	printf("Factorial of %d is %lld\n", number, fact);
	return 0;
}
