#include <stdio.h>
#include <stdlib.h>
#include "coda.h"

/* Inserisce un nodo in fondo alla coda 1 (politica FIFO). */
void aggiungi_packet1(Queue1 **head, Queue1 **tail, Queue1 *element) {
    if (element == NULL) {
        return;
    }

    element->next = NULL;
    if (*head == NULL) {
        *head = element;
    } else {
        (*tail)->next = element;
    }
    *tail = element;
}

/* Inserisce un nodo in fondo alla coda 2 (politica FIFO). */
void aggiungi_packet2(Queue2 **head, Queue2 **tail, Queue2 *element) {
    if (element == NULL) {
        return;
    }

    element->next = NULL;
    if (*head == NULL) {
        *head = element;
    } else {
        (*tail)->next = element;
    }
    *tail = element;
}

/* Estrae il nodo in testa dalla coda 1 senza liberarlo. */
Queue1 *rimuovi_coda1(Queue1 **head, Queue1 **tail) {
    Queue1 *ret;

    if (*head == NULL) {
        return NULL;
    }

    ret = *head;
    *head = ret->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    ret->next = NULL;
    return ret;
}

/* Estrae il nodo in testa dalla coda 2 senza liberarlo. */
Queue2 *rimuovi_coda2(Queue2 **head, Queue2 **tail) {
    Queue2 *ret;

    if (*head == NULL) {
        return NULL;
    }

    ret = *head;
    *head = ret->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    ret->next = NULL;
    return ret;
}

/* Stampa tutto il contenuto della coda 1 in ordine di arrivo. */
void stato_coda1(Queue1 *head) {
    Queue1 *p = head;
    if (p == NULL) {
        printf("Coda 1 vuota.\n");
        return;
    }

    while (p != NULL) {
        printf("[ID=%d] LEN=%d DATA=%s\n", p->id, p->len, p->data);
        p = p->next;
    }
}

/* Stampa tutto il contenuto della coda 2 in ordine di arrivo. */
void stato_coda2(Queue2 *head) {
    Queue2 *p = head;
    if (p == NULL) {
        printf("Coda 2 vuota.\n");
        return;
    }

    while (p != NULL) {
        printf("[ID=%d] LEN=%d DATA=%s\n", p->id, p->len, p->data);
        p = p->next;
    }
}

/* Libera tutti i nodi della coda 1 per evitare memory leak. */
void svuota_coda1(Queue1 **head, Queue1 **tail) {
    Queue1 *el;
    do {
        el = rimuovi_coda1(head, tail);
        if (el != NULL) {
            free(el);
        }
    } while (el != NULL);
}

/* Libera tutti i nodi della coda 2 per evitare memory leak. */
void svuota_coda2(Queue2 **head, Queue2 **tail) {
    Queue2 *el;
    do {
        el = rimuovi_coda2(head, tail);
        if (el != NULL) {
            free(el);
        }
    } while (el != NULL);
}

/* Somma la lunghezza di tutti i pacchetti presenti in coda 1. */
int lunghezza_totale_coda1(Queue1 *head) {
    int totale = 0;
    Queue1 *p = head;
    while (p != NULL) {
        totale += p->len;
        p = p->next;
    }
    return totale;
}

/* Somma la lunghezza di tutti i pacchetti presenti in coda 2. */
int lunghezza_totale_coda2(Queue2 *head) {
    int totale = 0;
    Queue2 *p = head;
    while (p != NULL) {
        totale += p->len;
        p = p->next;
    }
    return totale;
}

