#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// Static stacks 

// 1.

// a)  inicializa uma stack (passa a representar uma stack vazia)

void SinitStack (SStack s){
	s->sp = 0;
}

// b) testa se uma stack é vazia

int  SisEmpty (SStack s){
	return s->sp == 0;
}

/* c) que acrescenta x ao topo de s; 
retornar 0 se for feita com sucesso (i.e., se a stack ainda nao estiver cheia) 
retornar 1 se nao for possıvel (i.e., se a stack estiver cheia).
*/

int Spush (SStack s, int x){
	int r = 0;
    
    if (s->sp == Max) r=1;  
    else {
        s->values[s->sp] = x;
        s->sp++;
    }

	return r;
}

/* d) remove de uma stack o elemento que esta no topo.
A funcao devera colocar no endereco x o elemento removido
A funcao devera retornar 0 se a operacao for possıvel (i.e. a stack nao esta vazia) 
e 1 em caso de erro (stack vazia).
*/

int Spop (SStack s, int *x) {
    int r=0;
    
    if (SisEmpty(s)) r = 1;
    else {
        s->sp--; // porque o topo está abaixo do sp
        *x = s->values[s->sp];
    }

	return r;
}

/* e) coloca no endereco x o elemento que esta no topo da stack (sem modicar a stack). 
A funcao devera retornar 0 se a operacao for possivel (i.e. a stack nao esta vazia) 
e 1 em caso de erro (stack vazia).
*/

int Stop (SStack s, int *x) {
    int r=0;
	
	if (SisEmpty(s)) r = 1;
	else {
		*x = s->values[s->sp-1];
	}

	return r;
}

void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}

// 3.

// Stacks with dynamic arrays

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

// a)

void DinitStack (DStack s) {
	s->size = Max;
	s->sp = 0;
	s->values = (int*) malloc(sizeof(int) * s->size);
}

// b)

int DisEmpty (DStack s) {
	return s->sp == 0;
}

// c)

int Dpush (DStack s, int x){
	int r=0;

    if (s->sp == s->size) r = dupStack(s);
	if (!r) {
		s->values[s->sp] = x;
		s->sp++;
	}
	return r;
}

// d)

int Dpop (DStack s, int *x){
	int r=0;
	
	if (DisEmpty(s)) r = 1;
    else {
        s->sp--;
        *x = s->values[s->sp];
    }
	return r;
}

// e)

int Dtop (DStack s, int *x){
	int r=0;
	
	if (DisEmpty(s)) r = 1;
	else {
		*x = s->values[s->sp-1];
	}
	return r;
}

void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}
