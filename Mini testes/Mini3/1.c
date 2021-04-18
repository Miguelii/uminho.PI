#include <stdio.h>
/* Enunciado Pergunta 1
Copiar de uma função de hash tem por objectivo calcular um inteiro a partir de uma string. 
Um exemplo de uma função de hash muito simples consiste em somar todos os códigos ASCII da string. 
Esta função pode ser implementada da seguinte forma.

int hash (char s[]) {
  int r = 0;
  while (*s) {r += *s; s++;}
  return r;
}

Com esta função o valor de hash da string "abc" é 294 = 97+98+99.

Uma estratégia melhor para calcular um valor de hash consiste em multiplicar cada código ASCII 
pela posição em que o respectivo caracter aparece na string (contada a partir do início). 
Com esta estratégia o valor de hash da string "abc" passaria a ser 590 = 97*1+98*2+99*3. 

Com esta estratégia qual seria o valor de hash da string "programacao imperativa"?
*/

// Resolução:

int hash(char s[]) {
    int r = 0;
    int i = 1;
    while (*s) {
        //r += *s;
        r = r + (*s)*i;
        s++;
        i++;
    }
    return r;
}

int main() {
    char s[] = "programacao imperativa";

    printf("Valor: %d\n", hash(s));
}
