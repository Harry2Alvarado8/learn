#include<iostream>
#include<conio.h>
#include<windows.h>
struct Autos{
	char nom[10];
   float precio;
   int year;
};
typedef struct Autos carro;

void main(){
		int opc,n;
      float sumt,neto,itbm;
      carro car[25];
      int carga(carro []);
      void search(int ,float *,float *,float *,carro []);
      void see(int ,carro []);
      void orden(int ,carro []);
		do{
      clrscr();
      cout <<"\n\t************************************"<<endl;
      cout <<"\t**   1) Registrar Autos           **"<<endl;
      cout <<"\t**   2) Busqueda de auto por anio **"<<endl;
      cout <<"\t**   3) Ordenar auto por anio     **"<<endl;
      cout <<"\t**   4) Ver autos registrados     **"<<endl;
      cout <<"\t**   0) Salir                     **"<<endl;
      cout <<"\t**         ::>___                 **"<<endl;
      cout <<"\t************************************\n"<<endl;

     gotoxy(24,8);cin >> opc;
      switch(opc){
      	case 1:
         		n = carga(car); 		 cout <<"\n\n";
               system("pause");
         	break;
         case 2:
         		neto = NULL;
               itbm = NULL;
               sumt = NULL;
         	  	search(n,&neto,&itbm,&sumt,car);
               //cout<<"\n\tPrecio total de autos encontrados: $ "<<sumt;
      			cout <<"\n\t************************************"<<endl;
               cout <<"\t**   Precio Neto:        "<<neto<<"  **"<<endl;
      			cout <<"\t**   Precio de ITBM:     "<<itbm<<"  **"<<endl;
      			cout <<"\t**   Precio Total Neto:  "<<sumt<<"  **"<<endl;
      			cout <<"\t************************************\n"<<endl;
               				   		 cout <<"\n\n";
               system("pause");
         	break;
         case 3:  /*
     					 for(i=0;i<n+1;i++){
							for(j=i+1;j<n;j++){
         					if(car[i].year > car[j].year){
           						 aux = car[i];
                            car[i] = car[j];
                            car[j] = aux;
                        }
         				}
      				}         */
                  orden(n,car);
                      cout <<"\n\n";
               system("pause");
         	break;
         case 4:
               see(n,car);     		 cout <<"\n\n";
               system("pause");
         	break;
         case 5:
         		cout <<"Gracias por Visitar el programa!!\n\n\n";
         	break;
         default: cout << "\tOpcion invalida!  Intentar de nuevo\n" <<endl;
         }
         	}while(0!=opc);
}


int carga(carro car[25]){
		int x;
		cout << "\n\nCantidad de autos : ";
      cin >> x;
      car[x];
      for(int i=0;i < x; i++){
         cout <<"\n\n";
         cout <<"\tMarca del auto:  ";
         cin >>car[i].nom;
         cout <<"\tPrecio del auto: ";
         cin >>car[i].precio;
			cout <<"\tAnio del auto:   ";
         cin >>car[i].year;
      	}
      return x;
}


void search(int x,float *neto,float *itbm,float *sumt,carro car[25]){
		int y;
      //float itbm,neto;
		cout <<"\nDime anio del auto: ";
      cin >> y;
      for(int i=0;i < x;i++){
      	if(car[i].year == y){
         	cout <<"\n\n";
            cout <<"\tAnio del auto: -> " << car[i].year<<endl;
            cout <<"\n";
         	cout <<"\tMarca del auto:    " << car[i].nom << endl;
         	cout <<"\tPrecio del auto: $ " << car[i].precio << endl;
				//cout <<"Anio del auto: " << car[i].year;
            *neto += car[i].precio;
          }
      }
      *itbm = *neto * .07;
      *sumt = *neto + *itbm;
}


void orden(int x,carro car[25]){
		carro aux;
      char opc;
      cout <<"\n\n\t a)Ordenar anio de menor a Mayor"<<endl;
      cout <<"\t b)Ordenar anio de Mayor a menor\n\t\t:: ";
      do{
      cin >> opc;
      if(opc == 'a' || opc == 'A'){
      		for(int i=0;i<x+1;i++){
					for(int j=i+1;j<x;j++){
         			if(car[i].year > car[j].year){
            			aux = car[i];
            			car[i] = car[j];
            			car[j] = aux;
            		}
         		}
      		}
            cout <<"\n\tSe a ordenado de menor a Mayor\n";
      }else if(opc == 'b' || opc == 'B'){
      		for(int i=0;i<x+1;i++){
					for(int j=i+1;j<x;j++){
         			if(car[i].year < car[j].year){
            			aux = car[i];
            			car[i] = car[j];
            			car[j] = aux;
            		}
         		}
      		}
            cout <<"\n\tSe a ordenado de Mayor a menor\n";
      }else{
      	cout<<"\nLas opciopnes son a o b\n";
         }
      }while(!((opc == 'b' || opc == 'B')||(opc == 'a' || opc == 'A')));

}


void see(int x,carro car[25]){
            cout <<"\nLista de autos Registrados"<<endl;
		for(int i=0;i < x;i++){
            cout <<"\n";
         	cout <<"\tMarca del auto:  >   " << car[i].nom << endl;
         	cout <<"\tPrecio del auto: > $ " << car[i].precio << endl;
				cout <<"\tAnio del auto:   >   " << car[i].year << endl<<endl;

          }
}