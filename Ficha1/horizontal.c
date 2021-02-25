#include<stdio.h>

void triangulo (int n) {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n-i-1 ;j++) {
            putchar(' ');
        }
        for(int j=1;j<= 2*i-1; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}

// OU

void repeteChar(char c, int n) {
    for(int i=0; i<n; i++) {
        putchar(c);
    }
}

void triangulov2(int n) {
    int i = 1;
    while(i < (n*2-1)) {
        repeteChar(' ', ((n*2-1)-1)/2);
        repeteChar('#', i);
        repeteChar(' ', ((n*2-1)-1)/2);
        i += 2;
        putchar('\n');
    }
}

