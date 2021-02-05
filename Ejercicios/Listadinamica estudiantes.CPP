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
   void mostrarDatEst_pares(cListaDin oListaDin);
   void reubicarDatEst(cListaDin oListaDin,int p1,int p2);
   void ordenarDatEst(cListaDin oListaDin);
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
   	cout <<"\nLos estudiantes registrados son: \n";
      	for(int i=1;i<=oListaDin.getCount();i++){
            cout<<"\nESTUDIANTE "<<i<<"\n";
         	prtEst = (cEst*)oListaDin.getInfNod(i);
         	prtEst ->verDatEst();
         }
   }

}
void cEst::mostrarDatEst_pares(cListaDin oListaDin){
 	cEst* prtEst = new cEst;
   if(!(oListaDin.empty())){
   	cout <<"\nLos estudiantes registrados son: \n";
      	for(int i=1;i<=oListaDin.getCount();i++)
           if(i%2==0){
               cout<<"\nESTUDIANTE "<<i<<"\n";
         	   prtEst = (cEst*)oListaDin.getInfNod(i);
         	   prtEst ->verDatEst();
            }
   }

}

void cEst::reubicarDatEst(cListaDin oListaDin,int p1,int p2){
 	cEst* aux = new cEst;
   cEst* aux2 = new cEst;
   cEst* ptrEst = new cEst;
   if(!(oListaDin.empty())){
      	for(int i=1;i<=oListaDin.getCount();i++)
           if(i==p1){
         	   aux = (cEst*)oListaDin.getInfNod(i);
               }
            else{
               if(i==p2)
                   aux2 = (cEst*)oListaDin.getInfNod(i);
               }

               oListaDin.situarPos(p1);
               ptrEst = new cEst;
            	ptrEst=(cEst*)oListaDin.eliminar();
               oListaDin.situarPos(p1);
               oListaDin.agregar(aux2);

               oListaDin.situarPos(p2);
               ptrEst = new cEst;
            	ptrEst=(cEst*)oListaDin.eliminar();
               oListaDin.situarPos(p2);
               oListaDin.agregar(aux);

   }

}

void cEst::ordenarDatEst(cListaDin oListaDin){
   cEst* aux = new cEst;
   cEst* aux2 = new cEst;
   cEst* ptrEst = new cEst;
   cEst* prtEst1 = new cEst;
   cEst* prtEst2 = new cEst;
   int n1,n2;
   for(int i=1;i<=oListaDin.getCount()-1;i++)
       for(int j=i+1;j<=oListaDin.getCount();j++){
               prtEst1 = (cEst*)oListaDin.getInfNod(i);
         	   n1 = prtEst1 ->getCodigo();
               prtEst2 = (cEst*)oListaDin.getInfNod(j);
         	   n2 = prtEst2 ->getCodigo();
               if(n1>=n2){
                       aux = (cEst*)oListaDin.getInfNod(i);

                       oListaDin.situarPos(i);
                       ptrEst = new cEst;
                       ptrEst=(cEst*)oListaDin.eliminar();
                       oListaDin.situarPos(i);
                       oListaDin.agregar(prtEst2);

                       oListaDin.situarPos(j);
                       ptrEst = new cEst;
                       ptrEst=(cEst*)oListaDin.eliminar();
                       oListaDin.situarPos(j);
                       oListaDin.agregar(aux);

            }
       }
}

int menu()
{
	int op;
   cout<<"\n\t\t\tMENU ESTUDIANTES \n";
 	cout<<"1. Agregar  \n";
	cout<<"2. Eliminar\n";
   cout<<"3. Mostrar todos\n";
   cout<<"4. Mostrar en posiciones pares\n";
   cout<<"5. Intercambiar\n";
   cout<<"6. Ordenar\n";
   do
   {
   	cout<<"\nEscoja una opcion: \t";
      cin>>op;
   }
   while((op<1)||(op>6));
   return op;
}

void casos()
{
	int posIns, posElm;
   int ip1,ip2;
   cEst* ptrEst;
   char* pDat;
   char deseo;
   cListaDin oListaDin;
   cout<<"\t\t\tLISTA DINAMICA CON PUNTEROS A VOID,\n";
   do
   {
      clrscr();
   	int op=menu();
      switch (op)
      {
      	case 1:
         	cout<<"\t\t\tAGREGAR ESTUDIANTE \n";
            cout<<"\nInserte la posicion del elemento \n";
            cin>>posIns;
				if((posIns>=1) && (posIns<=(oListaDin.getCount()+1)))
            {

            	oListaDin.situarPos(posIns);
               cout<<"\nIngrese datos del estudiante:";
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
         	cout<<"\t\t\tELIMINAR ESTUDIANTE \n";
            if (!(oListaDin.empty()))
            {
               cout <<"\nIngrese la posicion del elemento a eliminar \n";
               cin >> posElm;
            	if((posElm>=1)&&(posElm<=oListaDin.getCount()))
               {
               	oListaDin.situarPos(posElm);
                  	ptrEst = new cEst;
            			ptrEst=(cEst*)oListaDin.eliminar();
               		cout<<"\nLos datos del estudiante que se han eliminado son: \n";
               		ptrEst ->verDatEst();
               }
               else
               {
               	cout<<"\nLa posicion ingresada es incorrecta \n";
               }
            }
            else
            {
            	cout<<"\nNo existen elementos para eliminar........ \n";
            }
            break;
         case 3:
         	cout<<"\t\t\tMOSTRAR ELEMENTOS \n";
            if (!(oListaDin.empty()))
            	ptrEst->mostrarDatEst(oListaDin);
            else
            	cout<<"\nNo existen estudiantes... \n";
            break;
         case 4:
            cout<<"\t\t\tMOSTRAR ELEMENTOS PARES \n";
            if (!(oListaDin.empty()))
            	ptrEst->mostrarDatEst_pares(oListaDin);
            else
            	cout<<"\nNo existen estudiantes... \n";
            break;
         case 5:
            cout<<"\t\tINTERCAMBIAR ESTUDIANTES\n";
            if (!(oListaDin.empty())){
                 do{
                      cout <<"\nIngrese la primera posicion para intercambiar: ";
                      cin >> ip1;
                    }while((ip1<=0)||(ip1>oListaDin.getCount()));
                 do{
                      cout <<"\nIngrese la segunda posicion para intercambiar: ";
                      cin >> ip2;
                    }while((ip2<=0)||(ip2>oListaDin.getCount()));
                 ptrEst->reubicarDatEst(oListaDin,ip1,ip2);
               }
            else{
            	cout<<"\nNo existen estudiantes........... \n";
               }
            break;
         case 6:
             cout<<"\t\t\tORDENAMIENTO ASCENDENTE\n";
            if (!(oListaDin.empty())){
               ptrEst->ordenarDatEst(oListaDin);
            	ptrEst->mostrarDatEst(oListaDin);
               }
            else{
            	cout<<"\nNo existen estudiantes........... \n";
               }
            break;

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
   clrscr();
   getch();
}