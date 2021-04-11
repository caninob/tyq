#include <iostream>
#include <cmath>
#include <math.h>
// declaro las librerias que voy a utiizar
void print_serie (int nmin, int nmax); //declaro la funcion print serie para que me imprima la serie 1/n^2 desde un parámetro nmin hasta un parámetro nmax
int main(void) //declaro la función main
{
  const int m = 10, n = 1500; //Estamos pidiendo que nos reserven el espacio para un entero en la memoria (4 bytes)
  print_serie (m,n); //llamo a la funcion main
  
   return 0;
}

void print_serie (int nmin, int nmax) //implementacion
{
    double suma = 0;
    for (int ii = nmin ; ii <= nmax ; ii = ii+1)
    {
      double b = pow (ii, 2);
      double a = 1/b; //le asigno la variable "a" al cuadrado inverso del natural ii
      
    suma = suma+a;
    }
    
    
  

    std::cout << suma << "\n";
    
}