#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

/* Libera la memoria della lista concatenata creata durante il programma. */
static void free_list(struct account *head) {
    struct account *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    int choice;
    struct account *head = NULL;
    struct account *tail = NULL;

    /* Sezione 1: messaggio iniziale e menu operazioni. */
    printf("Welcome in PlugYourCount!\n");
    printf("Scegli un'operazione:\n");
    printf("1) Salva movimenti economici\n");
    printf("2) Analizza situazione economica\n");
    printf("3) Prenota un meeting urgente\n");
    printf("4) Lascia una recensione\n");
    printf("Scelta: ");

    if (scanf("%d", &choice) != 1) {
        printf("Scelta non valida.\n");
        return 1;
    }

    /* Sezione 2: in base alla scelta, esegue il blocco relativo. */
    switch (choice) {
        case 1: {
            int i;
            int count;

            /* Sezione 2.1: acquisisce quanti movimenti inserire. */
            printf("Quanti movimenti vuoi inserire? ");
            if (scanf("%d", &count) != 1 || count <= 0) {
                printf("Numero movimenti non valido.\n");
                return 1;
            }

            /* Sezione 2.2: costruisce la lista con mese e saldo per ogni movimento. */
            for (i = 0; i < count; i++) {
                struct account *node = (struct account *)malloc(sizeof(struct account));
                if (node == NULL) {
                    printf("Errore allocazione memoria.\n");
                    free_list(head);
                    return 1;
                }

                printf("Movimento %d - mese (1-12): ", i + 1);
                if (scanf("%d", &node->month_description) != 1 ||
                    node->month_description < 1 || node->month_description > 12) {
                    printf("Mese non valido.\n");
                    free(node);
                    free_list(head);
                    return 1;
                }

                printf("Movimento %d - saldo (positivo o negativo): ", i + 1);
                node->balance = numberreader();
                node->next = NULL;

                if (head == NULL) {
                    head = node;
                    tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
            }

            /* Sezione 2.3: salva tutti i nodi nel file CSV. */
            if (saveinfos(head) == 0) {
                printf("Movimenti salvati correttamente.\n");
            }
            break;
        }

        case 2:
            /* Sezione 2.4: analizza i dati presenti nel CSV. */
            analyse();
            break;

        case 3:
            /* Sezione 2.5: prenotazione appuntamento. */
            urgentmeeting();
            break;

        case 4:
            /* Sezione 2.6: acquisizione recensione utente. */
            leavereview();
            break;

        default:
            printf("Opzione non valida.\n");
            break;
    }

    /* Sezione 3: cleanup finale e uscita dal programma. */
    free_list(head);
    printf("Grazie per aver usato PlugYourCount.\n");

    return 0;
}
