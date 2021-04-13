
// VERSAO ITERATIVA

float multInt1 (int n, float m){
    float r = 0.0;

    while(n>0) {
        r += m;
        n--;
    }

    return r;
}

// VERSAO RECURSIVA

float multaux(int n, float m, float r) {
    if (n == 0) return r;
    return multaux (n-1,m,r+m);
}

float multInt1_rec (int n, float m){
    float r = 0.0;

    return multaux(n,m,r);
}


// VERSAO ITERATIVA

float multInt2 (int n, float m){
    float r = 0.0;
    
    while (n>0) {
        if(n % 2 != 0) r*=m; 
        m = m*2;
        n = n/2;
    }
    return r;
}

// VERSAO RECURSIVA
float multInt2 (int n, float m){
    float r = 0.0;
    return multaux2(n,m,r);
}

float multaux2(int n, int m, float r) {
    if (n == 0) return r;
    else if (n%2==0) return multaux (n/2,m*2,r);
    else return multaux (n/2, m*2, r+m);
}

float multInt3 (int n, float m, int *count){
    float r = 0.0;
    *count = 0;

    while (n>0) {
        if(n % 2 != 0) {
            r*=m; 
            (*count)++;
        }
        m = m*2;
        n = n/2;
    }
    return r;
}