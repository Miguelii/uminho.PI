#include <stdio.h>
#include <stdlib.h>

/* Enunciado Pergunta 2
Para n = 73 se quisermos ordenar as parecelas por ordem decrescente usando o algoritmo bubble sort quantas operações de swap seriam realizadas?

Por exemplo, para n = 6 o bubble sort faria 11 swaps.


Resolução:

Primeiro dar printf às parcelas
Na main, criar um array e copiar as parcelas para lá
No bubbleSort adicionar um contador, para contar os swaps, e um printf no fim
Por fim, fazer o bubbleSort do array que criamos com as parcelas e ver quantos swaps efetua

Nota : O bubblesort e o swap foram feitos nas aulas teoricas, mas se pedisse outro algoritmo podiam ir buscar à net um código qualquer.
*/

#include <stdio.h>
#include <stdlib.h>

int sumhtpo (int n){
  int r = 0;
  int i = 0;
  while (n != 1) {
    printf("%d,", n); // Para ver as parcelas
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  return r;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   int count = 0;
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] < arr[j+1]) {
              swap(&arr[j], &arr[j+1]);
              count++;
           }
       }
   }       
    printf("\nSwaps: %d \n",count);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d \n", arr[i]);
    printf("\n");
}

int main(){
    // Parcelas de n = 73
    //int arr[] = {73,220,110,55,166,83,250,125,376,188,94,47,142,71,214,107,322,161,484,242,121,364,182,91,274,137,412,206,103,310,155,466,233,700,350,175,526,263,790,395,1186,593,1780,890,445,1336,668,334,167,502,251,754,377,1132,566,283,850,425,1276,638,319,958,479,1438,719,2158,1079,3238,1619,4858,2429,7288,3644,1822,911,2734,1367,4102,2051,6154,3077,9232,4616,2308,1154,577,1732,866,433,1300,650,325,976,488,244,122,61,184,92,46,23,70,35,106,53,160,80,40,20,10,5,16,8,4,2};

    // Parcelas de n = 6
    int arr[] = {6,3,10,5,16,8,4,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    sumhtpo(6);

    bubbleSort(arr,n);

    printf("Array ordenado: \n");
    printArray(arr,n);

    return 0;
}

