#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  int valor;
  struct nodo *pai, *esq, *dir;
} *ABin;

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt, Celula;

typedef struct palavras {
  char *palavra;
  int nOcorr;
struct palavras *esq, *dir;
} *Palavras;


LInt newLInt (int x, LInt xs){
    LInt r = malloc(sizeof(Celula));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}
// -----------------------------------

//PERGUNTA 1
//Versão sem usar array auxiliar, mas muito ineficiente!

int paresImpares(int v[],int N) {
  int aux[N];
  
  int i=0;
  int j=0;
  for(i=0;i<N;i++) {
    for(j=i+1;j<N;j++) {
      if(v[j] % 2 == 0) {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
  
  int k;
  for(k=0;v[k]%2==0;k++);
  
  return k;
}


//PERGUNTA 2

void merge (LInt *r, LInt l1, LInt l2){
    
    while(l1!=NULL && l2 != NULL) {
        if(l1->valor < l2->valor) {
            *r = l1;
            l1 = l1->prox;
            r = &((*r)->prox);
            
            
        } else {
            *r = l2;
            l2 = l2->prox;
            r = &((*r)->prox);
        }
    }
    
    if(l1==NULL) *r = l2;
    else *r = l1;
    
}

//PERGUNTA 3

void latino(int N, int m[N][N]) {
  int i;
  int j;
  
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(i+j+1 > N) {
        m[i][j] = i+j+1-N;
      }
      else {
        m[i][j] = i+j+1;
      }
    }
  }
}

// Pergunta 4

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


int main() {

    //Pergunta 1
    int v[] = {1,2,3,4,5,6,7,8,9};
    int res = paresImpares(v,9);

    //Pergunta 2
    int m[3][3];
    latino(3,m);

}
