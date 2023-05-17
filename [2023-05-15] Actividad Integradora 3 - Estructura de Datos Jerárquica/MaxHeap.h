// El primer intento de MaxHeap usando el código del profesor.

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

// Para crear al heap, debemos de escribir su clase con template T.
template <class T> class MaxHeap {
private:
  vector<int> heap; // La LISTA (o vector) que representa el heap.
  vector<T> data; // Capacidad maxima del heap.
  int maxSize; // Guardará el tamano maximo del heap.
  int currentSize; // Guardará el tamano actual del heap.
  int parent(int k);  // Parte del dato padre.
  int left(int k);  // hijo izquierda del padre.
  int right(int k);  // hijo derecha del padre.
public:
  MaxHeap(int maxCapacity); // Constructor.
  ~MaxHeap(); // Destructor.
  bool isEmpty();
  T empty(); // Imprime si esta vacio.
  int getMaxCapacity();
  int getCurrentSize();
  T size(); // Imprime el tamano del heap.
  void printHeap();
  void push(T key);
  T getTop();
  T top(); // Imprime el valor maximo
  void pop(T key); // Quita el ultimo miembro del heap.
};



// A continuacion están las funciones del Heap.
// Crea el heap.
template <class T>
MaxHeap<T>::MaxHeap(int maxCapacity) {
  maxSize = maxCapacity;
  currentSize = 0;
  data.resize(maxSize);
}

// Destruye el heap.
template <class T>
MaxHeap<T>::~MaxHeap() {
  maxSize = 0;
  currentSize = 0;
  data.clear();
}

// Te avisa si el heap esta vacio.
// Regresa 1 si esta vacio, 0 si tiene algo.
template <class T>
bool MaxHeap<T>::isEmpty() {
  return (currentSize <= 0);
}

// empty() | Regresa un mensaje si esta vacio, otro si no.
template <class T>
T MaxHeap<T>::empty() {
  if ((isEmpty() == 1)) {
    cout << "isEmpty(): El heap está vacío.";
  } else if ((isEmpty() == 0)) {
    cout << "isEmpty(): El heap contiene datos.\n";
  }
  return 0;
}

// regresa la capacidad del heap.
template <class T>
int MaxHeap<T>::getMaxCapacity() {
  return maxSize;
}

// regresa el tamano actual del heap.
template <class T>
int MaxHeap<T>::getCurrentSize() {
  //currentSize = sizeof(heap);
  return currentSize;
}

// size() | IMPRIME el tamano actual del heap.
template <class T>
T MaxHeap<T>::size() {
  cout << "size(): El tamaño del heap es de: " << getCurrentSize() << endl;
  return 0;
}

// printHeap: Imprime el heap (ya heapifeado) en una linea.
template <class T> void MaxHeap<T>::printHeap() {
  std::cout << "Contenido del maxheap: " << std::endl;
  for (int i = 0; i < currentSize; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

/* Las siguientes se encargan de establecer los numeros padres y 2 hijos
(izquierda y derecha) del heap. */
template <class T>
int MaxHeap<T>::parent(int k) {
  return (k-1)/2;
}

template <class T>
int MaxHeap<T>::left(int k) {
  return (2*k + 1);
}

template <class T>
int MaxHeap<T>::right(int k) {
  return (2*k + 2);
}

// push() | Complejidad: O(log N) | Agrega un numero nuevo al heap.
template <class T>
void MaxHeap<T>::push(T key) { // Asegura que no haya overflows.
  if (currentSize == maxSize) {
    throw std::out_of_range("Overflow: no se puede insertar la llave.\n");
  }
  // Insertamos la nueva llave al final del vector
  int k = currentSize;
  data[k] = key;
  currentSize++;
  // Reparar las propiedades del maxheap si son violadas
  while (k != 0 && data[parent(k)] < data[k]) {
    std::swap(data[k], data[parent(k)]);
    k = parent(k);
  }
}

// getTop() | Complejidad: O(1) | Regresa el valor mayor del heap (El que esta primero.) 
template <class T>
T MaxHeap<T>::getTop() {
  if (isEmpty()) {
    throw std::out_of_range("El heap esta vacio.\n");
    return {};
  }
  return data[0];
}

template <class T>
T MaxHeap<T>::top() {
  cout << "top(): El máximo valor del heap es: " << getTop() << endl;
  return 0;
}

// pop() | Complejidad: O(logN) | Elimina el ultimo miembro del heap (lista).
template <class T>
void MaxHeap<T>::pop(T key) {
  if (currentSize == maxSize) { // Asegura que no haya overflows.
    throw std::out_of_range("Overflow: no se puede insertar la llave.\n");
  }
  currentSize--; // Encoge el currentSize
  heap.pop_back(); // Funcion del '#include <list>' que realiza el pop del heap.
}