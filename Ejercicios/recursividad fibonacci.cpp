#include<iostream>
#include<conio.h>
int fibonacci(int n)
{//de fibonacci
 if(n>2)
   return fibonacci(n-1)+fibonacci(n-2);
 else
   if(n==2)
     return 1;
   else
     if(n==1)
       return 1;
     else
       if(n==0)
         return 0;

}//de fibonacci

int main()
{//de main
 int n,i;
 cout<<"Introduzca el numero de elementos que desea generar: ";
 cin>>n;
 for(i=0;i<=n;i++)
 cout<<"\n"<<fibonacci(i);

 getch();
}//de main