#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coda.h"

int main(void) {
    int scelta;
    int len;
    int id = 1;
    char testo[1500];

    Queue1 *head1 = NULL;
    Queue1 *tail1 = NULL;
    Queue2 *head2 = NULL;
    Queue2 *tail2 = NULL;

    printf("Benvenuto nel sistema di gestione packet.\n");

    /* Ciclo principale del menu: continua finche' l'utente non sceglie di uscire. */
    do {
        printf("\nMenu:\n");
        printf("1) Aggiungi un pacchetto\n");
        printf("2) Stampa stato delle code\n");
        printf("3) Svuota entrambe le code\n");
        printf("4) Stampa lunghezza totale dei pacchetti\n");
        printf("5) Esci\n");
        printf("Scelta: ");

        if (scanf("%d", &scelta) != 1) {
            printf("Input non valido.\n");
            return 1;
        }

        switch (scelta) {
            case 1: {
                /* Acquisizione dati del nuovo pacchetto e instradamento nella coda corretta. */
                printf("Inserire la lunghezza del pacchetto (1..1500): ");
                if (scanf("%d", &len) != 1 || len <= 0 || len > 1500) {
                    printf("Lunghezza non valida.\n");
                    break;
                }

                printf("Inserire una stringa dati (senza spazi): ");
                if (scanf("%1499s", testo) != 1) {
                    printf("Errore lettura dati.\n");
                    break;
                }

                if (len <= 750) {
                    Queue1 *nodo1 = (Queue1 *)malloc(sizeof(Queue1));
                    if (nodo1 == NULL) {
                        printf("Memoria insufficiente.\n");
                        break;
                    }
                    strncpy(nodo1->data, testo, sizeof(nodo1->data) - 1);
                    nodo1->data[sizeof(nodo1->data) - 1] = '\0';
                    nodo1->len = len;
                    nodo1->id = id++;
                    nodo1->next = NULL;
                    aggiungi_packet1(&head1, &tail1, nodo1);
                    printf("Pacchetto inserito in coda 1.\n");
                } else {
                    Queue2 *nodo2 = (Queue2 *)malloc(sizeof(Queue2));
                    if (nodo2 == NULL) {
                        printf("Memoria insufficiente.\n");
                        break;
                    }
                    strncpy(nodo2->data, testo, sizeof(nodo2->data) - 1);
                    nodo2->data[sizeof(nodo2->data) - 1] = '\0';
                    nodo2->len = len;
                    nodo2->id = id++;
                    nodo2->next = NULL;
                    aggiungi_packet2(&head2, &tail2, nodo2);
                    printf("Pacchetto inserito in coda 2.\n");
                }
                break;
            }

            case 2:
                /* Stampa lo stato corrente di entrambe le code FIFO. */
                printf("\n-- Stato coda 1 --\n");
                stato_coda1(head1);
                printf("\n-- Stato coda 2 --\n");
                stato_coda2(head2);
                break;

            case 3:
                /* Svuota entrambe le code e libera tutta la memoria allocata. */
                svuota_coda1(&head1, &tail1);
                svuota_coda2(&head2, &tail2);
                printf("Code svuotate.\n");
                break;

            case 4:
                /* Calcola e mostra il totale delle lunghezze nelle due code. */
                printf("Totale lunghezze coda 1: %d\n", lunghezza_totale_coda1(head1));
                printf("Totale lunghezze coda 2: %d\n", lunghezza_totale_coda2(head2));
                printf("Totale complessivo: %d\n",
                       lunghezza_totale_coda1(head1) + lunghezza_totale_coda2(head2));
                break;

            case 5:
                break;

            default:
                printf("Scelta non valida.\n");
                break;
        }

    } while (scelta != 5);

    /* Cleanup finale in uscita: protegge da leak anche se le code non erano state svuotate. */
    svuota_coda1(&head1, &tail1);
    svuota_coda2(&head2, &tail2);
    printf("Chiusura programma.\n");
    return 0;
}

