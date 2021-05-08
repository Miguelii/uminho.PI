#include <stdio.h>

typedef struct slist {
  int valor;
  struct slist * prox;
} *LInt;

/* 2) Apaga o último elemento de uma lista não vazia e devolve o endereço da cabeça da lista resultante

if (a) {free(b); a->prox = NULL; a = l;}
free(b); if (a) {a->prox = NULL; a = l;} Correta
free(b); if (a) a->prox = NULL; a = l; 
if (a) {a->prox = NULL; a = l;} free(b); Correta
*/

LInt init (LInt l) {
  LInt a = NULL;
  LInt b = l;
  while (b->prox) {
    a = b;
    b = b->prox;
  }
  free(b); if (a) {a->prox = NULL; a = l;}
  // if (a) {a->prox = NULL; a = l;} free(b);
  return a;
}
