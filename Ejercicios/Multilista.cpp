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
        aux2->setAnt(aux);  /////////////////////////////////////
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

void mostrarEst(void* info)
{
  cEst*ptr=(cEst*)info;
  ptr->mostrar();
}

int cod;

int condicion(void* info)
{
 int flag=0;
 cEst* ptr=(cEst*)info;
  if(ptr->getCodigo()==cod)
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

void cCurso::mostrarCursos()
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
 agregar(ptrEst);
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

 void mostrar2(void* info)
 {
  cCurso* ptrc=(cCurso*)info;
  ptrc->mostrarEstudiantes();
  cout<<endl;
 }

char origen[20];
char paralelo[20];

int condicOrig(void* info)
{
 int flag=0;
 cCurso* ptr;
 ptr=(cCurso*)info;
 if((strcmp(ptr->getSemestre(),origen)==0)&&(strcmp(ptr->getParalelo(),paralelo)==0))
 flag=1;
 return(flag);
}

char destino[20];

int condicDes(void* info)
{
 int flag=0;
  cCurso* ptr;
 ptr=(cCurso*)info;
 if((strcmp(ptr->getSemestre(),destino)==0)&&(strcmp(ptr->getParalelo(),paralelo)==0))
 flag=1;
 return(flag);
}

class cEscuela:public cListaDinDob
{
 int ccu;
 cCurso* ptrCurso;
 public:
 void agregarCurso();
 void cambiar();
 void buscarEstudiante();
 void eliminar();
 void mostrarCursos();
 int menu();
 void casos();
};

void cEscuela::agregarCurso()
{
 cout<<"Ingrese la cantidad de cursos que tiene la escuela\n";
 cin>>ccu;
 for(int i=0;i<ccu;i++)
 {
  ptrCurso=new cCurso;
  ptrCurso->agregarEstudiantes();
  agregar(ptrCurso);
 }
}

void cEscuela::buscarEstudiante()
{
 cEst* ptrEst;
 cCurso* ptrCurso1;
 cout<<"ingrese el codigo del estudiante que va a buscar y mostrar\n";
 cin>>cod;
  for(int i=0; i<ccu;i++)
   {
   ptrCurso1=(cCurso*)retornar();
   if(ptrCurso1!=NULL)
   {
    ptrEst=ptrCurso1->buscarEstudiante();
    if(ptrEst!=NULL)
    {
     ptrCurso1->mostrarCursos();
    }
  }
 }
}

void cEscuela::cambiar()
{
cEst* ptrEst;
cCurso* ptrCurso1;
cCurso* ptrCurso2;
cout<<"Ingrese el semestre de origen didbde se va a cambiar al estudiante\n";
cin>>origen;
cout<<"Ingrese el paralelo del semestre dek cual se desea cambiar\n";
cin>>paralelo;
ptrCurso1=(cCurso*)buscarCurso(condicOrig);
cout<<"Ingrese el semestre de destino a donde se va a cambiar al estudainte\n";
cin>>destino;
cout<<"Ingrese el paralelo del semestre al cual se desea cambiar\n";
cin>>paralelo;
ptrCurso2=(cCurso*)buscarCurso(condicDes);
if((ptrCurso1!=NULL)&&(ptrCurso2!=NULL))
 {
   cout<<"Ingrese el codigo del estudiante que se va a intercambiar\n";
   cin>>cod;
   ptrEst=ptrCurso1->buscarEstudiante();
   if(ptrEst!=NULL)
   {
    ptrEst=ptrCurso1->eliminarUnEst();
    ptrCurso2->agregarUnEst(ptrEst);
   }
   else
   cout<<"no se encontrpo al estudiante con ese codigo\n";
 }
   else
   cout<<"no se encontro uno de los cursos para realizar el intercambio\n";
}

void cEscuela::mostrarCursos()
{
 cout<<"la lista de cursos que tiene el sistema cademico es";
 foreach(mostrar2);
}




int cEscuela::menu()
{
	int op;
   clrscr();
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar cursos \n";
	cout<<"2. Cambiar de curso a un estudiante \n";
   cout<<"3. Buscar un estudiante y mostrar el  curso que se encuentra \n";
   cout<<"4. Mostrar los cursos y estudiantes\n";
   do
   {
   	cout<<"Escoja una opcion \n";
      cin>>op;
   }
   while(op>4);
   return op;
}

void cEscuela::casos()
{
	char deseo;
   //int posIns, posElm;
   //cListaDinDob oListaDinDob;
    do
    {
    int op=menu();
    switch(op)
    {
     case 1:
     clrscr();
     agregarCurso();
     break;
     case 2:
      clrscr();
      cambiar();
      break;
     case 3:
      clrscr();
      buscarEstudiante();
      break;
    case 4:
    clrscr() ;
    mostrarCursos();
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
   cEscuela oEscuela;
   oEscuela.casos();
   getch();
}
