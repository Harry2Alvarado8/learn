//HARRY ALVARADO 8-918-1897
// Versión 0.1
#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
float Pul_mm(float );
float Yar_M(float );
float LB_KL(float );
Marco();
main(){
Marco();
  char menu;
	 int s;
	float Pul,Yar,LB;
   do{
   system("cls");
   Marco();
   gotoxy(35,3);printf("PARCIAL #2");
     gotoxy(6,5);printf("a) Calcular Pulgadas a Milimetros\n");
     gotoxy(6,6);printf("b) Calcular Yardas a Metros\n");
     gotoxy(6,7);printf("c) Calcular Libras a Kilogramos\n");
     gotoxy(6,8);printf("s) Salir del Programa\n");
     gotoxy(8,9);printf("Ingrese una de las opciones ");
     gotoxy(38,9);scanf("%c",&menu);
 	switch(menu){
        case 'a': gotoxy(8,12);printf("Pulgadas a Milimetros\n");
        			gotoxy(38,12);scanf("%f",&Pul);
               Pul_mm(Pul);
               gotoxy(10,15);printf("%.1f pulgadas son %.2f milimetros ",Pul,Pul_mm(Pul));
               getch();
        break;
        case 'b':gotoxy(8,12);printf("Yarda a Metros\n");
        			Yar_M(Yar);
               gotoxy(38,12);scanf("%f",&Yar);
               Yar_M(Yar);
                 gotoxy(10,15);printf("%.1f yardas son %.2f metros ",Yar,Yar_M(Yar));
                 getch();
        break;
        case 'c':
       			gotoxy(8,12); printf("Libras a Kilogramos\n");
        			gotoxy(38,12);scanf("%f",&LB);
               LB_KL(LB);
                 gotoxy(10,15);printf("%.1f libras son %.2f kilogramos ",LB,LB_KL(LB));
                 getch();
        break;
        case 's': s=4;
        break;
   }}while(s!=4);

}

float Pul_mm(float Pul){
		float RPul;
      	RPul=Pul*(2.54/1)*(10/1);
      	return RPul;
}
float Yar_M(float Yar){
      float RYar;
      	RYar=Yar*(0.9144/1);
         return RYar;
}
float LB_KL(float LB){
 		float RLB;
      RLB=LB*(0.453/1);
      return RLB;
}

Marco(){  //system("color 07");
textcolor(125);
			/* Marco Izquierdo*/
		for(int m=3;m<=24;m++){
 			gotoxy(5,m);cprintf("|");
              }
textcolor(YELLOW);    /* Marco Inferior*/
					for(int m=6;m<=74;m++){
 						gotoxy(m,24);cprintf("__");
             		 }
textcolor(10);   /* Marco Derecho*/
      for(int m=3;m<=24;m++){
 			gotoxy(76,m);cprintf("|");
              }
textcolor(99);  /*Marco Superior Doble*/
              for(int m=6;m<=74;m++){
 						gotoxy(m,4);cprintf("__");
         		     }
textcolor(31);
                    for(int m=6;m<=74;m++){
 								gotoxy(m,2);cprintf("__");
         		     			}
}
