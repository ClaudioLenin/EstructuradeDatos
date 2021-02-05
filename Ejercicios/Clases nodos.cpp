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
   void cListaDin::swap(int ind1, int ind2);
   cNodo* cListaDin::situarPosSwap(int iPos);

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





class cFarm
{
	char nombre[10];
   char tipo[10];
   int codigo;

   public:
   cFarm();
   void setNombre (char* newNomb);
   char* getNombre();
   void setTipo (char* newApellido);
   char* getTipo();
   void setCodigo (int newCodigo);
   int getCodigo();
   void leerDatFarm();
   void verDatFarm();
   void mostrarDatFarm(cListaDin oListaDin);
   void mostrarDatFarmInv(cListaDin oListaDin);
   void mostrarDatFarmPares(cListaDin oListaDin);
   void mostrarDatFarmImp(cListaDin oListaDin);
   void ordenar(cListaDin oListaDin);

   };

cFarm::cFarm()
{
   strcpy(nombre," ");
	strcpy(tipo," ");
	codigo=0;
}

void cFarm::setNombre(char* newNombre)
{
   strcpy(nombre,newNombre);
}

char* cFarm::getNombre()
{
	return nombre;
}

void cFarm::setTipo(char* newTipo)
{
   strcpy(tipo,newTipo);
}

char* cFarm::getTipo()
{
	return tipo;
}

void cFarm::setCodigo(int newCodigo)
{
	codigo=newCodigo;
}

int cFarm::getCodigo()
{
	return codigo;
}

void cFarm::leerDatFarm()
{
	char nomb[10];
 	char tipo[10];
   int cod;

   cout<<"Ingrese el nombre del producto \n";
   cin>>nomb;
   setNombre(nomb);
   cout<<"Ingrese el tipo del producto \n";
   cin>>tipo;
   setTipo(tipo);
   cout<<"Ingrese el codigo del producto \n";
   cin>>cod;
   setCodigo(cod);
}

void cFarm::verDatFarm()
{
	cout<<getNombre()<<"\n"<<getTipo()<<"\n"<<getCodigo()<<"\n";
}


void cFarm::mostrarDatFarmPares(cListaDin oListaDin)
{//de cfarm
cFarm* prtFarm=new cFarm;
	if (!(oListaDin.empty()))
   {
   	cout<<"Los productos pares registrados son \n";
      for (int i=1;i<=oListaDin.getCount();i++)
      {
       if(i%2==0)
       {
        prtFarm=(cFarm*)oListaDin.getInfNod(i);
        prtFarm->verDatFarm();
       }
      }
   }
}//de cfarm





void cFarm::mostrarDatFarmImp(cListaDin oListaDin)
{//de cfarm
cFarm* prtFarm=new cFarm;
	if (!(oListaDin.empty()))
   {
   	cout<<"\nLos productos impares registrados son \n";
      for (int i=1;i<=oListaDin.getCount();i++)
      {
       if(i%2!=0)
       {
         prtFarm=(cFarm*)oListaDin.getInfNod(i);
      	prtFarm->verDatFarm();
       }
      }
   }
}//de cfarm


void cFarm::mostrarDatFarmInv(cListaDin oListaDin)
{//de cfarm
cFarm* prtFarm=new cFarm;
	if (!(oListaDin.empty()))
   {
   	cout<<"Los productos registrados son \n";
      for (int i=oListaDin.getCount();i>=1;i--)
      {
      	prtFarm=(cFarm*)oListaDin.getInfNod(i);
         prtFarm->verDatFarm();
      }
   }
}//de cfarm

void cFarm::mostrarDatFarm(cListaDin oListaDin)
{
   cFarm* prtFarm=new cFarm;
	if (!(oListaDin.empty()))
   {
   	cout<<"Los productos registrados son \n";
      for (int i=1;i<=oListaDin.getCount();i++)
      {
      	prtFarm=(cFarm*)oListaDin.getInfNod(i);
         prtFarm->verDatFarm();
      }
   }
}

void cFarm::ordenar(cListaDin oListaDin)
{
   cFarm* prtFarm=new cFarm;
	if (!(oListaDin.empty()))
   {
      for (int i=1;i<=oListaDin.getCount()-1;i++)
      {
			prtFarm=(cFarm*)oListaDin.getInfNod(i);
         int cod1=prtFarm->getCodigo();
      	for (int j=i+1;j<=oListaDin.getCount();j++)
	      {
            prtFarm=(cFarm*)oListaDin.getInfNod(j);
	         int cod2=prtFarm->getCodigo();
   	   	if (cod1<cod2)
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
	cout<<"1. Agregar un producto \n";
	cout<<"2. Eliminar un producto \n";
   cout<<"3. Mostrar todos los productos \n";
   cout<<"4. Mostrar Lista en orden inverso\n";
   cout<<"5. Mostrar datos pares e impares\n";
   cout<<"6. Ordenar productos descendentemente\n";
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
   int posIns, posElm;
   cListaDin oListaDin;
   cFarm* ptrFarm;

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
            	cout<<"Ingrese el producto a insertar \n";
               ptrFarm=new cFarm;
	            ptrFarm->leerDatFarm();
               oListaDin.agregar(ptrFarm,posIns);
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
                  ptrFarm=new cFarm;
               	ptrFarm=(cFarm*)oListaDin.eliminar(posElm);
                  cout<<"Los datos del producto que se han eliminado son \n";
                  ptrFarm->verDatFarm();
               }
               else
               {
               	cout<<"La posicion ingresada es incorrecta \n";
               }
            }
            else
            {
            	cout<<"No existen productos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR TODOS LOS PRODUCTOS \n";
            if (!(oListaDin.empty()))
            	ptrFarm->mostrarDatFarm(oListaDin);
            else
            	cout<<"No existen productos que mostrar \n";
            break;
            case 4:
            cout<<"MOSTRAR TODOS LOS DATOS EN ORDEN INVERSO\n";
            if (!(oListaDin.empty()))
            	ptrFarm->mostrarDatFarmInv(oListaDin);
            else
            	cout<<"No existen productos que mostrar \n";
            break;
            case 5:
         	cout<<"MOSTRAR TODOS LOS PRODUCTOS PARES E IMPARES \n";
            if (!(oListaDin.empty()))
               {
            	ptrFarm->mostrarDatFarmImp(oListaDin);
               ptrFarm->mostrarDatFarmPares(oListaDin);
               }
            else
            	cout<<"No existen productos que mostrar \n";
            break;
            case 6:
         	cout<<"ORDENAR DESCENDENTE PRODUCTOS POR CODIGO \n";
            if (!(oListaDin.empty()))
            {
					ptrFarm->ordenar(oListaDin);
               ptrFarm->mostrarDatFarm(oListaDin);
            }
            else
            	cout<<"No existen productos que mostrar \n";
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