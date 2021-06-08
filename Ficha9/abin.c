#include "abin.h"

// https://codeboard.io/projects/243300

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

void dumpABin (ABin a, int N) {
    if(a != NULL) {
        dumpABin(a->esq, N);
        printf("%d ", a->valor);
        dumpABin(a->dir, N);
    }
}

void freeABin (ABin a) {
    if(a) {
        freeABin(a->esq);
        freeABin(a->dir);
        free(a);
    }
}

// 1)

// a) calcula a altura de uma  ́arvore

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

// b) calcula o numero de folhas (i.e., nodos cujas sub-arvores sao ambas vazias)

int nFolhas (ABin a){
    int r = 0;
    if(a) {
        if(a->esq || a->dir) r = nFolhas(a->esq) + nFolhas(a->dir);
        else r++;
    }
    return r;
}

// c) calcula o nodo mais a esquerda de uma ́arvore

ABin maisEsquerda (ABin a){
    ABin r = NULL;
    if(a) {
        if(a->esq) r = maisEsquerda(a->esq);
        else r = a;
    }
    return r;
}

// d) escreve no ecra os elementos da arvore questao ao nıvel 1
// Considere que a raiz de uma  ́arvore se encontra no nıvel 0

void imprimeNivel (ABin a, int l){
    if(a) {
        if(l==1) printf("%d ",a->valor);
        else {
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}

// e) testa se x ocorre na arvore.

int procuraE (ABin a, int x){
    int r = 0;
    if(a!=NULL) {
        r = (a->valor == x) || procuraE(a->esq,x) || procuraE(a->dir,x);
    }
    return r;
}

// 2)  arvores binarias de procura

/* f) procura um elemento numa arvore
A funcao devera retornar o endereço da celula ondeo  
elemento ocorre ou NULL caso o elemento nao exista na arvore
*/

struct nodo *procura (ABin a, int x){
	int r = NULL;
	while(a && !r) {
		if(a->valor == x) 
			r = a;
		else if(x < a->valor)
			a = a->esq;
		else 
            a = a->dir;
	}
    return r;
}

// g) calcula o nıvel a que o elemento ocorre na ́arvore(-1 caso nao exista)

int nivel (ABin a, int x){
	int r = -1;
	int n = 0;
	while(a && (r == -1)) {
		if(a->valor == x)
			r = n;
		else if(x < a->valor)
			a = a->esq;
		else
			a = a->dir;
		n++;
	}
    return r;
}

int nivelRec (ABin a, int x) {
	int r = -1;
	if (a) {
		if(a->valor == x)
			return 1;
		else {
			r = max(nivelRec(a->esq,x), nivelRec(a->dir,x));
			return r != -1 ? 1 + r : -1;
		}
	}
}


/* h) que imprime no ecran, por ordem crescente, 
todos os elementos da arvore que sao (estritamente) menores do que um dado valor
*/

void inorder (ABin a) {
	if(a != NULL) {
		inorder(a->esq);
		printf("%d \n", a->valor);
		inorder(a->dir);
	}
}


void imprimeAte (ABin a, int x){
	if(a) {
		if(a->valor == x)
			inorder(a->esq);
		else if(a->valor < x) {
			inorder(a);
			printf("%d \n", a->valor);
			imprimeAte(a->dir,x);
		}
        else {
            imprimeAte(a->esq,x);
        }
	}
}
