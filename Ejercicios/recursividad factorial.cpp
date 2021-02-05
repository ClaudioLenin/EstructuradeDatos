#include<iostream.h>
#include<conio.h>
long double factorial(int);
int main()
{//de main
 int n;
 cout<<"Introduzaca el numero: ";
 cin>>n;
 cout<<"\nEl factorial es: "<<factorial(n)<<endl;
 getch();
}//de main

long double factorial(int n)
{//de factorial
 if(n==0)
 return 1;
 else
 return n*factorial(n-1);
}//de factorial
