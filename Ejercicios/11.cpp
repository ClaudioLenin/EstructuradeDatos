#include <iostream.h>
#include <string.h>
#include <conio.h>

class cNodo
{
   void* info;
   cNodo* sig;

   public:
   cNodo();
   void setInfo(void* newInfo);
   void* getInfo();
   void setSig(cNodo* newSig);
   cNodo* getSig();
};

cNodo::cNodo()
{
   info=NULL;
   sig=NULL;
}

void cNodo::setInfo(void* newInfo)
{
	info=newInfo;
}

void* cNodo::getInfo()
{
	return(info);
}

void cNodo::setSig(cNodo* newSig)
{
	sig=newSig;
}

cNodo* cNodo::getSig()
{
	return(sig);
}

class cColaDin
{
   int count;
   cNodo* first;
   cNodo* last;

   public:
   cColaDin();
   void setCount(int newCount);
   int getCount();
   int empty();
   void agregar(void* info);
   void* eliminar();
   void* getInfNod(int a);
};

cColaDin::cColaDin()
{
   count=0;
   first=NULL;
   last=NULL;
}

void cColaDin::setCount(int newCount)
{
	count=newCount;
}

int cColaDin::getCount()
{
	return(count);
}

int cColaDin::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cColaDin::agregar(void* info)
{
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty()))
   {
   	last->setSig(newNodo);
      last=last->getSig();
   }
   else
   {
   	first=newNodo;
      last=newNodo;
   }
   setCount(getCount()+1);
}

void* cColaDin::eliminar()
{
	void* datElim;
   cNodo* aux;
   if (!(empty()))
   {
   	datElim=first->getInfo();
      if (first==last)
      {
      	delete(first);
         last=NULL;
      }
   	else
   	{
   		aux=first;
         first=first->getSig();
     		aux->setSig(NULL);
      	delete(aux);
   	}
   	setCount(getCount()-1);
	}
   return (datElim);
}

void* cColaDin::getInfNod(int a)
{
	cNodo* aux;
   if (!(empty()))
   {
   	aux=first;
      for(int i=1;i<a;i++)
      {
      	aux=aux->getSig();
      }
   }
   return (aux->getInfo());
}

class cEst
{
	char nombre[10];
   char apellido [10];
   int codigo;

   public:
   cEst();
   void setNombre (char* newNomb);
   char* getNombre();
   void setApellido (char* newApellido);
   char* getApellido();
   void setCodigo (int newCodigo);
   int getCodigo();
   void leerDatEst();
   void verDatEst();
   void mostrarDatEst(cColaDin oColaDin);
};

cEst::cEst()
{
   strcpy(nombre," ");
	strcpy(apellido," ");
	codigo=0;
}

void cEst::setNombre(char* newNombre)
{
   strcpy(nombre,newNombre);
}

char* cEst::getNombre()
{
	return nombre;
}

void cEst::setApellido(char* newApellido)
{
   strcpy(apellido,newApellido);
}

char* cEst::getApellido()
{
	return apellido;
}

void cEst::setCodigo(int newCodigo)
{
	codigo=newCodigo;
}

int cEst::getCodigo()
{
	return codigo;
}

void cEst::leerDatEst()
{
	char nomb[10];
 	char apell[10];
   int cod;

   cout<<"Ingrese el nombre del estudiante \n";
   cin>>nomb;
   setNombre(nomb);
   cout<<"Ingrese el apellido del estudiante \n";
   cin>>apell;
   setApellido(apell);
   cout<<"Ingrese el codigo del estudiante \n";
   cin>>cod;
   setCodigo(cod);
}

void cEst::verDatEst()
{
	cout<<getNombre()<<"\n"<<getApellido()<<"\n"<<getCodigo()<<"\n";
}

void cEst::mostrarDatEst(cColaDin oColaDin)
{
   cEst* prtEst=new cEst;
	if (!(oColaDin.empty()))
   {
   	cout<<"Los estudiantes registrados son \n";
      for (int i=1;i<=oColaDin.getCount();i++)
      {
      	prtEst=(cEst*)oColaDin.getInfNod(i);
         prtEst->verDatEst();
      }
   }
}

int menu()
{
	int op;
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar 1 estudiante \n";
	cout<<"2. Eliminar 1 estudiante \n";
   cout<<"3. Mostrar todos los estudiantes \n";
   do
   {
   	cout<<"Escoja una opcion \n";
      cin>>op;
   }
   while(op>3);
   return op;
}

void casos()
{
	char deseo;
   cColaDin oColaDin;
   cEst* ptrEst;
   cout<<"COLA DINAMICA CON PUNTERO A VOID \n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"INGRESO DE ESTUDIANTES \n";
            cout<<"Ingrese el elemento a ser insertado \n";
				ptrEst=new cEst;
            ptrEst->leerDatEst();
            oColaDin.agregar(ptrEst);
            break;
         case 2:
         	cout<<"ELIMINAR ESTUDIANTES \n";
            if (!(oColaDin.empty()))
            {
				   ptrEst=new cEst;
               ptrEst=(cEst*)oColaDin.eliminar();
               cout<<"Los datos del estudiante que se han eliminado son \n";
               ptrEst->verDatEst();
            }
            else
            {
            	cout<<"No existen elementos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR TODOS LOS ESTUDIANTES \n";
            if (!(oColaDin.empty()))
            	ptrEst->mostrarDatEst(oColaDin);
            else
            	cout<<"No existen estudiantes que mostrar \n";
            break;
      }
      cout<<"Desea hacer algo mas (s/n) \n";
      cin>>deseo;
   }
   while (deseo!='n');
}

void main()
{
	clrscr();
   casos();
   getch();
}
