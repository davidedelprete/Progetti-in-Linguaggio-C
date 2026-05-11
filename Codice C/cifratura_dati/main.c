#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key.h"

#define SIZE 100
#define FILE_NAME "Secret.txt"

/* Pulisce il buffer di input dopo scanf per evitare letture sporche. */
static void clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

/* Legge una riga completa e rimuove il carattere '\n' finale. */
static int read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) {
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

int main(void) {
    /* Variabili principali per menu, chiave, messaggio e file. */
    int choice = 0;
    unsigned int seed = 0;
    int generated_key = 0;
    unsigned char key_byte = 0;
    char message[SIZE] = {0};
    unsigned char encrypted[SIZE] = {0};
    char decrypted[SIZE] = {0};
    size_t msg_len = 0;
    size_t enc_len = 0;
    FILE *fp = NULL;

    /* Ciclo principale del menu: gestisce tutte le operazioni utente. */
    while (1) {
        printf("1 Inserisci chiave per il seed\n");
        printf("2 Inserire stringa\n");
        printf("3 Cifratura messaggio\n");
        printf("4 Salva su file\n");
        printf("5 Recupera messaggio da file\n");
        printf("6 Esci\n");
        printf("Scelta: ");

        if (scanf("%d", &choice) != 1) {
            printf("[ERRORE] Inserire un numero valido.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                /* Acquisisce il seed e calcola la chiave usata per XOR. */
                printf("Inserisci una chiave intera: ");
                if (scanf("%u", &seed) != 1) {
                    printf("[ERRORE] Seed non valido.\n");
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();
                generated_key = key(seed);
                key_byte = (unsigned char)(generated_key & 0xFF);
                printf("Valore generato: %d (byte XOR: %u)\n", generated_key, key_byte);
                break;

            case 2:
                /* Legge il messaggio in chiaro, inclusi eventuali spazi. */
                printf("Inserire una stringa: ");
                if (!read_line(message, sizeof(message))) {
                    printf("[ERRORE] Lettura stringa non riuscita.\n");
                    break;
                }
                msg_len = strlen(message);
                printf("Messaggio acquisito: %s\n", message);
                break;

            case 3:
                /* Cifra il messaggio con XOR e mostra il risultato in esadecimale. */
                if (msg_len == 0) {
                    printf("[ERRORE] Inserire prima una stringa (opzione 2).\n");
                    break;
                }

                enc_len = msg_len;
                for (size_t i = 0; i < enc_len; i++) {
                    encrypted[i] = (unsigned char)message[i] ^ key_byte;
                }

                printf("Messaggio cifrato (hex): ");
                for (size_t i = 0; i < enc_len; i++) {
                    printf("%02X", encrypted[i]);
                }
                printf("\n");
                break;

            case 4:
                /* Salva su file il testo cifrato in formato esadecimale. */
                if (enc_len == 0) {
                    printf("[ERRORE] Eseguire prima la cifratura (opzione 3).\n");
                    break;
                }

                fp = fopen(FILE_NAME, "w");
                if (fp == NULL) {
                    printf("[ERRORE] Non sono riuscito ad aprire il file in scrittura.\n");
                    break;
                }

                for (size_t i = 0; i < enc_len; i++) {
                    fprintf(fp, "%02X", encrypted[i]);
                }
                fclose(fp);
                fp = NULL;
                printf("Salvataggio avvenuto con successo\n");
                break;

            case 5: {
                /* Legge da file, converte da esadecimale e decifra con XOR. */
                char file_hex[SIZE * 2 + 1] = {0};
                size_t hex_len = 0;

                fp = fopen(FILE_NAME, "r");
                if (fp == NULL) {
                    printf("[ERRORE] Non sono riuscito ad aprire il file.\n");
                    break;
                }

                if (fgets(file_hex, sizeof(file_hex), fp) == NULL) {
                    fclose(fp);
                    fp = NULL;
                    printf("[ERRORE] File vuoto o lettura fallita.\n");
                    break;
                }
                fclose(fp);
                fp = NULL;

                file_hex[strcspn(file_hex, "\n")] = '\0';
                hex_len = strlen(file_hex);
                if (hex_len == 0 || (hex_len % 2) != 0) {
                    printf("[ERRORE] Contenuto cifrato non valido.\n");
                    break;
                }

                enc_len = hex_len / 2;
                if (enc_len >= SIZE) {
                    printf("[ERRORE] Messaggio troppo lungo nel file.\n");
                    break;
                }

                for (size_t i = 0; i < enc_len; i++) {
                    unsigned int value = 0;
                    if (sscanf(file_hex + (i * 2), "%2X", &value) != 1) {
                        printf("[ERRORE] Formato hex non valido nel file.\n");
                        enc_len = 0;
                        break;
                    }
                    encrypted[i] = (unsigned char)value;
                    decrypted[i] = (char)(encrypted[i] ^ key_byte);
                }

                if (enc_len == 0) {
                    break;
                }

                decrypted[enc_len] = '\0';
                printf("Messaggio decifrato: %s\n", decrypted);
                break;
            }

            case 6:
                /* Uscita ordinata dal programma. */
                printf("Uscita dal programma.\n");
                return 0;

            default:
                /* Gestisce una scelta menu non prevista. */
                printf("[ERRORE] Scelta non valida.\n");
                break;
        }
    }
}
