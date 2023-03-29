/* Tarea individual: Act-Integradora-1 Conceptos básicos y algoritmos fundamentales
Arturo Sánchez Rodríguez | A01275427
Grant Keegan | A01700753
28 de marzo del 2023
Programación de estructuras de datos y algoritmos fundamentales (Gpo 850) */

//En este código se están empleando los métodos de ordenamiento Insertion Sort y Bubble Sort.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "class.h"
using namespace std;

Bitacora::Bitacora(){
} // Crea la instancia de la clase 'Bitacora'.

void Bitacora::leer(){
    string linea;
    ifstream archivo("bitacora-1.txt");
    if(archivo.is_open()){
        while(getline(archivo, linea)){
            registros.push_back(linea);
            fechas.push_back(linea.substr(0,14));
        }
    }
    archivo.close();
};

// Este algoritmo es para el ordenamiento de Bubble Sort.
void Bitacora::ordenar_efectivo(){
    int comparaciones = 0; // Para contear las comparaciones e imprimirlos.
    int swaps = 0; // Para contear los swaps e imprimirlos.
    for(int i = 1; i < registros.size(); i++){
        for(int j = i; j > 0; j--){
            comparaciones++;
            if(fechas[j] < fechas[j-1]){
                swaps++;
                string temp1 = fechas[j];
                string temp2 = registros[j];
                fechas[j] = fechas[j-1];
                registros[j] = registros[j-1];
                fechas[j-1] = temp1;
                registros[j-1] = temp2;
            }
            else
                break;
        }
    }
    cout << "Algoritmo efectivo." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << endl;
    cout << "Swaps realizados: " << swaps << endl;
};

// Este algortimo es para el ordenamiento de Insertion Sort.
void Bitacora::ordenar_poco_efectivo(){
    int comparaciones = 0; // Para contear las comparaciones e imprimirlos.
    int swaps = 0; // Para contear los swaps e imprimirlos.
    for(int i = 0; i < registros.size()-1; i++){
        for(int j = 0; j < registros.size()-i-1; j++){
            comparaciones++;
            if(fechas[j] > fechas[j+1]){
                swaps++;
                string temp1 = fechas[j];
                string temp2 = registros[j];
                fechas[j] = fechas[j+1];
                registros[j] = registros[j+1];
                fechas[j+1] = temp1;
                registros[j+1] = temp2;
            }
        }
    }
    cout << "Algoritmo poco efectivo." << endl;
    cout << "Comparaciones realizadas: " << comparaciones << endl;
    cout << "Swaps realizados: " << swaps << endl;
};

// Este metodo de la clase es para encontrar las fechas seleccionadas en el archivo.
void Bitacora::verificar_fechas(){
    int encontrado1 = 0;
    int encontrado2 = 0;
    for(int i = 0; i < registros.size(); i++){
        if(fechas[i] == inicio){
            encontrado1 = 1;
        }
        if(fechas[i] == fin){
            encontrado2 = 1;
        }
    }
    // Las siguientes lineas son por si el usuario introduce algo que no es una fecha debida.
    if(encontrado1 == 0){
        cout << "La fecha de inicio no se encuentra en la bitacora." << endl;
    }
    if(encontrado2 == 0){
        cout << "La fecha de fin no se encuentra en la bitacora." << endl;
    }
};

// Este metodo es para la busqueda de fechas con los parametros que ingrese el usuario.
void Bitacora::buscar_fechas(){
    string inicio, fin;
    cout << "Introduzca la fecha de inicio (mes, dia, hora, minutos, segundos): ";
    cin >> inicio;
    cout << "Introduzca la fecha de fin (mes, dia, hora, minutos, segundos): ";
    cin >> fin;
    this->inicio = inicio;
    this->fin = fin;
    verificar_fechas();
    if(inicio == fin){
        cout << "Ambas fechas son iguales. No hay informacion." << endl;
    }
    else{
        int encontrado1 = 0;
        int encontrado2 = 0;
        int pos1 = 0;
        int pos2 = 0;
        for(int i = 0; i < registros.size(); i++){
            if(fechas[i] == inicio && encontrado1 == 0){
                encontrado1 = 1;
                pos1 = i;
            }
            if(fechas[i] == fin && encontrado2 == 0){
                encontrado2 = 1;
                pos2 = i;
            }
        }
        cout << "Los registros encontrados son:" << endl;
        for(int i = pos1; i <= pos2; i++){
            cout << registros[i] << endl;
        }
    }
    cout << "Numero de ordenamientos: " << registros.size() << endl;
};

// Al final esta funcion debe de imprimir los resultados de la bitacora en un archivo .txt
void Bitacora::imprimir(){
    for(int i = 0; i < registros.size(); i++){
        cout << registros[i] << endl;
    }
};

//Lo que hace el siguiente código es escribir un archivo .txt de los registros que fueron almacenados en el vector.
//Para eso creamos el archivo de texto llamado bitacora-2.txt asi analizando el registro de datos con un ciclo for y despues imprimiendo los registros en el nuevo archivo. 
void Bitacora::imprimirN(){
    ofstream archivo;
    archivo.open("bitacora-2.txt");
    for(int i = 0; i < registros.size(); i++){
        archivo << registros[i] << endl;
    }
    archivo.close();
};

int main(){
    Bitacora b;
    b.leer();
    b.ordenar_efectivo();
    b.ordenar_poco_efectivo();
    b.buscar_fechas();
    b.imprimir();
    b.imprimirN();
    return 0;
};
