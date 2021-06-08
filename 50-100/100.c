#include <stdio.h>
#include <stdlib.h>

// ##### LISTAS LIGADAS #####

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt, Nodo;

// 1)

int length(LInt l) {
    int r = 0;
    for (r=0; l!=NULL; l=l->prox) r++;
    return r;
}

// 2) 

void freeL (LInt l) {
    LInt temp;

    while(l!=NULL) {
        temp=l;
        l=l->prox;
        free(temp);
    }
}

// 3)

void imprimeL (LInt l) {
    while(l!=NULL) {
        printf("%d ", l->valor);
        l=l->prox;
    }
    printf("\n");
}

// 4)

LInt reverseL (LInt l) {
    LInt prox, ant = NULL;

    if(l!=NULL) {
        while(l!=NULL) {
            prox = l->prox;
            l->prox = ant;
            ant = l;
            l = prox;
        }
        l->prox = ant;
    }
    return l;
}

// 5)

void insertOrd (LInt *l, int x) {
    LInt novo = malloc(sizeof(Nodo));
    novo->valor = x;

    while(*l!=NULL && (*l)->valor<x)
        l = &((*l)->prox);
    novo->prox = *l;
    *l = novo;
}

// 6)

int removeOneOrd(LInt *l, int x) {
    int r = 0;

    while(*l!=NULL && (*l)->valor!=x)
        l = &((*l)->prox);
    if(*l==NULL) r=1;
    else {
        r=0;
        *l = (*l)->prox;
    }
    return r;
}

// 7)

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

// 8)

void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    while(l!=NULL) {
        if(l->valor < x) {
            *mx = l;
            mx = &(l->prox);
        }
        else {
            *Mx = l;
            Mx = &(l->prox);
        }
        l = l->prox;
    }
    *mx = NULL;
    *Mx = NULL;
}

// 9)

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

// 10

int removeAll (LInt *l, int x) {
  int r = 0;

  while (*l!=NULL)
    if ((*l)->valor == x) {
      *l = (*l)->prox;
      ++r;
    }
    else l = &((*l)->prox);

  return r;
}



// 11)

int isIn (int x, int v[], int N) {
  int i, r;

  for (i=0; i<N && v[i]!=x; ++i);

  if (i==N) r = 0;
  else r = 1;

  return r;
}
int removeDups (LInt *l) {
  int r = 0, size = length (*l);
  int elems[size];

  LInt tmp;
  while (*l!=NULL && (*l)->prox!=NULL)
    if (isIn ((*l)->valor, elems, size)) {
      tmp = *l;
      *l = (*l)->prox;
      free (tmp);
    }
    else {
      elems[r++] = (*l)->valor;
      l = &((*l)->prox);
    }

  return r;
}

// 12)

int removeMaiorL (LInt *l) {
  LInt *l_aux = l;
  int r = (*l)->valor;
  l = &((*l)->prox);

  // Encontrar o maior elemento
  while (*l != NULL) {
    if ((*l)->valor > r) r = (*l)->valor;
    l = &((*l)->prox);
  }

  // Remover o maior elemento
  while ((*l_aux)->valor != r)
    l_aux = &((*l_aux)->prox);

  LInt tmp = *l_aux;
  *l_aux = (*l_aux)->prox;
  free (tmp);

  return r;
}

// 13)
void init (LInt *l) {
  while ((*l)->prox != NULL)
  l = &((*l)->prox);

  LInt tmp = *l;
  *l = (*l)->prox;
  free (tmp);
}

// 14)
void appendL (LInt *l, int x) {
  while (*l != NULL) l = &((*l)->prox);

  LInt novo = malloc (sizeof (struct lista));
  novo->valor = x;
  novo->prox = NULL;

  *l = novo;
}

// 15)
void concatL (LInt *a, LInt b) {
  while (*a != NULL) a = &((*a)->prox);
  *a = b;
}

// 16)
LInt cloneL (LInt l) {
  LInt r;

  if (l == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct lista));
    r->valor = l->valor;
    r->prox = cloneL (l->prox);
  }

  return r;
}

// 17)

LInt cloneRev (LInt l) {
  LInt r = NULL;
  LInt novo;

  while (l != NULL) {
    novo = malloc (sizeof (struct lista));
    novo->valor = l->valor;
    novo->prox = r;
    r = novo;
    l = l->prox;
  }

  return r;
}

// 18)

int maximo (LInt l) {
  int r = l->valor;
  l = l->prox;

  while (l != NULL) {
    if (l->valor > r) r = l->valor;
    l = l->prox;
  }

  return r;
}

// 19)

int take (int n, LInt *l) {
  int r = 0;

  while (*l != NULL && n != 0) {
    l = &((*l)->prox);
    ++r; --n;
  }

  while (*l != NULL) {
    LInt tmp = *l;
    *l = (*l)->prox;
    free (tmp);
  }

  return r;
}

// 20)

int drop (int n, LInt *l) {
  int r = 0;
  LInt tmp;

  while (*l != NULL && n != 0) {
    tmp = *l;
    *l = (*l)->prox;
    free (tmp);
    ++r; --n;
  }

  return r;
}

// 21)

LInt Nforward (LInt l, int N) {
  for (int i=0; i<N; ++i) l = l->prox;

  return l;
}

// 22)

int listToArray (LInt l, int v[], int N) {
  int r;

  for (r = 0; l!=NULL && r<N; ++r) {
    v[r] = l->valor;
    l = l->prox;
  }

  return r;
}

// 23)

LInt arrayToList (int v[], int N) {
  LInt r = NULL;
  LInt *sitio = &r;

  for (int i=0; i<N; ++i) {
    *sitio = malloc (sizeof (struct lista));
    (*sitio)->valor = v[i];
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
  }

  return r;
}

// 24)

LInt somasAcL (LInt l) {
  LInt r = NULL;
  LInt *sitio = &r;

  int counter = 0;
  while (l != NULL) {
    counter += l->valor;
    *sitio = malloc (sizeof (struct lista));
    (*sitio)->valor = counter;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

// 25)

void remreps (LInt l) {
  while (l != NULL && l->prox != NULL) {
    if (l->valor == l->prox->valor) l->prox = l->prox->prox;
    else l = l->prox;
  }
}

// 26)

LInt rotateL (LInt l) {
  LInt head = l;

  while (l != NULL && l->prox != NULL) l = l->prox;

  if (l != NULL) {
    l->prox = head;
    l = head->prox;
    head->prox = NULL;
  }

  return l;
}

// 27)

LInt parte (LInt l) {
  LInt r, *aux;
  aux = &r;

  while (l!=NULL && l->prox!=NULL) {
      *aux = l->prox;
      l->prox=l->prox->prox;
      aux = &((*aux)->prox);
      l = l->prox;
  }
  *aux = NULL;

  return r;
}

// ##### ARVORES BINÁRIAS #####

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// 28)
int max(int a, int b) {
    return a>b ? a : b;
}
int altura (ABin a) {
    int r = 0;
    if(a != NULL) {
        r += 1 + max(altura(a->esq),altura(a->dir));
    }
    return r;
}

// 29)

ABin cloneAB (ABin a) {
  ABin r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct nodo));
    r->valor = a->valor;
    r->esq = cloneAB (a->esq);
    r->dir = cloneAB (a->dir);
  }

  return r;
}

// 30)

void mirror (ABin *a) {
  if (*a != NULL) {
    ABin tmp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = tmp;
    mirror (&((*a)->dir));
    mirror (&((*a)->esq));
  }
}

LInt concat (LInt a, LInt b) {
  LInt r = a;

  if (a == NULL) r = b;
  else if (b != NULL) {
    while (a->prox != NULL) a = a->prox;
    a->prox = b;
  }

  return r;
}

// 31)

void inorder (ABin a, LInt *l) {
  *l = NULL;
  if (a != NULL) {
    inorder (a->esq, l);
    while (*l != NULL) l = &((*l)->prox);
    (*l) = malloc (sizeof (struct lista));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    inorder (a->dir, &((*l)->prox));
  }
}

// 32)

void preorder (ABin a, LInt *l) {
  *l = NULL;
  if (a != NULL) {
    *l = malloc (sizeof (struct lista));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    preorder (a->esq, &((*l)->prox));
    while (*l != NULL) l = &((*l)->prox);
    preorder (a->dir, l);
  }
}

// 33)

void postorder (ABin a, LInt *l) {
  *l = NULL;
  if (a != NULL) {
    postorder (a->esq, l);
    while (*l != NULL) l = &((*l)->prox);
    postorder (a->dir, l);
    while (*l != NULL) l = &((*l)->prox);
    *l = malloc (sizeof (struct lista));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
  }
}

// 34)

int min (int a, int b) {
  int r;

  if (a < b) r = a;
  else r = b;

  return r;
}
int depth (ABin a, int x) {
  int r;

  if (a == NULL) r = -1;
  else if (a->valor == x) r = 1;
  else {
    int r_esq = depth (a->esq, x);
    int r_dir = depth (a->dir, x);

    if (r_esq == -1 && r_dir == -1) r = -1;
    else if (r_esq == -1) r = 1 + r_dir;
    else if (r_dir == -1) r = 1 + r_esq;
    else r = 1 + min (r_esq, r_dir);
  }

  return r;
}

// 35)

int freeAB (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else {
    r = 1 + freeAB (a->dir) + freeAB (a->esq);
    free (a);
  }

  return r;
}



// 36)

int pruneAB_aux (ABin *a, int l, int level) {
  int r;
  if (*a == NULL) r = 0;
  else if (level <= l) {
    int r_dir, r_esq;
    r_dir = pruneAB_aux (&((*a)->dir), l, level+1);
    r_esq = pruneAB_aux (&((*a)->esq), l, level+1);
    r = r_esq + r_dir;
  }
  else {
    int r_dir, r_esq;
    r_dir = pruneAB_aux (&((*a)->dir), l, level+1);
    r_esq = pruneAB_aux (&((*a)->esq), l, level+1);

    if (level != l+1) free (a);
    else *a = NULL;

    r = 1 + r_dir + r_esq;
  }

  return r;
}
int pruneAB (ABin *a, int l) {
  int r = pruneAB_aux (a, l, 1);
  return r;
}

// 37)

int iguaisAB (ABin a, ABin b) {
  int r;
  if (a == NULL && b == NULL) r = 1;
  else if (a == NULL || b == NULL) r = 0;
  else if (a->valor == b->valor)
    r = iguaisAB (a->esq, b->esq) && iguaisAB (a->dir, b->dir);
  else r = 0;

  return r;
}

// 38)

LInt nivelL (ABin a, int n) {
  LInt r;
  if (a == NULL) r = NULL;
  else if (n == 1) {
    r = malloc (sizeof (struct lista));
    r->valor = a->valor;
    r->prox = NULL;
  }
  else {
    LInt r_dir;
    r = nivelL (a->esq, n-1);
    r_dir = nivelL (a->dir, n-1);
    r = concat (r, r_dir);
  }

  return r;
}

// 39)

int nivelV (ABin a, int n, int v[]) {
  int r;
  if (a == NULL) r = 0;
  else if (n == 1) {
    v[0] = a->valor;
    r = 1;
  }
  else {
    r = nivelV (a->esq, n-1, v);
    r += nivelV (a->dir, n-1, v+r);
  }

  return r;
}

// 40)

int dumpABin (ABin a, int v[], int N) {
  int r;
  if (a == NULL || N == 0) r = 0;
  else {
    r = dumpABin (a->esq, v, N);
    if (r < N) {
      v[r] = a->valor;
      ++r;
    }
    if (r < N) r += dumpABin (a->dir, v+r, N-r);
  }

  return r;
}



// 41)

int somaABin (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else r = a->valor + somaABin (a->esq) + somaABin (a->dir) ;

  return r;
}
ABin somasAcA (ABin a) {
  ABin r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct nodo));
    r->valor = somaABin (a);
    r->esq = somasAcA (a->esq);
    r->dir = somasAcA (a->dir);
  }

  return r;
}

// 42)

int contaFolhas (ABin a) {
  int r;
  if (a == NULL) r = 0;
  else if (a->dir == NULL && a->esq == NULL) r = 1;
  else r = contaFolhas (a->esq) + contaFolhas (a->dir);

  return r;
}

// 43)

ABin cloneMirror (ABin a) {
  ABin r;
  if (a == NULL) r = NULL;
  else {
    r = malloc (sizeof (struct nodo));
    r->valor = a->valor;
    r->esq = cloneMirror (a->dir);
    r->dir = cloneMirror (a->esq);
  }

  return r;
}



// 44: 10/10
int addOrd (ABin *a, int x) {
  int r;

  while (*a != NULL && (*a)->valor != x) {
    if (x < (*a)->valor) a = &((*a)->esq);
    else a = &((*a)->dir);
  }

  if (*a == NULL) {
    r = 0;
    *a = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
  }
  else r = 1;

  return r;
}

// versao recursiva

int addOrd_rec (ABin *a, int x) {
  int r;

  if (*a == NULL) {
    *a = malloc (sizeof (struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
    r = 0;
  }
  else if (x < (*a)->valor) r = addOrd (&((*a)->esq), x);
  else if (x == (*a)->valor) r = 1;
  else r = addOrd (&((*a)->dir), x);

  return r;
}

// 45)

int lookupAB (ABin a, int x) {
  int r;

  while (a != NULL && a->valor != x) {
    if (x < a->valor) a = a->esq;
    else a = a->dir;
  }

  if (a == NULL) r = 0;
  else r = 1;

  return r;
}

// 46)

int depthOrd (ABin a, int x) {
  int r = 1;

  while (a != NULL && a->valor != x) {
    if (x < a->valor) a = a->esq;
    else a = a->dir;
    ++r;
  }

  if (a == NULL) r = -1;

  return r;
}

// 47)

int maiorAB (ABin a) {
  int r;

  while (a->dir != NULL) a = a->dir;

  r = a->valor;

  return r;
}

// 48)

void removeMaiorA (ABin *a) {
  while ((*a) != NULL && (*a)->dir != NULL)
    a = &((*a)->dir);

  if (*a != NULL) {
    ABin tmp = (*a)->esq;
    free (*a);
    *a = tmp;
  }
}

// 49)

int quantosMaiores (ABin a, int x) {
  int r;

  if (a == NULL) r = 0;
  else if (a->valor <= x) r = quantosMaiores (a->dir, x);
  else r = 1 + quantosMaiores (a->esq, x) + quantosMaiores (a->dir, x);

  return r;
}

// 50)

void listToBTree (LInt l, ABin *a) {
  while (l != NULL) {
    *a = insere (*a, l->valor);
    l = l->prox;
  }
}

int quantosMenores (ABin a, int x) {
  int r;

  if (a == NULL) r = 0;
  else if (a->valor >= x) r = quantosMenores (a->esq, x);
  else r = 1 + quantosMenores (a->esq, x) + quantosMenores (a->dir, x);

  return r;
}

// 51)

int deProcura (ABin a) {
  int r;

  if (a == NULL) r = 1;
  else {
    int menores, maiores;
    menores = quantosMenores (a->dir, a->valor);
    maiores = quantosMaiores (a->esq, a->valor);

    if (maiores != 0 && menores != 0) r = 1;
    else r = deProcura (a->esq) && deProcura (a->dir);
  }

  return r;
}
