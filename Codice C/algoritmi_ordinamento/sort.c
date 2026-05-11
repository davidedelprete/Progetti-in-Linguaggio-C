#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* ============================================================================
 * Funzione di supporto: stampa lo stato dell'array a ogni passo.
 * Serve per capire come evolve l'ordinamento.
 * ============================================================================ */
static void stampa_step_algoritmo(int *array, int len, int step, int index) {
	int i;
	printf("Step %d\n", step);

	for(i = 0; i < len; i++) {
		if(i == index) {
			/* Evidenzia l'indice in cui e' stato inserito current. */
			printf("\t[%d]", array[i]);
		} else {
			printf("\t%d", array[i]);
		}
	}
	printf("\n");
}

/* ============================================================================
 * Insertion Sort
 * Inserisce ogni elemento nella posizione corretta della parte gia' ordinata.
 * ============================================================================ */
void insertion_sort(int *array, int len) {
	int i, j, current;

	for(i = 1; i < len; i++) {
		j = i;
		current = array[i];
		while((j > 0) && (array[j - 1] > current)) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = current;
		stampa_step_algoritmo(array, len, i, j);
	}
}

/* ============================================================================
 * Buffer temporaneo usato da Merge Sort durante la fusione.
 * ============================================================================ */
static int *tmp_array;

/* ============================================================================
 * Unisce due sotto-array gia' ordinati:
 * - sinistra: [left ... middle1]
 * - destra:   [middle2 ... right]
 * ============================================================================ */
static void merge_blocchi(int *array, int left, int middle1, int middle2, int right) {
	int left_idx = left;
	int right_idx = middle2;
	int tmp_idx = left;
	int i;

	while((left_idx <= middle1) && (right_idx <= right)) {
		if(array[left_idx] <= array[right_idx]) {
			tmp_array[tmp_idx++] = array[left_idx++];
		} else {
			tmp_array[tmp_idx++] = array[right_idx++];
		}
	}

	while(left_idx <= middle1) {
		tmp_array[tmp_idx++] = array[left_idx++];
	}

	while(right_idx <= right) {
		tmp_array[tmp_idx++] = array[right_idx++];
	}

	for(i = left; i <= right; i++) {
		array[i] = tmp_array[i];
	}
}

/* ============================================================================
 * Divide ricorsivamente l'array e poi richiama merge_blocchi.
 * In questo modo otteniamo l'array finale ordinato.
 * ============================================================================ */
static void ordina_sottoarray(int *array, int low, int high) {
	int middle1;
	int middle2;

	if((high - low) >= 1) {
		middle1 = (low + high) / 2;
		middle2 = middle1 + 1;

		ordina_sottoarray(array, low, middle1);
		ordina_sottoarray(array, middle2, high);
		merge_blocchi(array, low, middle1, middle2, high);
	}
}

/* ============================================================================
 * Merge Sort (funzione pubblica)
 * Alloca il buffer, ordina l'array e libera la memoria temporanea.
 * ============================================================================ */
void merge_sort(int *array, int len) {
	if(len <= 1) {
		return;
	}

	tmp_array = malloc(sizeof(int) * len);
	if(tmp_array == NULL) {
		fprintf(stderr, "Errore: memoria non disponibile per merge_sort.\n");
		return;
	}

	ordina_sottoarray(array, 0, len - 1);
	free(tmp_array);
	tmp_array = NULL;
}





