#include "tail.h"

					/*funzione crea lista*/
int crea_lista (int num, list* puntatori) {
	struct nodo* new_head = NULL; //creiamo un nuovo nodo
	new_head = (struct nodo*) malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo uno se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nodo
	new_head->next = puntatori->head; //facciamo puntare il nuovo nodo a NULL in quanto è il primo ma anche l'ultimo
	puntatori->head = new_head; //head punterà al nuovo nodo
	puntatori->tail = new_head; //tail punterà al nuovo nodo
	return 0; 
}
					/*funzione inserimento in testa*/
int inserimento_in_testa (int num, list* puntatori) {
	struct nodo* new_head = NULL; //creiamo un nuovo nodo
	new_head = (struct nodo*) malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo uno se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nuovo nodo
	new_head->next = puntatori->head; //il nuovo nodo dovrà puntare al precedente primo nodo
	puntatori->head = new_head; //head dovrà puntare al nuovo nodo
	return 0;
}
					/*funzione inserimento in coda*/
int inserimento_in_coda (int num, list* puntatori) {
	struct nodo* new_head = NULL; //creiamo un nuovo nodo
	new_head = (struct nodo*) malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo uno se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nuovo nodo
	new_head->next = NULL; //facciamo puntare il nuovo nodo a NULL
	struct nodo* temp = puntatori->tail; //creiamo un puntatore d'appoggio e lo facciamo coincidere con l'ultimo nodo
	temp->next=new_head; //facciamo puntare p al nuovo nodo
	puntatori->tail = new_head; //facciamo puntare tail al nuovo nodo
}
					/*funzione stampa*/
void stampa (list puntatori) {
	if (puntatori.head == NULL) { //Verifica se la testa punta a NULL
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
	while (puntatori.head != NULL) { //cicla finchè non si arriva alla fine
		if (puntatori.head->data == num) {
			return 1; //torniamo 1 se num è presente nella lista
		}
		puntatori.head = puntatori.head->next; //scorre avanti
	}
	return 0; //ritorna 0 se num non è nella lista
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
	struct nodo* forward_head = puntatori->head; //primo puntatore d'appoggio
        struct nodo* back_head = puntatori->head; //secondo puntatore d'appoggio
        while ((forward_head!=NULL)&&(forward_head->data!=num)) { //cicla finchè non si arriva alla fine o si trova il numero da eliminare
                back_head = forward_head; //il secondo puntatore raggiunge il primo
                forward_head = forward_head->next; //il primo passa avanti
        }
        if (forward_head == NULL) {
                return 1; //ritorna 1 se l'elemento non è stato trovato
        }
        if (forward_head==puntatori->head) {
                puntatori->head=puntatori->head->next; //se l'elemento da eliminare è il primo sposta head sul secondo
        }
        else {
                back_head->next=forward_head->next; //aggancia il nodo precedente a quello da eliminare al successivo
        }
	free(forward_head); //liberiamo la memoria del nodo eliminato
	forward_head = puntatori->head; //riportiamo il primo puntatore d'appoggio sul primo nodo
	back_head = puntatori->head;  //riportiamo il secondo puntatore d'appoggio sul primo nodo
        struct nodo* new_head; //nuovo nodo
        new_head = (struct nodo*)malloc(sizeof(struct nodo));
        if (new_head == NULL) {
                return 2; //torniamo 2 se il sistema non da la memoria
        }
        new_head->data = new_num; //popoliamo il nuovo nodo
        while ((forward_head!=NULL)&&((forward_head->data)<(new_head->data))) { //cicla finchè non si arriva alla fine o finchè non si trova il posto dove inserire il dato
                back_head = forward_head; //il secondo puntatore raggiunge il primo
                forward_head = forward_head->next; //il primo va avanti
        }
        if (forward_head == puntatori->head) { //verifica se l'inserimento avviene in testa
                new_head->next = puntatori->head;
                puntatori->head = new_head;
                return 0;
        }
        back_head->next=new_head;
        new_head->next=forward_head;
        if (forward_head==NULL) {
                puntatori->tail = new_head; //se l'inserimento avviene in coda colleghiamo tail
        }
        return 0;
}
					/*funzione inserimento ordinato*/
int inserimento_ordinato (int num, list* puntatori) {
	struct nodo* forward_head = puntatori->head; //primo puntatore d'appoggio
	struct nodo* back_head = puntatori->head; //secondo puntatore d'appoggio
	struct nodo* new_head; //nuovo nodo
	new_head = (struct nodo*)malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo 1 se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nuovo nodo
	while ((forward_head!=NULL)&&((forward_head->data)<(new_head->data))) { //cicla finchè non si arriva alla fine o finchè non si trova il posto dove inserire il dato
		back_head = forward_head; //il secondo puntatore raggiunge il primo
		forward_head = forward_head->next; //il primo va avanti
	}
	if (forward_head == puntatori->head) { //verifica se l'inserimento avviene in testa
		new_head->next = puntatori->head;
		puntatori->head = new_head;
		return 0;
	}
	back_head->next=new_head;
	new_head->next=forward_head;
	if (forward_head==NULL) {
		puntatori->tail = new_head; //se l'inserimento avviene in coda colleghiamo tail
	}
	return 0;
}
					/*funzione elimina*/
int elimina (int num, list* puntatori) {
	struct nodo* forward_head = puntatori->head; //primo puntatore d'appoggio
	struct nodo* back_head = puntatori->head; //secondo puntatore d'appoggio
	while ((forward_head!=NULL)&&(forward_head->data!=num)) { //cicla finchè non si arriva alla fine o si trova il numero da eliminare
		back_head = forward_head; //il secondo puntatore raggiunge il primo
		forward_head = forward_head->next; //il primo passa avanti
	}
	if (forward_head == NULL) {
		return 1; //ritorna 1 se l'elemento non è stato trovato
	}
	if (forward_head==puntatori->head) {
		puntatori->head=puntatori->head->next; //se l'elemento da eliminare è il primo sposta head sul secondo
	}
	else {
		back_head->next=forward_head->next; //aggancia il nodo precedente a quello da eliminare al successivo
	}
	free(forward_head); //liberiamo lo spazio del nodo eliminato
	return 0;
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
int accesso_in_n (int num, list puntatori, int **punt) {
	while (puntatori.head!=NULL) { //scorre fino alla fine
		if (puntatori.head->data == num) { //verifica se si trova l'elemento
			*punt = &(puntatori.head->data); //ritorna il puntatore a quell'elemento
			return 0;
		}
		puntatori.head = puntatori.head->next; //scorre avanti
	}
	return 1; //tornaimo NULL se l'elemento non è stato trovato
}
