#include <iostream.h>
#include <string.h>
#include <conio.h>

class cNodo
{
   void* info;
	cNodo* ant;
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
	ant=newAnt;
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

class cListaDinDob
{
   int count;
   cNodo* first;
   cNodo* last;
   cNodo* pos;
   cNodo* pos1;

   public:
   cListaDinDob();
   //int getCount();
   //void setCount(int nCount);
   int empty();
   //void situarPos(int iPos);
   void foreach(void(*mostrar)(void*));
   void* buscarCurso(int(*condiCurso)(void*));
   void* retornar();
   void agregar(void* info);
   void* eliminar();
  // void mostrar();
};

cListaDinDob::cListaDinDob()
{
   pos1=0;
   count=0;
   first=NULL;
   last=NULL;
   pos=NULL;
}

/*int cListaDinDob::getCount()
{
	return(count);
}

void cListaDinDob::setCount(int nCount)
{
	count=nCount;
} */

int cListaDinDob::empty()
{
   int flag=0;
	if (first==NULL)
	   flag=1;
    return(flag);
}

/*void cListaDinDob::situarPos(int iPos)
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
} */

void cListaDinDob::agregar(void* info)
{
   //cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (empty()==1)
   {
     first=newNodo;
     pos1=first;
     first->setSig(NULL);
     first->setAnt(NULL);

   }
      else
      {
            last->setSig(newNodo);
            newNodo->setSig(NULL);
            newNodo->setAnt(last);
            last=newNodo;
         }
         /*else
         {
         	aux=pos->getAnt();
            aux->setSig(newNodo);
            newNodo->setAnt(aux);
            newNodo->setSig(pos);
            pos->setAnt(newNodo);
         }*/
 /*  else
   {
      newNodo->setSig(NULL);
      newNodo->setAnt(NULL);
   	first=newNodo;
      pos=first;
      last=first;
   }*/
   count++;
   pos=first;
   //setCount(getCount()+1);
}

void* cListaDinDob::eliminar()
{
	//void* datElim;
   void* dato=NULL;
   cNodo* aux;
	cNodo* aux2;
   if (empty()==0)
   {
    if (pos!=NULL)
    {
      dato=pos->getInfo();
      if(pos==first)
      {
        first=first->getSig();
      }
      else
      {
        aux=pos->getAnt();
        aux->setSig(pos->getSig());
        if(pos==last)
        {
         last=aux;
        }
       else
       {
        aux2=pos->getSig();
        aux2=setAnt(aux);
       }
	}
   delete(pos);
   count--;
  }
  else
  cout<<"No se esta apuntando a ningun nodo\n";
 }
 else
 cout<<"La lista esta vacia\n";
 return(dato);
}

/*void cListaDinDob::mostrar()
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
} */

void* cListaDinDob::retornar()
{
 void* dato=NULL;
 dato=pos1->getInfo();
 pos1=pos1->getSig();
 return(dato);
}

void* cListaDinDob::buscarCurso(int(*condiCurso)(void*))
{
 void* info=NULL;
 pos=first;
 if(empty()==0)
  {
   while((info==NULL)&&(pos!=NULL))
   {
    if(condiCurso(pos->getInfo())==1)
    info=pos->getInfo();
    else
    pos=pos->getSig();
   }
  }
 return(info);
}

void cListaDinDob::foreach(void(*mostrar)(void*))
{
 pos=first;
 while(pos!=NULL)
  {
   mostrar(pos->getInfo());
   pos=pos->getSig();
  }
}

class cEst
{
	char nombre[10];
   char apellido [10];
   int codigo;

   public:
   //cEst();
   void setNombre (char* newNomb);
   char* getNombre();
   void setApellido (char* newApellido);
   char* getApellido();
   void setCodigo (int newCodigo);
   int getCodigo();
   void leer();
   void mostrar();
};

/*cEst::cEst()
{
   strcpy(nombre," ");
	strcpy(apellido," ");
	codigo=0;
} */

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

void cEst::leer()
{
	char nomb[10];
 	char apell[10];
   int cod;

   cout<<"Ingrese el nombre del estudiante ";
   cin>>nomb;
   setNombre(nomb);
   cout<<"Ingrese el apellido del estudiante ";
   cin>>apell;
   setApellido(apell);
   cout<<"Ingrese el codigo del estudiante ";
   cin>>cod;
   setCodigo(cod);
}

/*void cEst::verDatEst()
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

*/
void cEst::mostrar()
{
 cout<<getNombre()<<"\n";
 cout<<getApellido()<<"\n";
 cout<<getCodigo()<<"\n";
}

void mostrarest(void* info)
{
  cEst*ptr=(cEst*)info;
  ptr->mostrar();
}

int cod;

int condicion(void* info)
{
 int flag=0;
 cEst* ptr=(cEst*)info;
  if(ptr->getCodigo==cod)
   flag=1;
   return(flag);
}

class cCurso:public cListaDinDob
{
char paralelo[20];
char semestre[20];
int cantEstudiantes;
cEst* ptrEst;

public:
 void setParalelo(char* nParalelo);
 char* getParalelo();
 void setSemestre(char* nSemestre);
 char* getSemestre();
 void leerCurso();
 void mostrarEstudiantes();
 void agregarEstudiantes();
 void agregarUnEst(cEst* ptrEst);
 cEst* eliminarUnEst();
 cEst* buscarEstudiante();
 void mostrarCursos();
};

void cCurso::setParalelo(char* nParalelo)
{
 strcpy(paralelo,nParalelo);
}

char* cCurso::getParalelo()
{
 return(paralelo);
}

void cCurso::setSemestre(char* nSemestre)
{
 strcpy(semestre,nSemestre);
}

char* cCurso::getSemestre()
{
 return(semestre);
}

void cCurso::leerCurso()
{
 char cad[20];
 cout<<"Ingrese el semestre del curso\n";
 cin>>cad;
 setSemestre(cad);
 cout<<"Ingrese el paralelo del curso\n";
 cin>>cad;
 setParalelo(cad);
}

void cCurso::mostrarCursos
{
 cout<<"El semestre es: "<<getSemestre()<<"\n";
 cout<<"El paralelo es: "<<getParalelo()<<"\n";
}
void cCurso::agregarEstudiantes()
{
leerCurso();
cout<<"Ingrese la cantidad de estudiantes\n";
cin>>cantEstudiantes;
for(int i=0;i<cantEstudiantes;i++)
 {
  ptrEst=new cEst;
  ptrEst->leer();
  agregar(ptrEst);
 }
}
void cCurso::mostrarEstudiantes()
{
cout<<endl;
cout<<"Los datos del curso es\n";
mostrarCursos();
cout<<"Tiene la siguiente nomina de estudiantes\n";
foreach(mostrarEst);
}

void cCurso::agregarUnEst(cEst* ptrEst)
{
 agreagr(ptrEst);
}
cEst* cCurso::eliminarUnEst()
{
 cEst* ptr=(cEst*)eliminar();
 return(ptr);
}

cEst* cCurso::buscarEstudiante()
{
 cEst* ptr=(cEst*)buscarCurso(condicion);
 return(ptr);
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
   cListaDinDob oListaDinDob;

   cout<<"LISTA DINAMICA DOBLEMENTE ENLAZADA, INSERTAR Y ELIMINAR EN POS \n";
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
            if ((posIns>=1)&&(posIns<=(oListaDinDob.getCount()+1)))
            {
            	oListaDinDob.situarPos(posIns);
               cout<<"Ingrese el dato a insertar \n";
               char* pDat=new char;
               cin>>*(pDat);
               oListaDinDob.agregar(pDat);
            }
            else
            {
            	cout<<"La posicion ingresada es incorrecta \n";
            }
            break;
         case 2:
         	cout<<"ELIMINAR UN ELEMENTO \n";
            if (!(oListaDinDob.empty()))
            {
               cout<<"Ingrese la posicion del elemento a eliminar \n";
					cin>>posElm;
               if ((posElm>=1)&&(posElm<=oListaDinDob.getCount()))
               {
               	oListaDinDob.situarPos(posElm);
                  char* aux=(char*)oListaDinDob.eliminar();
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
            if (!(oListaDinDob.empty()))
            	oListaDinDob.mostrar();
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
