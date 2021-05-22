#include <stdio.h>

typedef struct slist {
  int valor;
  struct slist * prox;
} *LInt;

/* 1) Testar se uma lista está ordenada por ordem crescente

if (l->prox) if (l->valor > l->prox->valor) r = 0; Correta
if (l->prox && l->valor > l->prox->valor) r = 0; Correta
if (l->valor > l->prox->valor && l->prox) r = 0;
if (l->valor > l->prox->valor) r = 0; else r = 1;
*/

int sorted (LInt l) {
  int r = 1;
  while (l && r) {
    if (l->prox && l->valor > l->prox->valor) r = 0;
    //if (l->prox) if (l->valor > l->prox->valor) r = 0;
    l = l->prox;
  }
  return 1;
}
