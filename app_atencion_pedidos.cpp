#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX 5
struct rest{
	char nom[20];char ped[100];
   float precio;
};
typedef struct rest pedidos;
int main(){
	system("COLOR 30");
	pedidos pedido,cola[MAX];
	int op,NumClient,fren=-1,fin=0;
   void insertar_cola(pedidos [],int*,int*,pedidos);
   int cola_llena(int *);
   void eliminar_cola(pedidos [],int *,int *);
   cout<<"1-Ingresar Pedido del Cliente"<<endl;
   cout<<"2-Ver Lista de Pedidos"<<endl;
   cout<<"3-Atender Pedido del Siguiente Cliente"<<endl;
   cout<<"0-Salir/exit"<<endl;
   do{
   //NumClient++;
   cout<<"Ingrese una opcion:::::: ";
   cin>>op;
   switch(op){
   	case 3:
      	cout<<"******ATENDIDO************"<<endl;
         eliminar_cola(cola,&fren,&fin);
      	break;
   	case 0:	cout<<"Saliendo...."<<endl;
      	break;
   	case 1:   //cout<<"el bool "<<cola_llena(&fin)<<endl;
                //cout<<"ver final "<<fin<<endl;          //solo muestra en pantalla el valor final noes necesario imprimir esto
                //cout<<"ver frente "<<fren<<endl;        //tambien solo muestra
      			 if(cola_llena(&fin) == 1){    //la funcion juto con el if determina si podemos seguir introducion datos
      					cout<<"\tLista de Pedidos Llena "<<endl;       //si esta llena nos dice
                     cout<<"Note: (para agregar mas pedidos favor terminar de atender los que ya estan en lista)"<<endl;
      			 }else{                                 // en caso contrario
                    		cout<<"\nNombre del Cliente: ";gets(pedido.nom);
                        cout<<"Pedido :\n";gets(pedido.ped);
                        cout<<"Precio : ";cin>>pedido.precio;
                         insertar_cola(cola,&fren,&fin,pedido);
                     }
      	break;
      case 2:
         cout<<"ver frente "<<fren<<endl;
         cout<<"ver final "<<fin<<endl;
         if(fren == -1&&fin==0||(fren == fin)){
         cout<<"lista vacida"<<endl;
         }else{
      	for(int f=fren;f<fin;f++){
            cout<<"\n\t# Client: FHG2372"<<NumClient + f<<"\n";
         	//cout<<cola[f]<<endl;
            	cout<<"\tNombre del Cliente:	"<<cola[f].nom<<endl;
               cout<<"\tPedido del Cliente:	"<<cola[f].ped<<endl;
               cout<<"\tPrecio del Cliente:	"<<cola[f].precio<<endl; }
               }
      	break;
      } }while(op!=0);
   getch();
}

void insertar_cola(pedidos cola[MAX],int *frente,int *final,pedidos dato){
	if(*final != MAX){
     	cola[*final] = dato;
      	*final += 1;
     if(*frente == -1){
      	*frente += 1; }
   }
}

int cola_llena(int *final){      //funcion que verifica si la funcion esta llena
	int b;
	return b = (*final == MAX? 1:0);   //Una simplificacion de un if clasico
}

void eliminar_cola(pedidos cola[MAX],int *frente,int *final){
   if(*frente == -1){
   	cout<<"Lista de Pedidos Vacia"<<endl;
   }else{
     	cout<<"\n\t*****PEDIDO ATENDIDO****"<<endl;
   		cout<<"\tNombre del Cliente: "<<cola[*frente].nom<<endl;
   		cout<<"\tPedido del Cliente: "<<cola[*frente].ped<<endl;
   		cout<<"\tPrecio del Cliente: "<<cola[*frente].precio<<endl;
      if(*frente == *final - 1||*frente == MAX){
      	*frente = 0;
         *final = 0;
         if(*frente <= *final){  *frente = -1; *final = 0; }
         cout<<"\nUltimo Pedido\n\tLa Lista Se a vaciado"<<endl;
      }else{ *frente += 1; }
   }
}
