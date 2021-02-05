#include <iostream.h>
#include <conio.h>
#include <stdio.h>

void hanoi(int n,int com,int aux,int fin){
    if(n==1){
        printf("\n%c->%c\n",com,fin);
    }
    else{
        //mueve n-1 discos de origen a auxiliar
        hanoi(n-1,com,fin,aux);
        printf("\n%c->%c\n",com,fin);
        //mueve n-1 discos de auxiliar a destino
        hanoi(n-1,aux,com,fin);
    }
}

void main(){
   char com='A';
   char aux='B';
   char fin='C';
   int n;
   printf("\Numero de discos: ");
   scanf("%d",&n);
   fflush(stdin);//limpiar el buffer Standar Input
   printf("\n\nLos movimientos a realizar son: \n");
   hanoi(n,com,aux,fin);
   getch();
}