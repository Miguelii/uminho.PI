#include <stdio.h>
#include <limits.h>
#include <math.h>

// 2)

void swapM (int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

// 3)
void swap (int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
/* OU
    swapM(&v[i], &v[j])
    swapM(v+i,v+j)
*/

// 5)
void inverteArray (int v[], int N){
    int k;
    for (k=0;k<N/2; k++) {
        swap(v,k,N-1-k);
        // swapM(&v[k], &v[N-1-k])
        // swapM(v+k,v+N-1-k)
    }
}
void inverteArray2 (int v[], int N) {
    int inicio=0, fim=N-1;
    while(inicio<fim) {
        swap(v,inicio++,fim--);
    }
} 

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
    putchar ('\n');
}

// 4)
int soma (int v[], int N) {
    int soma;
    for(int i=0; i<N; i++) {
        soma+=v[i];
    }
    return soma;
}

// VERSAO RECURSIVA
int soma2_aux (int v[], int n, int soma) {
    if (n==0) return soma;
    return soma2_aux(v,n-1,soma+v[n-1]);
}
int soma2 (int v[], int n) {
    return soma2_aux(v,n,0);
}


// 6)
int maximum (int v[], int N, int *m){
    if (N>=0) {
        *m = v[0];
        for (int i=1; i<N; i++) 
            if (*m < v[i]) *m = v[i];
        return 0;
    }
    else
        return 1;
}

// 7)
void quadrados (int q[], int N){
    q[0] = 0;
    for (int i=1; i<N;i++) {
        q[i] = pow(q[i-1],2) + 2*q[i-1]+1;
    }
}

// 8)
void pascal (int v[], int N){
    int i,j;

    for (i=1; i<=N; i++) {
        j=i;
        while (j>0) {
            if (j == i) v[j] = 1;
            else if (j>1) v[j] += v[j-1];
            j--;
        }
        dumpV(v,i); // Com isto e o desenhaTriangulpP fica tempo linear 
    }

}

void desenhaTriangulpP (int N) {
    int vaux[N];
    pascal(vaux,N);
}


/* Versao ineficiente -> Tempo quadratico
void desenhaTriangulpP (int N){
    int k, v[N];
    for (k = 1; k <= 10; k++) {
        pascal(v,k);
        dumpV(v,k);
    }
}
*/

int main()
{  
    printf ("Testes\n");
    // teste das funções de swap
    
    int a, b, v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
    int x = 3, y = 5;
    printf ("x = %d y = %d\n", x, y);
    swapM (&x, &y);
    printf ("x = %d y = %d\n", x, y);
    
    printf ("%d %d\n", v[0], v[9]);
    swap (v,0,9);
    printf ("%d %d\n", v[0], v[9]);
    
    /*
    printf ("ao invertemos o array "); dumpV (v,10);
    inverteArray (v,10);
    printf ("obtemos               "); dumpV (v,10);

    */
    
    // teste das funções maximum, soma e quadrados
    /*
    x = maximum (v,10, &y);
    printf ("O maior elemento de "); dumpV (v,10);
    printf ("é %d\n", y);
    */
    /*
    printf ("Os 10 primeiros quadrados: "); 
    quadrados (v,10); 
    dumpV (v,10);
    */
    
    x = soma (v,10);
    printf ("A soma dos elementos de "); dumpV (v,10);
    printf ("e %d\n", x);
    
    
    // teste da função de cálculo do triangulo de Pascal
    
    printf ("A linha 5 do triângulo de Pascal e ");
    int k;
    for (k=1; k<=10; k++) {
        pascal(v,k);
        dumpV(v,k);
    }
    
    
    printf ("As linhas 0 a 10 do triângulo de Pascal\n\n");
    desenhaTriangulpP (12);
    
    printf ("\nFim dos testes\n");

    return 0;
}
