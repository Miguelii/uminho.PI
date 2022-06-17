#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PERGUNTA 5
int contido(int aux[], int x, int N) {
  
  if(N == 0) return 0;
  int k;
  for(k=0;k<N && aux[k] != x;k++);
  
  if(k==N) return 0;
  else return 1;
}


int sacos(int p[], int N, int C) {
  int aux[N];
  int index = 0;
  int peso = 0;
  int sacos = 0;
  
  for(int i=0;i<N;i++) {
    if(contido(aux,i,index) == 0) {
      peso += p[i];
      for(int j=i+1;j<N;j++) {
        if((peso + p[j] <= C) && (contido(aux,j,index) == 0))  {
          peso += p[j];
          aux[index++] = j;
        }
      }
      aux[index++] = i;
      peso = 0;
      sacos++;
    }
  }
  
  return sacos;
}

int main() {
  
  int v[] = {3,3,3,9};
  
  int res = sacos(v,4,9);
  
  printf("Sacos: %d",res);
  return 0;
}