typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;


// 1) 10/10

int length (LInt l){
    int res = 0;
    
    while(l != NULL) {
        res+=1;
        l = l->prox;
    }
    return res;
}

// 2)

void freeL (LInt l) {
	LInt tmp;

	while(l=NULL) {
		tmp = l;
		l = l->prox;
		free(l);
	}
}

// 3)

void imprimeL (LInt) {

	while(l=NULL) {
		printf("%d", l->valor);
		l = l->prox;
	}
	printf("\n");
}

// 4) 10/10

LInt reverseL (LInt l) {
  LInt prox, ant = NULL;

  if (l!=NULL) {
    while (l!=NULL) {
      prox = l->prox;
      l->prox = ant;
      ant = l;
      l = prox;
    }

    l->prox = ant;
  }

  return l;
}

// 5) 10/10

void insertOrd (LInt *l, int x) {
    LInt novo = malloc(sizeof(LInt));
    novo->valor = x;

    while(*l!=NULL && (*l)->valor<x)
        l = &((*l)->prox);
    novo->prox = *l;
    *l = novo;
}

// 6) 3/10

int removeOneOrd (LInt *l, int x){
    int r = 0;
    LInt ant;
    while(*l!=NULL && (*l)->valor!=x) {
        ant = *l;
        l = &((*l)->prox);
    }
    if(*l==NULL) r = 1;
    else {
        r=0;
        ant->prox = (*l)->prox;
        free(*l);
        *l = NULL;
    }
    
    return r;
}

// 7) 10/10

void merge (LInt *r, LInt l1, LInt l2){
    while(l1!=NULL && l2!=NULL) {
        if(l1->valor < l2->valor) {
            *r = l1;
            r = &((*r)->prox);
            l1 = l1->prox;
        } else {
            *r = l2;
            r = &((*r)->prox);
            l2 = l2->prox;
        }
    }
    if(l1==NULL) *r = l2;
    else *r = l1;
    
    
}

// 8) 10/10

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l!=NULL) {
        if(l->valor <x) {
            *mx = l;
            mx = &(l->prox);
        } else {
            *Mx = l;
            Mx = &(l->prox);
        }
        l = l->prox;
    }
    
    *mx = NULL;
    *Mx = NULL;
}

// 9) 10/10

LInt parteAmeio (LInt *l) {
  LInt ant, r = *l;
  int i, size = length(*l);

  for (i=0; i<size/2; ++i) {
    ant = *l;
    *l = (*l)->prox;
  }

  if (i==0) r = NULL;
  else ant->prox = NULL;

  return r;
}

// 10) 10/10


int removeAll (LInt *l, int x){
    
    int count = 0;
    
    while(*l!= NULL) {
        if((*l)->valor == x) {
            *l = (*l)->prox;
            count++;
        }
        else {
          l = &((*l)->prox);
        }
    }
    
    
    return count;
}

// 11) 10/10

int repetido(int N, int v[], int x) {
    
    int i;
    for(i=0;i<N && v[i] != x;i++);
    
    if(i==N) return 0;
    else return 1;
}

int removeDups (LInt *l){
    
    int index = 0;
    int ocurrencias[length(*l)];
    int count = 0;
    
    while(*l!=NULL && (*l)->prox) {
        if(repetido(index+1,ocurrencias,(*l)->valor) == 1) {
            LInt tmp = NULL;
            tmp = *l;
            (*l) = (*l)->prox;
            free(tmp);
            count++;
        } else {
            ocurrencias[index++] = (*l)->valor;
            l = &((*l)->prox);
        }
    }
    return count;
}

// 12) 10/10

int removeMaiorL (LInt *l){
    
    int maior = (*l)->valor;
    LInt *aux = l;
    
    if((*l) == NULL) return 0;
    
    //Encontrar maior elem
    while((*aux)!=NULL) {
        if((*aux)->valor > maior) {
            maior = (*aux)->valor;
            aux = &((*aux)->prox);
        } else {
            aux = &((*aux)->prox);
        }
    }
    
    //remover o maior elem
    while((*l)->valor != maior) l = &((*l)->prox);
    LInt tmp = *l;
    *l = (*l)->prox;
    free(tmp);
    
    return maior;
}

int main() {
  LInt l = NULL;
  
  l = newLInt(3,l);
  l = newLInt(2,l);
  l = newLInt(1,l);
  
  removeOneOrd(&l,3);
  procura(&l,2);
  l = insert(3,l);

  return 0;
}

