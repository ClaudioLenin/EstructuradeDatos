/*Grupo 2:

Cola estática de números enteros (40)

Se requiere que el programa:

- Cree el objeto

- Lea los elementos

- Saque elementos

- Muestre todos los elementos */

#include<iostream.h>
#include<conio.h>
#define MAX 40
class cola{
int v[MAX];
int ne;
int tope;
int i;
public:
void col()
{//de col

tope= MAX-1;
}//de col

void ingresar()
{//de ingresar
cout<<"Cuantos numeros desea ingresar: ";
cin>>ne;
for(i=0;i<ne;i++)
{//de for
 cout<<"Ingrese el elemento "<<(i+1)<<"\n";
 cin>>v[i];
 tope++;
}//de for


}//de ingresar

void mostrar()
{//de mostrar
cout<<"los elementos ingresados son: \n";
 for(i=0;i<ne;i++)
 {//de for
  cout<<v[i]<<"\n";
 }//de for

}//de mostrar

void sacar()
{//de sacar
for(i=0;i<ne;i++)
{//de sacar
 cout<<"El elemento"<<v[i]<<"fue sacado\n";


}//de sacar
}//de sacar


}; //fin de class


void main()
{//de main
cola coli;
coli.col();
coli.ingresar();
coli.mostrar();
coli.sacar();
getch();
}//de main
