#include <stdio.h>
#include "5.h"

// https://codeboard.io/projects/231790

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}
void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

// 1)

int nota (Aluno a){

    int nota;
    int minis = 0;
    int i = 0;

    while (i<6) {
        minis += a.miniT[i++];
    }

    nota = (minis*10/6*0.3) + a.teste*0.7;

    return (minis*10/6) >= 8 && (a.teste >= 8) && (nota > 9) ? nota : 0;
}

// 2)

int procuraNum (int num, Aluno t[], int N){
    int i = 0;
    int res = -1;

    while (i<N && t[i].numero < num) i++;

    return t[i].numero == num ? i : -1;
}

// 3)

void ordenaPorNum (Aluno t [], int N){
    
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    return -1;
}

// 4)
void criaIndPorNum (Aluno t [], int N, int ind[]){
    
}
void criaIndPorNome (Aluno t [], int N, int ind[]){
    
}

// 5)
void imprimeTurmaInd (int ind[], Aluno t[], int N){
    int i;
    for (i=0; i<N; i++)
        imprimeAluno (t + ind[i]);
}