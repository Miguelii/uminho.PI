#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Static queues

// 2.

// a) inicializa uma queue (passa a representar uma queue vazia)

void SinitQueue (SQueue q){
	q->length = 0;
	q->front = 0; // nao garante que esteja vazia, mas par ainicializaçao é importante 
}

// b) testa se uma queue é vazia

int  SisEmptyQ (SQueue q){
    
	return q->length == 0;
}

/* c) que acrescenta x ao fim de q; 
retornar 0 se a operaao for feita com sucesso (i.e., se a queue ainda n~ao estiver cheia) 
e 1 se nao for possivel (i.e., se a queue estiver cheia).
*/

int  Senqueue (SQueue q, int x){
	int r = 0;

	if (SisEmptyQ(q)) r = 1;
	else {
		q->values[(q->front + q->length) % Max] = x;
		q->length++; 
	}

	return r; 
}

/* d) remove de uma queue o elemento que esta no inicio. 
A funcao devera colocar no endereco x o elemento removido. 
A funcao deveran retornar 0 se a operacao for possvel (i.e. a queue n~ao esta vazia) 
e 1 em caso de erro (queue vazia).
*/

int  Sdequeue (SQueue q, int *x) {
	int r = 0;

	if (q->length == Max) r = 1;
	else {
		*x = q->values[q->front];
		q->length--;
		q->front = (q->front + 1) % Max;
	}
	return r;
}

/* e) coloca no endereco x o elemento que esta no inicio da queue (sem modicar a queue). 
retornar 0 se a operacao for possivel (i.e. a queue nao esta vazia) 
e 1 em caso de erro (queue vazia).
*/

int  Sfront (SQueue q, int *x) {
	int r = 0;

	if (q->length == Max) r = 1;
	else {
		*x = q->values[q->front];
	}
	return r;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// 3.

// Queues with dynamic arrays

int dupQueue (DQueue q) {
	// ...
	return (-1);
}

void DinitQueue (DQueue q) {
	// ...
}

int  DisEmptyQ (DQueue s) {
	return (-1);
}

int  Denqueue (DQueue q, int x){
	// ...
	return (-1);
}

int  Ddequeue (DQueue q, int *x){
	// ...
	return (-1);
}

int  Dfront (DQueue q, int *x){
	// ...
	return (-1);
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}
