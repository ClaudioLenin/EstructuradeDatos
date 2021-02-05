/*
1) Elaborar un programa utilizando TDA que simule una farmacia que adquiere productos con los siguientes datos:

- Código

- Nombre

- Costo unitario

- Cantidad en stock

- Proveedor

Se requiere que el programa-

- Lea el listado de productos adquiridos

   Grupo 1: Ordene ascendentemente por costo unitario

*/
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
struct farmacia{
     char *codigo;
     char *nombre;
     char *proveedor;
     int c_unitario;
     int c_stock;
};

typedef farmacia *farm;

farm crear_farmacia(){
	farm f=new farmacia;   
	f->codigo=new char[10];
	f->nombre=new char[30];
	f->proveedor=new char[30];
   return (f);
}
void liberar_farmacia(farm f){
	delete[] f->nombre;
	delete[] f->codigo;
	delete[] f->proveedor;
	delete[] f;
}

farm leer_farmacia (farm f){
	cout<<"\nIngrese el nombre del produco: ";
	cin.getline(f->nombre,30);

	while (strlen(f->nombre)==0){
		cin.getline(f->nombre,30);
	}

   cout<<"\nIngrese el codigo del producto: ";
	cin.getline(f->codigo,10);
	while (strlen(f->codigo)==0){
		cin.getline(f->codigo,10);
	}

   cout<<"\nIngrese el proveedor del producto: ";
	cin.getline(f->proveedor,30);
	while (strlen(f->proveedor)==0){
		cin.getline(f->proveedor,30);
	}

   do{
       cout<<"\nIngrese costo unitario del producto: ";
       cin>>f->c_unitario;
   }while(f->c_unitario<=0);
   do{
       cout<<"\nIngrese stock de producto: ";
       cin>>f->c_stock;
   }while(f->c_stock<=0);
   clrscr();
   return(f);
}

farm* leer_conjunto_de_productos(farm* f, int cant) {
	for (int i=0;i<cant;i++) {
		cout<<"\n\n PRODUCTO "<<(i+1)<<endl;
      cout<<"_______________________________\n";
		farm v=crear_farmacia();
		v=leer_farmacia(v);
		f[i]=v;
	};
	return f;
}

void imprimir_conjunto_de_productos(farm *f,int cant){
  cout<<"PRODUCTO\tCODIGO\t\tPROVEEDOR\tP. UNITARIO\t\tSTOCK\n";
  for(int i=0;i<cant;i++){
      cout<<f[i]->nombre<<"\t\t"<<f[i]->codigo<<"\t\t"<<f[i]->proveedor<<"\t\t"<<f[i]->c_unitario<<"\t\t\t"<<f[i]->c_stock<<endl;
  }
}



farm *ordenar_por_precio_unitario(farm *f,int cant){

   farm aux;
   for(int i=0;i<cant;i++)
      for(int j=i+1;j<cant;j++)
      if (f[j]->c_unitario < f[i]->c_unitario) {
					aux=f[i];
					f[i]=f[j];
					f[j]=aux;
			}
	return f;
}


void main(){
   int num;
   do{
	      cout<<"Ingrese cantidad de productos: ";
	      cin>>num;
      }while(num<=0);

	farm* cf=new farm[num];

	cf=leer_conjunto_de_productos(cf,num);
   cf=ordenar_por_precio_unitario(cf,num);
   clrscr();
	cout<<"\n_________________________________________\n";
	cout<<"\nPRODUCTOS ORDENADOS POR PRECIO UNITARIO\n";
	cout<<"\n_________________________________________\n";
   imprimir_conjunto_de_productos(cf,num);

    getch();


}











