#include <stdlib.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <dos.h>
#include <stdio.h>
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
    SetConsoleTitle("Sistema de Cuenta WORLD COMPUTER STORE S.A. ");
    Inventario *p;
    char menu;
    bool borraCrea=false;//Variable borraCrea es la que me ayudara que la funcion de crear una lista cambie a insertar 
    Inventario *PrimerMenu(Inventario *,bool *); 
    Inventario *SegundoMenu(Inventario *,bool *);
    Inventario *MasterExitente(bool *);
    void guardar(Inventario *);
    textcolor(7);
    p = MasterExitente(&borraCrea);
    do{ system("cls");
      cout<<"\n\t\t\t     WORLD COMPUTER STORE S.A.\n";
      cout<<"\n\t\t\t R.U.C.: 280607-1-80808  D.V.: 19\n";
      printf("\n\t\t\t\t   Menu Principal\n");
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
              guardar(p);
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
    char menu,archivoPropio[15]; int sino;
    void guardar(Inventario*);          //Guarda el invetario
    void guardarPropio(Inventario *,char []); 
    void mostrarInventario(Inventario*);           //Imprime en pantalla lista completa de ultimo a primero
    char NombreProd[20];
    Inventario *InventarioExitente(bool *); 
    Inventario *creaLista(Inventario *,bool *);
    Inventario *insertarLista(Inventario *);
    Inventario* buscarNombrePdoDefectuoso(Inventario*,char [],char []);
      do{   system("cls");
            cout<<"\n\t\t\t     WORLD COMPUTER STORE S.A.\n";
            cout<<"\n\t\t\t R.U.C.: 280607-1-80808  D.V.: 19\n";
            cout<<"\n\t\t\tMenu de Manipulacion de Inventario\n";
            cout<<"\n\t\t\t************************************"<<endl;
            cout<<"\t\t\t|                                  |"<<endl;
            if(*borraCrea==0){
            cout<<"\t\t\t|   1. Crear Lista                 |"<<endl;
            }else{
            cout<<"\t\t\t|   1. Insertar articulos          |"<<endl;}
            cout<<"\t\t\t|                                  |"<<endl;
            cout<<"\t\t\t|   2. Ver el Inventario           |"<<endl;
            cout<<"\t\t\t|                                  |"<<endl;
            cout<<"\t\t\t|   3. Buscar lista Existente      |"<<endl;
            cout<<"\t\t\t|                                  |"<<endl;
            cout<<"\t\t\t|   4. Borrar Articulo Defectuoso  |"<<endl;
            cout<<"\t\t\t|                                  |"<<endl;
            cout<<"\t\t\t|   5. Guardar el Inventario       |"<<endl;
            cout<<"\t\t\t|                                  |"<<endl;
            cout<<"\t\t\t|   6. Menu Principal              |"<<endl;
            cout<<"\t\t\t|                                  |"<<endl;
            cout<<"\t\t\t************************************"<<endl;
            cout<<"\t\t\t\t    ::>> ";cin>>menu;
              switch(menu){
                case '1':
                  if(*borraCrea){
                    p = insertarLista(p);
                  }else{ p = creaLista(p,borraCrea); }
                  break;
                case '2':
                  if(*borraCrea){
                    mostrarInventario(p);cout<<"\n\n";
                  }else{cout<<"\n\tNo se ha Creado Ninguna lista\n\n";}
                  system("pause");
                  break;
                case '3':
                    p = InventarioExitente(borraCrea);
                    system("pause");
                  break;
                case '4':
                  if(*borraCrea){
                    cout<<"\n\n\t\t\t Nombre del producto: ";cin>>NombreProd;
                    p = buscarNombrePdoDefectuoso(p,NombreProd,NULL);
                  }else{ cout<<"\n\tNo se ha Creado Ninguna lista\n\n"; }
                    system("pause");
                  break;
                case '5':
                  if(*borraCrea){
                    cout<<"\n\t\t\tDeseas ponerle un nombre propio al archivo\n\n\t\t\t [1] Si\t  [2] No \n\t\t\t:> ";cin>>sino;
                    if(sino==1){
                      cout<<"Nombre que desea darle al archivo: ";cin>>archivoPropio;
                      guardarPropio(p,archivoPropio);
                    }else{
                      guardar(p); 
                      cout<<"\n\t\t\tInventario Salvado, Satisfactoriamente\n\n";
                    }
                  }else{ cout<<"\n\tNo se ha Creado Ninguna lista\n\n"; }
                    system("pause");
                  break;
                case '6':
                    cout<<"\n\n\t\t\t   Regresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";
                  break;
                default: cout<<"Opcion Invalida!!..\n\n";sleep(1);
                  break;
                  } }while('6'!=menu);
      return p;
}

Inventario *SegundoMenu(Inventario *p,bool *borraCrea){
    char menu,NombreCliente[20];
    Inventario* crea_insertaLista(Inventario*,bool);    //Crea e Inserta Elem. en cualquier lista durente la ejecucion Return la lista
    void guardar(Inventario*);          //Guarda el invetario
    void mostrarInventario(Inventario*);           //Imprime lista completa de ultimo a primero
    Inventario* buscarProducto(Inventario*,char []);            //busca Elem. Char en toda la lista   Return la lista (en este caso porque eliminamos datos)
    do{   system("cls");
            cout<<"\n\t\t\t     WORLD COMPUTER STORE S.A.\n";
            cout<<"\n\t\t\t R.U.C.: 280607-1-80808  D.V.: 19\n";
            cout<<"\n\t\t\tMenu de Facturizacion de un Inventario\n";
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
                      cout<<"\n\n\tNombre del Cliente: ";
                      gets(NombreCliente);
                      p = buscarProducto(p,NombreCliente);
                    }else{
                      cout<<"\n\tNo se ha Creado Ninguna lista\n\n";  }
                     system("pause");
                  break;
                case '2':
                  if(*borraCrea){
                    mostrarInventario(p);cout<<"\n\n";
                  }else{
                    cout<<"\n\tNo se ha Creado Ninguna Lista\n\n";
                  }
                    system("pause");
                  break;
                case '3':
                  if(*borraCrea){
                    guardar(p);
                    cout<<"\nSe a Resguardado, Satisfactoriamente\n\n";
                  }else{
                    cout<<"\n\tNo se ha Creado Ninguna Lista\n\n";}
                    system("pause");
                  break;
                case '4':
                    cout<<"\n\n\t\t\t   Regresando al Menu Principal..";sleep(1);cout<<".";sleep(0.5);cout<<".";sleep(0.7);cout<<".";                  break;
                  break;
                default: cout<<"Opcion Invalida!!..\n\n";sleep(1); break;
                  }}while('4'!=menu);
      return p;
}
Inventario *buscarProducto(Inventario *p,char NombreCliente[20]){
    char menu,NombreProd[20],CodigoProd[10];
    float PrecioProd;
    int clear=0;
    Inventario* buscarNombrePdo(Inventario*,char [],char []);            //busca Elem. Char en toda la lista   Return la lista (en este caso porque eliminamos datos)
    Inventario* buscarCodigoPdo(Inventario*,char [],char []);
    do{if(clear>=1){system("cls");  cout<<"\n\n\t\t Para el cliente: "<<NombreCliente<<endl;}
      cout<<"\n\n";clear++;
      cout<<"\t\tComo deseas buscar el producto?\n";
      cout<<"\t\t  [1] Nombre\n";
      cout<<"\t\t  [2] Codigo\n";
      cout<<"\t\t  [3] Dejar de buscar o atender\n";
      cout<<"\t\t::> ";cin>>menu;
      switch(menu){
        case '1':
              cout<<"\n\t\tNombre del articulo: "; cin>>NombreProd;
                p = buscarNombrePdo(p,NombreProd,NombreCliente);
              system("pause");
          break;
        case '2':
              cout<<"\n\t\tCodigo del articulo: "; cin>>CodigoProd;
                p = buscarCodigoPdo(p,CodigoProd,NombreCliente);
              system("pause");
          break;
        case '3': cout<<"\n\t\t\tSaliendo del buscador..."<<endl;
          break;
        default:  cout<<"Opcion Invalida!!..."<<endl; sleep(1);
          break;
        }}while(menu!='3');
        return p;
}

Inventario *creaLista(Inventario *p,bool *borraCrea){
    char sino; Inventario*q;
    if(*borraCrea == false){
      *borraCrea=true;
      p = memoria(p);
      cout<<"\n\tNombre de articulo:     \t";  cin>>p->NombreProd;
      cout<<"\tCodigo del articulo:    \t";  cin>>p->CodigoProd;
      cout<<"\tCosto del articulo:     \t";  cin>>p->CostoProd;
      cout<<"\tCantidad de articulo:     \t";  cin>>p->CantidadProd;
      p->nodo = NULL;
      cout<<"\n\n\t [1] Seguir Ingresando\n\t [2] Dejar de Ingresar\n"<<endl;
      cout<<"\t::>: ";cin>>sino;
      if(!(sino=='1'||sino=='2')){
        cout<<"\t '"<<sino<<"' no es una Opcion"<<endl; }
         }
    while(sino=='1'){
        if(sino == '2'){break;} 
         q = memoria(q);
          cout<<"\n\tNombre de articulo:     \t";  cin>>q->NombreProd;
          cout<<"\tCodigo del articulo:    \t";  cin>>q->CodigoProd;
          cout<<"\tCosto del articulo:     \t";  cin>>q->CostoProd;
          cout<<"\tCantidad de articulo:     \t";  cin>>q->CantidadProd;
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
  Inventario *nocopia(char [],char [],float ,int ,Inventario *);
  //bool *ver;//Inventario *,*,*CostoProd,*CantidadProd;//*nodo;
  //*ver = true;
  char sino,NombreProd[20],CodigoProd[7];
  float CostoProd;  int CantidadProd;
  do{
    //q = memoria(q);
    cout<<"\n\tNombre de articulo:  \t";  cin>>NombreProd;
    cout<<"\tCodigo del articulo   \t"; cin>> CodigoProd;
    cout<<"\tCosto del articulo:   \t"; cin>> CostoProd;
    cout<<"\tCantidad de articulo:     \t"; cin>> CantidadProd;
    //q->nodo = p;
    p = nocopia(NombreProd,CodigoProd,CostoProd,CantidadProd,p);
    //p=q;
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
    x.open("master.txt",ios::out);
      if(!x)cout<<"Error al guardar los datos!!...\n\n";
      while(q!=NULL){

        x<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<"\t\t"<<q->CantidadProd<<endl;
        q=q->nodo;   }
      x.close();
}
void guardarPropio(Inventario *p, char archivoPropio[15]){
    fstream x;
    Inventario *q;
    q=p;
    x.open(archivoPropio,ios::out);
      if(!x)cout<<"Error al guardar los datos!!...\n\n";
      while(q!=NULL){

        x<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t\t"<<q->CodigoProd<<"\t\t"<<q->CantidadProd<<endl;
        q=q->nodo;   }
      x.close();
}

Inventario *InventarioExitente(bool *borraCrea){
  Inventario *elimina(Inventario *);
  //Inventario *nocopia(char [],char [],float ,int,Inventario *,bool *);
  fstream y;
  Inventario *p,*q;
  char Nombre[20],Codigo[7],namefile[15];
  float Costo;
  int Cantidad;
  bool controlaCrea = *borraCrea; 
  q = memoria(q);
  //bool *k;
  //*k = false;
  cout<<"\n\n\t Nota: \n\t importante agregar la extension del archivo (Ejm.: .txt, .dat, .etc )";
  cout<<"\n\n\t\t Nombre del archivo existente: ";cin>>namefile;
  y.open(namefile,ios::in);
  if(!y){cout<<"\n\n\t\t\t archivo no exite\n\n"; }else{
    while(controlaCrea == false && !y.eof()){
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
      
      //p = nocopia(Nombre,Codigo,Costo,Cantidad,p,k);
      controlaCrea = true;}  
      do{
      //*k = true;
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
      //p = nocopia(Nombre,Codigo,Costo,Cantidad,p,k);
      }while(!y.eof());
      *borraCrea = true;
  y.close();
  p = elimina(p); 
  cout<<"\n\t\tInventario Agregado Satisfactoriamente!!..\n\n";
  }
  return p; 
}           

Inventario *MasterExitente(bool *borraCrea){
  Inventario *elimina(Inventario *);
  fstream y;
  Inventario *p,*q;
  char Nombre[20],Codigo[7],namefile[15];
  float Costo;
  int Cantidad;
  bool controlaCrea = *borraCrea; 
  q = memoria(q);
  cout<<"Leyendo archivo existente.";sleep(1);cout<<"..";sleep(1);cout<<".";system("cls");
  y.open("master.txt",ios::in);
  if(!y){cout<<"\n\n\t\t\t Archivo master no Creado\n\n";sleep(1); }else{
    while(controlaCrea == false && !y.eof()){
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
      controlaCrea = true;}  
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
  cout<<"\n\t\tArchivo leido\n\n";sleep(1);
  }
  return p; 
} 

Inventario *buscarNombrePdo(Inventario *p,char NombrePdo[20],char NombreCliente[20]){
    Inventario *facturaProducto(Inventario *,char [],int ,int ,int ,float *,float *,float *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 1,cantEncontrada=0,cant_paraFacturar,EfectivoView=0; 
    float Total=0,SubTotal=0,ITBM=0,Efectivo,Cambio;
    char sino;
    q=p; 
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
         cout<<"\n\t\t\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"\t\tCantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"\n\t\tCantidad insuficiente para el pedido!!\n\n";
         }else{
          EfectivoView = 0;
          cout<<"\t\t|----------------------------------------------|"<<endl;
          p = facturaProducto(p,NombrePdo,x,cant_paraFacturar,EfectivoView,&Total,&SubTotal,&ITBM);
          cout<<"\t\t|----------------------------------------------|"<<endl;
          cout<<"\t\t    |\t Saldo a Pagar :: $ "<<Total<<"       |"<<endl;
          cout<<"\t\t|----------------------------------------------|"<<endl;
          cout<<"\t\t\tEfectivo >> $ ";cin>>Efectivo;
          Total=0;SubTotal=0;ITBM=0;
          cout<<"\n\t\t\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t\t\t::> ";cin>>sino;
            if(sino=='1'){
              system("cls");
              cout<<"\n\tSe ha Realizado la Facturacion del Item:\n\n\n\n";
              cout<<"\t\t----------------------------------------------"<<endl;
              cout<<"\n\t\t\t     WORLD COMPUTER STORE S.A.\n";
              cout<<"\n\t\t\t R.U.C.: 280607-1-80808  D.V.: 19\n";
              cout<<"\n\t\t\t\t FACTURA\n";
              cout<<"\n\t\t Numero: 1FHEBD1054087-6002\tRUC/CI: N/A";
              cout<<"\n\t\t Cliente: "<<NombreCliente<<endl;
              cout<<"\n\t\t Nombre\t"<<"\tCodigo "<<"\t\tCantidad Costo "<<endl;
              cout<<"\t\t----------------------------------------------"<<endl;
              EfectivoView = 1;
                p = facturaProducto(p,NombrePdo,x,cant_paraFacturar,EfectivoView,&Total,&SubTotal,&ITBM);        //funcion elimina dato
            
                cout<<"\n\t\t----------------------------------------------"<<endl;
                cout<<"\t\t SubTotal:\t\t\t\t"<<SubTotal<<endl;
                cout<<"\t\t ITBM:    \t\t\t\t"<<ITBM<<endl;
                cout<<"\t\t----------------------------------------------"<<endl;
                cout<<"\t\t Total:   \t\t\t\t"<<Total<<endl;
                Cambio = Efectivo - Total;
                cout<<"\t\t Efectivo:\t\t\t\t"<<Efectivo<<endl;
                cout<<"\t\t Cambio:  \t\t\t\t"<<Cambio<<endl;
                cout<<"\t\t----------------------------------------------\n"<<endl;
              }else if(sino=='2'){cout<<"\n\t\t\tPedido Cancelado....\n\n";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}

Inventario *buscarCodigoPdo(Inventario *p,char CodigoPdo[10],char NombreCliente[20]){
    Inventario *facturaProducto(Inventario *,char [],int ,int ,int ,float *,float *,float *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 2,cantEncontrada=0,cant_paraFacturar,EfectivoView=0; 
    float Total=0,SubTotal=0,ITBM=0,Efectivo,Cambio;
    char sino;
    q=p; 
    cout<<"\n\t\t Nombre\t"<<"\tCosto "<<"\tCodigo \tCantidad "<<endl;
    cout<<"\t\t-----------------------------------------"<<endl;
    while(q!=NULL){
        if(!strcmp(CodigoPdo,q->CodigoProd)){
        cout<<"\t\t "<<q->NombreProd<<"\t\t"<<q->CostoProd<<"\t"<<q->CodigoProd<<"\t"<<q->CantidadProd<<endl; cantEncontrada = q->CantidadProd;  }
      q=q->nodo;
      }
         if(q==NULL && cantEncontrada >= 1){
          if(cantEncontrada == 1){cout<<"\n\t\tSolo se ha encontrado un ("<<cantEncontrada<<") Elemento\n\n";}
          if(cantEncontrada > 1){cout<<"\n\t\tSe han encontrado "<<cantEncontrada<<" Elemento\n\n";}
            r = true;
         }else{
         cout<<"\n\t\t\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"\t\tCantidad a Facturar: ";
         cin>>cant_paraFacturar;
         if(cant_paraFacturar>cantEncontrada){
         cout<<"\n\t\tCantidad insuficiente para el pedido!!\n\n";
         }else{
          EfectivoView = 0;
          cout<<"\t\t|----------------------------------------------|"<<endl;
          p = facturaProducto(p,CodigoPdo,x,cant_paraFacturar,EfectivoView,&Total,&SubTotal,&ITBM);
          cout<<"\t\t|----------------------------------------------|"<<endl;
          cout<<"\t\t    |\t Saldo a Pagar :: $ "<<Total<<"       |"<<endl;
          cout<<"\t\t|----------------------------------------------|"<<endl;
          cout<<"\t\t\tEfectivo >> $ ";cin>>Efectivo;
          Total=0;SubTotal=0;ITBM=0;
          cout<<"\n\t\t\t[1] Facturar \t";
          cout<<"[2] Cancelar \n";
          cout<<"\n\t\t\t::> ";cin>>sino;
            if(sino=='1'){
              system("cls");
              cout<<"\n\tSe ha Realizado la Facturacion del Item:\n\n\n\n";
              cout<<"\t\t----------------------------------------------"<<endl;
              cout<<"\n\t\t\t     WORLD COMPUTER STORE S.A.\n";
              cout<<"\n\t\t\t R.U.C.: 280607-1-80808  D.V.: 19\n";
              cout<<"\n\t\t\t\t FACTURA\n";
              cout<<"\n\t\t Numero: 1FHEBD1054087-6002\tRUC/CI: N/A";
              cout<<"\n\t\t Cliente: "<<NombreCliente<<endl;
              cout<<"\n\t\t Nombre\t"<<"\tCodigo "<<"\t\tCantidad Costo "<<endl;
              cout<<"\t\t----------------------------------------------"<<endl;
              EfectivoView = 1;
                p = facturaProducto(p,CodigoPdo,x,cant_paraFacturar,EfectivoView,&Total,&SubTotal,&ITBM);        //funcion elimina dato
            
                cout<<"\n\t\t----------------------------------------------"<<endl;
                cout<<"\t\t SubTotal:\t\t\t\t"<<SubTotal<<endl;
                cout<<"\t\t ITBM:    \t\t\t\t"<<ITBM<<endl;
                cout<<"\t\t----------------------------------------------"<<endl;
                cout<<"\t\t Total:   \t\t\t\t"<<Total<<endl;
                Cambio = Efectivo - Total;
                cout<<"\t\t Efectivo:\t\t\t\t"<<Efectivo<<endl;
                cout<<"\t\t Cambio:  \t\t\t\t"<<Cambio<<endl;
                cout<<"\t\t----------------------------------------------\n"<<endl;
              }else if(sino=='2'){cout<<"\n\t\t\tPedido Cancelado....\n\n";sleep(1);
              }else{cout<<"\nletra o simbolo '"<<sino<<"' no es una Opcion"<<endl;sleep(2);}}}
         return p;
}

Inventario *facturaProducto(Inventario *p,char nom[20],int x,int cant_paraFacturar,int EfectivoView,float *Total=0,float *SubTotal=0,float *ITBM=0){
    Inventario *q,*t,*z;
      q=z=p;
      bool r = true;
      int suma=0;
      if(x == 1){
        while(z!=NULL){                         
          if(!strcmp(nom,z->NombreProd)){
            cout<<"\t\t "<<z->NombreProd<<"\t\t"<<z->CodigoProd<<"\t\t  "<<cant_paraFacturar<<"  x  "<<z->CostoProd<<endl;
           
          if(EfectivoView == 1){    z->CantidadProd -= cant_paraFacturar;  }
              // Este (if) hace que no descuente los item cuando solo se quiere el precio de aquellos
              *SubTotal+=z->CostoProd; break;  }
              z=z->nodo;     }

        while(strcmp(nom,q->NombreProd) && (r == true)){
            if(q->nodo!=NULL){
                  t=q;   q=q->nodo;
            }else{  r = false;   }
        }
      }else if(x == 2){
        while(z!=NULL){                         //vea lo que se esta facturando o eliminado de la lista
          if(!strcmp(nom,z->CodigoProd)){
            cout<<"\t\t "<<z->NombreProd<<"\t\t"<<z->CodigoProd<<"\t\t"<<z->CostoProd<<endl; 
            if(EfectivoView == 1){    z->CantidadProd -= cant_paraFacturar;  }
              *SubTotal+=z->CostoProd; break;}
            z=z->nodo;     }
        while(strcmp(nom,q->CodigoProd) && (r == true)){
            if(q->nodo!=NULL){
               t=q;    q=q->nodo;
            }else{  r = false;   }
        }
      }

      if(z->CantidadProd == 0 && EfectivoView == 1){ 
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

Inventario *buscarNombrePdoDefectuoso(Inventario *p,char NombrePdo[20],char NombreCliente[20]){
    Inventario *facturaProducto(Inventario *,char [],int ,int ,int ,float *,float *,float *);        //funcion elimina dato
    Inventario *q;
    bool r = false;
    int x = 1,cantEncontrada=0,cantDelete;
    float Total,SubTotal,ITBM;  // esto no se usa pero se tiene por que la funcion de factura lo requiere
    char sino;
    q=p;
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
         cout<<"\n\t\t\tNo exite Item en esta Lista\n\n";   }
         if(r){
         cout<<"\t\tCantidad a Eliminar: ";
         cin>>cantDelete;
         if(cantDelete>cantEncontrada){
         cout<<"\n\t\tNo exite dicha Cantidad!!\n\n";
         }else{
          cout<<"\n\t\t\tEsta seguro que desea Eliminar ";
          cout<<"\n\t\t\t[1] Si \t";
          cout<<"[2] No \n";
          cout<<"\n\t\t\t::> ";cin>>sino;
            p = facturaProducto(p,NombrePdo,1,cantDelete,1,&Total,&SubTotal,&ITBM);        //funcion elimina dato
            cout<<"\n\n\t\t\t operacion realizada...\n\n\n";
          }
        }
    return p;
}


Inventario *nocopia(char NombreProd[20],char CodigoProd[7],float CostoProd,int CantidadProd,Inventario *nodo){
  Inventario *q,*N;
    bool nohay = false;

      N = nodo; 
      while(N!=NULL){        
          if(!strcmp(CodigoProd,N->CodigoProd)){ nohay = true; }
            N=N->nodo;     }
    
      if (nohay == false){
        q = memoria(q);
        strcpy(q->NombreProd,NombreProd);
        strcpy(q->CodigoProd,CodigoProd);
        q->CostoProd = CostoProd;
        q->CantidadProd = CantidadProd;
        q->nodo = nodo;
      }else if (nohay == true){
        cout<<"\n\n\t\tError al agregar este Articulo, El Codigo ya exite\n\n";
        q = nodo;
      } 
  return q;
}