/* Crear una funcion sin retorno que tome como argumento
   una variable la altere dentro de la funcion a la variable
   y la imprima dentro de la funcion y en el MAIN
*/
#include<stdio.h>
void main(){
  int *cambio_valor(int *,int *);
  int a,b;
  int *apt;
  printf("Ingresa dos numeros, se te devolvera el mayor\n");
  scanf("%d",&a);
  scanf("%d",&b);
  *apt = *cambio_valor(&a,&b);
  printf("El cambio del valor es a:%d----- b:%d------ apt: %d \n",a,b,*apt);
}

int *cambio_valor(int *a,int *b){
  a = a + 5;*b += 5;
  printf("%d\n",*a );
  printf("%d\n",*b );
  return a;
}
