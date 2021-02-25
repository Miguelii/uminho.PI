
/* Para correr no terminal:
    gcc -c triangulo.c
    gcc -c vertical.c
    gcc -c horizontal.c
    gcc -o triv triangulo.o vertical.o
    gcc -o trih triangulo.o horizontal.o
*/

void triangulo (int n);

int main () {
triangulo (5);
return 0;
}
 