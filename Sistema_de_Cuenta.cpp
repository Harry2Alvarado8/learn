#include <stdlib.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <dos.h>
//using namespace std;
typedef struct ListaInventario{
  char NombreProd[20];
  char CodigoProd[7];
  float CostoProd;
  int CantidadProd;
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
      cout<<"\n\t\t\t**********************************"<<endl;
      cout<<"\t\t\t|                                |"<<endl;
      cout<<"\t\t\t|   1. Manipular Inventario      |"<<endl;
      cout<<"\t\t\t|                                |"<<endl;
      cout<<"\t\t\t|   2. Facturacion de un Item    |"<<endl;
      cout<<"\t\t\t|                                |"<<endl;
      cout<<"\t\t\t|   0. CerrarProg                |"<<endl;
      cout<<"\t\t\t|                                |"<<endl;
      cout<<"\t\t\t**********************************"<<endl;
      cout<<"\t\t\t\t    ::>> ";cin>>menu;
      switch(menu){
        case '0':
              cout<<"\n\n\t\t\t\tSaliendo..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(1);cout<<".";
          break;
        case '1':    p = PrimerMenu(p,&borraCrea);
          break;
        case '2':    p = SegundoMenu(p,&borraCrea);
          break;
        default: cout<<"Opcion Invalida!!...\n"<<endl;   break;
        } }while(menu!='0');
  return 0;
}

Inventario *memoria(Inventario *x){
    x = (Inventario*)malloc(sizeof (struct ListaInventario));
    return x;
}

Inventario *PrimerMenu(Inventario *p,bool *borraCrea){
    char menu;
    //Inventario* crea_insertaLista(Inventario*,bool *);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime en pantalla lista completa de ultimo a primero
    Inventario *InventarioExitente(bool *);  
    Inventario *creaLista(Inventario *,bool *);
    Inventario *insertarLista(Inventario *);
      //borraCrea++;
      do{   system("cls");
            cout<<"\n\t\t\t********************************"<<endl;
            cout<<"\t\t\t|                              |"<<endl;
            if(*borraCrea==0){
            cout<<"\t\t\t|   1. Crear Lista             |"<<endl;
            }else{
            cout<<"\t\t\t|   1. Insertar articulos      |"<<endl;}
            //cout<<"\t\t\t|   1. Crear o Insertar Lista    |"<<endl;
            cout<<"\t\t\t|                              |"<<endl;
            cout<<"\t\t\t|   2. Ver el Inventario       |"<<endl;
            cout<<"\t\t\t|                              |"<<endl;
            cout<<"\t\t\t|   3. Ver lista Existente     |"<<endl;
            cout<<"\t\t\t|                              |"<<endl;
            cout<<"\t\t\t|   4. Guardar el Inventario   |"<<endl;
            cout<<"\t\t\t|                              |"<<endl;
            cout<<"\t\t\t|   5. Menu Principal          |"<<endl;
            cout<<"\t\t\t|                              |"<<endl;
            cout<<"\t\t\t********************************"<<endl;
            cout<<"\t\t\t\t    ::>> ";cin>>menu;
              switch(menu){
                case '1':
                    //p = crea_insertaLista(p,borraCrea);
                  if(*borraCrea){
                    //mostrarInventario(p);cout<<"\n\n";
                    p = insertarLista(p);
                  }else{p = creaLista(p,borraCrea);}
                  break;
                case '2':
                 // if(*borraCrea){
                    mostrarInventario(p);cout<<"\n\n";
                  //}else{cout<<"No se ha Creado Ninguna lista\n\n";}
                  system("pause");
                  break;
                case '3':
                    p = InventarioExitente(borraCrea);
                    cout<<"\n\t\tInventario Agregado Satisfactoriamente!!..\n\n";
                    system("pause");
                  break;
                case '4':
                  if(*borraCrea){guardar(p); 
                    cout<<"\n\t\t\tInventario Salvado, Satisfactoriamente\n\n";
                  }else{cout<<"No se ha Creado Ninguna lista\n\n";}
                    system("pause");
                  break;
                case '5':
                    cout<<"\n\n\t\t\t   Regresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";
                  break;
                default: cout<<"Opcion Invalida!!..\n\n";sleep(1);
                  break;
                  } }while('5'!=menu);
      return p;
}

Inventario *SegundoMenu(Inventario *p,bool *borraCrea){
    char menu;//buscarNomProd[20];
    Inventario* crea_insertaLista(Inventario*,bool);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime lista completa de ultimo a primero
    Inventario* buscarProducto(Inventario*);            //busca Elem. Char en toda la lista   Return la lista (en este caso porque eliminamos datos)
    do{   system("cls");
            cout<<"\n\t\t\t*************************************"<<endl;
            cout<<"\t\t\t|                                   |"<<endl;
            cout<<"\t\t\t|  1. Buscar Item(articulo)         |"<<endl;
            cout<<"\t\t\t|                                   |"<<endl;
            cout<<"\t\t\t|  2. Ver el Inventario             |"<<endl;
            cout<<"\t\t\t|                                   |"<<endl;
            cout<<"\t\t\t|  3. Resguardar Inventario actual  |"<<endl;
            cout<<"\t\t\t|                                   |"<<endl;
            cout<<"\t\t\t|  4. Menu Principal                |"<<endl;
            cout<<"\t\t\t|                                   |"<<endl;
            cout<<"\t\t\t*************************************"<<endl;
            cout<<"\t\t\t\t    ::>> ";cin>>menu;
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
                    cout<<"\n\n\t\t\t   Regresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";                  break;
                  break;
                default: cout<<"Opcion Invalida!!..\n\n";sleep(1); break;
                  }}while('4'!=menu);
      return p;
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
      cout<<"\t\tComo deseas buscar el producto?\n";
      cout<<"\t\t [1] Nombre\n";
      cout<<"\t\t [2] Codigo\n";
      cout<<"\t\t [3] Precio\n";
      cout<<"\t\t [4] Dejar de buscar\n";
      cout<<"\t\t::> ";cin>>menu;
      switch(menu){
        case '1':
              cout<<"\n\t\tNombre del Item: "; cin>>NombreProd;
                p = buscarNombrePdo(p,NombreProd);
              system("pause");
          break;
        case '2':
              cout<<"\n\t\tCodigo del Item: "; cin>>CodigoProd;
                p = buscarCodigoPdo(p,CodigoProd);
              system("pause");
          break;
        case '3':
              cout<<"\n\t\tPrecio del Item: "; cin>>PrecioProd;
                p = buscarPrecioPdo(p,PrecioProd);
              system("pause");
          break;
        case '4': cout<<"Saliendo del buscador..."<<endl;
          break;
        default:  cout<<"Opcion Invalida!!..."<<endl; sleep(1);
          break;
        }}while(menu!='4');
        return p;
}

Inventario *creaLista(Inventario *p,bool *borraCrea){
    char sino; Inventario*q;
    if(*borraCrea == false){
      *borraCrea=true;
      p = memoria(p);
      cout<<"\n\tNombre de Item:     \t";  cin>>p->NombreProd;
      cout<<"\tCodigo del Item:    \t";  cin>>p->CodigoProd;
      cout<<"\tValor del Item:     \t";  cin>>p->CostoProd;
      cout<<"\tCatidad de Item:     \t";  cin>>p->CantidadProd;
      p->nodo = NULL;
      cout<<"\n\n\t [1] Seguir Ingresando\n\t [2] Dejar de Ingresar\n"<<endl;
      cout<<"\t::>: ";cin>>sino;
      if(!(sino=='1'||sino=='2')){
        cout<<"\t '"<<sino<<"' no es una Opcion"<<endl; }
         }
    while(sino=='1'){
        if(sino == '2'){break;} 
         q = memoria(q);
          cout<<"\n\tNombre de Item:  \t"; cin>>q->NombreProd;
          cout<<"\tCodigo del Item   \t"; cin>>q->CodigoProd;
          cout<<"\tValor del Item:   \t"; cin>>q->CostoProd;
          cout<<"\tCatidad de Item:     \t";  cin>>q->CantidadProd;
          q->nodo=p;
          p=q;
          cout<<"\n\n\t [1] Seguir Ingresando\n\t [2] Dejar de Ingresar\n"<<endl;
          cout<<"\t::>: ";cin>>sino;if(!(sino=='1'||sino=='2')){
            cout<<"\t '"<<sino<<"' no es una Opcion,(1 o 2 son las opciones)\n"<<endl;system("pause");break; }
      }
    return p; 
}

Inventario *insertarLista(Inventario *p){
  Inventario *q;
  char sino;
  do{
    q = memoria(q);
    cout<<"\n\tNombre de Item:  \t"; cin>>q->NombreProd;
    cout<<"\tCodigo del Item   \t"; cin>>q->CodigoProd;
    cout<<"\tValor del Item:   \t"; cin>>q->CostoProd;
    cout<<"\tCatidad de Item:     \t";  cin>>q->CantidadProd;
    q->nodo = p;
    p=q;
    cout<<"\n\n\t [1] Seguir Ingresando\n\t [2] Dejar de Ingresar\n"<<endl;
    cout<<"\t::>: ";cin>>sino;if(!(sino=='1'||sino=='2')){
    cout<<"\t '"<<sino<<"' no es una Opcion,(1 o 2 son las opciones)\n"<<endl;system("pause");break; }
  }while('2'!=sino);
  return p;
}

void mostrarInventario(Inventario *p){
    Inventario *q;
    q=p;
      cout<<"\n\t\t Nombre\t"<<"\tCosto "<<"\tCodigo \tCantidad "<<endl;
      cout<<"\t\t-----------------------------------------"<<endl;
    while(q!=NULL){
      cout<<"\t\t "<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<"\t"<<q->CantidadProd<<endl;
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

        x<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<"\t\t"<<q->CantidadProd<<endl;
        q=q->nodo;   }
      x.close();
}

Inventario *InventarioExitente(bool *borraCrea){
  Inventario *elimina(Inventario *);
  fstream y;
  Inventario *p,*q;
  char Nombre[20],Codigo[7];
  float Costo;
  int Cantidad; 
  bool controlaCrea = true;
  q = memoria(q);
  y.open("prueba2805.txt",ios::in);
    while(controlaCrea == true && !y.eof()){
      p = memoria(p);
      y>>Nombre;
      y>>Costo;
      y>>Codigo;
      y>>Cantidad;
        strcpy(p->NombreProd,Nombre);
        p->CostoProd = Costo;
        strcpy(p->CodigoProd,Codigo);
        p->CantidadProd = Cantidad;
      p->nodo = NULL;
      controlaCrea = false;}
      do{
      q = memoria(q);
      y>>Nombre;
      y>>Costo;
      y>>Codigo;
      y>>Cantidad;
        strcpy(q->NombreProd,Nombre);
        q->CostoProd = Costo;
        strcpy(q->CodigoProd,Codigo);
        q->CantidadProd = Cantidad;
      q->nodo=p;
      p=q;
      }while(!y.eof());
      *borraCrea = true;
  y.close();
  p = elimina(p);
  return p; 
}              

Inventario *buscarNombrePdo(Inventario *p,char NombrePdo[20]){
    Inventario *facturaProducto(Inventario *,char [],float ,int ,int ,float *,float *,float *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 1,cantEncontrada=0,cant_paraFacturar; 
    float Total=0,SubTotal=0,ITBM=0;
    char sino;
    q=p;
   // cout<<"\n\t\t Nombre\t\t"<<"Costo "<<"\t\tCodigo"<<endl;
   // cout<<"\t\t--------------------------------------"<<endl;
    cout<<"\n\t\t Nombre\t"<<"\tCosto "<<"\tCodigo \tCantidad "<<endl;
    cout<<"\t\t-----------------------------------------"<<endl;
    while(q!=NULL){
        if(!strcmp(NombrePdo,q->NombreProd)){
        cout<<"\t\t "<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<"\t"<<q->CantidadProd<<endl; cantEncontrada = q->CantidadProd;  }
      q=q->nodo;
      }
         if(q==NULL && cantEncontrada >= 1){
          if(cantEncontrada == 1){cout<<"\n\t\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
          if(cantEncontrada > 1){cout<<"\n\t\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
         cout<<"\n\t\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"\t\tCantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"\n\t\tCantidad insuficiente para el pedido!!\n\n";
         }else{
          cout<<"\n\t\t\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t\t\t::> ";cin>>sino;
            if(sino=='1'){
              cout<<"\n\t\tSe ha Realizado la Facturacion del Item:\n\n";
              //cout<<"\t\t Nombre\t\t"<<"Codigo"<<"\t\tCosto"<<endl;
              //cout<<"\t\t---------------------------------------"<<endl;
              cout<<"\n\t\t Nombre\t"<<"\tCodigo "<<"\t\tCantidad Costo "<<endl;
              cout<<"\t\t----------------------------------------------"<<endl;
              //cantEncontrada = cantEncontrada;
            //  do{
                p = facturaProducto(p,NombrePdo,NULL,x,cant_paraFacturar,&Total,&SubTotal,&ITBM);        //funcion elimina dato
            //    m++;
            //    }while(cant_paraFacturar!=m); 
                cout<<"\n\t\t---------------------------------------------"<<endl;
                cout<<"\t\t SubTotal:\t\t\t\t"<<SubTotal<<endl;
                cout<<"\t\t ITBM:    \t\t\t\t"<<ITBM<<endl;
                cout<<"\t\t----------------------------------------------"<<endl;
                cout<<"\t\t Total:   \t\t\t\t"<<Total<<endl;
                cout<<"\t\t----------------------------------------------\n"<<endl;
              }else if(sino=='2'){cout<<"\n\t\t\tPedido Cancelado....\n\n";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}

Inventario *buscarCodigoPdo(Inventario *p,char CodigoPdo[10]){
    Inventario *facturaProducto(Inventario *,char [],float ,int ,int ,float *,float *,float *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 2,cantEncontrada=0,cant_paraFacturar,m=0;
    float Total=0,SubTotal=0,ITBM=0;
    char sino;
    q=p;
    cout<<"\n\t\t Nombre\t\t"<<"Costo "<<"\t\tCodigo"<<endl;
    cout<<"\t\t--------------------------------------"<<endl;
    while(q!=NULL){
        if(!strcmp(CodigoPdo,q->CodigoProd)){
          cout<<"\t\t "<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<endl; cantEncontrada++;   }
      q=q->nodo;
      }
         if(q==NULL && cantEncontrada >= 1){
          if(cantEncontrada == 1){cout<<"\n\t\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
          if(cantEncontrada > 1){cout<<"\n\t\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
          cout<<"\n\t\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"\t\tCantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"\n\t\tCantidad insuficiente para el pedido!!\n\n";
         }else{
          cout<<"\n\t\t\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t\t\t::> ";cin>>sino;
           // if(!(sino=='1')){
            //    cout<<" '"<<sino<<"' no es una Opcion"<<endl; }
            if(sino=='1'){
              cout<<"\n\t\tSe ha Realizado la Facturacion del Item:\n\n";
              cout<<"\t\t Nombre\t\t"<<"Codigo"<<"\t\tCosto"<<endl;
              cout<<"\t\t---------------------------------------"<<endl;
              do{
                p = facturaProducto(p,CodigoPdo,NULL,x,cant_paraFacturar,&Total,&SubTotal,&ITBM);        //funcion elimina dato
                m++;
                }while(cant_paraFacturar!=m);
                cout<<"\n\t\t---------------------------------------"<<endl;
                cout<<"\t\t SubTotal:\t\t\t"<<SubTotal<<endl;
                cout<<"\t\t ITBM:    \t\t\t"<<ITBM<<endl;
                cout<<"\t\t---------------------------------------"<<endl;
                cout<<"\t\t Total:   \t\t\t"<<Total<<endl;
                cout<<"\t\t---------------------------------------\n"<<endl;
              }else if(sino=='2'){cout<<"\n\t\t\tPedido Cancelado....\n\n";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}

Inventario *buscarPrecioPdo(Inventario *p,float PrecioPdo){
    Inventario *facturaProducto(Inventario *,char [],float ,int ,int ,float *,float *,float *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 3,cantEncontrada=0,cant_paraFacturar;
    float Total=0,SubTotal=0,ITBM=0;
    char sino;
    q=p;
    cout<<"\n\t\t Nombre\t\t"<<"Costo "<<"\t\tCodigo"<<endl;
    cout<<"\t\t--------------------------------------"<<endl;
    while(q!=NULL){
        if(PrecioPdo==q->CostoProd){
          cout<<"\t\t "<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<endl; cantEncontrada++;   }
      q=q->nodo;
      }
         if(q==NULL && cantEncontrada >= 1){
          if(cantEncontrada == 1){cout<<"\n\t\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
          if(cantEncontrada > 1){cout<<"\n\t\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
        r = true;
         }else{
         cout<<"\n\t\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"\t\tCantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"\n\t\tCantidad insuficiente para el pedido!!\n\n";
         }else{
          cout<<"\n\t\t\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t\t\t::> ";cin>>sino;
           // if(!(sino=='1')){
            //    cout<<" '"<<sino<<"' no es una Opcion"<<endl; }
            if(sino=='1'){
              cout<<"\n\t\tSe ha Realizado la Facturacion del Item:\n\n";
              cout<<"\t\t Nombre\t\t"<<"Codigo"<<"\t\tCosto"<<endl;
              cout<<"\t\t---------------------------------------"<<endl;
             // do{
                p = facturaProducto(p,NULL,PrecioPdo,x,cant_paraFacturar,&Total,&SubTotal,&ITBM);        //funcion elimina dato
               // m++;
               // }while(cant_paraFacturar!=m); 
                cout<<"\n\t\t---------------------------------------"<<endl;
                cout<<"\t\t SubTotal:\t\t\t"<<SubTotal<<endl;
                cout<<"\t\t ITBM:    \t\t\t"<<ITBM<<endl;
                cout<<"\t\t---------------------------------------"<<endl;
                cout<<"\t\t Total:   \t\t\t"<<Total<<endl;
                cout<<"\t\t---------------------------------------\n"<<endl;
              }else if(sino=='2'){cout<<"\n\t\t\tPedido Cancelado....\n\n";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}


Inventario *facturaProducto(Inventario *p,char nom[20],float PrecioProd,int x,int cant_paraFacturar,float *Total=0,float *SubTotal=0,float *ITBM=0){
    Inventario *q,*t,*z;
      q=z=p;
      bool r = true;
      int suma=0,ultimo;
      if(x == 1){
        while(z!=NULL){                         //vea lo que se esta facturando o eliminado de la lista
          if(!strcmp(nom,z->NombreProd)){
            cout<<"\t\t "<<z->NombreProd<<"\t\t"<<z->CodigoProd<<"\t\t  "<<cant_paraFacturar<<"  x  "<<z->CostoProd<<endl;
              z->CostoProd;
               ultimo = z->CantidadProd;
              if(cant_paraFacturar == z->CantidadProd){
                ultimo = 1;
              }else{
                z->CantidadProd -= cant_paraFacturar;
              }
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
            cout<<"\t\t "<<z->NombreProd<<"\t\t"<<z->CodigoProd<<"\t\t"<<z->CostoProd<<endl; /*suma++; */
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
            cout<<"\t\t "<<z->NombreProd<<"\t\t"<<z->CodigoProd<<"\t\t"<<z->CostoProd<<endl; /*suma++; */
              *SubTotal+=z->CostoProd; break;}
            z=z->nodo;     }
        while((PrecioProd!=q->CostoProd) && (r == true)){
            if(q->nodo!=NULL){
               t=q;    q=q->nodo;
               }else{   r = false;   }
        }
      }
      if(ultimo==1){
      if(r == false){
          cout<<"Elemento con informacion x no se encuantra en lista\n\n";
      }else{
          if(p == q){
                p = q->nodo;
          }else{
                t->nodo = q->nodo;
                }
      }
      }
      *SubTotal *= cant_paraFacturar;
      *ITBM = (*SubTotal * 0.07);
      *Total = *ITBM + *SubTotal;
      return p;
}


Inventario *elimina(Inventario *p){
  Inventario *q;
  q=p;
  p=q->nodo;
  free(q);
  return (p);
} 