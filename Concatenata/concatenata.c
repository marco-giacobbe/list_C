#include "concatenata.h"
					/*Funzione crea lista*/
int crea_lista (int num,list* head) {
	list new_head = NULL; //creiamo un nuovo nodo
	new_head = (list)malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo 1 se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nodo
	new_head->next = NULL; //essendo anche l'ultimo punterà a NULL
	*head = new_head; //aggangiamo la testa al nuovo nodo
	return 0;
}
					/*Funzione inserimento_in testa*/
int inserimento_in_testa (int num, list* head) {
	list new_head = NULL; //creiamo un nuovo nodo
	new_head = (list)malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //torniamo 1 se il sistema non da la memoria
	}
	new_head->data=num; //popoliamo il nuovo nodo
	new_head->next=*head; //il nuovo nodo punterà al vecchio primo nodo
	*head = new_head; //agganciamo la testa al nuovo nodo
	return 0;
}
					/*Funzione inseriment_in_coda*/
int inserimento_in_coda (int num, list* head) {
	list new_node = (list)malloc(sizeof(struct nodo)); //creiamo un nuovo nodo
	if (new_node == NULL) {
		return 1; //torniamo 1 se il sistema non da la memoria
	}
	new_node->data = num; //popoliamo il nuovo nodo
	new_node->next = NULL; //in quanto ultimo deve puntare a NULL
	if (head == NULL) { //verifica se la lista è vuota
		*head=new_node; //se è vuota aggancia la testa al nodo
		return 0;
	}
	else {
		list temp_head = *head; //creiamo un puntatore d'appoggio
		while (temp_head->next!=NULL) { //cicla finchè non arriva all'ultimo nodo
			temp_head = (temp_head)->next; //scorre avanti
		}
		temp_head->next = new_node; //facciamo puntare il vecchio ultimo nodo al nuovo
		return 0;
	}
}
					/*Funzione stampa*/
void stampa (list head) {
	if (head == NULL) { //verifica se la testa punta a NULL
		printf("La lista è vuota");
		return;
	}
	while (head != NULL) { //cicla finchè non si arriva alla fine
		printf("%d ", head->data);
		head = head->next; //scorre avanti
	}
	printf("\n");
}
					/*Funzione esiste*/
int esiste (int num, list head) {
	while (head != NULL) { //cicla finchè non si arriva alla fine
		if (head->data == num) {
			return 1; //torniamo 1 se num è presente nella lista
		}
		head = head->next; //scorre avanti
	}
	return 0;
}
					/*Funzione modifica*/
int modifica (int num, int new_num, list* head) {
	list temp_head = *head; //Creiamo un puntatore d'appoggio
	while (temp_head!=NULL) { //cicla fino alla fine
		if (temp_head->data == num) { //verifica se il nodo puntato contiene num
			temp_head->data = new_num; //sostituisce il vecchio valore con new_num
			return 0;
		}
		temp_head = (temp_head)->next; //scorre avanti
	}
	return 1; //tornaimo 1 se num non è stato trovato
}
					/*Funzione modifica_e_ordina*/
int modifica_e_ordina (int num, int new_num, list* head) {
	list forward_head = *head; //primo puntatore d'appoggio
	list back_head = *head; //secondo puntatore d'appoggio
	while ((forward_head!=NULL)&&(forward_head->data!=num)) { //cicla fino alla fine o finchè non si trova il numero da eliminare
		back_head = forward_head; //il secondo puntatore raggiunge il primo
		forward_head = forward_head->next; //il primo passa avanti
	}
	if (forward_head == NULL) {
		return 1; //tornaimo 1 se l'elemento non esiste
	}
if (forward_head == *head) { //verifica se l'elemento da eliminare è il primo
		(*head)=(*head)->next; //aggancia la testa al secondo
	}
	else {
		back_head->next=forward_head->next; //aggancia il nodo precedente a quello da eliminare al successivo
	}
	free(forward_head); //liberiamo la memoriad del nodo eliminato
	forward_head = *head; //riportiamo il primo puntatore d'appoggio sul primo nodo
	back_head = *head; //riportiamo il secondo puntatore d'appoggio sul secondo nodo
	list temp_head; //nuovo nodo
	temp_head = (list)malloc(sizeof(struct nodo));
	if (temp_head == NULL) {
		return 2; //torniamo 2 se il sistema non da la memoria
	}
	temp_head->data = new_num; //popoliamo il nuovo nodo
	while ((forward_head!=NULL) && ((forward_head->data) < (temp_head->data))) { //cicla fino alla fine o finchè non si trova il posto dove inserire il dato
		back_head = forward_head; //il secondo puntatore raggiunge il primo
		forward_head = forward_head->next; //il primo va avanti
	}
	if (forward_head == *head) { //verifica se l'inserimento avviene in testa
		temp_head->next = *head; //aggancia il nuovo nodo al vecchio primo nodo
		*head = temp_head; //aggancia head al nuovo nodo
		return 0;
	}
	back_head->next = temp_head;
	temp_head->next = forward_head;
	return 0;
}
					/*Funzione inserimento ordinato*/
int inserimento_ordinato(int num,list* head) {
	list forward_head = *head; //primo puntatore d'appoggio
	list back_head = *head; //secondo puntatore d'appoggio
	list new_head; //nuovo nodo
	new_head = (struct nodo*)malloc(sizeof(struct nodo));
	if (new_head == NULL) {
		return 1; //tornaimo 1 se il sistema non da la memoria
	}
	new_head->data = num; //popoliamo il nuovo nodo
	while ((forward_head!=NULL) && ((forward_head->data) < (new_head->data))) { //cicla fino alla fine o finchè non si trova il posto dove inserire il dato
		back_head = forward_head; //il secondo puntatore raggiunge il primo
		forward_head = forward_head->next;  //il primo va avanti
	}
	if (forward_head == *head) { //verifica se l'inserimento avviene in testa
		new_head->next = *head; //il vecchio primo nodo punta al nuovo
		*head = new_head; //agganciamo head al nuovo nodo
		return 0;
	}
	back_head->next = new_head;
	new_head->next = forward_head;
	return 0;
}
					/*Funzione elimina*/
int elimina (int num, list* head) {
	list forward_head = *head; //primo puntatore d'appoggio
	list back_head = *head; //secondo puntatore d'appoggio
	while ((forward_head!=NULL)&&(forward_head->data!=num)) { //cicla fino alla fine o finchè si trova il numero da eliminare
		back_head = forward_head; //il secondo puntatore raggiunge il primo
		forward_head = forward_head->next; //il primo passa avanti
	}
	if (forward_head == NULL) {
		return 1; //ritorna 1 se l'elemento non è stato trovato
	}
	if (forward_head == *head) {
		(*head)=(*head)->next; //se l'elemento da eliminare è il primo aggancia la testa sul secondo
	}
	else {
		back_head->next=forward_head->next; //collega il nodo precedente a quello eliminato a quello successivo
	}
	free(forward_head); //liberiamo lo spazio del nodo eliminato
	return 0;
}
					/*Funzione count*/
int count (list head) {
	int counter=0;
	while (head!=NULL) { //cicla fino alla fine
		head = head->next; //scorre avanti
		counter+=1;	//incrementa il contatore
	}
	return counter; //torniamo il contatore
}
					/*Funzione accesso all'elemento N*/
int accesso_in_n (int num, list head, int **punt) {
	while (head!=NULL) { //cicla fino alla fine
		if (head->data == num) { //verifica se si trova l'elemento
			//return head; //torniamo il puntatore a quel nodo
			*punt = &head->data;
			return 0;
		}
		head = head->next; //scorre avanti
	}
	return 1; //tornaimo NULL se l'elemento non è stato trovato
}
