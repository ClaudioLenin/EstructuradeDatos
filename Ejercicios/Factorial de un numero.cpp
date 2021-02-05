#include <iostream.h>
#include <conio.h>

long double factorial (int);
void main (){
  int n;
  cout<<"Introduzca numero: ";
  cin>>n;
  cout<<"El factorial es: "<<factorial(n)<<endl;
  getch();
}
long double factorial(int n)
{
   if(n==0)
     return(1);
   else
     return(n*factorial(n-1));
}