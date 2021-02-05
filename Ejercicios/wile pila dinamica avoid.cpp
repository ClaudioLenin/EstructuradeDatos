#include<iostream>
#include<string.h>
#include<conio.h>

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
 cNodo* firts;
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
   firts=NULL;
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
	if(getCount()==0)
    	return 1;
   else
   	return 0;
}

void cPilaDin::agregar(void* Info)
{
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(Info);
   if(!(empty()))
   {
    last->setSig(newNodo);
    last=last->getSig();
   }
   else
   {
   	firts=newNodo;
      last=newNodo;
   }
   setCount(getCount()+1);
}

void* cPilaDin::eliminar()
{
	void* datElim;
   cNodo* aux;
   if(!(empty()))
   {
   	datElim=last->getInfo();
      if(firts==last)
      {
      	delete(last);
         firts=NULL;
      }
   else
   {
   	aux=firts;
      while(aux->getSig()!=last)
      	aux=aux->getSig();
         last=aux;
      delete(aux->getSig()) ;
      aux->setSig(NULL);
   }
   setCount(getCount()-1);
   }
return (datElim);
}

void cPilaDin::mostrar()
{
 cNodo* aux;
 void* dato;
 if(!(empty()))
 {
 	aux=firts;
   while(aux!=NULL)
   {
      //char* datImp=new char;
      //datImp=(char*)aux->getInfo;
      //cout<<*(datImp)<<"\n";

   	dato=aux->getInfo();
      cout<<dato<<"\n";
      aux=aux->getSig();
   }
 }
}
int menu()
{
 int op;
 cout<<"Que desea hacer? \n";
 cout<<"1.- Agregar elemento \n";
 cout<<"2.- Eliminar elemento \n";
 cout<<"3.- Mostrar todos los elementos \n";
 do
 {
 	 cout<<"Escoja una opcion \n";
    cin>>op;
 }while(op>3);
 return op;
}
 void casos()
 {
   char deseo;
   char* datElm;
   char* datIns;
 	//char datoIns,datElm, deseo;
   cPilaDin oPilaDin;
   cout<<"PILA CON ALMACENAMIENTO DINAMICO \n";
   do
   {
   	clrscr();
      int op=menu();
       switch(op)
       {
       	case 1:
           cout<<"1.- AGREGAR ELEMENTO \n";
           cout<<"Ingrese el elemento a ser insertado \n";
           datIns=new char;
           cin>>*(datIns);
           oPilaDin.agregar(datIns);
           //cin>>datoIns;
           //oPilaDin.agregar(datoIns);
           break;

         case 2:
           cout<<"2.- ELIMINAR ELEMENTO \n";
           if(!(oPilaDin.empty()))
           {
           char* datElm=new char;
           datElm=(char*)oPilaDin.eliminar();
           cout<<"se ha eliminado "<<*(datElm);
           	//datElm=oPilaDin.eliminar();
            //cout<<"Se ha Eliminado "<<datElm<<"\n";
           }
           else
           {
           	cout<<"No existe elemntos para eliminar \n";
           }
           break;

         case 3:
           cout<<"3.- MOSTRAR ELEMENTOS \n";
           if(!(oPilaDin.empty()))
           {
           	oPilaDin.mostrar();
           }
           else
           {
           	cout<<"No existe elemntos para mostrar \n";
           }
           break;
         }
       cout<<"Desea hacer algo mas(s/n) \n";
       cin>>deseo;
   }while(deseo!='n');
 }

 void main()
 {
 clrscr();

  casos();
  getch();
 }