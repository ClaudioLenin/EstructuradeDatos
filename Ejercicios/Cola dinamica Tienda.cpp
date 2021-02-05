#include<iostream.h>
#include<string.h>
#include<conio.h>

class cTienda
{
   void* info;
   cTienda* sig;

   public:
   cTienda();
   void setInfo(void* newInfo);
   void* getInfo();
   void setSig(cTienda* newSig);
   cTienda* getSig();
};

cTienda::cTienda()
{
   info=NULL;
   sig=NULL;
}

void cTienda::setInfo(void* newInfo)
{
	info=newInfo;
}

void* cTienda::getInfo()
{
	return(info);
}

void cTienda::setSig(cTienda* newSig)
{
	sig=newSig;
}

cTienda* cTienda::getSig()
{
	return(sig);
}

class cColaDin
{
   int count;
   cTienda* first;
   cTienda* last;

   public:
   cColaDin();
   void setCount(int newCount);
   int getCount();
   int empty();
   void agregar(void* info);
   void* eliminar();
   void *getInfNod(int a);
};

cColaDin::cColaDin()
{
   count=0;
   first=NULL;
   last=NULL;
}

void cColaDin::setCount(int newCount)
{
	count=newCount;
}

int cColaDin::getCount()
{
	return(count);
}

int cColaDin::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cColaDin::agregar(void* info)
{
	cTienda* newTienda=new cTienda;
   newTienda->setInfo(info);
   if (!(empty()))
   {
   	last->setSig(newTienda);
      last=last->getSig();
   }
   else
   {
   	first=newTienda;
      last=newTienda;
   }
   setCount(getCount()+1);
}

void* cColaDin::eliminar()
{
	void* datElim;
   cTienda* aux;
   if (!(empty()))
   {
   	datElim=first->getInfo();
      if (first==last)
      {
      	delete(first);
         last=NULL;
      }
   	else
   	{
   		aux=first;
         first=first->getSig();
     		aux->setSig(NULL);
      	delete(aux);
   	}
   	setCount(getCount()-1);
	}
   return (datElim);
}

void *cColaDin::getInfNod(int a){
     cTienda* aux;
     if(!(empty()))
     {
         aux=first;
         for(int i=1;i<a;i++)
             aux=aux->getSig();
     }
     return(aux->getInfo());
}


class cClientes{
     char nombre[10];
     char apellido[10];
     int codigo;
     public:
     cClientes();
     void setNombre(char *newNomb);
     char *getNombre();
     void setApellido(char *newApellido);
     char *getApellido();
     void setCodigo(int newCodigo);
     int getCodigo();
     void leerDatClientes();
     void verDatClientes();
     void mostrarDatClientes(cColaDin oColaDin);
};
cClientes::cClientes(){
    strcpy(nombre," ");
    strcpy(apellido," ");
    codigo=0;
}
void cClientes::setNombre(char *newNomb){
    strcpy(nombre,newNomb);
}
char *cClientes::getNombre(){
    return(nombre);
}
void cClientes::setApellido(char *newApellido){
    strcpy(apellido,newApellido);
}
char *cClientes::getApellido(){
    return(apellido);
}
void cClientes::setCodigo(int newCodigo){
    codigo=newCodigo;
}
int cClientes::getCodigo(){
    return(codigo);
}
void cClientes::leerDatClientes(){
    char nomb[10];
    char apell[10];
    int cod;

    cout<<"Ingrese el nombre del clientes de la tienda: ";
    cin>>nomb;
    setNombre(nomb);
    cout<<"Ingrese el apellido del cliente: ";
    cin>>apell;
    setApellido(apell);
    cout<<"Ingrese el codigo del cliente: ";
    cin>>cod;
    setCodigo(cod);
}
void cClientes::verDatClientes(){
    cout<<getNombre()<<"\n"<<getApellido()<<"\n"<<getCodigo()<<"\n";
}
void cClientes::mostrarDatClientes(cColaDin oColaDin){
    cClientes *prtClientes=new cClientes;
    if(!(oColaDin.empty())){
        cout<<"Los clientes registrados son\n";
        for(int i=1;i<=oColaDin.getCount();i++){
             prtClientes=(cClientes*)oColaDin.getInfNod(i);
             prtClientes->verDatClientes();
        }

    }
}


int menu()
{
	int op;
   cout<<"Que desea hacer? \n";
	cout<<"1. Agregar cliente \n";
	cout<<"2. Eliminar cliente \n";
   cout<<"3. Mostrar todos los clientes \n";
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
  cColaDin oColaDin;
  cClientes *ptrClientes;
   cout<<"COLA DINAMICA CON PUNTERO A VOID CLIENTES\n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"AGREGAR CLIENTE \n";
            cout<<"Ingrese el cliente a ser insertado \n";
            ptrClientes=new cClientes;
            ptrClientes->leerDatClientes();
            oColaDin.agregar(ptrClientes);
            break;
         case 2:
         	cout<<"ELIMINAR CLIENTE \n";
            if (!(oColaDin.empty()))
            {
            ptrClientes=new cClientes;
            ptrClientes=(cClientes*)oColaDin.eliminar();
            cout<<"Los datos del cliente que se han eliminado son \n";
            ptrClientes->verDatClientes();
             }
            else
            {
            	cout<<"No existen elementos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR TODOS LOS CLIENTES \n";
            if (!(oColaDin.empty()))
               ptrClientes->mostrarDatClientes(oColaDin);
            else
            	cout<<"No existen Clientes que mostrar \n";
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