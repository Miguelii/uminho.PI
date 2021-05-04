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

// 1) Testar se uma lista está ordenada por ordem crescente

int sorted (LInt l) {
  int r = 1;
  while (l && r) {
    if (l->prox && l->valor > l->prox->valor) r = 0;
    l = l->prox;
  }
  return 1;
}

	
//if (l->prox) if (l->valor > l->prox->valor) r = 0;	
//if (l->prox && l->valor > l->prox->valor) r = 0;
//if (l->valor > l->prox->valor && l->prox) r = 0;
//if (l->valor > l->prox->valor) r = 0; else r = 1;
