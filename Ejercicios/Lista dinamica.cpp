#include<iostream.h>
#include<string.h>
#include<conio.h>

class cNodo
{
   void* info;
   cNodo* sig;
   cNodo* ant;

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
   ant=NULL;
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

void cNodo::setAnt(cNodo* newAnt)
{
	sig=newAnt;
}

cNodo* cNodo::getAnt()
{
	return(ant);
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
   void situarPos(int iPos);
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

void cListaDin::situarPos(int iPos)
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

void cListaDin::agregar(void* info)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty()))
   {
		if (pos==first)
      {
      	newNodo->setSig(first);
         newNodo->setAnt(NULL);
         first->setAnt(newNodo);
         first=newNodo;
      }
      else
      {
      	if (pos==NULL)
         {
            last->setSig(newNodo);
            newNodo->setAnt(last);
            newNodo->setSig(NULL);
            last=newNodo;
         }
         else
         {
            aux=pos->getAnt();
            aux->setSig(newNodo);
            newNodo->setAnt(aux);
            newNodo->setSig(pos);
            pos->setAnt(newNodo);
         }
      }
   }
   else
   {
    newNodo->setSig(NULL);
    newNodo->setAnt(NULL);
    first=newNodo;
    pos=first;
    last=first;
   }
   setCount(getCount()+1);
}

void* cListaDin::eliminar()
{
	void* datElim;
   cNodo* aux;
   cNodo* aux2;
   if (!(empty())&&(pos!=NULL))
   {
    if (pos==first)
    {
    	datElim=pos->getInfo();
      first=first->getSig();
      if(first!=NULL)
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
         delete(pos);
         pos=last;
      }
      else
      {
      	aux=pos->getAnt();
         aux2=pos;
         pos=pos->getSig();
         datElim=aux2->getInfo();
         aux->setSig(pos);
         pos->setAnt(aux2);
         delete(aux2);
      }
    }
    setCount(getCount()-1);
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

   cout<<"LISTA DINAMICA CON PUNTERO A VOID, INSERTAR Y ELIMINAR EN POS \n";
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
            if ((posIns>=1)&&(posIns<=(oListaDin.getCount()+1)))
            {
            	oListaDin.situarPos(posIns);
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
               if ((posElm>=1)&&(posElm<=oListaDin.getCount()))
               {
               	oListaDin.situarPos(posElm);
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