#include <iostream.h>
#include <conio.h>
int fibonacci(int n){
    if(n>2)
       return(fibonacci(n-1)+fibonacci(n-2));     //solo esta linea es recursividad
    else
        if(n==2)
            return(1);
        else
            if(n==1)
                return(1);
            else
               if(n==0)
                  return(0);
}

void main(){
  int n,i;
  cout<<"Introduzca el numero de elementos que desea generar: ";
  cin>>n;
  for(i=0;i<=n;i++)
      cout<<fibonacci(i)<<"  ";
  getch();
}