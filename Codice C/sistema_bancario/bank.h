#ifndef BANK_H
#define BANK_H

/* Struttura base: rappresenta un singolo movimento economico mensile. */
struct account {
    int month_description;
    double balance;
    struct account *next;
};

/* Funzioni di utilita' e menu principale. */
double numberreader(void);
int saveinfos(const struct account *head);
double get_field(const char *buf, int field_n);
void analyse(void);
void urgentmeeting(void);
void leavereview(void);

#endif
