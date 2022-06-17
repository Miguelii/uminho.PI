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

LInt newLInt (int x, LInt xs){
    LInt r = malloc(sizeof(Celula));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}
// -----------------------------------

// PERGUNTA 1

void printArry(int arr[],int N) {

  int loop;
  for(loop = 0; loop < N; loop++)
    printf("%d ", arr[loop]);
}

void ordenaArray(int arr[], int N) {
  int i;
  int j;
  for(int i=0;i<N;i++) {
    for(int j=i+1;j<N;j++) {
      if(arr[i]>arr[j]) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
        }
    }
  }

}

int sumhtpo (int n) {
  int arr[1024];
  int index = 0;
  int count = 0;

  int r = 0;
  while(n!=1) {
    arr[index] = n;
    index++;
    //r += n;
    if (n%2  == 0) n = n/2; else n = 1+(3*n);
  }
  
  
  ordenaArray(arr,index+1);
  
  printArry(arr,index+1);

  return arr[99];
}

//PERGUNTA 2
//Enunciado confuso, mas acho que era isto que pediam

int moda(int v[], int N, int *m) {
  int i;
  int j;
  int count = 0;
  int maisfreq = 0;
  
  for(i=0;i<N;i++) {
    for(j=i;j<N;j++) {
      if(v[j]==v[i]) count++;
    }
    
    if(count==maisfreq) return 0;
    else if(count > maisfreq) {
      maisfreq = count;
      *m = v[i];
    }
    
    count = 0;
  }
  
  return maisfreq;
}


//PERGUNTA 3

int procura (LInt *l, int x) {
  
  LInt *aux = l;
  LInt temp = NULL;
  
  //Caso o x seja o elemento à cabeça
  if((*aux)->valor == x) return 1;

  while((*aux) != NULL && (*aux)->valor != x) {
    aux = &((*aux)->prox);
  }
  
  if((*aux) == NULL) return 0;
  else {
    temp = *aux;
    *aux = (*aux)->prox;
    free(temp);
    
    LInt novo = malloc (sizeof(Celula));
    novo->valor = x;
    novo->prox = *l;
    *l = novo;
    
    return 1;
  }
}

//PERGUNTA 4
int freeAB (ABin a) {
    
  if(a==NULL) return 0;
  
  int esq = freeAB(a->esq);
  int dir = freeAB(a->dir);
  
  free(a);
  return 1+esq+dir;
}

int main() {

  //Pergunta 1
  int res = sumhtpo(1000);
  printf("\n RES: %d",res);

  //Pergunta 2
  int v[] = {1,2,2,3,3,3,4,4,4,4,7,7,7,7,7};
  int coiso;
  int *m = &coiso;
  
  int res2 = moda(v,15,m);

  //Pergunta 3
  LInt l = NULL;
  
  l = newLInt(3,l);
  l = newLInt(2,l);
  l = newLInt(1,l);

  procura(&l,2);


  return 0;
}
