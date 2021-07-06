#include <stdio.h>
#include <stdlib.h>

// 1) 

void swap (int *x, int *y){
     int a;
     a = *x;
     *x = *y;
     *y = a;
}

int paresImpares (int v[], int N){
  int i;
  int j;
  for (i=0;i<N;i++){
    if (v[i] % 2 != 0){
      for (j=i+1;j<N;j++){
        if (v[j] % 2 == 0){
          swap (&v[i],&v[j]);
          break;
        }
      }
    }
  }
}

// 2)
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt, Nodo;

void merge (LInt *r, LInt a, LInt b) {
    while(a!=NULL && b!=NULL) {
        if(a->valor < b->valor) {
            *r = a;
            r = &((*r)->prox);
            a = a->prox;
        }
        else {
            *r = b;
            r = &((*r)->prox);
            b = b->prox;
        }
    }
    if(a==NULL) *r = b;
    else *r = a;
}

// 3)

void latino (int N, int m[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((i+j)<N) m[i][j] = i+j+1;
      else m[i][j] = i+j+1-N;
    }
  }
}

// 4) 

typedef struct nodo {
  int valor;
  struct nodo *pai, *esq, *dir;
} *ABin;

ABin next (ABin a) {
    if (a == NULL) return NULL;
    
    if (a->dir == NULL && a->pai == NULL) {
        return NULL;
    }else if (a->dir == NULL && a->pai->dir == a) {
        if (a->pai->pai != NULL) {
          return a->pai->pai;
        }
        return NULL;
    } else if (a->dir == NULL && a->pai->esq == a) {
        return a->pai;
    }

    return a->dir;
}

// 5) Nao está 100% correta  

typedef struct palavras {
  char *palavra;
  int nOcorr;
struct palavras *esq, *dir;
} *Palavras;

int acrescentaPal (Palavras *p, char *pal) {
    int cmp = strcmp(p, pal->palavra);
    if (cmp == 0) {
        pal->nOcorr += 1;
        return pal->n0corr;
    } else if (cmp < 0) {
        return acrescentaPal(p, pal->esq);
    } else {
        return acrescentaPal(p, pal->dir);
    }
}