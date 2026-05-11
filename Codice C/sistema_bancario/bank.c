#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

/* Legge un numero reale non negativo da tastiera con validazione base. */
double numberreader(void) {
    char in[64];
    char *ptr_rest = NULL;
    double n;

    while (1) {
        if (scanf("%63s", in) != 1) {
            printf("[ERRORE] Impossibile leggere il numero.\n");
            continue;
        }

        n = strtod(in, &ptr_rest);
        if (in == ptr_rest || *ptr_rest != '\0') {
            printf("[ERRORE] Inserisci solo numeri validi.\n");
            continue;
        }

        return n;
    }
}

/* Salva in append la lista di movimenti nel file CSV. */
int saveinfos(const struct account *head) {
    FILE *fp;
    const struct account *p = head;

    fp = fopen("bank-account.csv", "a");
    if (fp == NULL) {
        printf("Errore in apertura del file bank-account.csv\n");
        return -1;
    }

    while (p != NULL) {
        fprintf(fp, "%d,%.2f\n", p->month_description, p->balance);
        p = p->next;
    }

    fclose(fp);
    return 0;
}

/* Estrae il campo richiesto da una riga CSV "mese,bilancio". */
double get_field(const char *buf, int field_n) {
    int i;
    char *tok = NULL;
    char s[256];

    strncpy(s, buf, sizeof(s) - 1);
    s[sizeof(s) - 1] = '\0';

    tok = strtok(s, ",");
    for (i = 0; i < field_n && tok != NULL; i++) {
        tok = strtok(NULL, ",");
    }

    if (tok == NULL) {
        return 0.0;
    }

    return strtod(tok, NULL);
}

/* Legge il file CSV, calcola il totale e stampa una valutazione semplice. */
void analyse(void) {
    FILE *fp;
    char buf[256];
    int rows = 0;
    double total = 0.0;

    fp = fopen("bank-account.csv", "r");
    if (fp == NULL) {
        printf("Nessun dato disponibile da analizzare.\n");
        return;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        total += get_field(buf, 1);
        rows++;
    }

    fclose(fp);

    if (rows == 0) {
        printf("Il file e' vuoto, nessuna analisi da mostrare.\n");
        return;
    }

    printf("Movimenti analizzati: %d\n", rows);
    printf("Saldo totale: %.2f\n", total);

    if (total > 0.0) {
        printf("Situazione: SURPLUS. Ottima gestione!\n");
    } else if (total < 0.0) {
        printf("Situazione: DEFICIT. Consigliato ridurre le spese.\n");
    } else {
        printf("Situazione: PAREGGIO.\n");
    }
}

/* Prenotazione semplice di un appuntamento con controlli minimi sui range. */
void urgentmeeting(void) {
    int month;
    int day;
    int hour;

    printf("Inserisci il mese (1-12): ");
    if (scanf("%d", &month) != 1 || month < 1 || month > 12) {
        printf("Mese non valido.\n");
        return;
    }

    printf("Inserisci il giorno (1-31): ");
    if (scanf("%d", &day) != 1 || day < 1 || day > 31) {
        printf("Giorno non valido.\n");
        return;
    }

    printf("Inserisci l'ora (8-20): ");
    if (scanf("%d", &hour) != 1 || hour < 8 || hour > 20) {
        printf("Ora non valida.\n");
        return;
    }

    printf("Richiesta appuntamento salvata: %02d/%02d alle %02d:00\n", day, month, hour);
}

/* Acquisisce una recensione testuale (anche con spazi) e la stampa a schermo. */
void leavereview(void) {
    char review[256];
    int c;

    printf("Lascia una recensione: ");

    /* Pulisce eventuale '\n' rimasto nel buffer prima di fgets. */
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    if (fgets(review, sizeof(review), stdin) == NULL) {
        printf("Recensione non acquisita.\n");
        return;
    }

    review[strcspn(review, "\n")] = '\0';
    printf("Grazie per la recensione: \"%s\"\n", review);
}

