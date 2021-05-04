#include <stdio.h>
/*  Relembre a seguinte função.

int sumhtpo (int n){
  int r = 0;
  while (n != 1) {
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  return r;
}

Esta função calcula um somatório. Para n = 97 a menor parcela desse somatório é 2. A 2ª menor é 4. Qual é a 30ª menor parcela?

*/

// Resolução

int main() {
    int r=0;
    int n=6;
    int c = 0;

    while (n!=1) {
        r += n;
        printf("%d \n", n);
        
        if (n%2 == 0) {
            n = n/2;
            
        }
        else {
            n = 1+(3*n);
        }
        c++;
        
    }
    printf("Contador: %d\n", c);
    printf("r: %d\n", r);
    return r;
}
