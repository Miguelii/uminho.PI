#include <stdio.h>
#include <string.h>

// ********************** T4 *************************

Definiçao de funçoes. Localidade das variaveis

Endereço (&) de um variavel e conteudo (*) de um Endereço

Passagem de parametros por referencia

// ********************** T5 *************************

Arrays: declaraçao e uso
Arrays como endereços. Passagem de arrays como parametros


// ********************** T6 (9 de março) *************************

//-- Cenas
int x  // na maioria das vezes inteiro em 4 bytes 2^32 inteiros
	  // -2^31.. 2^31

unsigned int x // gama 0..2^32-1

long int x // na maioria das vezes inteiro representado em 8 bytes

unsigned long int x // 8 bytes para represendar numeros inteiros positivos

short in x // 2 bytes

#define A 34
#define MAX (a,b) (a>b?a:b)
//--

int main() {

	int a[10] = {1,2,3,4,5,6,7,8,9,0}

	int i,x;

	for (i=x=0; i<10; i++) 
		x+=a[i];

	return 0;
}


int sum(int v[], int N) {
	int i,x;

	i = sizeof(v);

	for (i=x=0; i<10; i++) 
		x+=v[i];
}

int main() {

	int a[10] = {1,2,3,4,5,6,7,8,9,0}

	int s;
	/*
	int s = 45;

	float f = 4.5;

	s = s/2;
	f = f/2;
	*/

	int *b;
	long int *c;

	
	s = sizeof(a);         // 10*4 = 40
	s = sizeof(int);       // 4 (int tem 4 bytes)
	s = sizeof(long int);  // 8 (long in tem 8 bytes)
	s = sizeof(b);         // 8 (endereços tem 8 bytes)

	b = a;
	b = a + 3;	  // avancei 3 inteiros

	c = a;
	c = a + 3;   // Avancei 3 long inteiros

	//s = sum(a,10);
	s = sum(b,10);

	return 0;
}


// ********************** T7 (11 de março) *************************

Strings em C sao um caso particular de arrays de caracteres

Caracter especial (cujo codigo ASCII é 0) '\0'


int comprimento (char s[]) { // strlen
    int i;
    for (i=0; *s; i++) i++;   // é igual ter *s!= '\0' ou s[i] != '\0'

    return i;
}

//char concatena (char s1[], char s2[])

char *concatena (char *s1, char *s2) {  // strcat
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i,j;

    for (j=0;i<l2;j++) s1[l1+j]=s2[j];

    s1[l1+j] = '\0';

	return s1;
}

//versao melhor do concatena
char *concatena (char *s1, char *s2) {

	char *t;
	t = s1;

	//*t != '\0'
	while (*t) t++; // vai até ao fim da primeira string

	while (*s2) {  // enquanto o s2 nao tiver vazio
		*t = *s2; // no *t ponho o que está no *s2
		t++;	  // avanço o t para a frente
		s2++;	  // avanço o s2 para a frente
	}

	*t = 0;

	return s1;
}

int main() {
    char a[20] = "Ola";
    char b[10] = "mundo";
    char *c;

    c = concatena(a,b);

    //print ("%d", comprimento(a));

    return 0;
}

// ********************** T8 (16 março) *************************

procuras de um elemento num array

em Haskell
elem :: Eq a => a -> [a] -> Bool

em C
int procura (int x, int v[], int N) {
	// retorna o indice onde x ocorre em v
	// se nao existir retorna -1
	int i; // indice para percorrer o array

	i=0;
	while(i<N && v[i]!=x) {
		i++;
	}
	if (i!=N) return i;
	else return -1;
}

É ineficiente pois só sabemos se o elemento nao pertence ao array depois de o percorrer todo

Procura em arrays ordenados (por ordem crescente)

int procura (int x, int v[], int N) {
	// v está ordenado
	int i;
	i=0;

	while(i<N && v[i]<x) {
		i++;
	}

	if (i<N && v[i]==x) return i;
	else return -1;
}

-> Procura binaria

int procuraB (int x, int v[], int N) {
	// v está ordenado
	return procuraEntre(x,v,N,0,N-1);
}

int procuraEntre(int x, int v[], int N, int inf, int sup) {
	//procura x em v entre os indices a e b
	int meio;

	if (inf > sup) return -1;

	meio = (inf+sup)/2;

	if (v[meio] == x) return meio;
	if (v[meio] > x) return (procuraEntre(x,v,N,inf,meio-1));
	return (procuraEntre(x,v,N,meio+1,sup));
}

-> Funçao mais bonita, porque o jbb diz que a anteriror é feia, sem tantos returns

int procuraEntre(int x, int v[], int N, int inf, int sup) {
	//procura x em v entre os indices a e b
	int meio;
	int r;

	if (inf > sup) r = -1;
	else {
		meio = (inf+sup)/2;

		if (v[meio] == x) r = meio;

		else if (v[meio] > x) r = procuraEntre(x,v,N,inf,meio-1);

		else r = procuraEntre(x,v,N,meio+1,sup);
	}
	return r;
}

-> Refazendo sem funçao auxiliar (tem um erro)

int procuraB (int x, int v[], int N) {

	int r,meio;

	if (N==0) r = -1;
	else {
		meio = N/2;

		if (v[meio] == x) r = meio;

		else if (v[meio] > x) r = procuraB(x,v,meio);

		else r = meio + 1 + procuraB(x,v+meio+1,N-meio-1)
	}
	return r;
}

Proximo episodio: Ordenar arrays

// ********************** T9 (18 de março) *************************

--- Funçao de ordenaçao de arrays ---

//50 minInd?
void ordenaR (int v[], int N) {
	int m, i;
	if (N>1) {
		// descobrir o indice do menor elemento
		m=0;
		for (i=1; i<N; i++) {
			if (v[i] < v[m]) m=i;
		}
		swap(v,0,m);
		ordenaR(v+1,N-1);
	}
}

void minSort (int v[], int N) {
	int m,i,j;

	for (j=0; j<N-1; j++)
		// descobrir o menor elemento desde j até N
		m=j;
		for (i=j+1; i<N; i++)
			if (v[i] < v[m]) m=i;
		swap(v,j,i);
}

void selSort (int v[], int N) {
	int i,j;

	for (j=0; i<N-1; j++)
		for (i=j+1; i<N; i++)
			if (v[i] < v[j]) swap(v,i,j);
}


void bubble (int v[], int N) {  
	int i;

	for (i=0; i<N-1; i++)
		if (v[i] > v[i+1]) swap(v,i,i+1);
}

Mete o maior elemento do array no fim
Se fizer isto N vezes vai sempre puxar o maior elemento e o array vai acabar por ficar ordenado

void bubbleSort (int v[], int N) {
	int i;

	for (i=0; i<N; i++) 
		bubble (v,N);
}

Como vimos no ctutor, chega a um ponto que o array está ordenado, mas a funçao continua a fazer bubble
Como podemos otimizar isto? 


// ********************** T9+ (23 de março) *************************

int bubble2 (int v[], int N) {
	int i;
	int r=0;

	for (i=0; i<N-1; i++)
		if (v[i] > v[i+1])
			swap (v,i,i+1)
			r=i;

	return r;
}

TPC: Fazer uma versao xpto do bubbleSort que usa o bubble2.

Em Haskell, a primeira definiçao de uma funçao de ordenaçao de listas:

isort :: Ord a => [a] -> [a]
isort [] = []
isort (h:t) = insert h (isort t)

void insSort (int v[], int N) {
	int i;
	// o array v, nos indices [0..i[ está ordenado
	i=1;
	while (i<N) {
		insere(v,i,v[i]);
		i++;
	}
}

void insere(int v[], int N, int x) {
    // v[0..N] está ordenado
    //inserir o x
    // no final v[0..N+1] está ordenado
    // 0 1 2  3  4  5  6 N=7
    // 2 4 6 10 15 24 35 8
    // x = 8

    int j;
    for (j=N-1; j>=0 && v[j]>x; j--) {
        v[j+1] = v[j]; // puxar os numeros para a frente
    }
    v[j+1] = x; // quando acaba o ciclo, ou seja, v[j]<x, entao metemos o nosso x na posiçao seguinte
}

--- Outras formas de ordenar arrays ---

-> Existem várias alternativas
-> Uma delas sao os algoritmos de Divisao e Conquista
	Divisao:
    Partir o problema em poblemas mais pequenos
    Se o array tiver N elementos, tentar ordenar N/2 elementos de cada vez
    Não é uma soluçao global para o problema, mas vai me aproximar dessa soluçao 
    Conquista:
    Fundir as soluçoes parciais na soluçao global


Merge - sort

Nota:
Para fazer uma funçao recursiva temos que ter um caso de paragem ou caso base e garantir que as
nossas chamdas recursivas sao feitas cada vez mais proximas desse caso de paragem

void merge (int a[], int na, int b[], int nb, int r[]); // funde dois arrays ordenados num só

// Funçao recursiva do mergeSort
void mergeSort(int v[], int N) {
    int m,i;
    int aux[N];
    if(N > 1) {
        m=N/2;
        // 1º metade v[0..m[ que tem m elementos
        // 2º metade v[m..N[ que tem N-m elemntos
        mergeSort(v,m); // chamar a funçao com a primeira metade, começa em v e tem m elementos
        mergeSort(v+m,N-m); // chamar a funçao com a segunda metade, começa em v+m e tem N-m elementos
        merge(v,m,v+m,N-m,aux); // o merge pega nos dois arrays, v e v+m, e preenche o array r com o merge dos dois
        // Falta pegar no resultado do aux e passar de volta para o array v
        for (i=0; i<N; i++) v[i] = aux[i];
    } 
}

// ********************** T10 (25 de março) *************************

Quick - sort

Igual ao mergeSort, exceto na parte de fundir a soluçoes onde este vai ser imediato, como se pode ver mais em baixo na funçao qSort

-> Escolher um elemento x do array (pivot)
-> Reorganizar o array de forma a que:
	Começam por aparecer totos os elementos menores ou iguais a x
	De seguida aparecem os restantes elementos (maiores do que x)

No mergeSort sabemos exatamente qual é o tamanho da primeira e segunda parte, no quickSort nao temos essa garantia

int partition (int v[], int N){
	/*
	usa como pivot o elemnto na posiçao v[N-1] (ultimo)

	no inicio _  _ _ _ _ _ _ ... _ _ _ X

			 <= <= > > > ? ? ... ? ? ? X
			 	   ^     ^             ^
			 	   r     i             N-1

	Depois do ciclo while:

			 <= <= <= > > > ? ... ? ? ? X
			 	      ^     ^           ^
			 	      r     i           N-1	
 	...
	         <= <= <= ... <= > > > > > X

	swap (v,r,N-1)

	no final <= <= <= ... <= X > > > > >
	                         ^
	                         r
	*/

	int r,i;

	r = i = 0;

	while (i<N-1) {
		if (v[i] > v[N-1]) 
			i++;
		else
			swap(v,r,i);
			r++;
			i++;
	}
	swap(v,r,N-1);
	return r;
}

-> Diz o jbb que acha mais bonito com um clico for:

int partition (int v[], int N){
	int r,i;

	for (r=i=0; i<N-1; i++) {
		if (v[i] <= v[N-1]) 
			swap(v,r,i);
			r++;
	}
	swap(v,r,N-1);
	return r;
}


void qSort (int v[], int N) {
	int p;

	if (N>1) {
		p = partition(v,N); 
		qSort(v,p);
		qSort(v+p+1,N-p-1); //o +1 e -1 é para nao incluir o X
	}
}
				<= <= <= ... <= X > > > > >
Nao é preciso fazer mais nada porque o array vai estar ordenado


--- Definiçao de tuplos em C ---

----------
int x
int y [10]

y[2] = 42; // Para actualizar uma componente era só meter o indice do que queremos actualizar 

----------
struct s {	// a struct s é uma forma de definir um par, onde a primera componente é um int e a segunda um arrays de ints
	int sp;
	int valores [Max];
}

struct s a, b[40]; // a é do tipo struct s e b um array de structs

a.sp = 5;           // A componente sp de a passa a ser 5.
a.valores[3] = 42; // 

b[2].sp = 3;       // vou a b indice 2 e ao componente sp dessa struct colocar o 3
b[3].valores[5] = 44;

proxima aula: passagem de structs como argumentos


// ********************** T11 (13 de abril) *************************

struct s {
	int sp;
	int valores [Max];
};

int x[10], y[10];

struct s a, b;

Diferenças entre struct e array

atribuiçao:

x=y está errado
a=b está correto

passagem como argumento

int f (int v[], int N);

int g (struct s a);

int main() {
	int x [400];
	struct s xxxx;

	f (x,400)
		1: Nao é feita uma copia do array
		2: quaisquer alteraçoes feitas no array pela Funçao

	g (xxxx)
		1: É feita uma copia do argumento (computacionalmente relevante)
		2: quaisquer alteraçoes feitas à struct pela funçao nao sao visiveis no exterior
}

------- Exemplo: Stack de inteiro --------

push acrescentrar um elemento
pop returar um elemento
top qual o proximo elemento a ser retirado
empty saber se a stack está vazia

// diferenças de typedef
int A;         <- A é uma variavel do tipo int
typedef int B; <- B é um tipo equivalente a int 
B x;           <- x é uma variavel do tipo B i.e., int

// diferenças de struct
int s;         <- s é uma variavel do tipo int
char s;        <- s é uma variavel do tipo char
struct stack {
	int valores [100];
	int quantos;
} s;           <- s é uma variavel cujo o tipo é struct stack


--- Exemplo de implementaçao de stack de inteiros ---

typedef struct stack { // A diferença é exatamente igual ao exemplo que vimos em cima
	int valores [100];
	int quantos;
} STACK;           

// os valores sao inseridos da esquerda para a direita

STACK push(int x, STACK s ) {
	s.valores[s.quantos++] = x;
	return s;
}

STACK pop(STACK s) {
	s.quantos--;
}

int top(STACK s) {
	return (s.valores[s.quantos - 1]);
}

int empty(STACK s) {
	return (s.quantos == 0);
} 

int main() {
  STACK s1;
  int aaa;
  s1.quantos = 0;
  s1 = push (3,s1);
  aaa = top (s1);
  return 0;
}

Como vimos no ctutor, esta implementaçao é lenta porque qualquer chamada à struct cria uma copia
-> Proxima aula ver como melhorar com recurso a apontadores;

// ********************** T12 (15 de abril) *************************




