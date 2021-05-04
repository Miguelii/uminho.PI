#include <stdio.h>

typedef struct slist {
  int valor;
  struct slist * prox;
} *LInt;

LInt newLInt (int x, LInt xs) {
  LInt r = malloc (sizeof(struct slist));
  if (r!=NULL) {
    r->valor = x;
    r->prox = xs;
  }
  return r;
}

// Apaga o último elemento de uma lista não vazia
// e devolve o endereço da cabeça da lista resultante

LInt init (LInt l) {
  LInt a = NULL;
  LInt b = l;
  while (b->prox) {
    a = b;
    b = b->prox;
  }
  free(b); if (a) {a->prox = NULL; a = l;}
  return a;
}
