#include<iostream.h>
#include<string.h>
#include<conio.h>

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
   void setCount(int nCount);
   int getCount();
   int empty();
   void situarPos(int iPos);
   void agregar(void* info);
   void* eliminar();
   void mostrar();
   void* getInfNod(int a);
};

cListaDin::cListaDin()
{
   count = 0;
   first = NULL;
   last = NULL;
   pos = NULL;
}

void cListaDin::setCount(int nCount)
{
	count = nCount;
}

int cListaDin::getCount()
{
	return(count);
}

int cListaDin::empty()
{
	if (getCount()==0)
	   return (1);
   else
   	return (0);
}

void cListaDin::situarPos(int iPos){
	int max = getCount();
   if((iPos>=1) && (iPos<=(max+1))){
   	if(!(empty())){
      	pos=first;
         for(int i=1; i<iPos;i++){
         	pos=pos->getSig();
         }
      }
   }
}

void cListaDin::agregar(void* info)
{
   cNodo* aux;
	cNodo* newNodo=new cNodo;
   newNodo->setInfo(info);
   if (!(empty())) {
   	if(pos==first){
      	newNodo->setSig(first);
         first=newNodo;
      }
   	else {
   		if(pos==NULL) {
         	last->setSig(newNodo);
            last=newNodo;
            pos=last;
         }
         else{
         	aux=first;
            while(aux->getSig()!=pos)
            	aux=aux->getSig();
            aux->setSig(newNodo);
            newNodo->setSig(pos);
   		}
      }
   }
   else {
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
   	if(pos==first){
       	aux = first;
       	datElim = aux -> getInfo();
       	first = first ->getSig();
       	delete (aux);
       }
       else{
       	if(pos ==last){
         	aux = first;
            while(aux->getSig()!=pos)
            	aux = aux->getSig();
            last = aux;
            datElim = pos->getInfo();
            last ->setSig(NULL);
            delete(pos);
         }
         else{
          	aux = first;
            while(aux ->getSig()!=pos)
            	aux = aux->getSig();
            datElim = pos->getInfo();
            aux ->setSig(pos->getSig());
            delete(pos);
         }
   	}
   	setCount(getCount()-1);
   	pos=first;
   }
   return(datElim);
}

void cListaDin::mostrar()
{
	cNodo* aux;
   if (!(empty()))
   {
   	aux=first;
      while (aux!=NULL)
      {
      	char* auxImp = new char;
         auxImp=(char*)aux->getInfo();
         cout<<*(auxImp)<<"\n";
         aux=aux->getSig();
      }
   }
}
void* cListaDin::getInfNod(int a){
	cNodo* aux;
   if(!(empty())){
		aux = first;
      	for(int i=1 ; i<a;i++){
        		aux = aux->getSig();
         }
   }
   return (aux->getInfo());
}
class cEst{
	char nombre[10];
   char apellido[10];
   int codigo;

   public:
   cEst();
   void setNombre(char* newNomb);
   char* getNombre();
   void setApellido(char* newApellido);
   char* getApellido();
   void setCodigo(int newCodigo);
   int getCodigo();
   void leerDatEst();
   void verDatEst();
   void mostrarDatEst(cListaDin oListaDin);
};

cEst::cEst(){
	strcpy(nombre, " ");
   strcpy(apellido, " ");
   codigo = 0;
}

void cEst::setNombre(char* newNombre){
	strcpy(nombre, newNombre);
}
char* cEst::getNombre(){
	return nombre;
}

void cEst::setApellido(char* newApellido){
	strcpy(apellido, newApellido);
}
char* cEst::getApellido(){
	return apellido;
}

void cEst::setCodigo(int newCodigo){
	codigo = newCodigo;
}

int cEst::getCodigo(){
	return codigo;
}

void cEst::leerDatEst(){
 	char nomb[10];
   char apell[10];
   int cod;
   cout<<"\nIngrese el nombre del estudiante: \n";
   cin >> nomb;
   setNombre(nomb);
   cout<<"\nIngrese el apellido del estudiante: \n";
   cin >> apell;
   setApellido(apell);
   cout<<"\nIngrese el codigo del estudiante: \n";
   cin >> cod;
   setCodigo(cod);
}

void cEst::verDatEst(){
	cout<<getNombre() <<"\n" << getApellido()<<"\n"<<getCodigo()<<"\n";
}

void cEst::mostrarDatEst(cListaDin oListaDin){
 	cEst* prtEst = new cEst;
   if(!(oListaDin.empty())){
   	cout <<"Los estudiantes registrados son: \n";
      	for(int i=1;i<=oListaDin.getCount();i++){
         	prtEst = (cEst*)oListaDin.getInfNod(i);
         	prtEst ->verDatEst();
         }
   }

}


int menu()
{
	int op;
   cout<<"\n  MENU ESTUDIANTE \n";
	cout<<"1. Agregar estudiante \n";
	cout<<"2. Eliminar estudiante\n";
   cout<<"3. Mostrar todos los estudiantes\n";
   do
   {
   	cout<<"Escoja una opcion: \t";
      cin>>op;
   }
   while(op>3);
   return op;
}

void casos()
{
	int posIns, posElm;
   cEst* ptrEst;
   char* pDat;
   char deseo;
   cListaDin oListaDin;
   cout<<"LISTA DINAMICA CON PUNTEROS A VOID\n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"AGREGAR ESTUDIANTE \n";
            cout<<"Inserte la posicion del elemento a insertar \n";
            cin>>posIns;
				if((posIns>=1) && (posIns<=(oListaDin.getCount()+1)))
            {

            	oListaDin.situarPos(posIns);
               cout<<"Ingrese datos del estudiante:\n";
               ptrEst = new cEst;
               ptrEst->leerDatEst();
               oListaDin.agregar(ptrEst);
            }
            else
            {
            	cout <<"\nLa posicion ingresada es incorrecta \n";
            }
            break;
         case 2:
         	cout<<"ELIMINAR ESTUDIANTE \n";
            if (!(oListaDin.empty()))
            {
               cout <<"Ingrese la posicion del elemento a eliminar \n";
               cin >> posElm;
            	if((posElm>=1)&&(posElm<=oListaDin.getCount()))
               {
               	oListaDin.situarPos(posElm);
                  	ptrEst = new cEst;
            			ptrEst=(cEst*)oListaDin.eliminar();
               		cout<<"El studiante que se ha eliminado es: \n";
               		ptrEst ->verDatEst();
               }
               else
               {
               	cout<<"\nLa posicion ingresada es incorrecta \n";
               }
            }
            else
            {
            	cout<<"No existen elementos para eliminar \n";
            }
            break;
         case 3:
         	cout<<"MOSTRAR ELEMENTOS \n";
            if (!(oListaDin.empty()))
            	ptrEst->mostrarDatEst(oListaDin);
            else
            	cout<<"No existen estudiantes \n";
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