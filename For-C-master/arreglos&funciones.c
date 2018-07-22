#include<stdio.h>
void main() {
  int edades[50];
  int size,i = 0;
  int carga(int []);
  size = carga(edades);
  while (i < size) {
    i++;
    printf("%d\n",edades[i] );
  }
}
int carga(int age[50]){
  int size,j = 0;
  printf("Tamaño de el arreglo\n"); //manejo discresional
  scanf("%d",&size);
    while (j<size) {
      j++;
      printf("Ingrese Numero\n");
      scanf("%d",&age[j]);
    }
  return size;
}
