
// 14) 10/10

char charMaisfreq (char s[]) {
    if(s[0]=='\0') return 0;
    
    int count = 0;
    int maxcount = 0;
    char maisfreq;
    int i,j;
    
    for(i=0;s[i]!='\0';i++) {
        for(j=0;s[j]!='\0';j++) {
            if(s[j]==s[i]) count++;
        }
        if(count>maxcount) {
            maxcount = count;
            maisfreq = s[i];
        }
        count = 0;
    }
    
    
    return maisfreq;
}

//charMaisfreq mais otimizado, só percorremos a string uma vez

char charMaisfreq2(char string[]){
    int count[256] = {0};
    int max = 0;
    int i;
    char maisfreq;
    
    for(i=0; i < strlen(string) ;i++) {
        count[(unsigned char)(string[i])] ++;
    }

    for(i=0; i < 256 ;i++) {
        if (count[i] > max) {
            max = count[i];
            maisfreq = (char) i;
        }
    }

    return maisfreq;
 }
 
// 15) 10/10

int iguaisConsecutivos (char s[]) {
    // adicione aqui o seu código...
    
    int count = 0;
    int maxcount = 0;
    
    int i,j;
    for(i=0;s[i]!='\0';i++) {
        for(j=i;s[j]!='\0';j++) {
            if(s[j]==s[i]) count++;
            else break;
        }
        if(count > maxcount) maxcount = count;
        count = 0;
    }
    
    
    return maxcount;
}

// 16) 10/10

int difConsecutivos(char s[]) 
{
    int count = 1;
    int maxcount = 0;
    
    int i,j;
    for(i=0;s[i]!='\0';i++) {
        for(j=i+1;j!='\0';j++) {
            if(s[j]!=s[i] && s[j]!=s[j-1]) count++;
            else break;
        }
        if(count>maxcount) maxcount=count;
        count = 0;
    }
    return maxcount;
}

// 17) 10/10

int maiorPrefixo (char s1 [], char s2 []) {
    int count = 0;
    int i,j;
    
    for(i=0;s1[i]!='\0' || s2[i]!='\0'; i++) {
        if(s1[i]==s2[i]) count++;
        else break;
    }
    
    return count;
}

// 18) 10/10

int maiorSufixo (char s1 [], char s2 []) { 
    // adicione o seu código aqui...
    
    int count = 0;
    
    //get length of s1 and s2
    int i,j;
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]!='\0';j++);
    
    //while(s1[i--]==s2[j--]) count++;

    int ind1, ind2;
    for(ind1=i-1,ind2=j-1; ind1>=0 || ind2>=0; ind1--,ind2--) {
        if(s1[ind1]==s2[ind2]) count++;
        else break;
    }
    return count;
}

// 19) 10/10

int sufPref (char s1[], char s2[]) {
    int res = 0;
    
    int i=0;
    int j=0;
    for(i=0;s1[i]!='\0';i++) {
        if(s1[i]== s2[j++]) res++;
        else res = j = 0;
    }
    
    return res;
}

// 20) 10/10

int contaPal (char s[]) {
    int inWord = 0, total = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            if(inWord) total++;
            inWord = 0;
        }
        else inWord = 1;
    }
    if(inWord) total++;
    return total;
}

// 21) 10/10

int contaVogais (char s[]) {
    int i=0;
    int count = 0;
    for(i=0;s[i]!='\0';i++) {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') count++;
    }
    return count;
}

// 22) 10/10

int contida (char a[], char b[]) {
    // adicione o seu código aqui...
    int i;
    int j;
    int res = 0;
    for(i=0;a[i]!='\0';i++) {
        for(j=0;b[j]!='j';j++) {
            if(a[i]==b[j]) {
                res = 1;
                break;
            }
            else res = 0;
        }
    }
    return res;
}

// 23) 10/10

int palindroma (char s[]) {

    int k;
    for(k=0;s[k]!='\0';k++);
    
    int i;
    for(i=0; s[i] ;i++) {
        if(s[i] != s[k-1]) return 0;
        else k--;
    }
    return 1;
}

// 24) 10/10

int remRep (char texto []) {
    int r = 1;
    int aux = 0;
    int i;
    if(texto[0]=='\0') return 0;

    for(i=1,aux=1;texto[i];i++) {
        if(texto[i-1]!=texto[i]) {
            texto[aux] = texto[i];
            aux++;
            r++;
        }
    }
    texto[aux] = '\0';
    return r;
}

// 25)

// 26) 10/10

void insere (int v[], int N, int x) {
    while(N>0 && v[N-1]>x)  {
        v[N]=v[N-1];
        N--;
    }
    v[N]=x;
}

// 27) 10/10

void merge (int r [], int a[], int b[], int na, int nb){
    int i=0;
    int j=0;
    int aux=0;
    while (aux < na+nb) {
        if(a[i] < b[j] && i < na || j>=nb) {
            r[aux] = a[i];
            aux++;
            i++;
        }
        else {
            r[aux] = b[j];
            aux++;
            j++;
        }
    }
}

// 28)

int crescente (int a[], int i, int j){
   int index;
   for(index=i;index<j;index++) {
       if(a[index]>a[index+1]) return 0;
   }
   return 1;
}

// 29) 10/10

int retiraNeg (int v[], int N){
    int i;
    int j;
    for(i=0;i<N;i++) {
        if(v[i]<0) {
            for(j=i;j<N;j++) {
                v[j] = v[j+1];
            }
            i--;
            N--;
        }
    }
    
    return N;
}

// 30) 10/10
#include <limits.h>

int menosFreq (int v[], int N){
   int r=-1;
   int menosfreq = 0;
   int count = 0;
   int mincount = INT_MAX;
   int i;
   int j;
   for(i=0;i<N;i++) {
       for(j=0;j<N;j++) {
           if(v[i]==v[j])  {
               count++;
           }
       }
       if(count<mincount) {
           mincount = count;
           menosfreq = v[i];
       }
       count = 0;
   }
   
   return menosfreq;
}

// Versão mais otimizada
// Como sabemos que o array está ordenado nao precisamos de 2 ciclos for
int menosFreq (int v[], int N){
   int menosfreq = 0;
   int count = 1;
   int mincount = INT_MAX;
   int i;
   for(i=1;i<N;i++) {
       if(v[i]!=v[i-1]) {
            if(count<mincount) {
                mincount = count;
                menosfreq = v[i-1];
            }
            count = 1;
       }
       else {
           count++;
       }
   }
   if(count<mincount) {
        mincount = count;
        menosfreq = v[i-1];
    }
   
   return menosfreq;
}

//31) 10/10

int maxCresc (int v[], int N) {
   int r = -1;
   // ... completar
   int i;
   int j;
   int count = 1;
   int maxcount = 0;
   
   for(i=1;i<N;i++) {
        if(v[i]>=v[i-1]) {
            count++;
        }
        else {
            if(count > maxcount) {
                maxcount = count;
            }
            count = 1;
        }
    }
    if(count > maxcount) {
                maxcount = count;
            }
    return maxcount;
}

// 32)

