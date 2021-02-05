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
   cNodo* moverA(int iPos);
   void agregar(void* info, int iPos);
   void* eliminar(int iPos);
   void* getInfNod(int a);
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
	if (!empty())
   {
   	pos=first;
      for (int i=1;i<iPos;i++)
      	pos=pos->getSig();
   }
   return(pos);
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

void cListaDin::agregar(void* info, int iPos)
{
   cNodo* aux;
   cNodo* newNodo=new cNodo;
	int max=getCount();
   if ((iPos>=1)&&(iPos<=(max+1)))
   {
      newNodo->setInfo(info);
      if (!empty())
      	{
      	if (iPos==1)
      	{
      		newNodo->setSig(first);
         	first=newNodo;
      	}
      	else
      	{
      		if (iPos==max+1)
         	{
            	last->setSig(newNodo);
            	last=newNodo;
         	}
         	else
         	{
   				pos=moverA(iPos);
            	aux=first;
            	while (aux->getSig()!=pos)
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
    	if (iPos==max)
      {
      	pos=moverA(iPos);
         aux=first;
         while (aux->getSig()!=pos)
         	aux=aux->getSig();
         last=aux;
         datElim=pos->getInfo();
         last->setSig(NULL);
         delete(pos);
         pos=first;
      }
      else
      {
      	pos=moverA(iPos);
         aux=first;
         while (aux->getSig()!=pos)
         	aux=aux->getSig();
			aux2=pos;
         pos=pos->getSig();
         datElim=aux2->getInfo();
         aux->setSig(pos);
         delete(aux2);
      }
    }
    setCount(getCount()-1);
	}
   return (datElim);
}

void* cListaDin::getInfNod(int a)
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
   void mostrarDatEst(cListaDin oListaDin);
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

void cEst::mostrarDatEst(cListaDin oListaDin)
{
   cEst* prtEst=new cEst;
	if (!(oListaDin.empty()))
   {
   	cout<<"Los estudiantes registrados son \n";
      for (int i=1;i<=oListaDin.getCount();i++)
      {
      	prtEst=(cEst*)oListaDin.getInfNod(i);
         prtEst->verDatEst();
      }
   }
}

int menu()
{
	int op;
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar un estudiante \n";
	cout<<"2. Eliminar un estudiante \n";
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
   int posIns, posElm;
   cListaDin oListaDin;
   cEst* ptrEst;

   cout<<"LISTA DINAMICA CON PUNTERO A VOID, INSERTAR Y ELIMINAR EN INDICE \n";
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
            	cout<<"Ingrese el estudiante a insertar \n";
               ptrEst=new cEst;
	            ptrEst->leerDatEst();
               oListaDin.agregar(ptrEst,posIns);
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
                  ptrEst=new cEst;
               	ptrEst=(cEst*)oListaDin.eliminar(posElm);
                  cout<<"Los datos del estudiante que se han eliminado son \n";
                  ptrEst->verDatEst();
               }
               else
               {
               	cout<<"La posicion ingresada es incorrecta \n";
               }
            }
            else
            {
            	cout<<"No existen estudiantes para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR TODOS LOS ESTUDIANTES \n";
            if (!(oListaDin.empty()))
            	ptrEst->mostrarDatEst(oListaDin);
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
