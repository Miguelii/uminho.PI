
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
    for (i = 0; source[i] != 0; i++) {
        dest[i] = source[i];
    }
    dest[i] = 0;
    return dest;
}

//9
int mystrcmp (char s1 [], char s2 []) {
    int i = 0;
    while (i != -1){
        if (s1[i] == 0 && s2[i] == 0)
            return 0;
        else if (s1[i] == 0 && s2[i] != 0)
            return -1;
        else if (s1 [i] != 0 && s2 [i] == 0)
            return 1;
        else if (s1 [i] > s2 [i])
            return 1;
        else if (s1 [i] < s2 [i])
            return -1;
        i++;
    }
    return 0;
}

//10
char  *mystrstr (char s1 [], char s2 []) {
    int isThere = 1;
    char *ans = s1;
    char *aux = s2;

    while (*s2 && *s1) {
        if (*s1 != *s2) {
            isThere = 0;
            ans = s1;
        }
        if (*s1 == *s2) {
            if (!isThere) {
                isThere = 1;
                ans = s1;
            }
            s2++;
        }
        s1++;
    }
    if (isThere && !(*s2)) {
        return ans;
    }
    else return NULL;
}

//11
void mystrrev (char s[]) {

    int i = 0;
    for (i = 0; s[i]; i++);
    char aux[i];
    for (int k = i-1, j = 0; k >= 0 && j < i; aux[j++] = s[k--]);
    for (int k = 0; k < i; k++) s[k] = aux[k];
}

void tail(char* s) {
    for(; *s; s++)
        *s = *(s+1);
}

//12
void mystrnoV (char s[]) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i'
        || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u') tail(&s[i]);
    }
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

int freqC (char ch, char s[]) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ch) count++;
    }
    return count;
}

//14
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

int contaFromHere (char s[]) {
    int count = 1;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i-1]) count++;
        else break;
    }
    return count;
}

//15
int iguaisConsecutivos (char s[]) {
    int count = 0, max = -1;
    for (int i = 0; s[i]; i++) {
        if ((count = contaFromHere (&s[i])) > max) max = count;
    }
    return max;
}

//16
int difConsecutivos (char s[]) {
    int count = 1, max = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] != s[i+1]) count++;
        else {
            if (count > max) max = count;
            count = 1;
        }
    }
    return max;
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
    int count = 1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') count++;
    }
    return count;
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
    int true;
    for (int i = 0; a[i]; i++) {
        true = 0;
        for (int j = 0; b[j]; j++) {
            if (b[j] == a[i]) true = 1;
        }
        if (!true) return true;
    }
    return true;
}

//23
int palindroma (char s[]) {
    int len = 0;
    for (len = 0; s[len]; len++);
    for (int i = 0, j = len-1; s[i]; i++, j--) if (s[i] != s[j]) return 0;
    return 1;
}

//24
int remRep (char x[]) {
    if(!(*x)) return 0;
    int i = 1;
    char prev = x[0];
    while(x[i]) {
        if(x[i] == prev) tail(&x[i]);
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

int countFreq(int v[], int N, int x) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] == x) count++;
    }
    return count;
}
//30
int menosFreq (int v[], int N) {
    int min = 10000, count, res;
    for (int i = 0; i < N; i++) {
        if ((count = countFreq(v, N, v[i])) < min) { 
            min = count;
            res = v[i];
        }
    }
    return res;
}

//31
int elimRepOrd (int v[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (v[i] == v[i+1]) {
            for (int j = i; j < n; j++) v[j] = v[j+1];
            n--;
            i--;
        }
    }
    return n;
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

int checkForPresence (int v[], int idx, int x) {
    int i;
    for (i = 0; i < idx; i++) {
        if (v[i] == x) return 1;
     }
    return 0;
}

//33
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
    int count = 0;
    for (int i = 0; i < na; i++) {
        int equals = 0;
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) equals = 1;
        }
        if (equals) count++;
    }
    return count;
}

//37 
int minInd (int v[], int n) {
    int min = 1000000, i, res = -1;
    for (i = 0; i < n; i++) 
        if (v[i] < min) {
            min = v[i];
            res = i;
        }
    return res;
}

//38
void somasAc (int v[], int Ac [], int N) {
    int soma = 0, i, k;
    for (i = 0; i < N; i++) {
        soma += v[i];
        Ac[i] = soma;
    }
}

//39
int triSup (int N, float m [N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            if (m[i][j]) != 0 return 0;
        }
    }
    return 1;
}

//40
void transposta (int N, float m [N][N]) {
    int i, j;
    float transposta [N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            transposta[j][i] = m[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = transposta[i][j];
        }
    }
}

//41
void addTo (int N, int M, int a [N][M], int b[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) 
            a[i][j] += b[i][j]; 
    }
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    int i = 0;
    for (i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

//43
int intersectSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    int i = 0;
    for (i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
}

//44
int intersectMSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0; 
    int i = 0; 
    for (i = 0; i < N; i++) {
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
        len += r[i];
    }
    return len;
}

//45
int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0, i;
    for (i = 0; i < N; i++) {
        r[i] = v2[i] + v1[i];
        len += r[i];
    }
    return len;
}

//46
int cardinalMSet (int N, int v[N]) {
    int len, i;
    for (i = 0; i < N; i++) len += v[i];
    return len;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
   typedef struct posicao {
       int x, y;
   } Posicao;

//47
Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        switch(mov[i]) {
            case Norte:
                inicial.y++;
                break;
            case Sul:
                inicial.y--;
                break;
            case Oeste:
                inicial.x--;
                break;
            default:
                inicial.x++;
        }
    }
    return inicial;
}


//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    for (int i = 0; i < N; i++) {
        if (inicial.x < final.x) {
            inicial.x++;
            mov[i] = Este;
        }
        else if (inicial.x > final.x) {
            inicial.x--;
            mov[i] = Oeste;
        }
        else if (inicial.y < final.y) {
            inicial.y++;
            mov[i] = Norte;
        }
        else if (inicial.y > final.y) {
            inicial.y --;
            mov[i] = Sul;
        }
        else break;
    }
    if (final.x != inicial.x || final.y != inicial.y) return -1;
    
    return i;
}

int getDistancia (Posicao pos1, Posicao pos2) {
	return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);}

//49
int maiscentral (Posicao pos[], int N) {
    int i, aux;
    int res = -1;
    int min = 1000000;
    Posicao centro;
    centro.x = 0;
    centro.y = 0;
    for (i = 0; i < N; i++) 
        if ((aux = getDistancia(centro, pos[i])) < min) {
            min = aux;
            res = i;
        }
    return res;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (getDistancia(p, pos[i]) == 1) res++;
    }
    return res;
}