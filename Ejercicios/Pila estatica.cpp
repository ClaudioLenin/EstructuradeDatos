
/*
  2) Elaborar un programa que simule:

- Grupo 1

Pila estática de números enteros (40)

Se requiere que el programa:

- Cree el objeto

- Lea los elementos

- Saque elementos

- Muestre todos los elementos

Por favor una vez finalizado el ejercicio, subir en un archivo comprimido con su nombre al link correspondiente.
*/

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define C 40

class n_enteros
{
	private:
	     int n[C];
	     int f;
	public:
	     int b;
	     n_enteros ();
	     int ingresar (int num);
	     int excluir ();
	     void consultar ();
};

n_enteros::n_enteros()
{
 f=-1;
 cout<<"\n\t\t _____________PILA CREADA______________";
}

int n_enteros::ingresar (int num)
{
 if (f==C-1)
 {
  cout<<"\n\n\t\t\t Pila llena..............."<<endl;
  return 0;
 }
 else
 {
  f++;
  n [f]=num;
  cout<<"\n\n\t\t\tDato insertado.............";
  return 1;
 }
}

int n_enteros::excluir ()
{
 int aux;
 if (f==-1)
 {
  cout<<"\n\n\n\t\t Pila Vacia.............";
  return 0;
 }
 else
 {
  aux = n [f];
  f --;
  cout<<"\n\t\t\t Dato eliminado............ ";
  return aux;
 }
}

void n_enteros::consultar (){
 int i;
 if (f==-1){
  cout <<"\n\t\t\t Pila Vacia, no se pueden consultar datos"<<endl;
  }
 else{
  cout<<"\n\n\n\t\t\t Los datos de la pila son:  "<<endl;
  cout<<"\n\t\t\t ";
  for (i=0;i<=f;i++)
	cout<<"   "<<n[i];
 }
}

void main ()
{
 int op;
 int c;
 n_enteros d;
 clrscr();

 do
 {
      cout <<"\n\n\t\t_________________________________________________________\n";
      cout <<"\n\t\t\t PILA DE ELEMENTOS"<<endl;
      cout <<"\n\n\t\t_________________________________________________________\n";
      cout <<"\n\t\t\t 1. Crear Pila"<<endl;
      cout <<"\n\t\t\t 2. Insertar Elemento"<<endl;
      cout <<"\n\t\t\t 3. Eliminar elemento"<<endl;
      cout <<"\n\t\t\t 4. Consultar"<<endl;
      cout <<"\n\t\t\t 5. Finalizar"<<endl;
      cin>>op;
      switch (op){
               case 1:
                      n_enteros ();
                      break;
               case 2:
                      cout <<"\nIngrese Dato: ";
                      cin>>c;
                      d.ingresar(c);
                      break;
               case 3:
                      cout <<"Se ha eliminado el dato: "<<d.excluir();
                      break;
               case 4:
                      d.consultar();
                      break;
               }
               cout<<endl;
               system("pause");
               clrscr();
           }while (op !=5);
      getch ();
}







































