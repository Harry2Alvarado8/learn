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
    char menu;
		bool borraCrea=false;//Variable borraCrea es la que me ayudara que la funcion de crear una lista cambie a insertar 
   	Inventario *PrimerMenu(Inventario *,bool *); 
    Inventario *SegundoMenu(Inventario *,bool *);
    do{ system("cls");
			cout<<"\n\t********************************"<<endl;
			cout<<"\t* 1. Manipular Inventario      *"<<endl;
			cout<<"\t* 2. Facturacion de un Item    *"<<endl;
			cout<<"\t* 0. CerrarProg                *"<<endl;
			cout<<"\t********************************"<<endl;
			cout<<"::>> ";cin>>menu;
		  switch(menu){
        case '0':
              cout<<"\tSaliendo..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(1);cout<<".";
          break;
       	case '1':    p = PrimerMenu(p,&borraCrea);
          break;
       	case '2':    p = SegundoMenu(p,&borraCrea);
				  break;
				default: cout<<"Opcion Invalida!!...\n"<<endl;   break;
	   		}	}while(menu!='0');
  return 0;
}

Inventario *memoria(Inventario *x){
		x = (Inventario*)malloc(sizeof (struct ListaInventario));
		return x;
}

Inventario *PrimerMenu(Inventario *p,bool *borraCrea){
    char menu;
    Inventario* crea_insertaLista(Inventario*,bool *);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime en pantalla lista completa de ultimo a primero
      //borraCrea++;
      do{   system("cls");
              cout<<"\n\t***************************"<<endl;
              cout<<"\t* 1. Crea/Inserta Lista   *"<<endl;
              cout<<"\t* 2. Ver Inventario       *"<<endl;
              cout<<"\t* 3. Salvar Item/Guardar  *"<<endl;
              cout<<"\t* 4. Menu Principal       *"<<endl;
              cout<<"\t***************************"<<endl;
              cout<<"::> ";cin>>menu;
              switch(menu){
                case '1':
                      p = crea_insertaLista(p,borraCrea);
                  break;
                case '2':
                  //borraCrea++;
                  if(*borraCrea){
                    mostrarInventario(p);cout<<"\n\n";
                  }else{cout<<"No se ha Creado Ninguna lista\n\n";}
                  system("pause");
                  break;
                case '3':
                  //borraCrea++;
                  if(*borraCrea){guardar(p); 
                     cout<<"\nInventario Salvado, Satisfactoriamente\n\n";
                  }else{cout<<"No se ha Creado Ninguna lista\n\n";}
                     system("pause");
                  break;
                case '4':
                    cout<<"\tRegresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";
                  break;
                default: cout<<"Opcion Invalida!!..\n\n";sleep(1);
                  break;
                  } }while('4'!=menu);
      return p;
}

Inventario *SegundoMenu(Inventario *p,bool *borraCrea){
    char menu;//buscarNomProd[20];
    Inventario* crea_insertaLista(Inventario*,bool);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime lista completa de ultimo a primero
    Inventario* buscarProducto(Inventario*);            //busca Elem. Char en toda la lista   Return la lista (en este caso porque eliminamos datos)
     
    do{   system("cls");
              cout<<"\n\t***************************"<<endl;
              cout<<"\t* 1. Buscar Item          *"<<endl;
              cout<<"\t* 2. Ver Inventario       *"<<endl;
              cout<<"\t* 3. Resguardar los Datos *"<<endl;
              cout<<"\t* 4. Menu Principal       *"<<endl;
              cout<<"\t***************************"<<endl;
              cout<<"::> ";cin>>menu;
            switch(menu){
                case '1':
                    if (*borraCrea){
                      p = buscarProducto(p);
                    }else{
                      cout<<"No se ha Creado Ninguna lista\n\n";  }
                     
                     system("pause");
                  break;
                case '2':
                  if(*borraCrea){
                    mostrarInventario(p);cout<<"\n\n";
                  }else{
                    cout<<"No se ha Creado Ninguna Lista\n\n";
                  }
                    system("pause");
                  break;
                case '3':
                  if(*borraCrea){
                    guardar(p);
                    cout<<"\nSe a Resguardado, Satisfactoriamente\n\n";
                  }else{
                    cout<<"No se ha Creado Ninguna Lista\n\n";}
                    system("pause");
                  break;
                case '4':
                    cout<<"\tRegresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";
                  break;
                  default: cout<<"Opcion Invalida!!..\n\n";sleep(1); break;
                  }}while('4'!=menu);
}
Inventario *buscarProducto(Inventario *p){
    char menu,NombreProd[20],CodigoProd[10];
    float PrecioProd;
    int clear=0;
    Inventario* buscarNombrePdo(Inventario*,char []);            //busca Elem. Char en toda la lista   Return la lista (en este caso porque eliminamos datos)
    Inventario* buscarCodigoPdo(Inventario*,char []);
    Inventario* buscarPrecioPdo(Inventario*,float);
    do{if(clear>=1){system("cls");}
      cout<<"\n\n";clear++;
      cout<<"\tComo deseas buscar el producto?\n";
      cout<<"\t [1] Nombre\n";
      cout<<"\t [2] Codigo\n";
      cout<<"\t [3] Precio\n";
      cout<<"\t [4] Dejar de buscar\n";
      cout<<"::> ";cin>>menu;
      switch(menu){
        case '1':
              cout<<"\nNombre del Item: "; cin>>NombreProd;
                p = buscarNombrePdo(p,NombreProd);
              system("pause");
          break;
        case '2':
              cout<<"\nCodigo del Item: "; cin>>CodigoProd;
                p = buscarCodigoPdo(p,CodigoProd);
              system("pause");
          break;
        case '3':
              cout<<"\nPrecio del Item: "; cin>>PrecioProd;
                p = buscarPrecioPdo(p,PrecioProd);
              system("pause");
          break;
        case '4':
          break;
        default:cout<<"Opcion Invalida!!..."<<endl;
          break;
        }}while(menu!='4');
        return p;
}
Inventario *crea_insertaLista(Inventario *p,bool *borraCrea){
		//fstream file;      // DECLARACION Y VARIABLE forma directa
		char sino; Inventario*q;
     // file.open("lol.txt",ios::out);  //OPEN  forma directa
    if(*borraCrea == false){
      *borraCrea=true;
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
      if(!(sino=='1'||sino=='2')){
        cout<<" '"<<sino<<"' no es una Opcion"<<endl; }
         }
		while(sino=='1' ||*borraCrea !=false){
      	if(sino == '2'){break;} 
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
				  cout<<"::>: ";cin>>sino;if(!(sino=='1'||sino=='2')){
            cout<<" '"<<sino<<"' no es una Opcion,(1 o 2 son las opciones)\n"<<endl;system("pause");break; }
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

Inventario *buscarNombrePdo(Inventario *p,char NombrePdo[20]){
    Inventario *facturaProducto(Inventario *,char [],float ,int ,int *,int *,int *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 1,cantEncontrada=0,cant_paraFacturar,m=0,Total,SubTotal,ITBM;
		char sino;
    q=p;
    cout<<"\t Nombre\t"<<"Costo "<<"\tCodigo"<<endl;
    cout<<"\t----------------------------"<<endl;
		while(q!=NULL){
      	if(!strcmp(NombrePdo,q->NombreProd)){
    			cout<<"\t "<<q->NombreProd<<"\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<endl; cantEncontrada++;   }
			q=q->nodo;
   		}
         if(q==NULL && cantEncontrada >= 1){
         	if(cantEncontrada == 1){cout<<"\n\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
         	if(cantEncontrada > 1){cout<<"\n\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
         cout<<"\n\tNo exite Item en esta Lista\n\n";  	}
         if(r){
         cout<<"Cantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"Cantidad insuficiente para el pedido\n";
         }else{
         	cout<<"\t[1] Facturar \t";
         	cout<<"[2] Cancelar \n";
         	cout<<"\n\t::> ";cin>>sino;
            if(sino=='1'){
              cout<<"\n\tSe ha Realizado la Facturacion del Item:\n\n";
              cout<<"\t Nombre\t"<<"Codigo"<<"\t\tCosto"<<endl;
              cout<<"\t----------------------------------"<<endl;
         	    do{
                p = facturaProducto(p,NombrePdo,NULL,x,&Total,&SubTotal,&ITBM);        //funcion elimina dato
                m++;
                }while(cant_paraFacturar!=m); 
                cout<<"\n\t----------------------------------"<<endl;
                cout<<"\t SubTotal:\t\t"<<SubTotal<<endl;
                cout<<"\t ITBM:    \t\t"<<ITBM<<endl;
                cout<<"\t----------------------------------"<<endl;
                cout<<"\t Total:   \t\t"<<Total<<endl;
                cout<<"\t----------------------------------"<<endl;
              }else if(sino=='2'){cout<<"Pedido Cancelado....";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}

Inventario *buscarCodigoPdo(Inventario *p,char CodigoPdo[10]){
    Inventario *facturaProducto(Inventario *,char [],float ,int ,int *,int *,int *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 2,cantEncontrada=0,cant_paraFacturar,m=0,Total,SubTotal,ITBM;
    char sino;
    q=p;
    cout<<"\t Nombre\t"<<"Costo "<<"\tCodigo"<<endl;
    cout<<"\t----------------------------"<<endl;
    while(q!=NULL){
        if(!strcmp(CodigoPdo,q->CodigoProd)){
          cout<<"\t "<<q->NombreProd<<"\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<endl; cantEncontrada++;   }
      q=q->nodo;
      }
         if(q==NULL && cantEncontrada >= 1){
          if(cantEncontrada == 1){cout<<"\n\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
          if(cantEncontrada > 1){cout<<"\n\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
         cout<<"\n\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"Cantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"Cantidad insuficiente para el pedido\n";
         }else{
          cout<<"\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t::> ";cin>>sino;
           // if(!(sino=='1')){
            //    cout<<" '"<<sino<<"' no es una Opcion"<<endl; }
            if(sino=='1'){
              cout<<"\n\tSe ha Realizado la Facturacion del Item:\n\n";
              cout<<"\t Nombre\t"<<"Codigo"<<"\t\tCosto"<<endl;
              cout<<"\t----------------------------------"<<endl;
              do{
                p = facturaProducto(p,CodigoPdo,NULL,x,&Total,&SubTotal,&ITBM);        //funcion elimina dato
                m++;
                }while(cant_paraFacturar!=m); 
                cout<<"\n\t----------------------------------"<<endl;
                cout<<"\t SubTotal:\t\t"<<SubTotal<<endl;
                cout<<"\t ITBM:    \t\t"<<ITBM<<endl;
                cout<<"\t----------------------------------"<<endl;
                cout<<"\t Total:   \t\t"<<Total<<endl;
                cout<<"\t----------------------------------"<<endl;
              }else if(sino=='2'){cout<<"Pedido Cancelado....";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}

Inventario *buscarPrecioPdo(Inventario *p,float PrecioPdo){
    Inventario *facturaProducto(Inventario *,char [],float ,int ,int *,int *,int *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 3,cantEncontrada=0,cant_paraFacturar,m=0,Total,SubTotal,ITBM;
    char sino;
    q=p;
    cout<<"\t Nombre\t"<<"Costo "<<"\tCodigo"<<endl;
    cout<<"\t----------------------------"<<endl;
    while(q!=NULL){
        if(PrecioPdo==q->CostoProd){
          cout<<"\t "<<q->NombreProd<<"\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<endl; cantEncontrada++;   }
      q=q->nodo;
      }
         if(q==NULL && cantEncontrada >= 1){
          if(cantEncontrada == 1){cout<<"\n\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
          if(cantEncontrada > 1){cout<<"\n\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
         cout<<"\n\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"Cantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"Cantidad insuficiente para el pedido\n";
         }else{
          cout<<"\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t::> ";cin>>sino;
           // if(!(sino=='1')){
            //    cout<<" '"<<sino<<"' no es una Opcion"<<endl; }
            if(sino=='1'){
              cout<<"\n\tSe ha Realizado la Facturacion del Item:\n\n";
              cout<<"\t Nombre\t"<<"Codigo"<<"\t\tCosto"<<endl;
              cout<<"\t----------------------------------"<<endl;
              do{
                p = facturaProducto(p,NULL,PrecioPdo,x,&Total,&SubTotal,&ITBM);        //funcion elimina dato
                m++;
                }while(cant_paraFacturar!=m); 
                cout<<"\n\t----------------------------------"<<endl;
                cout<<"\t SubTotal:\t\t"<<SubTotal<<endl;
                cout<<"\t ITBM:    \t\t"<<ITBM<<endl;
                cout<<"\t----------------------------------"<<endl;
                cout<<"\t Total:   \t\t"<<Total<<endl;
                cout<<"\t----------------------------------"<<endl;
              }else if(sino=='2'){cout<<"Pedido Cancelado....";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}


Inventario *facturaProducto(Inventario *p,char nom[20],float PrecioProd,int x,int *Total=0,int *SubTotal=0,int *ITBM=0){
    Inventario *q,*t,*z;
      q=z=p;
      bool r = true;
      int suma=0;
      if(x == 1){
        while(z!=NULL){                         //vea lo que se esta facturando o eliminado de la lista
          if(!strcmp(nom,z->NombreProd)){
            cout<<"\t "<<z->NombreProd<<"\t"<<z->CodigoProd<<"\t\t"<<z->CostoProd<<endl; /*suma++; */
               *SubTotal+=z->CostoProd; break;}
             z=z->nodo;     }
        while(strcmp(nom,q->NombreProd) && (r == true)){
            if(q->nodo!=NULL){
                  t=q;   q=q->nodo;
               }else{  r = false;   }
        }
      }else if(x == 2){
        while(z!=NULL){                         //vea lo que se esta facturando o eliminado de la lista
          if(!strcmp(nom,z->CodigoProd)){
            cout<<"\t "<<z->NombreProd<<"\t"<<z->CodigoProd<<"\t\t"<<z->CostoProd<<endl; /*suma++; */
              *SubTotal+=z->CostoProd; break;}
            z=z->nodo;     }
        while(strcmp(nom,q->CodigoProd) && (r == true)){
            if(q->nodo!=NULL){
               t=q;    q=q->nodo;
               }else{  r = false;   }
        }
      }else if (x == 3){
        while(z!=NULL){                         //vea lo que se esta facturando o eliminado de la lista
          if(PrecioProd == z->CostoProd){
            cout<<"\t "<<z->NombreProd<<"\t"<<z->CodigoProd<<"\t\t"<<z->CostoProd<<endl; /*suma++; */
              *SubTotal+=z->CostoProd; break;}
            z=z->nodo;     }
        while((PrecioProd!=q->CostoProd) && (r == true)){
            if(q->nodo!=NULL){
               t=q;    q=q->nodo;
               }else{   r = false;   }
        }
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
      *ITBM = (*SubTotal * 0.07);
      *Total = *ITBM + *SubTotal;
      return p;
}