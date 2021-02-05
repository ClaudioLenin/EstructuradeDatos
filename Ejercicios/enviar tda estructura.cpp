
/*Elaborar un programa utilizando TDA que simule una farmacia que adquiere productos con los siguientes datos:

- Código

- Nombre

- Costo unitario

- Cantidad en stock

- Proveedor

Se requiere que el programa-

- Lea el listado de productos adquiridos

   Grupo 1: Ordene ascendentemente por costo unitario

   Grupo 2: Ordene ascendentemente por proveedor

- Muestre los productos ordenados*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct farmacia { //de farmacia
   int codigo;
	char* nombre;
	char* provee;
	int cu; //costo unitario
	int cs;//cantidad en stock
}; //de struct farmacia

typedef farmacia* farm;    //definir tipo

farm crear_farm()
{//crear farmacia
	farm x=new farmacia;
   x->codigo;
	x->nombre=new char[50];
	x->provee=new char[50];
	x->cu;
   x->cs;
   return (x); //retorno todo el objeto
}//crear farmacia

void liberar_farm (farm x)
{//de liberar
	delete[] x->nombre;
	delete[] x->provee;
	delete[] x; //borar todo el objeto
}//de liberar

farm leer_farm (farm x)
{//de leer farmacia
	cout<<"Ingrese el codigo ";
   cin>>x->codigo;
	while (x->codigo<0){
		cout<<"codigo no valido";
		cin>>x->codigo;
	}//de leer farmacia

   cout<<"Ingrese el nombre ";
	cin.getline(x->nombre,50);
	while (strlen(x->nombre)==0)
   {//de while
		cin.getline(x->nombre,50);
	}//de while


	cout<<"Ingrese el proveedor ";
	cin.getline(x->provee,50);
	while (strlen(x->provee)==0)
   {//de while
		cin.getline(x->provee,50);
	}//de while

	cout<<"ingrese la cantidad: ";
	cin>>x->cs;
	while (x->cs<0)
   {//de while
		cout<<"No valido";
		cin>>x->cs;
	}//de whilw
   cout<<"ingrese el costo unitario: ";
	cin>>x->cu;
	while (x->cu<0)
   {//de while
		cout<<"No valido";
		cin>>x->cu;
	}//de while

	return x;
}//de leer farmacia

void imprimir_farm (farm x) {
	cout<<"\n Informacion de productos\n";
	cout<<"codigo: \t"<<x->codigo;
	cout<<"\n nombre: \t\t"<<x->nombre;
	cout<<"\n proveedor \t"<<x->provee;
	cout<<"\n Precio: \t"<<x->cu;
   cout<<"\n Cantidad stock: \t"<<x->cs;
}

farm* leer_conjunto_prod(farm* c, int n) {
	for (int i=0;i<n;i++) {
		cout<<"\n\n producto ["<<(i+1)<<"]:\n\n";
		farm a=crear_farm();
		a=leer_farm(a);
		c[i]=a;
	};
	return c;
}

void imprimir_conjunto_prod(farm* c, int n) {
	cout<<"codigo \tnombre \tprecio unit \tcant stock \tproveedor\n";
	for (int i=0;i<n;i++) {
		cout<<c[i]->codigo<<"\t"<<"\t"<<c[i]->nombre<<"\t";
		cout<<c[i]->cu<<"\t\t"<<c[i]->cs<<"\t\t"<<c[i]->provee<<"\n";
	};
}

farm* ordenar_prod (farm* c, int n)
{//de ordenar producros
	farm aux;    //auxiliar para farmacia
	for (int i=0;i<n;i++)
   {//de for i
		for (int j=i+1;j<n;j++)
      {//de for j
			if (c[j]->provee < c[i]->provee)
          {//de if
					aux=c[i];
					c[i]=c[j];
					c[j]=aux;
			}//de if
		} //de for j
	}//de for i
	return c;
}//de ordenar productos

int main()//programa principal
{//de main
   cout<<"\t\tPROGRAMA FARMACIA\n\n" ;
	int n=0;
	cout<<"Ingrese la cantidad de productos \n";
	cin>>n; //numero de productos
	farm* conjunto=new farm[n];  //crear conjunto de prod
   conjunto=leer_conjunto_prod(conjunto,n);
	cout<<"\nPRODUCTOS INGRESADOS \n";
	imprimir_conjunto_prod(conjunto,n);
   conjunto=ordenar_prod(conjunto,n);
	cout<<"\nPRODUCTOS ORDENADOS PROVEEDOR\n";
	imprimir_conjunto_prod(conjunto,n);
   getch();
}//de main