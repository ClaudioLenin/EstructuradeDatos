#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>

class cNodo
{
 void* info;
 cNodo * sig;
 cNodo* ant;

 public:
 void setInfo(void* nInfo);
 void* getInfo();
 void setSig(cNodo * nSig);
 cNodo* getSig();
 void setAnt(cNodo* nAnt);
 cNodo* getAnt();
 cNodo();
};

cNodo::cNodo()
{
 info = NULL;
 sig = NULL;
 ant = NULL;
};

void cNodo::setInfo(void* nInfo)
{
 info=nInfo;
};

void*  cNodo::getInfo()
{
 return(info);
};

void cNodo::setSig(cNodo* nSig)
{
 sig=nSig;
};

cNodo* cNodo::getSig()
{
 return(sig);
};

void cNodo::setAnt(cNodo* nAnt)
{
 ant=nAnt;
};

cNodo* cNodo::getAnt()
{
 return(ant);
};

class cLista
{
 int count;
 cNodo* first;
 cNodo* last;
 cNodo* pos;
 cNodo* pos1;
 
 public:
 cLista();
 int empty();
 void agregar(void* info);
 void* eliminar();
 void foreach(void(*mostrar)(void*));
 void* buscarCurso(int(*condiCurso)(void*));
 void* retornar();
};

cLista::cLista()
{
 first=NULL;
 last=NULL;
 pos=NULL;
 pos1=NULL;
 count=0;
};

int cLista::empty()
{
 int flag=0;
 if(first==NULL)
  flag=1;
 return(flag);
}

void cLista::agregar(void* info)
{
 cNodo* newNodo=new cNodo;
 newNodo->setInfo(info);
 if(empty()==1)
  {
   first=newNodo;
   pos1=first;
   first->setSig(NULL);
   first->setAnt(NULL);
   last=first;
  }
 else
  {
   last->setSig(newNodo);
   newNodo->setSig(NULL);
   newNodo->setAnt(last);
   last=newNodo;
  }
 count++;
 pos=first;
}

void* cLista::eliminar()
{
 cNodo* aux;
 cNodo* aux2;
 void*  dato=NULL;
 if (empty() == 0)
  {
   if ( pos != NULL )
    {
     dato=pos->getInfo();
     if(pos==first)
      {
       first = first->getSig();
      }
     else
      {
       aux = pos->getAnt();
       aux->setSig( pos->getSig() );
       if(pos==last)
		{
		 last=aux;
		}
       else
		{
		 aux2=pos->getSig();
		 aux2->setAnt(aux);
		}
      }
     delete( pos );
     count--;
    }
   else
    cout<<"No se esta? apuntando a ningun nodo\n";
  }
 else
  cout<<"La lista esta? vacia\n";
 return(dato);
}

void* cLista::retornar()
{
 void* dato=NULL;
 dato=pos1->getInfo();
 pos1=pos1->getSig();
 return(dato);
};

void* cLista::buscarCurso(int(*condiCurso)(void*))
{
 void* info=NULL;
 pos=first;
 if(empty()==0)
  {
   while((info==NULL)&&(pos!=NULL))
    {
     if(condiCurso(pos->getInfo())==1)
      info = pos->getInfo();
     else
      pos=pos->getSig();
    }
  }
 return(info);
}

void cLista::foreach(void(*mostrar)(void*))
{
 pos=first;
 while( pos != NULL )
  {
   mostrar(pos->getInfo());
   pos=pos->getSig();
  }
};

class cEstudiante
{
 char nombre[20];
 char apellido[20];
 char codigo[20];
 
 public:
 cEstudiante();
 void setNombre(char* nNombre);
 char* getNombre();
 void setApellido(char* nApellido);
 char* getApellido();
 void setCodigo(char* nCodigo);
 char* getCodigo();
 void leer();
 void mostrar();
};

cEstudiante::cEstudiante()
{
 strcpy(nombre," ");
 strcpy(apellido," ");
 strcpy(codigo," ");
}

void cEstudiante::setNombre(char* nNombre)
{
 strcpy(nombre,nNombre);
};

char* cEstudiante::getNombre()
{
 return(nombre);
};
void cEstudiante::setApellido(char* nApellido)
{
 strcpy(apellido,nApellido);
};
char* cEstudiante::getApellido()
{
 return(apellido);
};

void cEstudiante::setCodigo(char* nCodigo)
{
 strcpy(codigo,nCodigo);
};

char* cEstudiante::getCodigo()
{
 return(codigo);
};

void cEstudiante::leer()
{
 char cad[50];
 cout<<"Ingrese el nombre del estudiante\n";
 cin>>cad;
 setNombre(cad);
 cout<<"Ingrese el apellido del estudiante\n";
 cin>>cad;
 setApellido(cad);
 cout<<"Ingrese el codigo del estudiante\n";
 cin>>cad;
 setCodigo(cad);
};

void cEstudiante::mostrar()
{
 cout<<getNombre()<<"\n";
 cout<<getApellido()<<"\n";
 cout<<getCodigo()<<"\n";
};

void mostrarEst(void* info)
{
 cEstudiante* ptr=(cEstudiante*)info;
 ptr->mostrar();
};

char cod[50];

int condicion(void* info)
{
 int flag=0;
 cEstudiante* ptr=(cEstudiante*)info;
 if(strcmp(ptr->getCodigo(),cod)==0)
  flag=1;
 return(flag);
};

class cCurso:public cLista
{
 char paralelo[20];
 char semestre[20];
 int cantEstudiantes;
 cEstudiante* ptrEst;
 
 public:
 cCurso();
 void setParalelo(char* nParalelo);
 char* getParalelo();
 void setSemestre(char* nSemestre);
 char* getSemestre();
 void leerCurso();
 void mostrarEstudiantes();
 void agregarEstudiantes();
 void agregarUnEst(cEstudiante* ptrEst);
 cEstudiante* eliminarUnEst();
 cEstudiante* buscarEstudiante();
 void mostrarCursos();
};

cCurso::cCurso()
{
 strcpy(paralelo," ");
 strcpy(semestre," ");
 cantEstudiantes=0;
}

void cCurso::setParalelo(char* nParalelo)
{
 strcpy(paralelo,nParalelo);
};

char* cCurso::getParalelo()
{
 return(paralelo);
};

void cCurso::setSemestre(char* nSemestre)
{
 strcpy(semestre,nSemestre);
};

char* cCurso::getSemestre()
{
 return(semestre);
};

void cCurso::leerCurso()
{
 char cad[20];
 cout<<"Ingrese el semestre del curso\n";
 cin>>cad;
 setSemestre(cad);
 cout<<"Ingrese el paralelo del curso\n";
 cin>>cad;
 setParalelo(cad);
};

void cCurso::mostrarCursos()
{
 cout<<"El semestre es: "<<getSemestre()<<"\n";
 cout<<"El paralelo es: "<<getParalelo()<<"\n";
 cout<<"La cantidad de estudiantes del curso es: "<<cantEstudiantes<<"\n";
};

void cCurso::agregarEstudiantes()
{
 leerCurso();
 cout<<"Ingrese la cantidad de estudiantes\n";
 cin>>cantEstudiantes;
 for(int i=0; i<cantEstudiantes; i++)
  {
   ptrEst=new cEstudiante;
   ptrEst->leer();
   agregar(ptrEst);
  };
};

void cCurso::mostrarEstudiantes()
{
 cout<<endl;
 cout<<"Los datos del curso es\n";
 mostrarCursos();
 cout<<"Tiene la siguiente nomina de estudiantes\n";
 foreach(mostrarEst);
};

void cCurso::agregarUnEst(cEstudiante* ptrEst)
{
 agregar(ptrEst);
};

cEstudiante* cCurso::eliminarUnEst()
{
 cEstudiante* ptr=(cEstudiante*)eliminar();
 return(ptr);
};

cEstudiante* cCurso::buscarEstudiante()
{
 cEstudiante* ptr=(cEstudiante*)buscarCurso(condicion);
 return(ptr);
};

void mostrar2(void* info)
{
 cCurso* ptrc=(cCurso*)info;
 ptrc->mostrarEstudiantes();
 cout<<endl;
};

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
 };

char destino[20];
int condicDes(void* info)
{
 int flag=0;
 cCurso* ptr;
 ptr=(cCurso*)info;
 if((strcmp(ptr->getSemestre(),destino)==0)&&(strcmp(ptr->getParalelo(),paralelo)==0))
  flag=1;
 return(flag);
 };

class cEscuela:public cLista
{
 int cantCursos;
 cCurso* ptrCurso;
 
 public:
 void agregarCurso();
 void cambiar();
 void buscarEstudiante();
 void eliminar();
 void mostrarCurso();
 int menu();
 void casos();
};

void cEscuela::agregarCurso()
{
 cout<<"Ingrese la cantidad de cursos que tiene la Escuela\n";
 cin>>cantCursos;
 for(int i=0; i<cantCursos; i++)
  {
   ptrCurso=new cCurso;
   ptrCurso->agregarEstudiantes();
   agregar(ptrCurso);
  }
}

void cEscuela::buscarEstudiante()
{
 cEstudiante* ptrEst;
 cCurso* ptrCurso1;
 cout<<"Ingrese el codigo del estudiante que se va a buscar y mostrar\n";
 cin>>cod;
 for(int i=0;i<cantCursos; i++)
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
 cEstudiante* ptrEst;
 cCurso*ptrCurso1;
 cCurso*ptrCurso2;
 cout<<"Ingrese el semestre de origen de donde se va a cambiar al estudiante\n";
 cin>>origen;
 cout<<"Ingrese el paralelo del semestre del cual se desea cambiar el estudiante\n";
 cin>>paralelo;
 ptrCurso1=(cCurso*)buscarCurso(condicOrig);
 cout<<"Ingrese el semestre de destino a donde se va a cambiar al estudiante\n";
 cin>>destino;
 cout<<"Ingrese el paralelo del semestre al cual se desea cambiar el estudiante\n";
 cin>>paralelo;
 ptrCurso2=(cCurso*)buscarCurso(condicDes);
 if((ptrCurso1!=NULL)&&(ptrCurso2!=NULL))
  {
   cout<<"Ingrese el codigo del estudiantes que se va a intercambiar de un curso a otro\n",
   cin>>cod;
   ptrEst=ptrCurso1->buscarEstudiante();
   if(ptrEst!=NULL)
    {
     ptrEst=ptrCurso1->eliminarUnEst();
     ptrCurso2->agregarUnEst(ptrEst);
    }
   else
    cout<<"No se encontro al estudiante con ese codigo\n";
  }
 else
  cout<<"No se encontro uno de los cursos para realizar el intercambio\n";
}

void cEscuela::mostrarCurso()
{
 cout<<"La lista de cursos que tiene el sistema academico es:\n";
 foreach(mostrar2);
};

int cEscuela::menu()
{
 int op;
 clrscr();
 cout<<"Que desea realizar\n";
 cout<<"1.- Agregar cursos\n";
 cout<<"2.- Cambiar de curso a un estudiante\n";
 cout<<"3.- Buscar un estudiante y mostrar en el cursos que se encuentra\n";
 cout<<"4.- Mostrar los cursos y estudiantes\n";
 do
  {
   cout<<"Escoja su opcion\n";
   cin>>op;
  }
 while(op>4);
 return(op);
}

void cEscuela::casos()
{
 char deseo;
 do
  {
   int op=menu();
   switch(op)
    {
     case 1:{
	     clrscr();
	     agregarCurso();
	    }
	    break;
     case 2:{
	     clrscr();
	     cambiar();
	    }
	    break;
     case 3:{
	     clrscr();
	     buscarEstudiante();
	    }
	    break;
     case 4:{
	     clrscr();
	     mostrarCurso();
	    }
	    break;
    };
   cout<<"Desea realizar otra opcion s/n: ";
   cin>>deseo;
  }
 while(deseo!='n');
};

void main()
{
 clrscr();
 cEscuela oEscuela;
 oEscuela.casos();
 getch();
};