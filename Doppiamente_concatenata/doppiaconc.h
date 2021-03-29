#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int data;
	struct nodo* next;
	struct nodo* prec;
};

struct puntatori {
	struct nodo* head;
	struct nodo* tail;
};

typedef struct puntatori list;

int crea_lista (int num, list* puntatori);

int inserimento_in_testa (int num, list* puntatori);

int inserimento_in_coda (int num, list* puntatori);

void stampa (list puntatori);

int esiste (int num, list puntatori);

int modifica (int num, int new_num, list* puntatori);

int modifica_e_ordina (int num, int new_num, list* puntatori);

int inserimento_ordinato (int num, list* puntatori);

int elimina (int num, list* puntatori);

int count (list puntatori);

int accesso_in_n (int num, list puntatori, int **punt);
