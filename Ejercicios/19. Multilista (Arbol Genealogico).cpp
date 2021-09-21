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
 cNodo();
 void setInfo(void* nInfo);
 void* getInfo();
 void setSig(cNodo * nSig);
 cNodo* getSig();
 void setAnt(cNodo* nAnte);
 cNodo* getAnt();
};

cNodo::cNodo()
{
 info = NULL;
 sig = NULL;
 ant = NULL;
}

void cNodo::setInfo(void* nInfo)
{
 info=nInfo;
}

void* cNodo::getInfo()
{
 return(info);
}

void cNodo::setSig(cNodo* nSig)
{
 sig=nSig;
}

cNodo* cNodo::getSig()
{
 return(sig);
}

void cNodo::setAnt(cNodo* nAnte)
{
 ant=nAnte;
}

cNodo* cNodo::getAnt()
{
 return(ant);
}

class cMultiLista
{
 int count;
 cNodo* first;
 cNodo* last;
 cNodo* pos;
 cNodo* pos1;

 public:
 cMultiLista();
 int vacia();
 int getCount();
 void setCount(int nCount);
 void situarPos(int nPos);
 void situarPos1(int nPos);
 void agregarEn(void* info);
 void agregar(void* info);
 void* eliminarEn();
 void forEach(void(*mostrar)(void*));
 void* buscarCodIntegrante(int(*condBusCodIntegrante)(void*));
 void* buscarCodGeneracion(int(*condicionCodigoGeneracion)(void*));
 void* eliminarCodIntegrante(int(*condBusCodIntegrante)(void*));
 void* retornarInfo();
};

cMultiLista::cMultiLista()
{
 first=NULL;
 last=NULL;
 pos=NULL;
 count=0;
}

int cMultiLista::vacia()
{
 int flag=0;
 if(first==NULL)
  flag=1;
 return(flag);
}

void cMultiLista::situarPos(int nPos)
{
 if(vacia()==0)
  {
   if(nPos==0)
    {
     pos=NULL;
    }
   else
    {
     pos=first;
     for(int i=1; i<nPos; i++)
      {
       pos=pos->getSig();
      }
    }
  }
}

int cMultiLista::getCount()
{
	return(count);
}

void cMultiLista::setCount(int nCount)
{
	count=nCount;
}

void cMultiLista::situarPos1(int nPos)
{
 if(vacia()==0)
  {
     pos1=first;
     for(int i=1; i<nPos; i++)
      {
       pos1=pos1->getSig();
      }    
  }
}

void* cMultiLista::retornarInfo()
{
 void* dato=NULL;
 dato=pos1->getInfo();
 return(dato);
 
}

void cMultiLista::agregarEn(void *  info)
{
 cNodo * newNodo = new cNodo;
 cNodo * aux;
 newNodo->setInfo(info);
 if(vacia() == 0)
  {   	
	if( pos == first )
      {
       newNodo->setSig(first);
	   newNodo->setAnt(NULL);
       first->setAnt(newNodo);
       first=newNodo;
      }
	else
	{
     if( pos == NULL )
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
  count++;
}

void* cMultiLista::eliminarEn()
{
 cNodo* aux;
 cNodo* aux2;
 void*  dato=NULL;
 if (vacia() == 0)
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
     delete(pos);
     count--;
    }
   else
    cout<<"No se esta? apuntando a ningun nodo\n";
  }
 else
  cout<<"La lista esta vacia\n";
 return(dato);
}

void* cMultiLista::buscarCodIntegrante(int(*condBusCodIntegrante)(void*))
{
 void* p=NULL;
 pos=first;
 if(vacia()==0)
  {
   while((p==NULL)&&(pos!=NULL))
    {
     if(condBusCodIntegrante(pos->getInfo())==1)
      p = pos->getInfo();
     else
      pos=pos->getSig();
    }
  }
 return(p);
}

void* cMultiLista::buscarCodGeneracion(int(*condicionCodigoGeneracion)(void*))
{
 void* p=NULL;
 pos=first;
 if(vacia()==0)
  {
   while((p==NULL)&&(pos!=NULL))
    {
     if(condicionCodigoGeneracion(pos->getInfo())==1)
      p = pos->getInfo();
     else
      pos=pos->getSig();
    }
  }
 return(p);
}

void* cMultiLista::eliminarCodIntegrante(int(*condBusCodIntegrante)(void*))
{
 void* p=NULL;
 pos=first;
 if(vacia()==0)
  {
   while((p==NULL)&&(pos!=NULL))
    {
     if(condBusCodIntegrante(pos->getInfo())==1)
      p = eliminarEn();
     else
      pos=pos->getSig();
    }
  }
 return(p);
}

void cMultiLista::agregar(void* info)
{
 cNodo* newNodo=new cNodo;
 newNodo->setInfo(info);
 if(vacia()==1)
  {
   first=newNodo;
   first->setSig(NULL);
   first->setAnt(NULL);
   last=first;
   pos=first;
  }
 else
  {
   last->setSig(newNodo);
   newNodo->setSig(NULL);
   newNodo->setAnt(last);
   last=newNodo;
   pos=last;
  }
 count++;
}

void cMultiLista::forEach(void(*mostrar)(void*))
{
 pos=first;
 while( pos != NULL )
  {
   mostrar(pos->getInfo());
   pos=pos->getSig();
  }
}

class cInfo
{
 char id[20];
 char nombre[20];
 
 public:
 char *getId();
 void setId(char *nid);
 char *getNombre();
 void setNombre(char *nNombre);
 void leerInfo();
 void mostrarInfo();
};

char *cInfo::getId()
{
 return(id);
}

void cInfo::setId(char *nid)
{
 strcmp(id,nid);
}

char *cInfo::getNombre()
{
 return(nombre);
}

void cInfo::setNombre(char *nNombre)
{
 strcmp(nombre,nNombre);
}

void cInfo::leerInfo()
{
 cout<<"Ingrese el id:\n";
 cin>>id;
 setId(id);
 cout<<"Ingrese el nombre:\n";
 cin>>nombre;
 setId(nombre);
}

void cInfo::mostrarInfo()
{
 cout<<"El nombre es: "<<getNombre()<<endl;
 cout<<"El id es: "<<getId()<<endl;
}

class cIntegrante:public cInfo
{
 int edad;
 
 public:
 cIntegrante();
 void setEdad(int nEdad);
 int getEdad();
 void leerIntegrante();
 void mostrarIntegrante();
};

cIntegrante::cIntegrante()
{
 edad=0;	
}

void cIntegrante::setEdad(int nEdad)
{
 edad=nEdad;
}

int cIntegrante::getEdad()
{
 return(edad);
}

void cIntegrante::leerIntegrante()
{
 cout<<"Ingreso de datos del integrante:\n";
 leerInfo();
 cout<<"Ingrese la edad:\n";
 cin>>edad;
 setEdad(edad);
}

void cIntegrante::mostrarIntegrante()
{
 mostrarInfo();
 cout<<getEdad()<<"\n";
}

void mostrarDatosIntegrante(void* info)
{
 cIntegrante* ptrIntegrante;
 ptrIntegrante=(cIntegrante*)info;
 ptrIntegrante->mostrarIntegrante();
}

char codigoIntegrante[20];
int condBusCodIntegrante(void* info)
{
 int flag=0;
 cIntegrante* ptrIntegrante;
 ptrIntegrante=(cIntegrante*)info;
 if(strcmp(ptrIntegrante->getId(),codigoIntegrante)==0)
  flag=1;
 return(flag);
 }

class cGeneracion:public cMultiLista,public cInfo
{
 int cantidadIntegrantes;
 char lugar[20];
 cIntegrante* ptrIntegrante;
 
 public:
 cGeneracion();
 void setCantidadIntegrantes(int nCantidadIntegrantes);
 int getCantidadIntegrantes();
 void setLugar(char* nLugar);
 char* getLugar();
 void leerGeneracion();
 void mostrarGeneracion();
 void mostrarGeneracionIntegrantes();
 void agregarIntegrante();
 void agregarUnIntegrante(cIntegrante* ptrIntegrante);
 cIntegrante* eliminarUnIntegrante();
 cIntegrante* buscarIntegrante();
 cIntegrante* eliminarIntegrante();
};

cGeneracion::cGeneracion()
{
  cantidadIntegrantes=0;
  strcpy(lugar," ");
  ptrIntegrante=NULL;
}

void cGeneracion::setCantidadIntegrantes(int nCantidadIntegrantes)
{
 cantidadIntegrantes=nCantidadIntegrantes;
}

int cGeneracion::getCantidadIntegrantes()
{
 return(cantidadIntegrantes);
}

void cGeneracion::setLugar(char* nLugar)
{
 strcpy(lugar,nLugar);
}

char* cGeneracion::getLugar()
{
 return(lugar);
}

void cGeneracion::leerGeneracion()
{
 cout<<"Ingreso de datos de la Generacion:\n";
 leerInfo();
 cout<<"Ingrese el lugar:\n";
 cin>>lugar;
 setLugar(lugar);
}

void cGeneracion::mostrarGeneracion()
{
 mostrarInfo(); 
 cout<<"El lugar de la generacion es: "<<getLugar()<<"\n";
}

void cGeneracion::mostrarGeneracionIntegrantes()
{
 cout<<"La datos de la Generacion son:\n";
 mostrarGeneracion();
 cout<<"Tiene los siguientes integrantes:\n";
 forEach(mostrarDatosIntegrante);
}

void cGeneracion::agregarIntegrante()
{
 cout<<"Ingrese la cantidad de integrantes:\n";
 cin>>cantidadIntegrantes;
 for(int i=0; i<cantidadIntegrantes; i++)
  {
   ptrIntegrante=new cIntegrante;
   ptrIntegrante->leerIntegrante();
   agregar(ptrIntegrante);
  }
}

void cGeneracion::agregarUnIntegrante(cIntegrante* ptrIntegrante)
{
 agregar(ptrIntegrante);
}

cIntegrante* cGeneracion::eliminarUnIntegrante()
{
 cIntegrante *ptrIntegrante=(cIntegrante*)eliminarEn();
 return(ptrIntegrante);
}

cIntegrante* cGeneracion::buscarIntegrante()
{
 cIntegrante* ptrIntegrante=(cIntegrante*)buscarCodIntegrante(condBusCodIntegrante);
 return(ptrIntegrante);
}

cIntegrante* cGeneracion::eliminarIntegrante()
{
 cIntegrante* ptrIntegrante=(cIntegrante*)eliminarCodIntegrante(condBusCodIntegrante);
 return(ptrIntegrante);
}

void mostrarGeneracionIntegrantes(void* info)
{
 cGeneracion* ptrGeneracion=(cGeneracion*)info;
 ptrGeneracion->mostrarGeneracionIntegrantes();
}

void mostrarGeneracion(void* info)
{
 cGeneracion* ptrGeneracion=(cGeneracion*)info;
 ptrGeneracion->mostrarGeneracion();
}

char codOrigenGeneracion[20];
int condBusCodOrigGeneracion(void* info)
{
 int flag=0;
 cGeneracion* ptrGeneracion=(cGeneracion*)info;
 if(strcmp(ptrGeneracion->getId(),codOrigenGeneracion)==0)
  flag=1;
 return(flag);
 }

char codDestinoGeneracion[20];
int condBusCodDestGeneracion(void* info)
{
 int flag=0;
 cGeneracion* ptrGeneracion=(cGeneracion*)info;
 if(strcmp(ptrGeneracion->getId(),codDestinoGeneracion)==0)
  flag=1;
 return(flag);
 }

char codigoGeneracion[20];
int condBusCodGeneracion(void* info)
{
 int flag=0;
 cGeneracion* ptrGeneracion;
 ptrGeneracion=(cGeneracion*)info;
 if(strcmp(ptrGeneracion->getId(),codigoGeneracion)==0)
  flag=1;
 return(flag);
 }

class cArbolGenealogico:public cMultiLista
{
 int cantidadGeneraciones;
 cGeneracion* ptrGeneracion;
 
 public:
 void agregarGeneracionEn();
 void intercambiarIntegranteGeneracion();
 void mostrarGeneracionIntegrantesArbol();
 void cantGeneraciones();
 int menu();
 void casos();
};

void cArbolGenealogico::agregarGeneracionEn()
{
 int posIns;
 cout<<"Ingrese la posicion del elemento a insertar en el arbol genealogico\n";
 cin>>posIns;
 if ((posIns>=1)&&(posIns<=(getCount()+1)))
 {
   situarPos(posIns); 
   ptrGeneracion=new cGeneracion;
   ptrGeneracion->leerGeneracion();
   ptrGeneracion->agregarIntegrante();
   agregarEn(ptrGeneracion); 
 }	 
}

void cArbolGenealogico::intercambiarIntegranteGeneracion()
{
 cIntegrante* ptrIntegrante;
 cGeneracion* ptrcGeneracionOrigen;
 cGeneracion* ptrGeneracionDestino;
 cout<<"Ingrese el identificador de origen de la generacion:\n";
 cin>>codOrigenGeneracion;
 ptrcGeneracionOrigen=(cGeneracion*)buscarCodGeneracion(condBusCodOrigGeneracion);
 cout<<"Ingrese el identificador de destino de la generacion:\n";
 cin>>codDestinoGeneracion;
 ptrGeneracionDestino=(cGeneracion*)buscarCodGeneracion(condBusCodDestGeneracion);
 if((ptrcGeneracionOrigen!=NULL)&&(ptrGeneracionDestino!=NULL))
  {
   cout<<"Ingrese el identificador del integrante:\n",
   cin>>codigoIntegrante;
   ptrIntegrante=ptrcGeneracionOrigen->buscarIntegrante();
   if(ptrIntegrante!=NULL)
    {
     ptrIntegrante=ptrcGeneracionOrigen->eliminarUnIntegrante();
     ptrGeneracionDestino->agregarUnIntegrante(ptrIntegrante);
	 cout<<"Integrante cambiado\n";
    }
   else
    cout<<"No se encontro al integrante con ese id\n";
  }
 else
  cout<<"No se encontro una de las generaciones para realizar el intercambio\n";
}

void cArbolGenealogico::mostrarGeneracionIntegrantesArbol()
{
 cout<<"La lista de generaciones que tiene el arbol genealogico son:\n";
 forEach(mostrarGeneracionIntegrantes);
}

void cArbolGenealogico::cantGeneraciones()
{
 cout<<"En el arbol genealogico el numero de generaciones ingresadas es de\n"<<getCount()<<"\n";
 cout<<"La lista de generaciones que tiene el arbol genealogico son:\n";
 forEach(mostrarGeneracion);
}

int cArbolGenealogico::menu()
{
 int cop;
 clrscr();
 cout<<"Que desea realizar\n";
 cout<<"1.- Agregar generaciones dada la posicion\n";
 cout<<"2.- Mostrar las generaciones\n";
 cout<<"3.- Cambiar de generacion a un integrante\n"; 
 cout<<"4.- Cantidad de generaciones existentes y mostrar sus datos\n";
 do
  {
   cout<<"Escoja su opcion\n";
   cin>>cop;
  }
 while(cop>6);
 return(cop);
}

void cArbolGenealogico::casos()
{
 char deseo;
 do
  {
   int op=menu();
   switch(op)
    {
     case 1:{
	     clrscr();
	     agregarGeneracionEn();
	    }
	    break;
	 case 2:{
	     clrscr();
	     mostrarGeneracionIntegrantesArbol();
	    }
	    break;	
	 case 3:{
	     clrscr();
	     intercambiarIntegranteGeneracion();
	    }
	    break;
     case 4:{
	     clrscr();
	     cantGeneraciones();
	    }
	    break;	
    }
   cout<<"Desea realizar otra opcion s/n: ";
   cin>>deseo;
  }
 while(deseo!='n');
}

void main()
{
 clrscr();
 cArbolGenealogico oArbolGenealogico;
 oArbolGenealogico.casos();
 getch();
}
