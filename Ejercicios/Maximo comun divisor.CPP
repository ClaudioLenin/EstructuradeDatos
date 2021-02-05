#include"iostream.h"
#include"conio.h"
int MCD(int a,int b)
 {
  if(a>=b && a%b==0)
   return b;
  else
   return MCD(b,a%b);
 }

void main(void)
{
 clrscr();
 int n1,n2;
 cout<<"Ingrese el primer numero :";cin>>n1;
 cout<<"Ingrese el segundo numero :";cin>>n2;
 cout<<endl<<"El Maximo Comun Divisor es :"<<MCD(n1,n2);
 getch();
}