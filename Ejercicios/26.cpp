#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct E_libro {
	char* titulo;
	char* autor;
	char* editorial;
	int precio;
};

typedef E_libro* libro;

libro crear_libro(){
	libro x=new E_libro;
	x->titulo=new char[50];
	x->autor=new char[50];
	x->editorial=new char[50];
   return (x);
}

void liberar_libro (libro x){
	delete[] x->titulo;
	delete[] x->autor;
	delete[] x->editorial;
	delete[] x;
}

libro leer_libro (libro x){
	cout<<"Digite el titulo del libro: ";
	cin.getline(x->titulo,50);
	while (strlen(x->titulo)==0){
		cin.getline(x->titulo,50);
	}
	cout<<"Digite el autor del libro: ";
	cin.getline(x->autor,50);
	while (strlen(x->autor)==0){
		cin.getline(x->autor,50);
	}
	cout<<"Digite el editorial del libro: ";
	cin.getline(x->editorial,50);
	while (strlen(x->editorial)==0){
		cin.getline(x->editorial,50);
	}
	cout<<"Digite el precio del libro: ";
	cin>>x->precio;
	while (x->precio<0){
		cout<<"No v?lido, digite el precio del libro";
		cin>>x->precio;
	}
	return x;
}

void imprimir_libro (libro x) {
	cout<<"\n Informacion del libro\n";
	cout<<"-------------------------\n";
	cout<<"T?tulo: \t"<<x->titulo;
	cout<<"\n Autor: \t\t"<<x->autor;
	cout<<"\n Editorial: \t"<<x->editorial;
	cout<<"\n Precio: \t"<<x->precio<<"\n\n";
}

libro* leer_conjunto_libros(libro* c, int n) {
	for (int i=0;i<n;i++) {
		cout<<"\n\n Libro "<<(i+1)<<":\n\n";
		libro a=crear_libro();
		a=leer_libro(a);
		c[i]=a;
	};
	return c;
}

void imprimir_conjunto_libros(libro* c, int n) {
	cout<<"TITULO \t\t AUTOR \t\tEDITORIAL \t\tPRECIO \n";
	for (int i=0;i<n;i++) {
		cout<<c[i]->titulo<<"\t\t"<<c[i]->autor<<"\t\t";
		cout<<c[i]->editorial<<"\t\t\t"<<c[i]->precio<<"\n";
	};
}

libro* ordenar_por_precio (libro* c, int n) {
	libro aux;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++) {
			if (c[j]->precio < c[i]->precio) {
					aux=c[i];
					c[i]=c[j];
					c[j]=aux;
			}
		}
	}
	return c;
}

int main(){
	int n=0;
	cout<<"Cuantos libros desea ingresar? \n";
	cin>>n;
	libro* conjunto=new libro[n];

	conjunto=leer_conjunto_libros(conjunto,n);
	cout<<"\n____________________________\n";
	cout<<"\nLIBROS INGRESADOS POR EL USUARIO\n";
	cout<<"\n____________________________\n";
	imprimir_conjunto_libros(conjunto,n);

	conjunto=ordenar_por_precio(conjunto,n);
	cout<<"\n____________________________\n";
	cout<<"\nLIBROS ORDENADOS POR PRECIO\n";
	cout<<"\n____________________________\n";
	imprimir_conjunto_libros(conjunto,n);

	system("pause");
}
