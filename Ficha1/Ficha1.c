#include <stdio.h>

// 3 Programas iterativos

/*
1. Escreva um programa que desenhe no ecran (usando o caracter #) um quadrado de
dimensao 5. O resultado da invocacao da funcao com um argumento 5 devera ser
#####
#####
#####
#####
#####
*/

// Utilizando for
void um(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) putchar('#');
        putchar('\n');
    }
}

// Utilizando while
void umv2(int n) {
    int i=0,j=0;
    while(i<n) {
        while(j<n){
            putchar('#');
            j++;
        }
        putchar('\n');
        i++;
        j=0;

    }
}

/*
2.Escreva um programa que desenhe no ecran (usando os caracteres # e _) um tabuleiro
de xadrez. O resultado da invoca¸c˜ao dessa fun¸c˜ao com um argumento 5 dever´a ser
#_#_#     (0,0) (0,1) (0,2)...
_#_#_     (1.0) (1,1) (1,2)...
#_#_#
_#_#_
#_#_#
*/

void dois(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((i+j)%2==0) putchar('#');
            else putchar('_');
        }
        putchar('\n');
    }

}

/*
3. Escreva duas funcoes que desenham triangulos (usando o caracter #). O resultado da
#
##
###
####
#####
####
###
##
#

    #
   ###
  #####
 #######
#########

Defina cada uma dessas funcoes (com o nome triangulo), num ficheiro separado (vertical.c
e horizontal.c). Compile esses dois ficheiros (usando o comando gcc -c) separadamente.

Compile este programa (com o comando gcc -c triangulo.c). Construa (e use) agora
dois executaveis, usando os comandos
• gcc -o t1 triangulo.o vertical.o
• gcc -o t2 triangulo.o horizontal.o
*/



int main () {
    um(5);
    printf("-----\n");
    umv2(5);
    printf("-----\n");
    dois(8);
    printf("-----\n");
    return 0;
}
