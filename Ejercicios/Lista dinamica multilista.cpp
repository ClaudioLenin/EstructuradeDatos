#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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
   void forEach(void(*mostrar)(void*));
   void* buscarJaula(int(*condiCurso)(void*));
	void* retornar();
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

void cListaDinMult::agregar(void* info)
{
	cNodo* newNodo = new cNodo;
   newNodo -> setInfo(info);
   if(empty() == 1)
   {
   	first = newNodo;
      pos1 = first;
      first -> setSig(NULL);
      first -> setAnt(NULL);
      last = first;
   }
   else
   {
   	last -> setSig(newNodo);
      newNodo -> setSig(NULL);
      newNodo -> setAnt(last);
      last = newNodo;
   }
	count++;
   pos = first;
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
      	cout << " NO se esta apuntando a ningun nodo \n";
   }
   else
   	cout << " La lista esta vacia \n";
	return (datElim);
}

void* cListaDinMult::retornar()
{
	void* dato = NULL;
   dato = pos1 -> getInfo();
   pos1 = pos1 -> getSig();
   return(dato);
}

void* cListaDinMult::buscarJaula(int(*condiJaula)(void*))    //firstThan
{
	void* info = NULL;
   pos = first;
   if(empty() == 0)
   {
   	while((info == NULL) && (pos != NULL))
      {
      	if(condiJaula(pos -> getInfo()) == 1)
         	info = pos -> getInfo();
         else
         	pos = pos -> getSig();
      }
   }
   return(info);
}

void cListaDinMult::forEach(void(*mostrar)(void*))
{
	pos = first;
   while(pos != NULL)
   {
   	mostrar(pos -> getInfo());
      pos = pos -> getSig();
   }
}

class cIdentificacion
{
   protected:
		char id[20];
	   char nombre[20];
   public:
   	cIdentificacion();
   	void setId(char* newId);
		char* getId();
      void setNombre(char* newNom);
      char* getNombre();
};

cIdentificacion::cIdentificacion()
{
	strcpy(id, " ");
   strcpy(nombre, " ");
}

void cIdentificacion::setId(char* newId)
{
	strcpy(id, newId);
}

char* cIdentificacion::getId()
{
	return (id);
}

void cIdentificacion::setNombre(char* newNom)
{
	strcpy(nombre, newNom);
}

char* cIdentificacion::getNombre()
{
	return(nombre);
}

class cAnimal : public cIdentificacion
{
	char raza[20];

   public:
   	cAnimal();
      void setRaza(char* newRaza);
      char* getRaza();
      void leer();
      void mostrar();
};

cAnimal::cAnimal()
{
   strcpy(raza, " ");
}

void cAnimal::setRaza(char* newRaza)
{
	strcpy(raza, newRaza);
}

char* cAnimal::getRaza()
{
	return raza;
}

void cAnimal::leer()
{
	char cad[20];
   cout << " Ingrese el nombre del animal: ";
   cin >> cad;
   setNombre(cad);
   cout << " Ingrese la ID del animal: ";
   cin >> cad;
   setId(cad);
   cout << " Ingrese la raza del animal: ";
   cin >> cad;
   setRaza(cad);
}

void cAnimal::mostrar()
{
	cout << endl << "  " << getNombre() << endl;
   cout << "  " << getId() << endl;
   cout << "  " << getRaza() << endl;
}

void mostrarAnim(void* info) //para el forEach
{
	cAnimal* ptr = (cAnimal*) info;
   ptr -> mostrar();
}

char id[50]; //para buscar la id

int condicion(void* info) //para el firstThan
{
	int flag = 0;
   cAnimal* ptr = (cAnimal*) info;
   if(strcmp(ptr -> getId(), id) == 0) //comparar char
   	flag = 1;
   return (flag);
}

class cJaula : public cListaDinMult, public cIdentificacion
{
	char ubicacion[20];
   char responsable[20];
   int cantAnimales;
   cAnimal* ptrAnim;
	public:
   	cJaula();
   	void setUbicacion(char* newUbc);
      char* getUbicacion();
      void setResponsable(char* newResp);
      char* getResponsable();
      void leerJaula();
      void mostrarAnimales();
      void agregarAnimales();
      void agregarUnAnimal(cAnimal* ptrAnim);
      cAnimal* eliminarUnAnimal();
      cAnimal* buscarAnimal();
      void mostrarJaulas();
};

cJaula::cJaula()
{
	strcpy(ubicacion, " ");
   strcpy(responsable, " ");
   cantAnimales = 0;
   ptrAnim = NULL;
}

void cJaula::setUbicacion(char* newUbc)
{
	strcpy(ubicacion, newUbc);
}

char* cJaula::getUbicacion()
{
	return ubicacion;
}

void cJaula::setResponsable(char* newResp)
{
	strcpy(responsable, newResp);
}

char* cJaula::getResponsable()
{
	return responsable;
}

void cJaula::leerJaula()
{
	char cad[20];
   cout << " Ingrese el nombre de la jaula: ";
   cin >> cad;
   setNombre(cad);
   cout << " Ingrese la ID de la jaula: ";
   cin >> cad;
   setId(cad);
   cout << " Ingrese la ubicacion de la jaula: ";
   cin >> cad;
   setUbicacion(cad);
   cout << " Ingrese el responsable de la jaula: ";
   cin >> cad;
   setResponsable(cad);
}

void cJaula::mostrarJaulas()
{
	cout << " El nombre de la jaula es: " << getNombre() << endl;
   cout << " La ID de la jaula es: " << getId() << endl;
	cout << " Su ubicacion es: " << getUbicacion() << endl;
   cout << " El responsable es: " << getResponsable() << endl;
}

void cJaula::agregarAnimales()
{
	leerJaula();
   cout << " Ingrese la cantidad de animales: ";
   cin >> cantAnimales;
   for(int i=0; i < cantAnimales; i++)
   {
   	cout << "\n Animal " << (i+1) << endl;
   	ptrAnim = new cAnimal;
      ptrAnim -> leer();
      agregar(ptrAnim);
   }
}

void cJaula::mostrarAnimales()
{
	cout << endl;
   cout << " Los datos de la jaula son: " << endl;
   mostrarJaulas();
   cout << "\n Tiene los siguientes animales: " << endl;
   forEach(mostrarAnim);
}

void cJaula::agregarUnAnimal(cAnimal* ptrAnim)
{
	agregar(ptrAnim);
}

cAnimal* cJaula::eliminarUnAnimal()
{
	cAnimal* ptr = (cAnimal*) eliminar();
   return(ptr);
}

cAnimal* cJaula::buscarAnimal()
{
	cAnimal* ptr = (cAnimal*) buscarJaula(condicion);
   return(ptr);
}

void mostrar2 (void* info)
{
	cJaula* ptrc = (cJaula*)info;
   ptrc -> mostrarAnimales();
   cout << endl;
}

char origen[20];

int condicOrig(void* info)
{
	int flag = 0;
   cJaula* ptr;
   ptr = (cJaula*)info;
   if(strcmp(ptr -> getId(), origen) == 0)
   	flag = 1;
   return (flag);
}

char destino[20];

int condicDes(void* info)
{
   int flag = 0;
	cJaula* ptr;
   ptr = (cJaula*)info;
   if(strcmp(ptr -> getId(), destino) == 0)
   	flag = 1;
   return (flag);
}

class cZoologico : public cListaDinMult
{
	int cantJaulas;
   cJaula* ptrJaula;
   public:
   	void agregarJaula();
      void cambiar();
      void buscarAnimal();
      void eliminar();
      void mostrarJaulas();
      int menu();
      void casos();
};



void cZoologico::agregarJaula()
{
	cout << " Ingrese la cantidad de jaulas que tiene el Zoologico: ";
   cin >> cantJaulas;
   for(int i=0; i < cantJaulas; i++)
   {
   	
   	cout << "\n\n\t Jaula " << (i+1) << endl;
   	ptrJaula = new cJaula;
      ptrJaula -> agregarAnimales();
      agregar(ptrJaula);
   }
}

void cZoologico::buscarAnimal()
{
	cAnimal* ptrAnim;
   cJaula* ptrJaula1;
   cout << " Ingrese la ID del animal que se va a buscar y mostrar: ";
   cin >> id;
   for(int i=0; i < cantJaulas; i++)
   {
   	ptrJaula1 = (cJaula*)retornar();
      if(ptrJaula1 != NULL)
      {
      	ptrAnim = ptrJaula1 -> buscarAnimal();
         if(ptrAnim != NULL)
         	ptrJaula1 -> mostrarJaulas();
      }
   }
}

void cZoologico::cambiar()
{
	cAnimal* ptrAnim;
   cJaula* ptrJaula1;
   cJaula* ptrJaula2;
   cout << " Ingrese el ID de la jaula de origen de donde se va a cambiar al animal: ";
   cin >> origen;
   ptrJaula1 = (cJaula*) buscarJaula(condicOrig);
   cout << " Ingrese el ID de la jaula de destino a donde se va a cambiar al animal: ";
   cin >> destino;
   ptrJaula2 = (cJaula*) buscarJaula(condicDes);
   if((ptrJaula1 != NULL) && (ptrJaula2 != NULL))
   {
   	cout << " Ingrese el ID del animal que se va a intercambiar: ";
      cin >> id;
      ptrAnim = ptrJaula1 -> buscarAnimal();
      if(ptrAnim != NULL)
      {
      	ptrAnim = ptrJaula1 -> eliminarUnAnimal();
         ptrJaula2 -> agregarUnAnimal(ptrAnim);
      }
      else
      	cout << " No se encontro al animal con ese id! \n";
   }
   else
   	cout << " No se encontro uno de las jaulas para realizar el intercambio! \n";
}

void cZoologico::mostrarJaulas()
{
	cout << " La lista de jaulas que tiene el zoologico es: " << endl;
   forEach(mostrar2);
}

cZoologico::menu()
{
  	int op;
   cout << "\n\n\t\t\t MENU \n";
   cout << "\t 1. Agregar Jaulas \n";
   cout << "\t 2. Cambiar de jaula a un animal \n";
   cout << "\t 3. Buscar un animal y mostrar en la jaula en la que se encuentra \n";
   cout << "\t 4. Mostrar las jaulas y animales \n";
   do
   {
		cout << "\n\t Escoja una opcion: ";
      cin >> op;
   }while(op > 4);
   return op;
}

void cZoologico::casos()
{
   char deseo;
   do
   {

      int op = menu();
      switch(op)
      {
      	case 1:

         	cout << "\n\n\t AGREGAR JAULAS \n";
            agregarJaula();
            break;
         case 2:

         	cout << "\n\n\t CAMBIAR DE JAULA A UN ANIMAL \n";
            cambiar();
            break;
         case 3:
                    	cout << "\n\n\t BUSCAR Y MOSTRAR UN ANIMAL \n";
            buscarAnimal();
            break;
         case 4:

            cout << "\n\n\t MOSTRAR JAULAS Y ANIMALES \n";
            mostrarJaulas();
            break;
      }
      cout << "Desea hacer algo mas? (s/n) \n";
      cin >> deseo;
   }while(deseo != 'n');
   clrscr();

}



void main()
{
		cZoologico oZoologico;
   oZoologico.casos();
}
