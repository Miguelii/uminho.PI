#include <stdio.h>
/* Enunciado Pergunta 2

Considerando que n = 39 quantas parcelas do somatório calculado são números oblongos? 
Um número é oblongo se é igual ao produto de 2 inteiros consecutivos. Por exemplo 6 é um número oblongo porque 6 = 2*3.
*/

// Resolução:

int oblongos(int n) {
    int f=0;
    for(int i=0; i<10;i++) {
        if(n==(i*(i+1))) f=1;
    }
    return f;
}

int main() {
    int r=0;
    int n=39;
    while (n!=1) {
        r += n; 
        if (n%2 == 0) n = n/2;
        else (n = 1+(3*n));
        if(oblongos(n)==1) printf("n= %i e oblongos\n",n);
    }
    return r;
}
