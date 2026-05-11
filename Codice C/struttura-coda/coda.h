/* Header semplice per gestione di due code di pacchetti */

#ifndef CODA_H
#define CODA_H

typedef struct queue_node1 {
    char data[1500];
    int len;
    int id;
    struct queue_node1 *next;
} Queue1;

typedef struct queue_node2 {
    char data[1500];
    int len;
    int id;
    struct queue_node2 *next;
} Queue2;

void aggiungi_packet1(Queue1 **head, Queue1 **tail, Queue1 *element);
void aggiungi_packet2(Queue2 **head, Queue2 **tail, Queue2 *element);

Queue1 *rimuovi_coda1(Queue1 **head, Queue1 **tail);
Queue2 *rimuovi_coda2(Queue2 **head, Queue2 **tail);

void stato_coda1(Queue1 *head);
void stato_coda2(Queue2 *head);

void svuota_coda1(Queue1 **head, Queue1 **tail);
void svuota_coda2(Queue2 **head, Queue2 **tail);

int lunghezza_totale_coda1(Queue1 *head);
int lunghezza_totale_coda2(Queue2 *head);

#endif
