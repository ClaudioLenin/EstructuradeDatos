#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
  if (n>2)
    return fibonacci(n-1) + fibonacci(n-2);
  else if (n==2)
    return 1;
  else if (n==1)       
    return 1;
  else if (n==0)
    return 0;
}

int main(void)
{
    int n,i;
    cout << "Introduzca el numero de elementos que desea generar: ";
    cin >> n;
    for (i=0; i<=n; i++)
    {
      printf("%d\n", fibonacci(i));
    }
  system("pause");
}