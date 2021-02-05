/*Dada una lista de estudiantes:
- Mostrar la informacion de uno de ellos dado su codigo
- Mostrar todos los estudiantes
- Transformar a mayusculas todos los datos de todos los estudiantes*/

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
   void situarPos(int iPos);
   void agregar(void* info);
   void* eliminar();
   void* firstThan(int(*CondBusCod)(void*));
   void forEach(void(*Accion)(void*));
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
         first=newNodo;
      }
      else
      {
      	if (pos==NULL)
         {
            last->setSig(newNodo);
            last=newNodo;
            pos=last;
         }
         else
         {
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

void* cListaDin::eliminar()
{
	void* datElim;
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
    	if (pos==last)
      {
      	aux=first;
         while (aux->getSig()!=pos)
         	aux=aux->getSig();
      	last=aux;
         datElim=pos->getInfo();
         last->setSig(NULL);
         delete(pos);
      }
      else
      {
      	aux=first;
         while (aux->getSig()!=pos)
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

void* cListaDin::firstThan(int(*CondBusCod)(void*))
{
	void* info=NULL;
   if (!(empty()))
   {
   	pos=first;
      while((pos!=NULL)&&(info==NULL))
      {
      	if(CondBusCod(pos->getInfo())==1)
         	info=pos->getInfo();
         pos=pos->getSig();
      }
   }
   return (info);
} 

void cListaDin::forEach(void(*Accion)(void*))
{
	if(!(empty()))
   {
   	pos=first;
      while(pos!=NULL)
      {
      	Accion(pos->getInfo());
         pos=pos->getSig();
      }
   }
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

int codigoGlobal=0;

int CondBusCod(void* info)
{
	int band=0;
   cEst* ptrEst=(cEst*)info;
   if (ptrEst->getCodigo()==codigoGlobal)
   	band=1;
   return(band);
}

void AccionMostEst(void* info)
{
	cEst* ptr=(cEst*)info;
   ptr->verDatEst();
}

void AccionTransMay(void* info)
{
	cEst* ptrEst=(cEst*)info;
   char* cad1=ptrEst->getNombre(),*ptr1;
   ptr1=strupr(cad1);
   cout<<"\n"<<ptr1;
	char* cad2=ptrEst->getApellido(),*ptr2;
   ptr2=strupr(cad2);
   cout<<"\n"<<ptr2;
   cout<<"\n"<<ptrEst->getCodigo()<<"\n";
}

int menu()
{
	int op;
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar un estudiante \n";
	cout<<"2. Eliminar un estudiante \n";
   cout<<"3. Buscar un estudiante dado un codigo \n";
   cout<<"4. Mostrar todos los estudiantes \n";
   cout<<"5. Transformar a mayusculas los datos de todos los estudiantes \n";
   do
   {
   	cout<<"Escoja una opcion \n";
      cin>>op;
   }
   while(op>5);
   return op;
}

void casos()
{
	char deseo;
   int posIns, posElm;
   cListaDin oListaDin;

   cout<<"LISTA DE ESTUDIANTES - INSERTAR Y ELIMINAR EL POS \n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"AGREGAR UN ESTUDIANTE \n";
				cout<<"Ingrese la posicion del estudiante que desea agregar \n";
				cin>>posIns;
            if ((posIns>=1)&&(posIns<=(oListaDin.getCount()+1)))
            {
            	oListaDin.situarPos(posIns);
               cEst* ptrEst=new cEst;
               ptrEst->leerDatEst();
               oListaDin.agregar(ptrEst);
            }
            else
            {
            	cout<<"La posicion ingresada es incorrecta \n";
            }
            break;
         case 2:
         	cout<<"ELIMINAR UN ESTUDIANTE \n";
            if (!(oListaDin.empty()))
            {
               cout<<"Ingrese la posicion del estudiante que desea eliminar \n";
					cin>>posElm;
               if ((posElm>=1)&&(posElm<=oListaDin.getCount()))
               {
               	oListaDin.situarPos(posElm);
						cEst* ptrEstElm=(cEst*)oListaDin.eliminar();
                  ptrEstElm->verDatEst();
               }
               else
               {
               	cout<<"La posicion ingresada es incorrecta \n";
               }
            }
            else
            {
            	cout<<"No existen estudiantes que eliminar \n";
            }
            break;
         case 3:
         	cout<<"BUSCAR UN ESTUDIANTE DADO SU CODIGO \n";
            if (!(oListaDin.empty()))
            {
            	cout<<"Ingrese el codigo a buscar \n";
               cin>>codigoGlobal;
               cEst* ptrEst=(cEst*)oListaDin.firstThan(CondBusCod);
               if (ptrEst!=NULL)
               {
               	cout<<"El estudiante ha sido encontrado \n";
                  cout<<"Los datos son: \n";
                  ptrEst->verDatEst();
               }
               else
               {
               	cout<<"El estudiante no ha sudo encontrado \n";
               }
            }
            else
            	cout<<"No existen estudiantes que buscar \n";
            break;
         case 4:
         	cout<<"MOSTRAR TODOS LOS ELEMENTOS \n";
            if (!(oListaDin.empty()))
            {
               cout<<"Todos los estudiantes son \n";
            	oListaDin.forEach(AccionMostEst);
            }
            else
            	cout<<"No existen estudiantes que mostrar \n";
            break;
         case 5:
         	cout<<"TRANFORMAR A MAYUSCULAS LOS DATOS DE LOS ESTUDIANTES \n";
            if (!(oListaDin.empty()))
            {
         		cout<<"Los datos de los estudiantes son: \n";
            	oListaDin.forEach(AccionTransMay);
            }
            else
            	cout<<"No existen datos que transformar \n";
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
