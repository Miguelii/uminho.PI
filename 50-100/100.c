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
    //... completar
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


