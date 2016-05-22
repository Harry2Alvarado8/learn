#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
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
   do{
   if(fren!=-1){system("pause");}//Esto es solo para que no se inicie en al momento de iniciar el programa
   cout<<"\t\n\t************************************************"<<endl;
   cout<<"\t*\t1-Ingresar Pedido del Cliente          *"<<endl;
   cout<<"\t*\t2-Ver Lista de Pedidos                 *"<<endl;
   cout<<"\t*\t3-Atender Pedido del Siguiente Cliente *"<<endl;
   cout<<"\t*\t0-Salir/exit                           *"<<endl;
   cout<<"\t************************************************"<<endl;
   cout<<"\n\tIngrese una opcion:::> ";     cin>>op;
   switch(op){
   	case 0:	cout<<"\n\tSaliendo.";sleep(1);cout<<".";sleep(1);cout<<".";sleep(1);cout<<".";
      	break;
   	case 1:
      			 if(cola_llena(&fin) == 1){    //la funcion juto con el if determina si podemos seguir introducion datos
      					cout<<"\tLista de Pedidos Llena "<<endl;
                     cout<<"Note: (para agregar mas pedidos favor terminar de atender los que ya estan en lista)"<<endl;
      			 }else{
                		cout<<"\nNombre del Cliente: ";gets(pedido.nom);
                     cout<<"Pedido : ";gets(pedido.ped);
                     cout<<"Precio : B/. ";cin>>pedido.precio;
                     insertar_cola(cola,&fren,&fin,pedido);		}
      	break;
      case 2:
         //cout<<"ver frente "<<fren<<endl;
         //cout<<"ver final "<<fin<<endl;
         if(fren == -1&&fin==0||(fren == fin)){
         cout<<"\nlista vacida!!.."<<endl;
         }else{
      	for(int f=fren;f<fin;f++){
            cout<<"\n\t# Client: FH32"<<NumClient + f<<"\n";
            	cout<<"\tNombre del Cliente:	"<<cola[f].nom<<endl;
               cout<<"\tPedido del Cliente:	"<<cola[f].ped<<endl;
               cout<<"\tPrecio del Cliente:	"<<cola[f].precio<<endl; }
               }
      	break;
      case 3:
      	cout<<"\n\t********PEDIDOS************"<<endl;
         eliminar_cola(cola,&fren,&fin);
      	break;
      default:
      	cout<<"\nOpcion Invalida!!!..."<<endl;
      	break;
      } }while(op!=0);
   //getch();
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
