#define Max 10

struct staticQueue {
	int front; // comprimento da queue
	int length; // cabeça da queue
	int values [Max]; // array de valores
};
typedef struct staticQueue *SQueue;

struct dinQueue {
	int size; // guarda o tamanho do array values
	int front;
	int length;
	int *values;
};
typedef struct dinQueue *DQueue;

void SinitQueue (SQueue q);
int  SisEmptyQ  (SQueue q);
int  Senqueue   (SQueue q, int x);
int  Sdequeue   (SQueue q, int *x);
int  Sfront     (SQueue q, int *x);
void ShowSQueue (SQueue q);

void DinitQueue (DQueue q);
int  DisEmptyQ  (DQueue q);
int  Denqueue   (DQueue q, int x);
int  Ddequeue   (DQueue q, int *x);
int  Dfront     (DQueue q, int *x);
void ShowDQueue (DQueue q);

