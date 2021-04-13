#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

// 1) conta quantas vogais uma string tem

int pertence(char letras[], char c) {

}

int contaLetras(char *s, char *letras) {

}

int contaVogais (char *s) {
    int count = 0;
    while (*s != '\0') {
        if (*s == 'a' || *s == 'A' || *s == 'e' || *s == 'E' || *s == 'i' || *s == 'I' || *s =='o' || *s=='O' || *s == 'u' || *s == 'U') 
            count ++;
    } 
}

int contaVogais2 (char *s) {
    int count = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] =='o' || s[i] =='O' || s[i] == 'u' || s[i] == 'U') 
            count ++;
         i++;
    }
    return count;
}

int contaVogaisRec (char *s) {
    if (*s == '\0') return 0;
    else {
        if (*s == 'a' || *s == 'A' || *s == 'e' || *s == 'E' || *s == 'i' || *s == 'I' || *s =='o' || *s=='O' || *s == 'u' || *s == 'U')
            return 1 + contaVogaisRec(s+1);
        else 
            return contaVogaisRec(s+1);
    }
}

// 2) remove de uma string todas as repeticoes consecutivas de vogais. retorna o numero de vogas removidas
/*
int retiraVogaisRep (char *s) {

}
*/


int main() {
    char texto[] = "Isto e um texto de teste.";
    char vogais[] = {'a','A','e','é','E','i','I','o','O','u','U'};
    
    printf("Vogais: %d\n", contaVogais2(texto));
    printf("Vogais em lista: %d\n", contaLetras(texto,vogais));

    return 0;
}