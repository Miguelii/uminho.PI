#include <stdio.h>
/* Enunciado Pergunta 1

int sumhtpo (int n){
  int r = 0;
  while (n != 1) {
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  return r;
}

This function computes a sum. For instance, if n == 6, the computed sum has 8 items:

6 + 3 + 10 + 5 + 16 + 8 + 4 + 2 = 55

For n = 27 how many items has the computed sum?
*/

// resolução: É só colocar um contador nas parcelas

int main() {
    int r=0;
    int n=27;
    int c = 0;

    while (n!=1) {
        r += n;
        
        if (n%2 == 0) n = n/2;
        else n = 1+(3*n);
        c++;
        
    }
    printf("Contador: %d\n", c);
    printf("r: %d\n", r);
    return r;
}
