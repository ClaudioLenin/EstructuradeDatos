#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

long double factorial(int n)
{
 if (n==0)
  return 1;
 else
  return n*factorial(n-1);
}

int main()
{   int n;
    cout << "Introduzca numero: ";
    cin >> n;
    cout << "El factorial es: " << factorial(n) << endl;
    system("pause");
}