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

class cPilaDin
{
   int count;
   cNodo* first;
   cNodo* last;

   public:
   cPilaDin();
   void setCount(int newCount);
   int getCount();
   int empty();
   void agregar(void* info);
   void* eliminar();
   void mostrar();
};

cPilaDin::cPilaDin()
{
   count=0;
   first=NULL;
   last=NULL;
}

void cPilaDin::setCount(int newCount)
{
	count=newCount;
}

int cPilaDin::getCount()
{
	return(count);
}

int cPilaDin::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cPilaDin::agregar(void* info)
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

void* cPilaDin::eliminar()
{
	void* datElim;
   cNodo* aux;
   if (!(empty()))
   {
   	datElim=last->getInfo();
      if (first==last)
      {
      	delete(last);
         first=NULL;
      }
   	else
   	{
   		aux=first;
      	while (aux->getSig()!=last)
      		aux=aux->getSig();
	      last=aux;
      	delete(aux->getSig());
      	last->setSig(NULL);
   	}
   	setCount(getCount()-1);
	}
   return (datElim);  
}

void cPilaDin::mostrar()
{
	cNodo* aux;
   if (!(empty()))
   {
   	aux=first;
      while (aux!=NULL)
      {
			char* datImp=new char;
      	datImp=(char*)aux->getInfo();
         cout<<*(datImp)<<"\n";
         aux=aux->getSig();
      }
   }
}

int menu()
{
	int op;
   cout<<"PILA DINAMICA CON PUNTERO A VOID \n";
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar elemento \n";
	cout<<"2. Eliminar elemento \n";
   cout<<"3. Mostrar todos los elementos \n";
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
   char* datIns, datElm;
   cPilaDin oPilaDin;
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"AGREGAR ELEMENTO \n";
            cout<<"Ingrese el elemento a ser insertado \n";
            datIns=new char;
            cin>>*(datIns);
            oPilaDin.agregar(datIns);
            break;
         case 2:
         	cout<<"ELIMINAR ELEMENTO \n";
            if (!(oPilaDin.empty()))
            {
               datElm=new char;
            	datElm=(char*)oPilaDin.eliminar();
               cout<<"Se ha eliminado "<<*(datElm)<<"\n";
            }
            else
            {
            	cout<<"No existen elementos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR ELEMENTOS \n";
            if (!(oPilaDin.empty()))
            	oPilaDin.mostrar();
            else
            	cout<<"No existen elementos \n";
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