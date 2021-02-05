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
   void* getInfNod(int a);

   cNodo* situarPosSwap(int iPos);
   void swap(int ind1, int ind2);
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

cNodo* cListaDin::situarPosSwap(int iPos)
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
  return pos;
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

void cListaDin::swap(int ind1, int ind2)
{
	cNodo* aux1;
   cNodo* aux2;
   void* infoAux;
   if (!(empty()))
   {
   	aux1=situarPosSwap(ind1);
      aux2=situarPosSwap(ind2);
      infoAux=aux1->getInfo();
      aux1->setInfo(aux2->getInfo());
      aux2->setInfo(infoAux);
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
   void mostrarDatEst(cListaDin oListaDin);

	void mostrarDatEstPares(cListaDin oListaDin);
   void ordenar(cListaDin oListaDin);
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

void cEst::mostrarDatEstPares(cListaDin oListaDin)
{
   cEst* prtEst=new cEst;
	if (!(oListaDin.empty()))
   {
   	cout<<"Los estudiantes registrados en nodos pares son \n";
      for (int i=1;i<=oListaDin.getCount();i++)
      {
      	if (i%2==0)
         {
      		prtEst=(cEst*)oListaDin.getInfNod(i);
         	prtEst->verDatEst();
         }
      }
   }
}

void cEst::ordenar(cListaDin oListaDin)
{
   cEst* prtEst=new cEst;
	if (!(oListaDin.empty()))
   {
      for (int i=1;i<=oListaDin.getCount()-1;i++)
      {
			prtEst=(cEst*)oListaDin.getInfNod(i);
         int cod1=prtEst->getCodigo();
      	for (int j=i+1;j<=oListaDin.getCount();j++)
	      {
            prtEst=(cEst*)oListaDin.getInfNod(j);
	         int cod2=prtEst->getCodigo();
   	   	if (cod1>cod2)
     	    	{
					oListaDin.swap(i,j);
         	}
      	}
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
   cout<<"4. Mostrar estudiantes en nodos pares\n";
   cout<<"5. Intercambiar dos estudiantes\n";
   cout<<"6. Ordenar ascendentemente los estudiantes por codigo\n";
   do
   {
   	cout<<"Escoja una opcion \n";
      cin>>op;
   }
   while(op>6);
   return op;
}

void casos()
{
	char deseo;
   int posIns, posElm, ind1, ind2;
   cListaDin oListaDin;
   cEst* ptrEst;
   cout<<"LISTA DINAMICA DE ESTUDIANTES, INSERTAR Y ELIMINAR EN POS \n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"INSERTAR UN ESTUDIANTE \n";
				cout<<"Ingrese la posicion del elemento a insertar \n";
				cin>>posIns;
            if ((posIns>=1)&&(posIns<=(oListaDin.getCount()+1)))
            {
            	oListaDin.situarPos(posIns);
               cout<<"Ingrese el estudiante que desea insertar \n";
               ptrEst=new cEst;
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
               cout<<"Ingrese la posicion del elemento a eliminar \n";
					cin>>posElm;
               if ((posElm>=1)&&(posElm<=oListaDin.getCount()))
               {
               	oListaDin.situarPos(posElm);
                  ptrEst=new cEst;
               	ptrEst=(cEst*)oListaDin.eliminar();
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
         case 4:
         	cout<<"MOSTRAR ESTUDIANTES EN NODOS PARES \n";
            if (!(oListaDin.empty()))
	           	ptrEst->mostrarDatEstPares(oListaDin);
            else
            	cout<<"No existen estudiantes que mostrar \n";
            break;
         case 5:
         	cout<<"INTERCAMBIAR DOS ESTUDIANTES \n";
            if (!(oListaDin.empty()))
            {
               cout<<"Ingrese la posicion del primer estudiante a intercambiar \n";
					cin>>ind1;
               cout<<"Ingrese la posicion del segundo estudiante a intercambiar \n";
 					cin>>ind2;
               if (((ind1>=1)&&(ind1<=oListaDin.getCount()))&&((ind2>=1)&&(ind2<=oListaDin.getCount()))&&(ind1!=ind2))
               {
               	oListaDin.swap(ind1,ind2);
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
			case 6:
         	cout<<"ORDENAR ASCENDENTEMENTE ESTUDIANTES POR CODIGO \n";
            if (!(oListaDin.empty()))
            {
					ptrEst->ordenar(oListaDin);
            }   
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
