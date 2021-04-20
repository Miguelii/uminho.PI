#include <stdio.h>


int main() {
    int r=0;
    int n=6;
    int c = 0;

    while (n!=1) {
        r += n;
        
        if (n%2 == 0) {
            n = n/2;
            
        }
        else {
            n = 1+(3*n);
        }
        printf("%d \n", n);
        c++;
        
    }
    printf("Contador: %d\n", c);
    printf("r: %d\n", r);
    return r;
}
