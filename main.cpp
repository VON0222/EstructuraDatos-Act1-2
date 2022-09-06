// =================================================================
//
// File: main.cpp
// Author: José Diego Llaca Castro
// Date: 05/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;				//Abre archivos
	ofstream outputFile;			//Cierra archivos
	int n, q, acum, bubble, insertion, selection;			//Declaración de variables
	vector<int>sequential;			//Vector para datos de busqueda secuencial
	vector<int>binary;				//Vector para datos de busqueda binaria

	//Leer el archivo
	if(argc != 3){
		cout << "usage: " << argv[0] << " input_file output_file" << endl;
		return -1;
	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open()){
		cout << argv[0] << ": File \"" << argv[1] << "\" not found" << endl;
		return -1;
	}

	outputFile.open(argv[2]);

	//Recorre el archivo
	inputFile >> n;			//Lee la primer linea para saber cuantos numeros tiene el vector

	//Declaración de vectores que almacenan nos numeros que se leen
	vector<int>original(n);			//Donde se almacena al arreglo de numeros 
	vector<int>replica;				//Donde se almacena el arreglo de numeros que no se modificará

	//Lee el archivo para llenar el vector
	for (int i = 0; i < n; i++){
		inputFile >> acum;
		original[i] = acum;
	}

	//APLICACIÓN DE ALGORITMOS DE ORDENAMIENTO//

	replica = original;
	bubble = bubbleSort(original);			//Aplicación de Bubble
	original = replica;
	insertion = insertionSort(original);	//Aplicación de Insertion
	original = replica;
	selection = selectionSort(original);	//Aplicación de Selection

	//Despliega en archivo
	outputFile << bubble << " ";
	outputFile << insertion << " ";
	outputFile << selection << " " << endl;

	//APLICACIÓN DE ALGORITMOS DE BUSQUEDA//

	//Lee el archivo para saber la cantidad de datos a buscar
	inputFile >> q;

	//Implementa search
	for (int j = 0; j < q; j++){
		inputFile >> acum;			//Lee los numeros
		sequential = sequentialSearch(original, acum);			//Implementación de busqueda secuencial
		outputFile << sequential[0] << " ";			//Despliega el indice
		outputFile << sequential[1] << " ";			//Despliega numero de comparaciones

		binary = binarySearch(original, acum);			//Implementación de busqueda binaria
		outputFile << binary[0] << " ";				//Despliega el indice
		outputFile << binary[1] << endl;			//Despliega numero de comparaciones
	}

	//Cierra archivos
	inputFile.close();
	outputFile.close();
	return 0;
}
