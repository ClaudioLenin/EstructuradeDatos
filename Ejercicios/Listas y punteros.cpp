#include <iostream.h>
#include <string.h>
#include <conio.h>

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
   void situarPos(int iPos);
   void agregar(void* info);
   void * eliminar();
   void mostrar();
};

cListaDin::cListaDin()
{
	count=0;
   first=NULL;
   last=NULL;
   pos=NULL;
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

void cListaDin::situarPos(int iPos){
    int max=getCount();
    if((iPos>=1)&&(iPos<=(max+1))){
          if(!(empty())){
              pos=first;
              for(int i=1;i<iPos;i++)
                    pos=pos->getSig();
          }
    }
}
void cListaDin::agregar(void * info)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty()))
   {
      if(pos==first){
          newNodo->setSig(first);
          first=newNodo;
      }
      else{
          if(pos==NULL){
               last->setSig(newNodo);
               last=newNodo;
               pos=last;
          }
          else{
               aux=first;
               while(aux->getSig()!=pos)
                   aux=aux->getSig();
               aux->setSig(newNodo);
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

void *cListaDin::eliminar()
{
	void *datElim;
   cNodo* aux;
   if (!(empty()))
   {
      if (pos==first)
      {
         aux=first;
         datElim=aux->getInfo();
         first=first->getSig();
         delete(aux);
      }
   	else
   	{
         if(pos==last){
             aux=first;
             while (aux->getSig()!=pos)
      	      	aux=aux->getSig();
	          last=aux;
             datElim=pos->getInfo();
             last->setSig(NULL);
             delete(pos);
         }
         else{
             aux=first;
             while(aux->getSig()!=pos)
                 aux=aux->getSig();
             datElim=pos->getInfo();
             aux->setSig(pos->getSig());
             delete(pos);
         }

   	}
   	setCount(getCount()-1);
      pos=first;
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
               oListaDin.situarPos(posIns);
               cout<<"Ingrese el dato a insertar\n";
               char *pDat=new char;
               cin>>*(pDat);
               oListaDin.agregar(pDat);
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
                    oListaDin.situarPos(posElm);
                    char * aux=(char *)oListaDin.eliminar();
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