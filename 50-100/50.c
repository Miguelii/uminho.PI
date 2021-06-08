//1
void le_seq () {
    int max = 0;
    int c = 1;
    while (c != 0) {
        printf("Insere um numero: ");
        scanf("%d", &c);
        if (max < c) max = c;
    }
    printf("O maior número é: %d\n", max);
}

//2
void avg() {
    int i = 0;
    float c = 1, soma = 0;
    while (c != 0) {
        printf("Insere um numero: ");
        scanf("%f", &c);
        soma += c;
        i++;
    } 
    float media = soma/(i-1);
    printf("Media: %.2f\n", media);
}

//3
void segundo_maior () {
    int max = 0, second = 0;
    int c = 1;
    while (c != 0) {
        printf("Insere um numero: ");
        scanf("%d", &c);
        if (c > max) {
            second = max;
            max = c;
        }
        else if (c > second && c < max) second = c;
    }
    printf("O segundo maior e: %d\n", second);
}

//4
int bitsUm(unsigned int N) {
    int count1 = 0;
    while (N > 0) {
        if (N % 2 != 0)
            count1++;
        N /= 2;
    }
    return count1;
}

//5
int trailingZ (unsigned int n) {
    int count = 0, i;
    //int tem 32 bits
    for (i = 0; i < 32; i++, n /= 2) {
        if (n % 2 != 0)
            break;
        else 
            count++;
    }
    return count;
}

//6
int qDig (unsigned int n) {
    int count = 0;
    if (n == 0) return 1;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

//7
char *mystrcat (char s1[], char s2[]) {
    int i, k, j;
    for (i = 0; s1[i] != 0; i++);
    for (k = 0; s2[k] != 0; k++, i++)
        s1[i] = s2[k];

    s1[i] = '\0';
    return s1;
}

//8
char *mystrcpy (char *dest, char source []) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

//9
int mystrcmp(char s1[], char s2[]) {
    int i;
    for(i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return s1[i]-s2[i];
}

//10
char *mystrstr(char s1[], char s2[]) {
    char *res = NULL;
    int i,p;
    if (s2[0] == '\0') return s1;
    for(i = 0; s1[i] != '\0' && res == NULL; i++) {
        for(p = 0; s2[p] != '\0' && s2[p] == s1[i+p];p++);
        if (s2[p] == '\0')
            res = s1 + i;
    }
    return res;
}

//11
void mystrrev (char s[]) {

    int i = 0;
    for (i = 0; s[i]; i++);
    char aux[i];
    for (int k = i-1, j = 0; k >= 0 && j < i; aux[j++] = s[k--]);
    for (int k = 0; k < i; k++) s[k] = aux[k];
}

//12
void strnoV (char t[]){
    int i, pos;
    for (i = 0, pos = 0; t[i] != '\0';i++) {
        if (t[i] != 'a' &&
            t[i] != 'e' &&
            t[i] != 'i' &&
            t[i] != 'o' &&
            t[i] != 'u' &&
            t[i] != 'A' &&
            t[i] != 'E' &&
            t[i] != 'I' &&
            t[i] != 'O' &&
            t[i] != 'U') {
            t[pos++] = t[i];
        }
    }
    t[pos] = '\0';
}

//13
void truncW (char t[], int n) {
    int wordLen = 0;
    while(*t) {
        if(*t == ' ' || *t == '\n' || *t == '\t') {t++; wordLen = 0;}
        else {
            if(wordLen++ >= n) tail(t);
            else t++;
        }
    } 
}



//14

int freqC (char ch, char s[]) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ch) count++;
    }
    return count;
}

char charMaisfreq (char s[]) {
    char maisfreq = 0;
    int freqMax = 0, freq;
    for (int i = 0; s[i]; i++) {
        if ((freq = freqC(s[i], s)) > freqMax) {
            freqMax = freq;
            maisfreq = s[i];
        }
    }
    return maisfreq;
}

//15

int iguaisConsecutivos (char s[]) {
    int consec = 1, max = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == s[i + 1]) consec++;
        else {
            if(consec > max) max = consec;
            consec = 1;
        }
    }
    return max;
}

//16

int not_in_prev(char str[], int k, int n) {
    int ans = 1;
    for(int i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int ans = 0;
    for(size_t i = 0; s[i]; i++) {
        int consec = 0;
        for(size_t j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}

//17
int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for (int i = 0; s1[i] == s2[i] && s1[i]; i++);
    return i;
}

//18
int maiorSufixo (char s1 [], char s2 []) {
    int i = 0, j = 0, k = 0;
    for (i = 0; s1[i]; i++);
    for (j = 0; s2[j]; j++);
    while (s1[i--] == s2[j--]) k++;
    return k;
}

//19
int sufPref (char s1[], char s2[]) {
    int ans = 0, i, j= 0;
    for (i = 0; s1[i]; i++) {
        if (s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
}

//20
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

//21
int contaVogais (char s[]) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i'
        || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u') count++;
    }
    return count;
}

//22
int contida (char a[], char b[]) {
    int cont = 1;
    for(int i = 0; a[i]; i++) {
        int pertence = 0;
        for(int j = 0; b[j]; j++) {
            if(a[i] == b[j]) pertence = 1;
        }
        if(!pertence) {
            cont = 0;
            break;
        }
    }
    return cont;
}

//23
int palindrome (char s[]) {
    int len = 0;
    for(int i = 0; s[i]; i++) len++;
    for(int i = 0; s[i]; i++) if(s[i] != s[len - 1 - i]) return 0;
    return 1;
}

//24
int remRep (char x[]) {
    if(!(*x)) return 0;
    int i = 1;
    char prev = x[0];
    while(x[i]) {
        if(x[i] == prev) tail(x + i);
        else prev = x[i++];
    }
    return i;
}

//25
int limpaEspacos (char t[]) {
    int i = 0;
    int prevSpace = 0;
    while(t[i]) {
        if(t[i] == ' ') {
            if(prevSpace) {
                tail(t + i);
                continue;
            }
            else prevSpace = 1;
        }
        else prevSpace = 0;
        i++;
    }
    return i;
}

//26
void insere (int v[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (v[i] >= x) {
            for (int j = N; j > i; j--) {
                v[j] = v[j-1];
            }
            v[i] = x;
            N++;
            break;
        }
        if (i == N-1) {
            v[N] = x;
            N++;
        }
    }
}

//27
void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;

    while (k < na + nb) {
        if (a[i] < b[j] && i < na || j >= nb) {
            r[k++] = a[i++];
        }
        else r[k++] = b[j++];
    }
}

//28
int crescente (int a[], int i, int j) {
    int cresc = 1;
    for (int k = i; k < j-1; k++) {
        if (a[k+1] < a[k]) cresc = 0;
    }
    return cresc;
}

//29
int retiraNeg (int v[], int N) {
    for (int i = 0; i < N; i++) {
        if (v[i] < 0) {
            for (int j = i; j < N; j++) {
                v[j] = v[j+1];
            }
            N--;
            i--;
        }
    }
    return N;
}

//30

int menosFreq (int v[], int N) {
    int freq = 1, minFreq = N, ans = v[0], i;
    for(i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq < minFreq) {
                minFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if(freq < minFreq) {
        minFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}

//31

int maisFreq (int v[], int N) {
    int freq = 1, maxFreq = 0, ans = v[0];
    for(int i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    return ans;
}

//32
int maxCresc (int v[], int N) {
    int count = 1, max = -1, i;
    for (i = 1; i < N; i++) {
        if (v[i] >= v[i-1]) count++;
        else {
            max = count > max ? count : max;
            count = 1;
        }
    }
    max = count > max ? count : max;
    return max;
}



//33
int checkForPresence (int v[], int idx, int x) {
    int i;
    for (i = 0; i < idx; i++) {
        if (v[i] == x) return 1;
     }
    return 0;
}

int elimRep (int v[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (checkForPresence(v, i, v[i])) {
            for (j = i; j < n; j++) v[j] = v[j+1];
            n--;
            i--;
        }
    }
    return n;
}

//34
int elimRepOrd (int v[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        if (v[i] == v[i-1]) {
            for (j = i; j < n; j++) v[j] = v[j+1];
            n--;
            i--;
        }
    }
    return n;
}

//35
int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, ans = 0;
    while(i < na && j < nb) {
        if(a[i] == b[j]) {
            ans++;
            i++;
            j++;
        }
        else if(a[i] > b[j]) j++;
        else i++;
    }
    return ans;
}

//36
int comuns (int a[], int na, int b[], int nb) {
    int ans = 0;
    for(int i = 0; i < na; i++) {
        int belongs = 0;
        for(int j = 0; j < nb; j++) if(a[i] == b[j]) belongs = 1;
        if(belongs) ans++;
    }
    return ans;
}

//37 
int minInd (int v[], int n) {
    int minIndex = 0;
    for(int i = 1; i < n; i++) 
        if(v[i] < v[minIndex]) 
            minIndex = i;
    return minIndex;
}

//38
void somasAc (int v[], int Ac [], int N) {
    for(int i = 0; i < N; i++) {
        Ac[i] = 0;
        for(int j = 0; j <= i; j++) {
            Ac[i] += v[j];
        }
    }
}

//39
int triSup (int N, float m [N][N]) {
    int x = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(m[i][j]) x = 0;
        }
    }
    return x;
}

//40
void transposta (int N, float m[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//41
void addTo (int N, int M, int a[N][M], int b[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            *(*(a + i)+j) += b[i][j];
        }
    }
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

//43
int intersectSet (int N, int v1[N], int v2[N],int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
}

//44
int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
        len += r[i]; 
    }
    return len;
}

//45
int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i];
        len += r[i]; 
    }
    return len;
}

//46
int cardinalMSet (int N, int v[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) len += v[i];
    return len;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
   typedef struct posicao {
       int x, y;
   } Posicao;

//47
Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    for(int i = 0; i < N; i++) {
        Movimento x = mov[i];
        if(x == Norte) inicial.y++;
        if(x == Este) inicial.x++;
        if(x == Sul) inicial.y--;
        if(x == Oeste) inicial.x--;
    }
    return inicial;
}


//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    int* xi = &inicial.x;
    int* yi = &inicial.y;
    int xf = final.x, yf = final.y, i;
    for(i = 0; i < N; i++) {
        if((*xi) < xf) {
            (*xi)++;
            mov[i] = Este;
        }
        else if ((*xi) > xf) {
            (*xi)--;
            mov[i] = Oeste;
        } 
        else if ((*yi) < yf) {
            (*yi)++;
            mov[i] = Norte;
        }
        else if ((*yi) > yf) {
            (*yi)--;
            mov[i] = Sul;
        }
        else break;
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}


//49

int manDist(int x, int y, int x0, int y0) {
    return abs(x - x0) + abs(y - y0);
}

int maisCentral (Posicao pos[], int N) {
    int minDist = manDist(pos[0].x,pos[0].y,0,0);
    int ans = 0, i;
    for(i = 1; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,0,0) < minDist) {
            ans = i;
            minDist = manDist(pos[i].x,pos[i].y,0,0);
        }
    }
    return ans;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N) {
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,p.x,p.y) == 1) ans++;
    }
    return ans;
}