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

class cListaDin
{
   int count;
   cNodo* first;
   cNodo* last;
   cNodo* pos;

   public:
   cListaDin();
   int getCount();
   void setCount(int nCount);
   int empty();
   void situarPosAgr(int iPos);
   int situarPosElm(int iPos);
   void agregar(void* info);
   void* eliminar();
   void mostrar();
};

cListaDin::cListaDin()
{
   count=0;
   first=NULL;
   last=NULL;
   pos=NULL;
}

int cListaDin::getCount()
{
	return(count);
}

void cListaDin::setCount(int nCount)
{
	count=nCount;
}

int cListaDin::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cListaDin::situarPosAgr(int iPos)
{
	int max=getCount();
   if ((iPos>=0)&&(iPos<=(max)))
   {
   	if (iPos==0)
      {
      	pos=NULL;
      }
      else
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
}

int cListaDin::situarPosElm(int iPos)
{
	int max=getCount();
   int band=0;
   if ((iPos>=0)&&(iPos<=(max-1)))
   {
   	if (iPos==0)
      {
      	pos=NULL;
      }
      else
      {
         if (!(empty()))
         {
         	pos=first;
            for (int i=1;i<iPos;i++)
            	pos=pos->getSig();
         }
      }
   	band=1;
   }
 return (band);
}

void cListaDin::agregar(void* info)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty()))
   {
		if (pos==NULL)
      {
      	newNodo->setSig(first);
         first=newNodo;
         pos=first;
      }
      else
      {
      	if (pos==last)
         {
            pos->setSig(newNodo);
            last=newNodo;
         }
         else
         {
         	aux=pos->getSig();
            pos->setSig(newNodo);
            newNodo->setSig(aux);
         }
      }
   }
   else
   {
   	first=newNodo;
      last=first;
      pos=first;
   }
   setCount(getCount()+1);
}

void* cListaDin::eliminar()
{
	void* datElim;
   cNodo* aux;
   if (!(empty()))
   {
    if (pos==NULL)
    {
    	aux=first;
      datElim=aux->getInfo();
      first=first->getSig();
      delete(aux);
      pos=first;
      setCount(getCount()-1);
    }
    else
    {
    	aux=pos->getSig();
     	datElim=aux->getInfo();
      if (aux==last)
      {
			last=pos;
         last->setSig(NULL);
      }
      else
      {
      	pos->setSig(aux->getSig());
      }
      delete(aux);
      setCount(getCount()-1);
    }
	}
   return (datElim);
}

void cListaDin::mostrar()
{
	cNodo* aux;
   if (!(empty()))
   {
   	aux=first;
      while (aux!=NULL)
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
   int posIns, posElm;
   cListaDin oListaDin;

   cout<<"LISTA DINAMICA CON PUNTERO A VOID, INSERTAR Y ELIMINAR DESPUES DE POS \n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"INSERTAR UN ELEMENTO \n";
				cout<<"Ingrese la posicion del elemento a insertar \n";
				cin>>posIns;
            if ((posIns>=0)&&(posIns<=(oListaDin.getCount())))
            {
            	oListaDin.situarPosAgr(posIns);
               cout<<"Ingrese el dato a insertar \n";
               char* pDat=new char;
               cin>>*(pDat);
               oListaDin.agregar(pDat);
            }
            else
            {
            	cout<<"La posicion ingresada es incorrecta \n";
            }
            break;
         case 2:
         	cout<<"ELIMINAR UN ELEMENTO \n";
            if (!(oListaDin.empty()))
            {
               cout<<"Ingrese la posicion del elemento a eliminar \n";
					cin>>posElm;
               int cond=oListaDin.situarPosElm(posElm);
               if (cond==1)
               {
                	char* aux=(char*)oListaDin.eliminar();
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
