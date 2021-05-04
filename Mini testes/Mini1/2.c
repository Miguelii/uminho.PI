
int x,y;
for (y=0;y<8;y++) {    
  for (x=0;x<8;x++) {
    if (x [A] y == [C]) putchar('#');
    else putchar('.');
  }
  putchar('\n');
}

/*
Identifique o código a colocar nos slots assinalados para que o programa desenhe a seguinte figura.

#.......
.#......
..#.....
...#....
....#...
.....#..
......#.
.......#

[A] = -
[B] = 0

Olhando para a figura, chegamos facilmente ao resultado pedido x-y==0
*/

