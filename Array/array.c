#include "array.h"

					//funzione crea

int crea_lista (int num, list* head) {
	(*head).data[0]=num; //inserisce num al primo posto
	(*head).dim=1; //imposta la dimensione logica ad 1
	return 0;
}

					//funzione inserimento_testa

int inserimento_in_testa (int num, list* head) {
	int i; //contatore
	if ((*head).dim == N) { //controlla se l'array è pieno
		return 1; //ritorna 1 se non è possibile aggiungere elementi
	}
	for (i = (*head).dim-1;i>=0;i--) {
		(*head).data[i+1] = (*head).data[i]; //sposta tutti gli elementi di un posto verso destra
	}
	(*head).data[0] = num; //pone all'inizio dell'array l'elemento
	(*head).dim+=1; //incrementa la dimensione logica di uno
	return 0;
}

					//funzione inserimento_coda

int inserimento_in_coda (int num, list* head) {
	if ((*head).dim == N) { //controlla se l'array è pieno
		return 1; //ritorna 1 se non possibile aggiungere elementi
	}
	(*head).data[(*head).dim] = num; //pone nel primo posto libero l'elemento
	(*head).dim+=1; //incrementa la dimensione logica di uno
	return 0;
}
					
					//funzione stampa

void stampa(list head) {
	int i; //contatore
	for (i=0;i < head.dim;i++) { //cicla finchè non vengono passati tutti gli elementi della dimensione logica
		printf("%d ",head.data[i]); //stampa l'elemento nella posizione i
	}
	printf("\n");
}

					//funzione esiste

int esiste (int num, list head) {
	int i; //contatore
	for (i = head.dim-1;i>=0;i--) { //cicla finchè non vengono passati tutti gli elementi della dimensione logica
		if ((head).data[i] == num) { //verifica se l'elemento in posizione i coincide con l'elemento di cui si vuole controllare l'esistenza
			return 1; //torniamo 1 se esiste
		}
	}
	return 0; //torniamo 0 se non esiste
}

					//funzione modifica

int modifica (int num, int new_num, list* head) {
	int i; //contatore
        for (i = (*head).dim-1;i>=0;i--) { //cicla finchè non vengono passati tutti gli elementi della dimensione logica
                if ((*head).data[i] == num) { //verifica se l'elemento in posizione i coincide con l'elemento da modicare
                       (*head).data[i] = new_num; //rimpiazza il vecchio elemento con il nuovo
			return 0; //torna 0 se non ci sono problemi
                }
        }
        return 1; //torniamo 1 se non esiste il numero trovato

}

					//funzione modifica_e_ordina

int modifica_e_ordina (int num, int new_num, list* head) {
	int i; //contatore 
	int verifica = (*head).dim; //assume il valore della dimensione logica
        for (i = (*head).dim-1;i>=0;i--) { //scorre tutti gli elementi della dimensione logica
                if((*head).data[i]==num) { //verifica l'elemento nella posizione i è uguale all'elemento da eliminare
                        int j; //secondo contatore
                        for (j=i+1;j<(*head).dim;j++) { //scorre tutti gli eleemnti dalla posizione i+1 fino alla fine della dimensione logica
                                (*head).data[j-1] = (*head).data[j]; //sposta gli elementi di un posto verso sinistra
                        }
                        (*head).dim-=1; //diminuisce la dimensione logica di 1
                }
        }
	if (verifica == (*head).dim) {
		return 1; //ritorna 1 se l'elemento non è stato trovato
	}
	for (i=(*head).dim-1;i>=0;i--) { //cicla finchè non vengono passati tutti gli elementi della dimensione logica
                if ((new_num > (*head).data[i])) { //verifica se il numero da inserire è maggiore del numero nella posizione i
			int j; //secondo contatore
                        for (j = (*head).dim-1;j>i;j--) { //cicla finchè non vengono passati tutti gli elementi dalla posizione i in poi
                                (*head).data[j+1] = (*head).data[j]; //sposta gli elementi verso destra di un posto
                        }
                        break;
                }
        }
        if (i == -1) { //se i==-1 significa che non si è verificato il precedente if e quindi che nessun elemento non è stato spostato, dunque faremo un inserimento in testa
                for (i = (*head).dim-1;i>=0;i--) {
                        (*head).data[i+1] = (*head).data[i]; //spostiamo tutti gli elementi verso destra di una posizione
                }
                (*head).data[0] = new_num; //inseriamo l'elemento in prima posizione
        }
        else {
                (*head).data[i+1] = new_num; //se i!=-1 tutti gli elementi da spostare sono già stati spostati e possiamo inserire l'elemento in posizone i+1
        }
        (*head).dim +=1; //incrementiamo la dimensione logica di 1
	return 0;
}
					//funzione inserimento_ordinato

int inserimento_ordinato(int num, list* head) {
	if ((*head).dim == N) {
		return 1; //ritorna 1 se non è possibile aggiungere elementi
	}
	int i; //contatore
	for (i=(*head).dim-1;i>=0;i--) { //cicla finchè non vengono passati tutti gli elementi della dimensione logica
		if ((num > (*head).data[i])) { //verifica se il numero da inserire è maggiore del numero nella posizione i
			int j; //secondo contatore
			for (j = (*head).dim-1;j>i;j--) { //cicla finchè non vengono passati tutti gli elementi dalla posizione i in poi
               			(*head).data[j+1] = (*head).data[j]; //sposta gli elementi verso destra di un posto
			}
			break;
		}
	}
	if (i == -1) { //se i==-1 significa che non si è verificato il precedente if e quindi che nessun elemento non è stato spostato, dunque faremo un inserimento in testa
		for (i = (*head).dim-1;i>=0;i--) {
        	        (*head).data[i+1] = (*head).data[i]; //spostiamo tutti gli elementi verso destra di una posizione
	        }
       		(*head).data[0] = num; //inseriamo l'elemento in prima posizione
	}
	else {
		(*head).data[i+1] = num; //se i!=-1 tutti gli elementi da spostare sono già stati spostati e possiamo inserire l'elemento in posizone i+1
	}
	(*head).dim +=1; //incrementiamo la dimensione logica di 1
}
					//funzione elimina

int elimina (int num, list* head) {
	int i; //contatore 
	for (i = (*head).dim-1;i>=0;i--) { //scorre tutti gli elementi della dimensione logica
		if((*head).data[i]==num) { //verifica l'elemento nella posizione i è uguale all'elemento da eliminare
			int j; //secondo contatore
			for (j=i+1;j<(*head).dim;j++) { //scorre tutti gli eleemnti dalla posizione i+1 fino alla fine della dimensione logica
				(*head).data[j-1] = (*head).data[j]; //sposta gli elementi di un posto verso sinistra
			}
			(*head).dim-=1; //diminuisce la dimensione logica di 1
			return 0; //restituisce 0 se tutto è andato a buon fine
		}
	}
	return 1; //ritorna 1 se il numero non è stato trovato
}
					//funzione conta
int count (list head) {
	return head.dim; //restitusce la dimensione logica
}

int accesso_in_n (int num, list head,int **punt) {
	int i;
	for (i = head.dim-1;i>=0;i--) { //scorre tutti gli elementi della dimensione logica
		if(head.data[i]==num) {
			*punt = &(head.data[i]);
			return 0;
		}
	}
	return 1;
}
