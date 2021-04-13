/*
void swap(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
*/

// 3)
// VERSAO ITERATIVA
int mdc1 (int a, int b) {
    int divisor;
    if(a<b) divisor = a;
    else divisor = b;
    while(((a%b!=0) || (b%divisor != 0)) && (divisor>1)) divisor--;

    return divisor;
}

//4)
// VERSAO ITERATIVA
int mdc2 (int a, int b){
    while (a != b) {
        if (a<b) b=b-a;
        else a=a-b;
    }
    return a;
}

// VERSAO RECURSIVA
int mdc2_rec (int a, int b){
    if (a>b) return mdc2_rec(a-b,b);
    else if (a<b) return mdc2_rec(a,b-a);
    else return a;
}

int mdc3 (int a, int b, int *count){
    while (a != b) {
        if (a<b) b=b-a;
        else a=a-b;
        (*count)++;
    }
    return a;
}

// 5)
int mdc4 (int a, int b, int *count){
    while (a != b) {
        if (a<b) b=b%a;
        else a=a%b;
        (*count)++;
    }
    return a;
}