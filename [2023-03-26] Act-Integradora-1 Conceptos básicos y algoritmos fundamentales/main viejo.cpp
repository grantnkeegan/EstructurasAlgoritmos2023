#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <class.h>
using namespace std;

/* En esta actividad debemos de programar 2 algoritmos de ordenamiento.
Debemos usar el algoritmo mas efectivo y rapido para analizar y ordenar la lista que
esta en el archivo .txt (Utilizaremos Merge y Quick Sort, siendo quick el mas efectivo)*/

/* El objetivo de la actividad es ordenar todos los */

int quickSort() {
  
}

/*
int mergeSort() {
  
}*/

int main() {
  vector<string> datos;
  string linea;

  ifstream archivo("bitacora-1.txt");

  if(archivo.is_open()){
    while (getline(archivo, linea)){
      datos.push_back(linea);
    }
    archivo.close();
  }
  else{
    cout << "No se pudo abrir el archivo." << endl;
  }
  for (int i = 0; i < datos.size(); i++){
    cout << datos[i] << endl;
  }
  return 0;
}