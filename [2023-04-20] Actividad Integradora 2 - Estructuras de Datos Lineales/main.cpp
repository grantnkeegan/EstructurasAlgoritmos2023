/* La segunda actividad debera abrir el archivo .txt del caso
y asignar todos los datos a una lista Doubly Linked. */

/* Despues, debemos de ordenar ascendentemente la informacion
por fecha y hora por medio del Merge Sort */

#include <fstream>
#include <iostream>
using namespace std;
#include <bits/stdc++.h> 

// nodo de lista encadenada 
class Node { 
	public: 
	int data; 
	Node* next; 
	Node* prev; 
};

// Codigo para Doubly Linked List.
void push(Node** head_ref, int new_data) {  
	Node* new_node = new Node(); 
	new_node->data = new_data;  
	new_node->next = (*head_ref); 
	new_node->prev = NULL;
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 
	(*head_ref) = new_node; 
} 

// Esta función imprime el contenido de la lista
void printList(Node* node) 
{ 
	Node* last; 
	cout<<" \nImprime lista hacia al frente \n " ;  
	while (node != NULL) 
	{ 
		cout<<" "<<node->data<<" "; 
		last = node; 
		node = node->next; 
	} 
	cout<<"\nImprime lista hacia atras \n " ;  
	while (last != NULL) 
	{ 
		cout<<" "<<last->data<<" "; 
		last = last->prev; 
	} 
} 

// Algoritmo Merge Sort | Divide en 2 y vuelve a juntarlos ordenados.
// Complejidad = O(nlog)
// log n) La funcion junta los arrays divididos.
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - left;
  int L[n1], R[n2];
  for (int l1 = 0; l1 < n1; l1++)
    L[l1] = arr[left + l1];
  for (int l2 = 0; l2 < n2; l2++)
    R[l2] = arr[mid + 1 + l2];
  // Contienen las listas de subarrays.
  int l1, l2, lm;
  l1 = 0;
  l2 = 0;
  lm = left;
  // Fusiona los arreglos de regreso a arr[].
  while (l1 < n1 && l2 < n2) {
    if (L[l1] <= R[l2]) {
      arr[lm] = L[l1];
      l1++;
    } else {
      arr[lm] = R[l2];
      l2++;
    }
    lm++;
  }
  // Loop del array izquierdo.
  while (l1 < n1) {
    arr[lm] = L[l1];
    l1++;
    l2++;
  }
  // Loop del array derecho.
  while (l2 < n2) {
    arr[lm] = R[l2];
    l2++;
    lm++;
  }
}

// Divide el array en 2, los ordena y los junta por medio de merge().
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// Imprime el array ordenado.
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  // Las siguientes lineas del codigo se encargan de abrir el archivo:
  ifstream inputFile("nums.txt"); // Ingresa el archivo con el que trabajaremos.
  const int max_lines = 20000; // El maximo numero de lineas.
  string lines[max_lines];
  if(inputFile.is_open()) {
    string line; int i = 0;
    while (getline(inputFile, line) && i < max_lines) { // Loop para guardar las lineas en un array.
      lines[i] = line;
      i++;
    }
    inputFile.close(); // cierra el archivo.
  }
  for (int i = 0; i < max_lines && lines[i] != ""; i++) {
    cout << lines[i] << endl;
  }
  int arr[] = {32, 25, 11, 89, 33};
  int size = sizeof(arr) / sizeof(arr[0]); 
  mergeSort(arr, 0, size - 1); // Implementa nuestro algoritmo de ordenamiento.
  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}