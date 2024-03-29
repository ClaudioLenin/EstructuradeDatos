#include<iostream.h>
#include<string.h>
#include<conio.h>

class cNodo
{
	void *info;
   cNodo* sig;

   public:
   cNodo();
   void setInfo(void *newInfo);
   void *getInfo();
   void setSig(cNodo *newSig);
   cNodo *getSig();
};

cNodo::cNodo()
{
	info=NULL;
   sig=NULL;
}

void cNodo::setInfo(void * newInfo)
{
	info=newInfo;
}

void * cNodo::getInfo()
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
   void setCount(int nCount);
   int getCount();
   int empty();
   cNodo* moverA(int iPos);
   void agregar(void* info,int iPos);
   void* eliminar(int iPos);
   void mostrar();
};

cListaDin::cListaDin()
{
	count=0;
   first=NULL;
   last=NULL;
   pos=NULL;
}


cNodo* cListaDin::moverA(int iPos)
{
  if(!empty())
  {
   pos=first;
   for(int i=1;i<iPos;i++)
   pos=pos->getSig();
  }
 return(pos);
}


void cListaDin::setCount(int nCount)
{
	count=nCount;
}

int cListaDin::getCount()
{
	return(count);
}

int cListaDin::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cListaDin::agregar(void * info,int iPos)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   int max=getCount();
   if((iPos>=1)&&(iPos<=(max+1)))
   {
   newNodo->setInfo(info);
   if (!empty())
   {
      if(iPos==1){
          newNodo->setSig(first);
          first=newNodo;
      }
      else{
          if(iPos==max+1)
          {
               last->setSig(newNodo);
               last=newNodo;
          }
          else{
               pos=moverA(iPos);
               aux=first;
               while(aux->getSig()!=pos)
                   aux=aux->getSig();
               aux->setSig(newNodo);
               newNodo->setSig(pos);
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
}

void* cListaDin::eliminar(int iPos)
{
	void* datElim;
   cNodo* aux;
   cNodo* aux2;
   int max=getCount();

   if (!(empty()))
   {
      if (iPos==1)
      {
         aux=first;
         datElim=aux->getInfo();
         first=first->getSig();
      	delete(aux);

      }
   	else
   	{
         if(iPos==max)
            {
              pos=moverA(iPos);
              aux=first;
              while(aux->getSig()!=pos)
                aux=aux->getSig();
                 last=aux;
                 datElim=pos->getInfo();
                 last->setSig(NULL) ;
                 delete(pos);
                 pos=first;
             }
       else
          {
             pos=moverA(iPos);
             aux=first;
             while(aux->getSig()!=pos)
             aux=aux->getSig();
             aux2=pos;
             pos=pos->getSig();
             datElim=pos->getInfo();
             aux->setSig(pos);
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
      {
         char *auxImp=new char;
         auxImp =(char*)aux->getInfo();
         cout<<*(auxImp)<<"\n";
         aux=aux->getSig();
      }
   }
}

int menu()
{
	int op;
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
   int posIns,posElm;
   cListaDin oListaDin;


   cout<<"LISTA CON PUNTERO A VOID, INSERTAR Y ELIMINARALMACENAMIENTO DINAMICO \n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"AGREGAR ELEMENTO \n";
            cout<<"Ingrese la posicion del elemento a ser insertado \n";
            cin>>posIns;
            if((posIns>=1)&&(posIns<=(oListaDin.getCount()+1)))
            {
               cout<<"Ingrese el dato a insertar\n";
               char *pDat=new char;
               cin>>*(pDat);
               oListaDin.agregar(pDat,posIns);
            }
            else{
               cout<<"La posicion ingresada es incorrecta\n";
            }
            break;
         case 2:
         	cout<<"ELIMINAR ELEMENTO \n";
            if (!(oListaDin.empty()))
            {
               cout<<"Ingrese la posicion del elemento a eliminar\n";
               cin>>posElm;
               if((posElm>=1)&&(posElm<=oListaDin.getCount())){
                    char * aux=(char *)oListaDin.eliminar(posElm);
                    cout<<*(aux)<<"\n";
               }
               else{
                   cout<<"La posicion ingresada es incorrecta\n";
               }
            }
            else
            {
            	cout<<"No existen elementos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR ELEMENTOS \n";
            if (!(oListaDin.empty()))
            	oListaDin.mostrar();
            else
            	cout<<"No existen elementos para eliminar \n";
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
   clrscr();
   getch();
}