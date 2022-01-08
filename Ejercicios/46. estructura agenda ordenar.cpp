#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <windows.h>



struct agenda {   //de struct agenda
	char* nombre;
	char* apellido;
	char* direccion;
	char* numero;
};//de struct agenda

typedef agenda* usuario; //crear numero tipo de dato agenda

usuario crear_usuario() //funcion crea el nuevo usuario
{//de crear nuevo usuario
	usuario x=new agenda; //asignacion a usuario de nueva agenda
	x->nombre= new char[50]; //mnombre
	x->apellido=new char[50]; //apellido
	x->direccion=new char[50];//direccion
   x->numero=new char[50]; //ingreso del numero apuntado a x
   return x; //todo el objeto retorna
}//de crear nuevo usuario

void liberar_usuario (usuario x)//funcion para librerar espacio usuario
{//de liberar usuario
	delete[] x->nombre; //eliminar todas las caracteristicas
	delete[] x->apellido;
	delete[] x->direccion;
   delete[] x->numero ;
	delete[] x; //eliminar los datos del objeto
}//de liberar usuario

usuario leer_usuario (usuario x)
{//de leer usuario
	cout<<"Ingrese el nombre del usuario: ";
	cin.getline(x->nombre,50);
	while (strlen(x->nombre)==0){ //inicio de while
		cin.getline(x->nombre,50);
	}//fin de while
	cout<<"Ingrese el apellido del usuario: ";
	cin.getline(x->apellido,50);
	while (strlen(x->apellido)==0){ //inicio de while
		cin.getline(x->apellido,50);
	} //fin de while
	cout<<"Ingrese la direccion del usuario: ";
	cin.getline(x->direccion,50);
	while (strlen(x->direccion)==0){//inicio de while
		cin.getline(x->direccion,50);
	}//fin de while
   cout<<"Ingrese el numero del usuario: ";
	cin.getline(x->numero,50);
	while (strlen(x->numero)==0){//inicio de while
		cin.getline(x->numero,50);
	}//fin de while
	return x;
}//de  leer usuario

void mostrar (usuario x)
{//de mostrar
	cout<<"\n Detalles de los usuarios ingresados\n";
	cout<<"-------------------------\n";
	cout<<"Nombre: \t"<<x->nombre;
	cout<<"\n Apellido: \t\t"<<x->apellido;
	cout<<"\n Direccion: \t"<<x->direccion;
	cout<<"\n Numero: \t"<<x->numero<<"\n\n";
}//de mostrar

usuario* leer_usuarios(usuario* c, int n)
{//de leer numero usuarios
	for (int i=0;i<n;i++)
   {//de for
		cout<<"\n\n USUARIO "<<(i+1)<<":\n";

		usuario a=crear_usuario();  //se asigana a nuevo usuario

		a=leer_usuario(a);
		c[i]=a;
      cout<<"\n***********************************\n";
      clrscr(); //borrar pantalla
	} //de for
	return c;
}//de leer numero usuarios

void imprimir_usuarios(usuario* c, int n)//funcion imprimir
{//de imprimir
	cout<<"NOMBRE \t\t APELLIDO \t\tDIRECCION \t\tNUMERO \n";
   cout<<"***********************************************************************\n";
	for (int i=0;i<n;i++)
   {//de for
		cout<<c[i]->nombre<<"\t\t"<<c[i]->apellido<<"\t\t";
		cout<<c[i]->direccion<<"\t\t\t"<<c[i]->numero<<"\n";
	}//de for
}//de imprimir


usuario* ordenar_por_apellido (usuario* c, int n) {
	usuario aux;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (strcmp(c[i]->apellido,c[j]->apellido)>0) {
					aux=c[i];
					c[i]=c[j];
					c[j]=aux;
			}
	return c;
}

usuario* ordenar_por_numeros_telefonicos (usuario* c, int n) {
	usuario aux;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (strcmp(c[i]->numero,c[j]->numero)>0) {
					aux=c[i];
					c[i]=c[j];
					c[j]=aux;
			}
	return c;
}
usuario* ordenar_por_numeros_direccion (usuario* c, int n) {
	usuario aux;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (strcmp(c[i]->direccion,c[j]->direccion)>0) {
					aux=c[i];
					c[i]=c[j];
					c[j]=aux;
			}
	return c;
}

int main() //funcion principal
{//de main
	int n;
	cout<<"Cuantos usuarios desea ingresar? \n";
	cin>>n; //numero de usuarios
   clrscr();//borrar pantalla
	usuario* varios=new usuario[n];
	varios=leer_usuarios(varios,n);
	cout<<"\nUSUARIOS INGRESADOS\n";
	cout<<"\n*********************************************************************\n\n";
	imprimir_usuarios(varios,n);
   varios=ordenar_por_apellido(varios,n);
   cout<<"\nUSUARIOS ORDENADOS POR APELLIDOS\n";
	cout<<"\n*********************************************************************\n\n";
   imprimir_usuarios(varios,n);
   varios=ordenar_por_numeros_telefonicos (varios,n);
   cout<<"\nUSUARIOS ORDENADOS POR NUMEROS TELEFONICOS\n";
	cout<<"\n*********************************************************************\n\n";
   imprimir_usuarios(varios,n);
   varios=ordenar_por_numeros_direccion (varios,n);
   cout<<"\nUSUARIOS ORDENADOS POR DIRECCIONES\n";
	cout<<"\n*********************************************************************\n\n";
   imprimir_usuarios(varios,n);
	getch();
}