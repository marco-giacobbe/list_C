#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int data;
	struct nodo* next;
};
typedef struct nodo* list;

int crea_lista (int num,list* head);

int inserimento_in_testa (int num, list* head);

int inserimento_in_coda (int num, list* head);

void stampa (list head);

int esiste (int num, list head);

int modifica (int num, int new_num, list* head);

int modifica_e_ordina (int num, int new_num, list* head);

int inserimento_ordinato(int num,list* head);

int elimina (int num, list* head);

int count (list head);

int accesso_in_n (int num, list head, int **punt);
