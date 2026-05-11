#ifndef LISTA_H
#define LISTA_H

/* =========================================================
  Definizione della struttura dati per una voce di spesa.
  Ogni nodo contiene descrizione, costo e puntatore al prossimo.
  ========================================================= */
struct spesa {
	char descrizione[50];
	double costo;
	struct spesa *next;
};

/* =========================================================
  Prototipi delle funzioni usate nel programma.
  ========================================================= */
void add_to_linked_list(struct spesa **head, struct spesa *elem);
double legginumero(void);
unsigned int gestiscimenu(void);
struct spesa *creanuovo(void);
void gestisciaggiunta(struct spesa **head);
void gestiscirimozione(struct spesa **head);
void gestiscistatistiche(struct spesa *head);
int gestiscisalva(const struct spesa *head);

#endif


