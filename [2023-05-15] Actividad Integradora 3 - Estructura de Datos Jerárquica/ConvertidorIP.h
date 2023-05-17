// Este archivo es para una función que convierte el valor de las IP separadas a una sola:

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <list>
#include "main.cpp"
#include "MaxHeap.h"
#include "Registro.h"
#include "HeapSort.h"
#include "Registro.h"
using namespace std;

int convertidor() {
  unsigned int pos0 = 5;
  unsigned int pos1 = 1;
  unsigned int pos2 = 1;
  unsigned int pos3 = 1;
  
  // Usamos el multiplicar por la posición.
  unsigned int base0 = 1;
  unsigned int base1 = 256;
  unsigned int base2 = 65536;
  unsigned int base3 = 16777216;
  
  unsigned int v0 = pos0*base0;
  unsigned int v1 = pos1*base1;
  unsigned int v2 = pos2*base2;
  unsigned int v3 = pos3*base3;
  
  unsigned int valor_decimal = v0+v1+v2+v3;
  return valor_decimal;
}