// Grant Keegan | A01700753
// Cinthya Villalobos | A01751678
// Actividad Integradora 3: Estructura de Datos Jerárquica

/* En esta actividad, abriremos la lista de bitácora y agregaremos los
elementos ena una estructura de datos llamada binary heap.
Utilizaremos heap sort para ordenarlos, y al final mostraremos los 5 IPs
que tengan la mayor cantidad de accesos (instancias).
Un heap es cualquier lista ordenada dentro de un árbol binario.*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <stack>
#include <list>
#include "ConvertidorIP.h"
#include "MaxHeap.h"
#include "Registro.h"
//#include "HeapSort.h"
#include "Registro.h"
using namespace std;

string mes, dia, hms, ip, e1, e2, e3, e4, e5, e6;

int main() {
    // El siguiente código abre la bitácora y la pasa a diferentes líneas.
    // Las guarda en un vector.
    ifstream inputFile("bitacoraHeap.txt");
    vector<string> lineas;
    string linea;
    while (getline(inputFile, linea)) { // get_line para guardar las lineas.
      istringstream l(linea);
      l >> mes >> dia >> hms >> ip >> e1 > e2 > e3 > e4 > e5 > e6;
      string error;
      error = e1+" "+e2+" "+e3+" "+e4+" "+e5+" "+e6+" ";
      lineas.push_back(linea);
    }
    inputFile.close();
    for (const string & linea: lineas) {
      // convertidor(linea); // Convierte la IP de la lista en decimal.
      cout << linea << endl;
    }
    // Ahora debemos de juntar las lineas de la IP en un solo número, eliminando puntos.
    cout << v0 << endl;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << valor_decimal;
    return 0;
}