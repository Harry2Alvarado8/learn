#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <dos.h>
//using namespace std;
typedef struct ListaInventario{
	char NombreProd[20];
  char CodigoProd[10];
	float CostoProd;
	struct ListaInventario *nodo;
}Inventario;
//typedef struct nodos nod;

Inventario *memoria(Inventario*);
int main(){
		system("color 0A");
    SetConsoleTitle("Sistema de Cuenta Inc.");
		Inventario *p;
		int menu,borraCrea = 0;//Variable borraCrea es la que me ayudara que la funcion de crear una lista cambie a insertar 
   	Inventario *PrimerMenu(Inventario *,int borraCrea); 
    Inventario *SegundoMenu(Inventario *);
    do{ system("cls");
			cout<<"\n\t********************************"<<endl;
			cout<<"\t* 1. Manipular Inventario      *"<<endl;
			cout<<"\t* 2. Facturacion de un Item    *"<<endl;
			cout<<"\t* 0. CerrarProg                *"<<endl;
			cout<<"\t********************************"<<endl;
			cout<<"::>> ";cin>>menu;
		  switch(menu){
        case 0:
              cout<<"\tSaliendo..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(1);cout<<".";
          break;
       	case 1:    p = PrimerMenu(p,borraCrea);
          break;
       	case 2:    p = SegundoMenu(p);
				  break;
				default: cout<<"Opcion Invalida!!...\n"<<endl;   break;
	   		}	}while(menu!=0);
  return 0;
}

Inventario *memoria(Inventario *x){
		x = (Inventario*)malloc(sizeof (struct ListaInventario));
		return x;
}

Inventario *PrimerMenu(Inventario *p,int borraCrea = 0){
    int menu;
    Inventario* crea_insertaLista(Inventario*,int);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime en pantalla lista completa de ultimo a primero
      do{   system("cls");
              cout<<"\n\t***************************"<<endl;
              cout<<"\t* 1. Crea/Inserta Lista   *"<<endl;
              cout<<"\t* 2. Ver Inventario       *"<<endl;
              cout<<"\t* 3. Salvar Item/Guardar  *"<<endl;
              cout<<"\t* 4. Menu Principal       *"<<endl;
              cout<<"\t***************************"<<endl;
              cout<<"::> ";cin>>menu;
              switch(menu){
                case 1:
                    borraCrea++;
                      p = crea_insertaLista(p,borraCrea);
                  break;
                case 2:
                    mostrarInventario(p);cout<<"\n\n";
                    system("pause");
                  break;
                case 3:
                     guardar(p);
                     cout<<"\nInventario Salvado, Satisfactoriamente\n\n";
                     system("pause");
                  break;
                case 4:
                    cout<<"\tRegresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";
                  break;
                default: cout<<"Opcion Invalida!!..\n\n";sleep(1);
                  break;
                  } }while(4!=menu);
      return p;
}

Inventario *SegundoMenu(Inventario *p){
  int menu;
    char buscarNomProd[20];
    Inventario* crea_insertaLista(Inventario*,int);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime lista completa de ultimo a primero
    Inventario* buscarProducto(Inventario*,char []);            //busca Elem. Char en toda la lista   Return la lista (en este caso porque eliminamos datos)
     
    do{   system("cls");
              cout<<"\n\t***************************"<<endl;
              cout<<"\t* 1. Buscar Item          *"<<endl;
              cout<<"\t* 2. Ver Inventario       *"<<endl;
              cout<<"\t* 3. Resguardar los Datos *"<<endl;
              cout<<"\t* 4. Menu Principal       *"<<endl;
              cout<<"\t***************************"<<endl;
              cout<<"::> ";cin>>menu;
            switch(menu){
                case 1:
                    cout<<"\nNombre del Item: "; cin>>buscarNomProd;
                    p = buscarProducto(p,buscarNomProd);
                    system("pause");
                  break;
                case 2:
                    mostrarInventario(p);cout<<"\n\n";
                    system("pause");
                  break;
                case 3:
                    guardar(p);
                    cout<<"\nSe a Resguardado, Satisfactoriamente\n\n";
                    system("pause");
                  break;
                case 4:
                    cout<<"\tRegresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";
                  break;
                  default: cout<<"Opcion Invalida!!..\n\n";sleep(1); break;
                  }}while(4!=menu);
}

Inventario *crea_insertaLista(Inventario *p,int borraCrea){
		//fstream file;      // DECLARACION Y VARIABLE forma directa
		int sino; Inventario*q;
     // file.open("lol.txt",ios::out);  //OPEN  forma directa
    if(borraCrea==1){
		  p = memoria(p);
			cout<<"\nNombre de Item:     \t";  cin>>p->NombreProd;
			cout<<"Codigo del Item:    \t";  cin>>p->CodigoProd;
			cout<<"Valor del Item:     \t";  cin>>p->CostoProd;
	 	//file.open("lol.txt",ios::out);
			//file << p->name <<" "<< p->num <<" "<<p->saldo <<" "<<endl;    //una forma directa de guardar
		  p->nodo = NULL;
			cout<<"\n\n";
			cout<<" [1] Seguir Ingresando"<<endl;
			cout<<" [2] Dejar de Ingresar\n"<<endl;
			cout<<"::>: ";cin>>sino;
      borraCrea++;      }
		while(sino==1 ||borraCrea !=1){
      	if(sino == 2){break;} 
      	 q = memoria(q);
    			cout<<"\nNombre de Item:  \t"; cin>>q->NombreProd;
    			cout<<"Codigo del Item   \t"; cin>>q->CodigoProd;
    			cout<<"Valor del Item:   \t"; cin>>q->CostoProd;
	 			//	file <<q->name<<" "<< p->num <<" "<<p->saldo <<" "<<endl; //una forma directa de guardar
    		  q->nodo=p;
    		  p=q;
    			cout<<"\n\n";
          cout<<" [1] Seguir Ingresando"<<endl;
				  cout<<" [2] Dejar de Ingresar\n"<<endl;
				  cout<<"::>: ";cin>>sino;
   		}
    //	file.close();   //CLOSE  forma directa
   	return p;
}

void mostrarInventario(Inventario *p){
		Inventario *q;
		q=p;
      cout<<" Nombre\t"<<"\tCosto   "<<"\tCodigo"<<endl;
      cout<<"--------------------------------------"<<endl;
		while(q!=NULL){
    			cout<<" "<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<endl;
			q=q->nodo;
   		}
}

void guardar(Inventario *p){
		fstream x;
		Inventario *q;
		q=p;
    x.open("prueba2805.txt",ios::out);
      if(!x)cout<<"Error al guardar los datos!!...\n\n";
		  while(q!=NULL){
    		x<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<endl;
			  q=q->nodo;   }
      x.close();
}

Inventario *buscarProducto(Inventario *p,char buscarNomProd[20]){
    Inventario *facturaProducto(Inventario *,char []);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int cantEncontrada=0,sino,cant_paraFacturar,m=0;
		q=p;
    cout<<"\t Nombre\t"<<"\tCosto   "<<"\tCodigo"<<endl;
    cout<<"\n\t----------------------------"<<endl;
		while(q!=NULL){
      	if(!strcmp(buscarNomProd,q->NombreProd)){
    			cout<<"\t"<<q->NombreProd<<"\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<endl; cantEncontrada++;   }
			q=q->nodo;
   		}
         if(q==NULL && cantEncontrada >= 1){
         	if(cantEncontrada == 1){cout<<"\n\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
         	if(cantEncontrada > 1){cout<<"\n\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
         cout<<"\n\tNo exite Item en esta Lista\n\n";  	}
         if(r){
         cout<<"Cantidad a Facturar\n";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"Cantidad insuficiente para el pedido\n";
         }else{
         	cout<<"\t[1] Facturar \t";
         	cout<<"[2] Cancelar \n";
         	cout<<"\n\t::> ";cin>>sino;
            if(sino==1){
              cout<<"\n\tSe ha Realizado la Facturacion del Item:\n";
              cout<<"\n\t------------------------"<<endl;    //simple estetica esto es solo para que se
         	    do{
                p = facturaProducto(p,buscarNomProd);        //funcion elimina dato
                m++;
                }while(cant_paraFacturar!=m); 
              cout<<"\n\t------------------------"<<endl;
              }}}
         return p;
}


Inventario *facturaProducto(Inventario *p,char nom[20]){
		Inventario *q,*t,*z;
      q=z=p;
      bool r = true;
      int suma=0;
			while(z!=NULL){                         //vea lo que se esta facturando o eliminado de la lista
      		if(!strcmp(nom,z->NombreProd)){
    				cout<<"\t"<<z->NombreProd<<"\t"<<z->CostoProd<<"\t"<<z->CodigoProd<<endl; /*suma++; */ break; }
					   z=z->nodo;			}
      while(strcmp(nom,q->NombreProd) && (r == true)){
      			if(q->nodo!=NULL){
               		t=q;
                     q=q->nodo;
               }else{
               		r = false;	 }
      	}
      if(r == false){
      		cout<<"Elemento con informacion x no se encuantra en lista\n\n";
      }else{
      		if(p == q){
            		p = q->nodo;
            }else{
            		t->nodo = q->nodo;
                  }
      }
      return p;
}
