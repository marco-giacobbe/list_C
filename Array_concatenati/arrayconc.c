#include "arrayconc.h"

int crea_lista (int num, list* head) {
	(*head).data[0][0] = num; //popoliamo il primo nodo
	(*head).data[0][1] = -1;
	(*head).start1 = 0; //poniamo l'inizio della prima lista nell'elemento 0
	(*head).start2 = 1; //poniamo l'inizio della seconda lista nell'elemento 1
	(*head).end = 0;
	int i; //contatore
	for (i=1;i<N;i++) {
		if (i != (N-1)) {
			(*head).data[i][1]=(i+1); //ordina la seconda lista
		}
		else {
			(*head).data[i][1]=-1; //se l'elemento è l'ultimo della seconda lista mette next a -1
		}
	}
}

int inserimento_in_testa (int num, list* head) {
	if ((*head).start2 == -1) { //verifica se la lista è piena
		return 1; //torniamo 1 se non è possibile aggiungere elementi
	}
	(*head).data[(*head).start2][0] = num; //popoliamo il nodo
	int temp_start2 = (*head).data[(*head).start2][1]; //creiamo una variabile temporale per tenere tracca di dove inizierà la lista 2
	(*head).data[(*head).start2][1] = (*head).start1; //agganciamo il nuovo nodo al secondo
	(*head).start1 = (*head).start2; //facciamo coincidere start1 a start 2
	(*head).start2 = temp_start2; //start2 sarà pari alla variabile temporale
	return 0;
}

int inserimento_in_coda (int num, list* head) {
	if ((*head).start2 == -1) { //verifica se la lista è piena
                return 1; //torniamo 1 se non è possibile aggiungere elementi
        }
	(*head).data[(*head).end][1] = (*head).start2; //il vecchio ultimo nodo dovrà precedere il nuovo ultimo nodo
	(*head).data[(*head).start2][0] = num; //popoliamo l'ultimo nodo
	int temp_start2 = (*head).data[(*head).start2][1]; //creiamo una variabile temporale per tenere tracca di dove inizierà la lista 2
	(*head).data[(*head).start2][1] = -1; //poniamo a -1 il next dell'ultimo nodo
	(*head).end = (*head).start2; //poniamo end sull'ultimo nodo
	(*head).start2 = temp_start2; //la seconda lista dovrà partire ora dal secondo vecchio elemento
}
					/*funzione stampa*/
void  stampa (list head) {
	if (head.start1 == -1) {
		printf("La lista è vuota");
		return;
	}
	while (head.start1 != -1) {
                printf("%d ",head.data[head.start1][0]);
		head.start1 = head.data[head.start1][1];
        }
	printf("\n");
}
					/*funzione esiste*/
int esiste (int num, list head) {
	while (head.start1 != -1) {
		if(head.data[head.start1][0] == num) {
			return 1;
		}
		head.start1 = head.data[head.start1][1];
	}
	return 0;
}
					/*funzione modifica*/
int modifica (int num, int new_num, list* head) {
	int i;
	int temp_start1 = (*head).start1;
        for (i=0;i<N;i++) {
                if ((*head).data[temp_start1][0]==num) { //verifica se il campo data coincide con num
                        ((*head).data[temp_start1][0])=new_num;
			return 0;
                }
		temp_start1 = (*head).data[temp_start1][1];
        }
        return 1; //torniamo 1 se il numero da modificare non esiste
}
					/*funzione inserimento ordinato*/
int inserimento_ordinato(int num, list* head) {
	if ((*head).start2 == -1) { //verifica se la lista è piena
                return 1; //torniamo 1 se non è possibile aggiungere elementi
        }
	int temp_start1 = (*head).start1; //variabile temporale per sapere dove inserire il nuovo nodo
	int temp_head = (*head).start1; //variabile temporale per tenere traccia del nodo precedente a temp_start1
	int i;
        for (i=0;i<N;i++) {
                if (num < (*head).data[temp_start1][0]) {
			if (temp_start1 == (*head).start1) { //inserimento in testa
				inserimento_in_testa(num, head);
				return 0;
			}
			//inserimento in mezzo
			(*head).data[(*head).start2][0] = num; //popoliamo il nuovo nodo
			int temp_start2 = (*head).data[(*head).start2][1]; //creiamo una variabile temporale per agganciarci poi l'inizio della seconda lista
			(*head).data[(*head).start2][1] = (*head).data[temp_head][1]; //agganciamo il nuovo nodo al successivo
			(*head).data[temp_head][1] = (*head).start2; //agganciamo il nodo precedente al nuovo nodo
			(*head).start2 = temp_start2; //aggiustiamo l'inizio della seconda lista
			return 0;
		}
		else if (i==(*head).end) { //inserimento in coda
			inserimento_in_coda(num, head);
			return 0;
		}	
        	temp_head = temp_start1;
		temp_start1 = (*head).data[(*head).start1][1];
	}
}
					/*funzione elimina*/
int elimina (int num, list* head) {
        int i;
        int temp_start1 = (*head).start1;
	int temp_head = (*head).start1;
        for (i=0;i<N;i++) {
                if ((*head).data[temp_start1][0]==num) { //verifica se il campo data coincide con num
			if (temp_start1 == (*head).start1) { //eliminazione in testa
				(*head).start1 = (*head).data[(*head).start1][1]; //la lista 1 inizia dal secondo nodo
				(*head).data[temp_head][1] = (*head).start2; //aggiustiamo il next del nodo eliminato
				(*head).start2 = temp_head; //la lista 2 inizierà dal nodo eliminato
				return 0;
			}
			(*head).data[temp_head][1] = (*head).data[temp_start1][1]; //assegnamo al precedente il next del nodo eliminato
			(*head).data[temp_start1][1] = (*head).start2; //aggiustiamo il next del nodo eliminato
			(*head).start2 = temp_start1; //la lista 2 inizierà dal nodo eliminato
			if ((*head).end == temp_start1) { //verifica se si elimina in coda
				(*head).end = temp_head; //in caso sistemiamo l'end
			}
			return 0; 
		}
		temp_head = temp_start1; //temp_head raggiunge temp_start1
                temp_start1 = (*head).data[temp_start1][1]; //temp_start1 scorre avanti
        }
	return 1;

}
					/*funzione count*/
int count (list head) {
	int counter=0;
	int temp_head = (head).start1;
	while (temp_head != -1) {
		temp_head = (head).data[temp_head][1];
		counter+=1;
	}
	return counter;
}
                                        /*funzione modifica e ordina*/
int modifica_e_ordina (int num, int new_num, list* head) {
        elimina(num, head);
        inserimento_ordinato(new_num,head);
}
					/*funzione accesso all'elemento n*/
int accesso_in_n (int num, list head,int **punt) {
	while (head.start1 != -1) {
		if (head.data[head.start1][0]==num) {
			*punt = &(head.data[head.start1][0]);
			return 0;
		}
		head.start1 = head.data[head.start1][1];
	}
	return 1;
}
