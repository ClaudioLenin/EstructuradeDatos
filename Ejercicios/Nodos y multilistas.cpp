#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

class cNodo
{
	void* info;
   cNodo* sig;
   cNodo* ant;

   public:
   cNodo();
   void setInfo(void* newInfo);
   void* getInfo();
   void setSig(cNodo* newSig);
   cNodo* getSig();
   void setAnt(cNodo* newAnt);
   cNodo* getAnt();
};

cNodo::cNodo()
{
	info = NULL;
   sig = NULL;
   ant = NULL;
}

void cNodo::setInfo(void* newInfo)
{
	info = newInfo;
}

void* cNodo::getInfo()
{
	return (info);
}

void cNodo::setSig(cNodo* newSig)
{
	sig = newSig;
}

cNodo* cNodo::getSig()
{
	return (sig);
}

void cNodo::setAnt(cNodo* newAnt)
{
	ant = newAnt;
}

cNodo* cNodo::getAnt()
{
	return (ant);
}

class cListaDinMult
{
	int count;
   cNodo* first;
   cNodo* last;
   cNodo* pos;
   cNodo* pos1;

   public:
   cListaDinMult();
   int empty();
   void agregar(void* info);
   void* eliminar();
   void foreach(void(*mostrar)(void*));
   void* buscarGeneracion(int(*condiGeneracion)(void*));
	void* retornar();
   void situarPos(int iPos);
};

cListaDinMult::cListaDinMult()
{
	count = 0;
   first = NULL;
   last = NULL;
   pos = NULL;
   pos1 = NULL;
}

int cListaDinMult::empty()
{
	if(first == NULL)
   	return (1);
   else
   	return (0);
}

void cListaDinMult::situarPos(int iPos)
{
	int max=count;
   if ((iPos>=1)&&(iPos<=(max+1)))
   {
   	if (empty()==0)
      {
      	pos=first;
         for (int i=1;i<iPos;i++)
         {
         	pos=pos->getSig();
         }
      }
   }
}

void cListaDinMult::agregar(void* info)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty()))
   {
		if (pos==first)
      {
      	newNodo->setSig(first);
         newNodo-> setAnt(NULL);
         first -> setAnt(newNodo);
         first=newNodo;
      }
      else
      {
      	if (pos==NULL)
         {
            last->setSig(newNodo);
            newNodo -> setAnt(last);
            newNodo -> setSig(NULL);
            last=newNodo;
            //pos=last;
         }
         else
         {
            aux = pos -> getAnt();
            aux -> setSig(newNodo);
            newNodo -> setAnt(aux);
            newNodo->setSig(pos);
            pos -> setAnt(newNodo);
         }
      }
   }
   else
   {
   	first=newNodo;
      newNodo -> setSig(NULL);
      newNodo -> setAnt(NULL);
      pos=first;
      last = first;
   }
	count++;
}

void* cListaDinMult::eliminar()
{
	void* datElim = NULL;
   cNodo* aux;
   cNodo* aux2;
   if(empty() == 0)
   {
   	if(pos != NULL)
      {
         datElim = pos -> getInfo();
         if(pos == first)
         	first = first -> getSig();
			else
         {
         	aux = pos -> getAnt();
            aux -> setSig(pos -> getSig());
            if(pos == last)
            	last = aux;
            else
            {
            	aux2 = pos -> getSig();
               aux2 -> setAnt(aux);
            }
         }
         delete(pos);
         count--;
      }
      else
      	cout<<"\n No se esta apuntando a ningun nodo \n";
   }
   else
   	cout<<"\n La lista esta vacia \n";
	return (datElim);
}

void* cListaDinMult::retornar()
{
	void* dato = NULL;
   dato = pos1 -> getInfo();
   pos1 = pos1 -> getSig();
   return(dato);
}

void* cListaDinMult::buscarGeneracion(int(*condiGeneracion)(void*))
{
	void* info = NULL;
   pos = first;
   if(empty() == 0)
   {
   	while((info == NULL) && (pos != NULL))
      {
      	if(condiGeneracion(pos -> getInfo()) == 1)
         	info = pos -> getInfo();
         else
         	pos = pos -> getSig();
      }
   }
   return(info);
}

void cListaDinMult::foreach(void(*mostrar)(void*))
{
	pos = first;
   while(pos != NULL)
   {
   	mostrar(pos -> getInfo());
      pos = pos -> getSig();
   }
}

class cRegistro
{
   char nombre[20];
   char identificador[20];

   public:
   	cRegistro();
   	void setNombre(char* newNombre);
   	char* getNombre();
   	void setIdentificador(char* newIdentificador);
   	char* getIdentificador();
   	void leerRegistro();
   	void mostrarRegistro();
};

cRegistro::cRegistro()
{
   strcpy(nombre," ");
   strcpy(identificador," ");
}

void cRegistro::setNombre(char* newNombre)
{
   strcpy(nombre, newNombre);
}

char* cRegistro::getNombre()
{
   cout<<" ";return nombre;
}


void cRegistro::setIdentificador(char* newIdentificador)
{
   strcpy(identificador,newIdentificador);
}

char* cRegistro::getIdentificador()
{
   cout<<" ";return identificador;
}

void cRegistro::leerRegistro()
{
   char cadena[50];
   cout<<"\n Ingrese el nombre: ";
   gets(cadena);
   setNombre(cadena);
   cout<<" Ingrese el identificador: ";
   gets(cadena);
   setIdentificador(cadena);
}

void cRegistro::mostrarRegistro()
{
   cout<<"\n El nombre es: "<<getNombre();
   cout<<"El identificador es: "<<getIdentificador();
}


class cIntegrante:public cRegistro
{
   int edad;
   public:
   	cIntegrante();
   	void setEdad(int newEdad);
   	int getEdad();
   	void leer();
   	void mostrar();
};

cIntegrante::cIntegrante()
{
   edad=0;
}

void cIntegrante::setEdad(int newEdad)
{
   edad=newEdad;
}

int cIntegrante::getEdad()
{
   cout<<" ";return edad;
}

void cIntegrante::leer()
{
   int edad;
   cout<<"\n DATOS DE INTEGRANTE: ";
   cRegistro:leerRegistro();
   cout<<" Ingrese la edad: ";
   cin>>edad;
   setEdad(edad);
}

void cIntegrante::mostrar()
{
   cRegistro:mostrarRegistro();
   cout<<"\n La edad es: "<<getEdad()<<"\n";
}

void mostrarInte(void* info)
{
   cIntegrante* ptr=(cIntegrante*)info;
   ptr->mostrar();
};


char ident[50];

int condicion(void* info)
{
   int flag=0;
   cIntegrante* ptr=(cIntegrante*)info;
   if(strcmp(ptr->getIdentificador(),ident)==0)
   	flag=1;
   return(flag);
}

class cGeneracion:public cRegistro, public cListaDinMult
{
	char lugar[20];
   int cantIntegrantes;
   cIntegrante* ptrInte;

   public:
      cGeneracion();
   	void setLugar(char* nLugar);
      char* getLugar();
      void leerGeneracion();
      void mostrarIntegrantes();
      void agregarIntegrantes();
      void agregarUnInte(cIntegrante* ptrInte);
      cIntegrante* eliminarUnInte();
      cIntegrante* buscarIntegrante();
      void mostrarGeneraciones();
};

cGeneracion::cGeneracion()
{
   strcpy(lugar," ");
   cantIntegrantes=0;
}

void cGeneracion::setLugar(char* nLugar)
{
   strcpy(lugar,nLugar);
}

char* cGeneracion::getLugar()
{
   return lugar;
}

void cGeneracion::leerGeneracion()
{
   char cad[20];
   cout<<"\n DATOS DE GENERACION: ";
   cRegistro:leerRegistro();
   cout<<" Ingrese el lugar: ";
   gets(cad);
   setLugar(cad);
}

void cGeneracion::mostrarGeneraciones()
{
   cRegistro:mostrarRegistro();
   cout<<"\n El lugar es: "<<getLugar()<<"\n";
}

void cGeneracion::agregarIntegrantes()
{
   leerGeneracion();
   cout<<" Ingrese la cantidad de integrantes: ";
   cin>>cantIntegrantes;
   for(int i=0;i<cantIntegrantes;i++)
   {
      ptrInte=new cIntegrante;
      ptrInte->leer();
      agregar(ptrInte);
   }
}

void cGeneracion::mostrarIntegrantes()
{
   cout<<"\n Los datos de la generacion son:\n ";
   mostrarGeneraciones();
   cout<<"\n Tiene la siguiente nomina de integrantes: \n";
   foreach(mostrarInte);
}

void cGeneracion::agregarUnInte(cIntegrante* ptrInte)
{
   agregar(ptrInte);
}

cIntegrante* cGeneracion::eliminarUnInte()
{
   cIntegrante* ptr=(cIntegrante*)eliminar();
   return(ptr);
}

cIntegrante* cGeneracion::buscarIntegrante()
{
   cIntegrante* ptr=(cIntegrante*)buscarGeneracion(condicion);
   return(ptr);
}

void mostrar2(void* info)
{
   cGeneracion* ptrc=(cGeneracion*)info;
   ptrc->mostrarIntegrantes();
   cout<<"\n ";
}

void mostrar3(void* info)
{
   cGeneracion* ptrc=(cGeneracion*)info;
   ptrc->mostrarGeneraciones();
   cout<<"\n ";
}

char origen[20];
char destino[20];

int condicOrig(void* info)
{
   int flag=0;
   cGeneracion* ptr;
   ptr=(cGeneracion*)info;
   if((strcmp(ptr->getIdentificador(),origen)==0))
   	flag=1;
   return(flag);
}

int condicDes(void* info)
{
   int flag=0;
   cGeneracion* ptr;
   ptr=(cGeneracion*)info;
   if(strcmp(ptr->getIdentificador(),destino)==0)
   	flag=1;
   return(flag);
}


class cArbolGenealogico : public cListaDinMult
{
	int cantGeneraciones;
   cGeneracion* ptrGeneracion;
   public:
   	void agregarGeneracion();
      void cambiar();
      void buscarIntegrante();
      void eliminar();
      void verGeneraciones();
      void VersoloGeneraciones();
      int menu();
      void casos();
};

int cg;

void cArbolGenealogico::agregarGeneracion()
{
   int posIns;
	cout << "\n Ingrese la cantidad de Generaciones que tiene el Arbol Genealogico: ";
   cin >> cantGeneraciones;
   for(int i=0; i < cantGeneraciones; i++)
   {
      cout<<"\n Ingrese la posicion del elemento a insertar \n";
				cin>>posIns;
            if ((posIns>=1)&&(posIns<=(i+1)))
            {
            	situarPos(posIns);
               cout<<"\n\n\t Generacion " << (i+1) << endl;
               ptrGeneracion = new cGeneracion;
      			ptrGeneracion -> agregarIntegrantes();
      			agregar(ptrGeneracion);
            }
            else
            {
            	cout<<"La posicion ingresada es incorrecta \n";
               i=i-1;
            }
   }
}

void cArbolGenealogico::buscarIntegrante()
{
	cIntegrante* ptrInte=new cIntegrante;
   cGeneracion* ptrGene1=new cGeneracion;
   cout << " Ingrese el id del integrante que se va a buscar y mostrar: ";
   cin >>ident;
   for(int i=0; i < cantGeneraciones; i++)
   {
   	ptrGene1 = (cGeneracion*)retornar();
      if(ptrGene1 != NULL)
      {
      	ptrInte = ptrGene1 -> buscarIntegrante();
         if(ptrInte != NULL)
         	ptrGene1 -> mostrarGeneraciones();
      }
   }
}

void cArbolGenealogico::cambiar()
{
   cIntegrante* ptrInte;
   cGeneracion* ptrGene1;
   cGeneracion* ptrGene2;
   cout<<"\n Ingrese el identificador de la generacion de origen de donde se va a cambiar al integrante: ";
   cin>>origen;
   ptrGene1=(cGeneracion*)buscarGeneracion(condicOrig);
   cout<<"\n Ingrese el identificador de la generacion de destino a donde se va a cambiar al integrante: ";
   cin>>destino;
   ptrGene2=(cGeneracion*)buscarGeneracion(condicDes);
   if((ptrGene1!=NULL)&&(ptrGene2!=NULL))
   {
   	cout<<"\n Ingrese el identificador del integrante que se va a cambiar de generacion: ";
      cin>>ident;
      ptrInte=ptrGene1->buscarIntegrante();
      if(ptrInte!=NULL)
      {
      	ptrInte=ptrGene1->eliminarUnInte();
         ptrGene2->agregarUnInte(ptrInte);
      }
      else
         cout<<"\n No se encontro al integrante con ese identificador\n ";
   }
   else
      cout<<"\n No se encontro una de las generaciones para realizar el intercambio\n ";
}


void cArbolGenealogico::verGeneraciones()
{
	cout<<"\n LA LISTA DE GENERACIONES DEL ARBOL GENEALOGICO SON: " << endl;
   foreach(mostrar2);
}

void cArbolGenealogico::VersoloGeneraciones()
{
	cout<<"\n LA LISTA DE GENERACIONES DEL ARBOL GENEALOGICO SON: " << endl;
   cg=cg+cantGeneraciones;
   cout<<" La cantidad de generacion son: "<<cg<<"\n";
   foreach(mostrar3);
}

cArbolGenealogico::menu()
{
   int op,c,f;
   clrscr();
   cout<<"  QUE DESEA HACER? ";
   cout<<" ARBOL GENEALOGICO\n";
   cout<<" 1. AGREGAR GENERACIONES \n";
   cout<<" 2. MOSTRAR LAS GENERACIONES \n";
   cout<<" 3. CAMBIAR DE GENERACION A UN INTEGRANTE \n";
   cout<<" 4. CANTIDAD DE GENERACIONES EXISTENTES\n";
   cout<<"ESCOJA UNA OPCION: ";
   do
   {
     cin>>op;
   }while(op>4);
   return op;
}


void cArbolGenealogico::casos()
{
	char deseo;
   do
   {
      int op=menu();
      clrscr();
           switch (op)
      {
      	case 1:
         	    {
                   agregarGeneracion();
                   break;
                }
         case 2:
                {
                   VersoloGeneraciones();
                   break;
                }
         case 3:
                {
                   cambiar();
                   break;
                }
         case 4:
                {
                   verGeneraciones();
                   break;
                }
      }
      cout<<"\n\t\t Desea hacer algo mas (s/n):  ";
      cin>>deseo;
   }
   while (deseo!='n');
}

main()
{
   clrscr();
   cArbolGenealogico oArbolGenealogico;
   oArbolGenealogico.casos();
}



