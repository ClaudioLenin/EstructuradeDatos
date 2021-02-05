#include <iostream.h>
#include <conio.h>
int MCD(int a,int b){
    if((a>=b) && (a%b==0))
        return(b);
    else
        return MCD(b,a%b);
}
void main(){
   int n1,n2;
   cout<<"Ingrese el primer numero: ";
   cin>>n1;
   cout<<"Ingrese el segundo numero: ";
   cin>>n2;
   cout<<"El maximo comun divisor es: "<<MCD(n1,n2);
   getch();
}