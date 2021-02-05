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
 void setAnt(cNodo* nAnte);
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

void cNodo::setAnt(cNodo* nAnte)
{
 ant=nAnte;
};

cNodo* cNodo::getAnt()
{
 return(ant);
};


class clista
{
 int count;
 cNodo* first;
 cNodo* last;
 cNodo* pos;
 cNodo* pos1;
 
 public:
 clista();
 int vacia();
 void situarPos(int npos);
 void situarPos1(int npos);
 void insertEn(void* info);
 void agregar(void* info);
 void* eliminarEn();
 void foreach(void(*mostrar)(void*));
 void* buscar(int(*condicion)(void*));
 void* buscarj(int(*condicur)(void*));
 void* retornar();
};

clista::clista()
{
 first=NULL;
 last=NULL;
 pos=NULL;
 count=0;
};

int clista::vacia()
{
 int flag=0;
 if(first==NULL)
  flag=1;
 return(flag);
};

void clista::situarPos1(int npos)
{
 if(vacia()==0)
  {
   pos=first;
   for(int i=1; i<npos; i++)
    {
     pos=pos->getSig();
    };
  };
};

void clista::situarPos(int npos)
{
 if(vacia()==0)
  {
   if(npos==0)
    {
     pos=NULL;
    }
   else
    {
     pos=first;
     for(int i=1; i<npos; i++)
      {
       pos=pos->getSig();
      };
    };
  };
};

void* clista::retornar()
{
 void* dato=NULL;
 dato=pos1->getInfo();
 pos1=pos1->getSig();
 return(dato);
};

void clista::insertEn(void *  info)
{
 cNodo * nuevo = new cNodo;
 cNodo * aux;
 nuevo->setInfo(info);
 if(vacia() == 0)
  {
   if( pos != NULL )
    {
     if( pos == first )
      {
       nuevo->setSig(first);
       first->setAnt(nuevo);
       first=nuevo;
      }
     else
      {
       aux=pos->getAnt();
       aux->setSig(nuevo);
       nuevo->setSig(pos);
       nuevo->setAnt(aux);
       pos->setAnt(nuevo);
      };
    }
    else
     {
      nuevo->setSig( first );
      first->setAnt( nuevo );
      first=nuevo;
     };
    }
  else
   {
    first=nuevo;
    last=nuevo;
   };
  count++;
  pos=nuevo;
};

void* clista::eliminarEn()
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
	};
      };
     delete( pos );
     count--;
    }
   else
    cout<<"No se est? apuntando a ning?n nodo.\n";
  }
 else
  cout<<"La lista est? vac?a.\n";
 return(dato);
};

void* clista::buscar(int(*condicion)(void*))
{
 void* p=NULL;
 pos=first;
 if(vacia()==0)
  {
   while((p==NULL)&&(pos!=NULL))
    {
     if(condicion(pos->getInfo())==1)
      p = pos->getInfo();
     else
      pos=pos->getSig();
    };
  };
 return(p);
};

void* clista::buscarj(int(*condicur)(void*))
{
 void* p=NULL;
 pos=first;
 if(vacia()==0)
  {
   while((p==NULL)&&(pos!=NULL))
    {
     if(condicur(pos->getInfo())==1)
      p = pos->getInfo();
     else
      pos=pos->getSig();
    };
  };
 return(p);
};

void clista::agregar(void* info)
{
 cNodo* nuevo=new cNodo;
 nuevo->setInfo(info);
 if(vacia()==1)
  {
   first=nuevo;
   pos1=first;
   first->setSig(NULL);
   first->setAnt(NULL);
   last=first;
  }
 else
  {
   last->setSig(nuevo);
   nuevo->setSig(NULL);
   nuevo->setAnt(last);
   last=nuevo;
  };
 count++;
 pos=first;
};

void clista::foreach(void(*mostrar)(void*))
{
 pos=first;
 while( pos != NULL )
  {
   mostrar(pos->getInfo());
   pos=pos->getSig();
  };
};

class cInfo
{
 char id[10];
 char nomb[20];
 
 public:
 char *getId();
 void setId(char *nid);
 char *getNombre();
 void setNomb(char *nnomb);
 void leer();
 void mostrar();
};

char *cInfo::getId()
{
 return(id);
}

void cInfo::setId(char *nid)
{
 strcmp(id,nid);
};

char *cInfo::getNombre()
{
 return(nomb);
}

void cInfo::setNomb(char *nnomb)
{
 strcmp(nomb,nnomb);
};

void cInfo::leer()
{
 cout<<"Ingrese el id:\n ";
 cin>>id;
 setId(id);
 cout<<"Ingrese el nombre:\n ";
 cin>>nomb;
 setId(nomb);
}

void cInfo::mostrar()
{
 cout<<"El nombre es: "<<getNombre()<<endl;
 cout<<"El id es: "<<getId()<<endl;
};

class cAnim:public cInfo
{
 char raza[20];
 
 public:
 void setRaza(char* nraza);
 char* getRaza();
 void leer();
 void mostrara();
};

void cAnim::setRaza(char* nraza)
{
 strcpy(raza,nraza);
};

char* cAnim::getRaza()
{
 return(raza);
};

void cAnim::leer()
{
 cout<<"Ingreso de animal\n";
 cInfo::leer();
 cout<<"Ingrese la raza\n";
 cin>>raza;
 setRaza(raza);
};

void cAnim::mostrara()
{
 cInfo::mostrar();
 cout<<getRaza()<<"\n";
};

void mostrar1(void* info)
{
 cAnim* ptr;
 ptr=(cAnim*)info;
 ptr->mostrar();
};

char cod[20];
int condicion(void* info)
{
 int flag=0;
 cAnim* ptr;
 ptr=(cAnim*)info;
 if(strcmp(ptr->getId(),cod)==0)
  flag=1;
 return(flag);
 };

class cJaula:public clista,public cInfo
{
 char ubic[20];
 char resp[20];
 int canim;
 cAnim* ptrAnim;
 
 public:
 void setUbicacion(char* nubic);
 char* getUbicacion();
 void setResp(char* nresp);
 char* getResp();
 void leerj();
 void mostrar();
 void mostrarj();
 void agregaranim();
 void agregarUnAnim(cAnim* ptrAnim);
 cAnim* eliminarUnAnim();
 cAnim* buscarAnimal();
 void eliminarestu();
};

void cJaula::setUbicacion(char* nubic)
{
 strcpy(ubic,nubic);
};

char* cJaula::getUbicacion()
{
 return(ubic);
};

void cJaula::setResp(char* nresp)
{
 strcpy(resp,nresp);
};

char* cJaula::getResp()
{
 return(resp);
};

void cJaula::leerj()
{
 cout<<"Ingreso de jaula\n";
 cInfo::leer();
 cout<<"Ingrese la ubicacion\n";
 cin>>ubic;
 setUbicacion(ubic);
 cout<<"Ingrese el nombre del responsable\n";
 cin>>resp;
 setResp(resp);
};

void cJaula::mostrarj()
{
 cInfo::mostrar(); 
 cout<<"La ubicacion de la jaula es: "<<getUbicacion()<<"\n";
 cout<<"El responsable de la jaula es: "<<getResp()<<"\n";
};

void cJaula::agregaranim()
{
 cout<<"Ingrese la cantidad de animales\n";
 cin>>canim;
 for(int i=0; i<canim; i++)
  {
   ptrAnim=new cAnim;
   ptrAnim->leer();
   agregar(ptrAnim);
  };
};

void cJaula::mostrar()
{
 cout<<"La datos de la jaula son\n";
 mostrarj();
 cout<<"Tiene la siguiente lista de animales\n";
 foreach(mostrar1);
};

void cJaula::agregarUnAnim(cAnim* ptrAnim)
{
 agregar(ptrAnim);
};

cAnim* cJaula::eliminarUnAnim()
{
 cAnim *ptr=(cAnim*)eliminarEn();
 return(ptr);
};

cAnim* cJaula::buscarAnimal()
{
 cAnim* ptr=(cAnim*)buscar(condicion);
 return(ptr);
};

void mostrar2(void* info)
{
 cJaula* ptrj=(cJaula*)info;
 ptrj->mostrar();
};

char ori[20];
int condiori(void* info)
{
 int flag=0;
 cJaula* ptr=(cJaula*)info;
 if(strcmp(ptr->getId(),ori)==0)
  flag=1;
 return(flag);
 };

char des[20];
int condides(void* info)
{
 int flag=0;
 cJaula* ptr;
 ptr=(cJaula*)info;
 if(strcmp(ptr->getId(),des)==0)
  flag=1;
 return(flag);
 };

class cZoo:public clista
{
 int cj;
 cJaula* ptrj;
 
 public:
 void agregarj();
 void intercambiar();
 void intercambio();
 void buscarAnimal();
 void eliminar();
 void mostrarj();
 int menu();
 void casos();
};

void cZoo::agregarj()
{
 cout<<"Ingrese la cantidad de jaulas que tiene el zoologico\n";
 cin>>cj;
 for(int i=0; i<cj; i++)
  {
   ptrj=new cJaula;
   ptrj->leerj();
   ptrj->agregaranim();
   agregar(ptrj);
  };
};

void cZoo::intercambiar()
{
 char id[10];
 cAnim* ptrAnim;
 cJaula* ptrcJaula1;
 cJaula* ptrcJaula2;
 cout<<"Ingrese el identificador de origen de la jaula\n";
 cin>>ori;
 ptrcJaula1=(cJaula*)buscarj(condiori);
 cout<<"Ingrese el identificador de destino de la jaula\n";
 cin>>des;
 ptrcJaula2=(cJaula*)buscarj(condides);
 if((ptrcJaula1!=NULL)&&(ptrcJaula2!=NULL))
  {
   cout<<"Ingrese el identificador del animal\n",
   cin>>id;
   ptrAnim=ptrcJaula1->buscarAnimal();
   if(ptrAnim!=NULL)
    {
     ptrAnim=ptrcJaula1->eliminarUnAnim();
     ptrcJaula2->agregarUnAnim(ptrAnim);
	 cout<<"Animal cambiado\n";
    }
   else
    cout<<"No se encontro al animal con ese id\n";
  }
 else
  cout<<"No se encontro una de las jaulas para realizar el intercambio\n";
};

void cZoo::buscarAnimal()
{
 cAnim* ptrAnim;
 cJaula* ptrcJaula1;
 cout<<"Ingrese el codigo del animal que se va a buscar y mostrar\n";
 cin>>cod;
 for(int i=0;i<cj; i++)
  {
   ptrcJaula1=(cJaula*)retornar();
   if(ptrcJaula1!=NULL)
    {
     ptrAnim=ptrcJaula1->buscarAnimal();
     if(ptrAnim!=NULL)
      {
       ptrcJaula1->mostrarj();
      };
    };
  };
};

void cZoo::mostrarj()
{
 cout<<"La lista de jaulas que tiene el zoologico son:\n";
 foreach(mostrar2);
};

int cZoo::menu()
{
 int cop;
 clrscr();
 cout<<"Que desea realizar\n";
 cout<<"1.- Agregar jaulas\n";
 cout<<"2.- Cambiar de jaula a un animal\n";
 cout<<"3.- Buscar un animal y mostrar en las jaulas que se encuentra\n";
 cout<<"4.- Mostrar las jaulas\n";
 do
  {
   cout<<"Escoja su opcion\n";
   cin>>cop;
  }
 while(cop>4);
 return(cop);
};

void cZoo::casos()
{
 char deseo;
 do
  {
   int op=menu();
   switch(op)
    {
     case 1:{
	     clrscr();
	     agregarj();
	    };
	    break;
     case 2:{
	     clrscr();
	     intercambiar();
	    };
	    break;
     case 3:{
	     clrscr();
	     buscarAnimal();
	    };
	    break;
     case 4:{
	     clrscr();
	     mostrarj();
	    };
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
 cZoo oZoo;
 oZoo.casos();
 getch();
};
