#include <iostream.h>
#include <conio.h>
#define MAX 10

class pila
{
	private:
	 char datos [MAX];
	 int tope;
	public:
	 int b;
	 pila ();
	 char meter (char nuevo);
	 char sacar (void);
	 void consultar (void);
};

pila::pila()
{
 tope=-1;
 cout<<"\n\t\t *******PILA CREADA******";
}

char pila::meter (char nuevo)
{
 if (tope==MAX-1)
 {
  cout<<"\n\n\t\t\t Pila llena"<<endl;
  return 0;
 }
 else
 {
  tope++;
  datos [tope]=nuevo;
  cout<<"\n\n\t\t\t***** Dato insertado *****";
  return 1;
 }
}

char pila::sacar (void)
{
 char valor;
 if (tope==-1)
 {
  cout<<"\n\n\n\t\t Pila Vacia";
  return 0;
 }
 else
 {
  valor =datos [tope];
  tope --;
  cout<<"\n\t\t\t ***** Dato eliminado *****";
  return valor;
 }
}

void pila::consultar ()
{
 int i;
 if (tope==-1)
  cout <<"\n\t\t\t Pila Vacia, no se pueden consultar datos"<<endl;
 else
 {
  cout<<"\n\n\n\t\t\t Los datos de la pila son:  "<<endl;
  cout<<"\n\t\t\t ";
  for (i=0;i<=tope;i++)
  {
	cout<<"   "<<datos[i];
  }
 }
}

int main (void)
{
 int opc;
 char dato;
 pila pili;
 clrscr();
 do
 {
  cout <<"\n\n\t\t\******************************************\n";
  cout <<"\n\t\t\t PILA ESTATICA"<<endl;
  cout <<"\n\n\t\t\******************************************\n";
  cout <<"\n\t\t\t 1. Crear Pila"<<endl;
  cout <<"\n\t\t\t 2. Insertar Elemento"<<endl;
  cout <<"\n\t\t\t 3. Eliminar elemento"<<endl;
  cout <<"\n\t\t\t 4. Consultar"<<endl;
  cout <<"\n\t\t\t 5. Finalizar"<<endl;
  cin>>opc;
  switch (opc)
  {
   case 1:
    pila ();
    break;
   case 2:
    cout <<"\n\t\t\t Ingrese el dato a Insertar"<<endl;
    cin>>dato;
    pili.meter(dato);
    break;
   case 3:
     cout <<"Se ha eliminado el dato: "<<pili.sacar();
    break;
   case 4:
    pili.consultar();
    break;
  }
 }while (opc !=5);
 getch ();
 return 0;
}
