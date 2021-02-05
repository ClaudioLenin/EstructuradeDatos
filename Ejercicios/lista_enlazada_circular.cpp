#include <iostream.h>
#include <string.h>
#include <conio.h>

class cNodo
{
   void* info;
   cNodo *ant;
   cNodo* sig;

   public:
   cNodo();
   void setInfo(void* newInfo);
   void* getInfo();
   void setAnt(cNodo* newAnt);
   cNodo* getAnt();
   void setSig(cNodo* newSig);
   cNodo* getSig();
};

cNodo::cNodo()
{
   info=NULL;
   sig=NULL;
   ant=NULL;
}

void cNodo::setAnt(cNodo* newAnt){
   ant=newAnt;
}
cNodo* cNodo::getAnt(){
   return(ant);
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

class cListaDinDob
{
   int count;
   cNodo* first;
   cNodo* last;
   cNodo* pos;

   public:
   cListaDinDob();
   int getCount();
   void setCount(int nCount);
   int empty();
   void situarPos(int iPos);
   void agregar(void* info);
   void* eliminar();
   void mostrar();
};

cListaDinDob::cListaDinDob()
{
   count=0;
   first=NULL;
   last=NULL;
   pos=NULL;
}

int cListaDinDob::getCount()
{
	return(count);
}

void cListaDinDob::setCount(int nCount)
{
	count=nCount;
}

int cListaDinDob::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cListaDinDob::situarPos(int iPos)
{
	int max=getCount();
   if ((iPos>=1)&&(iPos<=(max+1)))
   {
   	if (!(empty()))
      {
      	pos=first;
         for (int i=1;i<iPos;i++)
         {
         	pos=pos->getSig();
         }
      }
   }
}

void cListaDinDob::agregar(void* info)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty()))
   {
	  last=newNodo;
     newNodo->setAnt(pos);
     pos->setSig(newNodo);
     last->setSig(first);
     first->setAnt(last);
     pos=last;
   }
   else
    {
      first=newNodo;
      pos=first;
      last=first;
      newNodo->setAnt(last);
      newNodo->setSig(first);
    }
   setCount(getCount()+1);
}

void* cListaDinDob::eliminar()
{
	void* datElim;
   cNodo* aux;
   if (!(empty())&&(pos!=NULL))
   {
    if (pos==first)
    {
      datElim=pos->getInfo();
      first=first->getSig();

      if(first!=NULL)
      {
      (pos->getSig())->setAnt(NULL);
      last->setSig(first);
      first->setAnt(last);
      }
      delete(pos);
      pos=first;
    }
    else
    {
    	if (pos==last)
      {
         datElim=pos->getInfo();
         last=last->getAnt();
         last->setSig(NULL);
         first->setAnt(NULL);
         last->setSig(first);
         delete(pos);
         pos=last;
      }
      else
      {
         aux=pos;
         pos=pos->getAnt();
         datElim=aux->getInfo();
         pos->setSig(aux->getSig());
         (aux->getSig())->setAnt(pos);
         delete(aux);
      }
    }
    setCount(getCount()-1);
	}
   return (datElim);
}

void cListaDinDob::mostrar()
{
	cNodo* aux;
   if (!(empty()))
   {
   	aux=first;
      for(int i=1;i<=getCount();i++)
      {  char* auxImp=new char;
         auxImp=(char*)aux->getInfo();
         cout<<*(auxImp)<<"\n";
         aux=aux->getSig();
      }
   }
}


int menu()
{
	int op;
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar un elemento \n";
	cout<<"2. Eliminar un elemento \n";
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
   char* pDat;
   int posIns, posElm;
   cListaDinDob oListaDin;

   cout<<"LISTA DINAMICA CON PUNTERO A VOID, INSERTAR Y ELIMINAR EN POS \n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
               cout<<"INGRESAR UN ELEMENTO\n\n";
            	cout<<"Ingrese el dato a insertar \n";
               pDat=new char;
               cin>>*(pDat);
               oListaDin.agregar(pDat);
            break;
         case 2:
         	cout<<"ELIMINAR UN ELEMENTO \n";
            if (!(oListaDin.empty()))
            {
               cout<<"Ingrese la posicion del elemento a eliminar \n";
					cin>>posElm;
               if ((posElm>=1)&&(posElm<=oListaDin.getCount()))
               {
               	oListaDin.situarPos(posElm);
                  char* aux = (char*)oListaDin.eliminar();
                  cout<<*(aux)<<"\n";
               }
               else
               {
               	cout<<"La posicion ingresada es incorrecta \n";
               }
            }
            else
            {
            	cout<<"No existen elementos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR TODOS LOS ELEMENTOS \n";
            if (!(oListaDin.empty()))
            	oListaDin.mostrar();
            else
            	cout<<"No existen elementos que mostrar \n";
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