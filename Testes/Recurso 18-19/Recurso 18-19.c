#include <stdio.h>
#include <stdlib.h>

// Parte A

// 1)

char charMaisfreq (char s[]) {
    char maisfreq = 0;
    int count = 0;
    int freq = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        count = 0;
        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] == s[i]) count++; 
        }
        if (count > freq) {
            freq = count;
            maisfreq = s[i];
        }
    }
    return maisfreq;
}

// 2)

int maxCresc (int v[], int N) {
    int count = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] >= v[i-1]) count++;
        else {
            max = count > max ? count : max;
            count = 1;
        }
    }
    max = count > max ? count : max;
    return max;
}


// 3)

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

LInt somasAcL (LInt l) {
  LInt r = NULL;
  LInt *sitio = &r;

  int sum = 0;
  while (l != NULL) {
    sum += l->valor;
    *sitio = malloc (sizeof (struct slist));
    (*sitio)->valor = sum;
    (*sitio)->prox = NULL;
    sitio = &((*sitio)->prox);
    l = l->prox;
  }

  return r;
}

// 4)

LInt rotateL (LInt l) {
    LInt inicio = l;
    while (l != NULL && l->prox != NULL) {
        l = l->prox;
    }
    if (l != NULL) {
        l->prox = inicio;
        l = inicio->prox;
        inicio->prox = NULL;
    }
    return l;
}

// 5)

typedef struct posicao {
    int x,y;
} Posicao;

int manDist (int x, int y, int x0, int y0) {
    return abs(x-x0) + abs(y-y0);
}

int vizinhos (Posicao p, Posicao pos[], int N) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        if (manDist(pos[i].x,pos[i].y,p.x,p.y) == 1) count++;
    }
    return count;
}


// Parte B

typedef struct nodo {
    int nlesq;
    char* linha;
    struct nodo *esq, *dir;
} *Rope;

// 1)

int nlinhas(Rope r) {
    int count = 0;
    if(r) {
        if(r->esq || r->dir) count = nFolhas(r->esq) + nFolhas(r->dir);
        else count++;
    }
    return count;
}

// 2) Não sei se está 100% correta

void print(Rope r) {
    if (r != NULL) {
        print(r->esq);
        printf("%c ", r->linha);
        print(r->dir); 
    }
}