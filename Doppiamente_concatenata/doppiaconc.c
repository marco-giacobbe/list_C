#include "doppiaconc.h"
					/*funzione crea lista*/
int crea_lista (int num, list* puntatori) {
	struct nodo* new_head = NULL; //creiamo un nuovo nodo
	new_head = (struct nodo*) malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo uno se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nodo
	new_head->prec = puntatori->head; //puntatori->head; //facciamo puntare prec a NULL in quanto è il primo nodo
	new_head->next = puntatori->head; //facciamo puntare next a NULL in quanto è anche l'ultimo
	puntatori->head = new_head; //head punterà al nuovo nodo
	puntatori->tail = new_head; //tail punterà al nuovo nodo
	return 0;
}
					/*funzione inserimento in testa*/
int inserimento_in_testa (int num, list* puntatori) {
	struct nodo* new_head = NULL; //creiamo un nuovo nodo
	new_head = (struct nodo* ) malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo uno se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nuovo nodo
	puntatori->head->prec = new_head; //il prec del vecchio primo nodo dovrà puntare al nuovo nodo
	new_head->next = puntatori->head; //il nuovo nodo dovrà puntare al vecchio primo nodo
	new_head->prec = NULL; //il prec del nuovo nodo dovrà puntare a NULL in quanto primo
	puntatori->head = new_head; //agganciamo head al primo nodo
}
					/*funzione inserimento in coda*/
int inserimento_in_coda (int num, list* puntatori) {
	struct nodo* new_head = NULL; //creiamo un nuovo nodo;
	new_head = (struct nodo* ) malloc(sizeof(struct nodo));
        if (new_head == NULL) {
                return 1; //torniamo uno se il sistema non da la memoria
        }
	new_head->data = num; //popoliamo il nuovo nodo
	puntatori->tail->next = new_head; //il vecchio ultimo nodo dovrà puntare al nuovo nodo
	new_head->prec = puntatori->tail; //il prec del nuovo nodo dovrà puntare al vecchio ultimo nodo
	new_head->next = NULL; //il nuovo nodo dovrà puntare a NULL in quanto ultimo
	puntatori->tail = new_head; //tail dovrà puntare all'ultimo nodo

}
					/*funzione stampa*/
void stampa (list puntatori) {
	if (puntatori.head == NULL) { //verifica se la testa punta a NULL
		printf("La lista è vuota");
		return;
	}
	while (puntatori.head != NULL) { //cicla finchè non si arriva alla fine
		printf("%d ", puntatori.head->data);
		puntatori.head = puntatori.head->next; //scorre avanti
	}
	printf("\n");
}
					/*funzione esiste*/
int esiste (int num, list puntatori) {
	while (puntatori.head != NULL) { //cicla fino alla fine 
		if (puntatori.head->data == num) { 
			return 1; //torniamo 1 se esiste
		}
		puntatori.head = puntatori.head->next;

	}
	return 0; //torniamo 0 se non esiste
}
					/*funzione modifica*/
int modifica (int num, int new_num, list* puntatori) {
	struct nodo* temp = puntatori->head; //creiamo un puntatore d'appoggio e lo facciamo coincidere con il primo nodo
        while (temp!=NULL) { //cicla fino alla fine
                if (temp->data == num) { //verifica se il nodo contiene il numero da modificare
                        temp->data = new_num; //se si lo sostituisce con il nuovo numero
                        return 0;
                }
                temp=temp->next; //scorre al nodo successivo
        }
        return 1; //ritorna 1 se il numero da modificare non è presente nella lista
}
					/*funzione modifica_e_ordina*/
int modifica_e_ordina (int num, int new_num, list* puntatori) {
	struct nodo* temp = puntatori->head;
        while ((temp!=NULL)&&(temp->data!=num)) { //cicla finchè non si arriva alla fine o si trova l'elemento
                temp = temp->next; //temp scorer avanti
        }
        if (temp==NULL) {
                return 1; //torniamo 1 se l'elemento non è stato trovato
        }
        struct nodo* elimina = temp; //creiamo un puntatore per tenere traccia dell'elemento da eliminare
        temp = temp->next; //temp avanza di una posizione
        temp->prec = elimina->prec; //colleghiamo il nodo successivo a quello eliminato al precedente
        temp = temp->prec; //spostiamo temp sul precedente
        temp->next = elimina->next; //colleghiamo il nodo precedente a quello eliminato al successivo
        free (elimina); //liberiamo lo spazio occupato dal nodo eliminato
	struct nodo* new_head; //nuovo nodo
        new_head = (struct nodo*)malloc(sizeof(struct nodo));
        if (new_head == NULL) {
                return 1; //torniamo 1 se il sistema non da la memoria
        }
        new_head->data = new_num; //popoliamo il nuovo nodo
        temp = puntatori->head; //puntatore d'appoggio
        while ((temp!=NULL)&&((temp->data)<(new_head->data))) {
                temp = temp->next; //il puntatore d'appoggio scorre avanti
        }
        new_head->prec = temp->prec; //prec del nuovo nodo dovrà puntare al suo precedente
        new_head->next = temp; //il nuovo nodo dovrà puntare al suo successivo
        temp->prec = new_head; //il prec del nodo successivo al nuovo dovrà puntare al nuovo
        temp = temp->prec;
        temp = temp->prec; //torniamo indietro di due posizioni
        temp->next = new_head; //il next del puntatore precedente al nuovo dovrà puntare al nuovo

}
					/*funzione inserimento ordinato*/
int inserimento_ordinato (int num, list* puntatori) {
	struct nodo* new_head; //nuovo nodo
        new_head = (struct nodo*)malloc(sizeof(struct nodo));
        if (new_head == NULL) {
                return 1; //torniamo 1 se il sistema non da la memoria
        }
        new_head->data = num; //popoliamo il nuovo nodo
	struct nodo* temp = puntatori->head; //puntatore d'appoggio
	while ((temp!=NULL)&&((temp->data)<(new_head->data))) {
		temp = temp->next; //il puntatore d'appoggio scorre avanti
	}
	new_head->prec = temp->prec; //prec del nuovo nodo dovrà puntare al suo precedente
	new_head->next = temp; //il nuovo nodo dovrà puntare al suo successivo
	temp->prec = new_head; //il prec del nodo successivo al nuovo dovrà puntare al nuovo
	temp = temp->prec;     
	temp = temp->prec; //torniamo indietro di due posizioni
	temp->next = new_head; //il next del puntatore precedente al nuovo dovrà puntare al nuovo

}
					/*funzione elimina*/
int elimina (int num, list* puntatori) {
	struct nodo* temp = puntatori->head;
	while ((temp!=NULL)&&(temp->data!=num)) { //cicla finchè non si arriva alla fine o si trova l'elemento
		temp = temp->next; //temp scorer avanti
	}
	if (temp==NULL) {
		return 1; //torniamo 1 se l'elemento non è stato trovato
	}
	struct nodo* elimina = temp; //creiamo un puntatore per tenere traccia dell'elemento da eliminare
	temp = temp->next; //temp avanza di una posizione
	temp->prec = elimina->prec; //colleghiamo il nodo successivo a quello eliminato al precedente
	temp = temp->prec; //spostiamo temp sul precedente
	temp->next = elimina->next; //colleghiamo il nodo precedente a quello eliminato al successivo
	free (elimina); //liberiamo lo spazio occupato dal nodo eliminato
}
					/*funzione count*/
int count (list puntatori) {
	int counter=0;
        while (puntatori.head!=NULL) { //cicla finchè non arriva alla fine
                puntatori.head = puntatori.head->next; //scorre avanti
                counter+=1; //incrementa il contatore
        }
        return counter; //ritorna il contatore

}
					/*accesso all'elemento N*/
int  accesso_in_n (int num, list puntatori, int **punt) {
	while (puntatori.head!=NULL) { //scorre fino alla fine
                if (puntatori.head->data == num) { //verifica se si trova l'elemento
                        *punt = &(puntatori.head->data); //ritorna il puntatore a quell'elemento
			return 0;
                }
                puntatori.head = puntatori.head->next; //scorre avanti
        }
        return 1; //tornaimo 1 se l'elemento non è stato trovato
}
