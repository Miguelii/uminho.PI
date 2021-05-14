#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////// Declarações //////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras, Celula;

void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);

//////////////////////////////////////////////////////////////////////

// 1) que liberta todo o espaco (da heap) ocupado pela lista de palavras.

// versao iterativa

void libertaLista (Palavras l) {
    Palavras aux;
    while (l != NULL) {
        aux = l;
        l = l -> prox;
        free(aux);
    }
}

// Versao recursiva

void libertaLista2 (Palavras l) {
    if(l) {
        libertaLista(l->prox);
        free(l);
    }
}

// 2) calcula quantas palavras (diferentes) existem armazenadas.

// versao iterativa

int quantasP (Palavras l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->prox;
    }
    return count;
}

// Versao recursiva

int quantasP2 (Palavras l) {
    if (l) return 1 + quantasP(l->prox);
    else return 0;
}

// 3) escreve no ecra, uma por linha, todas as palavras armazenadas, bem como o numero de ocorrencias.

// versao iterativa

void listaPal (Palavras l) { 
    while(l) {
        printf("%s - %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// versao recursiva

void listaPal2 (Palavras l) { 
    if(l) {
        printf("%s - %d\n", l->palavra, l->ocorr);
        listaPal(l->prox);
    }
}

// 4) determina qual a ultima palavra da lista.

char * ultima (Palavras l) {
    while(l && l->prox) {
        l = l->prox;
    }
    return l ? l->palavra : NULL;
}

// 5) acrescenta uma palavra no inicio da lista (com 1 como numero de ocorrencias).

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras aux = malloc(sizeof(Celula)); 
    // se fizer um sizeof de Palavras ele vai dar o tamanho de bytes de um apontador
    // Ao adicionar Celula à nossa struct, ele vai dar o tamanho em bytes da estrutura(tamanho de um apontador + tamanho de in + tamanho de um apontador)

    aux->palavra = strdup(p);
    aux->ocorr = 1;
    aux->prox = l;

    return aux;
}

// 6) acrescenta uma palavra no fim da lista (com 1 como numero de ocorrencias)

Palavras acrescentaFim (Palavras l, char *p) {

    Palavras aux = malloc(sizeof(Celula));
    Palavras aux2 = l;

    aux->palavra = strdup(p);
    aux->ocorr = 1;
    aux->prox = NULL;

    while(l && l->prox) l = l->prox;
    if (l){
        l->prox  = aux;
        return aux2;
    }
    else return aux;
}

/* 7) regista mais uma ocorrencia da palavra p.
Se a palavra ja existir, o numero de ocorrencias deve ser incrementado. 
No outro caso deve ser inserida uma nova celula.
A insercao de uma nova celula pode ser feita no inicio da lista ou ordenadamente, assumindo
que a lista esta armazenada por ordem alfabetica.
*/

Palavras acrescenta (Palavras l, char *p) {

    if(!l || (strcmp(p,l->palavra) < 0)) {  // Se l for NULL ou se palavra é mais pequena do que a está no inicio
        return acrescentaInicio(l,p);
    }
    else if(strcmp(p,l->palavra) == 0) {    // ver se palavra é igual à que está no inicio
        l->ocorr++;
        return l;
    }
    else { 
    // para entrar neste else primeiro sabemos que a lista não é vazia
    // A palavra a inserir é maior do que a lista que estamos neste momento a observar
    
    l->prox = acrescenta(l->prox,p); 
    // O acrescenta l->prox de p acrescenta nas seguintes, ou seja, estou a alterar as listas seguintes
    // Se estou a alterar a lista seguinte tenho que atribuir isto ao apontador seguinte
    return l;
    }
}

// 8) calcula a celula correspondente a palavra mais frequente

struct celula * maisFreq (Palavras l) {

    Palavras res = NULL;
    int max = 0;

    while(l) {
        if (l->ocorr > max) {
            res = l;
            max = l->ocorr;
        }
        l = l->prox;
    }
    return res;
}


// Para testes
int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

  
    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    

    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}