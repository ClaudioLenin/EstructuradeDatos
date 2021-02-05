#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#define MAX 30

class cola
{
 private:
  char datos [MAX];
  int frente;
  int final;
 public:
  cola ();
  char meter (char nuevo);
  char sacar (void);
  void consultar (void);
};

cola::cola()
{
 frente=0;
 final=0;
 cout<<"\n\t\t *******COLA CREADA******";
}

char cola::meter (char nuevo)
{
 if (final==MAX-1)
 {
  cout<<"\n\n\t\t\t Cola Llena"<<endl;
  return 0;
 }
 else
 {
  datos [final]=nuevo;
  final++;
  cout<<"\n\n\t\t\t***** Dato insertado *****";
  return 1;
 }
}

char cola::sacar (void)
{
 char valor;
 if (final==0)
 {
  cout<<"\n\n\n\t\t Cola Vacia";
  return 0;
 }
 else
 {
  valor =datos [frente];
  frente++;
  cout<<"\n\t\t\t ***** Dato eliminado *****";
  return valor;
 }
}

void cola::consultar ()
{
 int i=frente;
 if (final==0)
  cout <<"\n\t\t\t Cola Vacia, no se pueden consultra datos"<<endl;
 else
 {
  cout<<"\n\n\n\t\t\t Los datos de la Cola son:  "<<endl;
  cout<<"\n\t\t\t ";
  while(i<=final-1)
  {
	cout<<"   "<<datos[i];
	i++;
  }
 }
}

int main (void)
{
 int opc;
 char dato;
 cola col;
 clrscr();
 do
 {
  cout <<"\n\n\t\t\******************************************\n";
  cout <<"\n\t\t\t COLA ESTATICA"<<endl;
  cout <<"\n\n\t\t\******************************************\n";
  cout <<"\n\t\t\t 1. Crear Cola"<<endl;
  cout <<"\n\t\t\t 2. Insertar Elemento"<<endl;
  cout <<"\n\t\t\t 3. Eliminar elemento"<<endl;
  cout <<"\n\t\t\t 4. Consultar"<<endl;
  cout <<"\n\t\t\t 5. Finalizar"<<endl;
  cin>>opc;
 switch (opc)
 {
  case 1:
	cola ();
	break;
  case 2:
	cout <<"\n\t\t\t Ingresar el dato a Insertar"<<endl;
	cin>>dato;
	col.meter(dato);
	break;
  case 3:
	cout<<"Se ha eliminado: "<<col.sacar();
	break;
  case 4:
	col.consultar();
	break;
  }
 } while (opc !=5);
 getch ();
 return 0;
}





