/*
   Realice la siguiente serie utilizando la metodologia de recursividad
   2/2   4/4   6/8   8/16   10/32  .......
*/
#include <iostream.h>
#include <conio.h>
#include <math.h>
int serie(int x,int y,int z){ //Funcion que permite generar la serie
      if(z!=0){  //condicion de la impresion
          cout<<x<<"/"<<y<<"  ";
          return serie(x+2,y*2,z-1); //llamado a la funcion que permite generar la serie (Se genera un ciclo dentro de la funcion mientras z no sea igual a cero)
          }

}

void main(){
   int n;  //cantidad de numeros de la serie
   int a=2;  //variable de inicio del denominador
   int b=2;  //variable de inicio del numerador
   cout<<"Ingrese cantidad de elementos de la serie que desea visualizar: ";
   cin>>n;   //lectura de la cantidad de numeros a generar

   serie(a,b,n); //llamado a la funcion que permite generar la serie
   getch();
}