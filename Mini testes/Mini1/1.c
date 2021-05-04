

int func(int x) {
  int r = 0;
  while (x > 0) {
    r += 2;
    x = x - r;
  }
  return r;
}

// Qual o maior valor de x que faz com que seja produzido o resultado 4? -> 6

// Chegamos facilmente ao resultado fazendo os calculos  

