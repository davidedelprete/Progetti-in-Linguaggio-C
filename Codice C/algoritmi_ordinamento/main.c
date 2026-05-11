#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* ============================================================================
 * Funzione di utilita': stampa un array di interi su una riga.
 * ============================================================================ */
static void print_array(const int *array, int len) {
	int i;

	for(i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void) {
	/* =========================================================================
	 * Dati di partenza:
	 * usiamo due copie dello stesso array per confrontare i due algoritmi.
	 * ========================================================================= */
	int original[] = {5, 23, 56, 10, 9};
	int insertion_array[] = {5, 23, 56, 10, 9};
	int merge_array[] = {5, 23, 56, 10, 9};
	int len = (int)(sizeof(original) / sizeof(original[0]));

	/* =========================================================================
	 * Stampa dell'array iniziale.
	 * ========================================================================= */
	printf("Array iniziale:\n");
	print_array(original, len);

	/* =========================================================================
	 * Esecuzione Insertion Sort su una copia.
	 * ========================================================================= */
	printf("\nRisultato Insertion Sort:\n");
	insertion_sort(insertion_array, len);
	print_array(insertion_array, len);

	/* =========================================================================
	 * Esecuzione Merge Sort su un'altra copia.
	 * ========================================================================= */
	printf("\nRisultato Merge Sort:\n");
	merge_sort(merge_array, len);
	print_array(merge_array, len);

	return 0;
}
