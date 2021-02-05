#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
void hanoi(int n,int com,int aux,int fin)
{//de hanoi
 if(n==1)
  {//de if
   printf("\n%c->%c\n",com,fin) ;
  }//de if
 else
 {//de else
   //mueve n-1 discos de origen al auxiliar
   hanoi(n-1,com,fin,aux);
       printf("\n%c->%c\n",com,fin) ;
   //mueve n-1 discos de auxiliar a destino
   hanoi(n-1,aux,com,fin);


 }//de else
}//de hanoi

void main()
 {//de main
  clrscr();
  char com='A';
  char aux='B';
  char fin='C';
  int n;
  cout<<"\n Numero de discos: ";
  cin>>n;
  //limpiar el buffer standard imput
  fflush(stdin);
  printf("\n\n Los movimientos a realizar son: \n");
  hanoi(n,com,aux,fin);
  getch();
 }//de main
