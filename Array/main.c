#include "array.h"

int main () {
        list lista;
        crea_lista(0,&lista);
        inserimento_in_testa(-10,&lista);
        inserimento_in_coda(1000,&lista);
        inserimento_ordinato(20,&lista);
        stampa(lista);
        int i = esiste (30,lista);
        printf("%d\n\n",i);
        modifica(20,30,&lista);
        stampa(lista);
        i = esiste (30,lista);
        printf("%d\n\n",i);
        elimina(30,&lista);
        stampa(lista);
        i = esiste (30,lista);
        printf("%d\n\n",i);
        inserimento_ordinato(30,&lista);
        stampa(lista);
        int *p=NULL;
        accesso_in_n(1000,lista,&p);
        printf("%p\n",p);
        accesso_in_n(0,lista,&p);
        printf("%p\n",p);
        modifica_e_ordina(30,100,&lista);
        stampa(lista);
        int num_elem = count(lista);
        printf("%d", num_elem);

}
