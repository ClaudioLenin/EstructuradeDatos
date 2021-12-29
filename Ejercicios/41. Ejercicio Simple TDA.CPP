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
   x->precio=0;
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
   cin>>x->titulo;
	//cin.getline(x->titulo,50);
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
	cout<<"\n Titulo: \t"<<x->titulo;
	cout<<"\n Autor: \t"<<x->autor;
	cout<<"\n Editorial: \t"<<x->editorial;
	cout<<"\n Precio: \t"<<x->precio<<"\n\n";
}

int main(){
	libro lbr=crear_libro();
   leer_libro(lbr);
	cout<<"\n____________________________\n";
	cout<<"\nDATOS DEL LIBRO INGRESADO POR EL USUARIO\n";
	cout<<"\n____________________________\n";
	imprimir_libro(lbr);
	system("pause");
}