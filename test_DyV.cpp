#include "DyV.h"
#include <chrono>

using namespace std;

void Inicializar_variables(vector<int> &v_int, vector<double> v_double, vector<char> v_char){

	v_int = {80, 52, 9, 21};
	v_double = {83.4, 5.3, 23.2, 51.6};
	v_char = {'h', 's', 'v', 'b'};

}

void Medicion_Tiempos(){

	vector<int> v_int;
	vector<double> v_double;
	vector<char> v_char;

	Inicializar_variables(v_int, v_double, v_char);

	int size_int = v_int.size();
	int size_double = v_double.size();
	int size_char = v_char.size();	

	//// ÚLTIMO ////

	auto start = std::chrono::system_clock::now();
	QuickSort_ultElem(v_int, 0, size_int - 1);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	std::cout << "Time QuickSort último elemento int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_ultElem(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort último elemento double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_ultElem(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort último elemento char: " << duration.count() << "s" << std::endl;

	//// PRIMERO ////

	start = std::chrono::system_clock::now();
	QuickSort_primElem(v_int, 0, size_int - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort primer elemento int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_primElem(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort primer elemento double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_primElem(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort primer elemento char: " << duration.count() << "s" << std::endl;

	//// CENTRAL ////

	start = std::chrono::system_clock::now();
	QuickSort_midElem(v_int, 0, size_int - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento central int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_midElem(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento central double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_midElem(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento central char: " << duration.count() << "s" << std::endl;

	//// ALEATORIO ////

	start = std::chrono::system_clock::now();
	QuickSort_randElem(v_int, 0, size_int - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento aleatorio int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_randElem(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento aleatorio double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_randElem(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento aleatorio char: " << duration.count() << "s" << std::endl;

}

int main(int argc, char** argv){
	
	//// BÚSQUEDA BINARIA ////

	cout << "		>> " << "BÚSQUEDA BINARIA" << " <<		" << endl << endl;

	vector<int> v_int = {8, 15, 23, 51};
	int x_int = 8;
	int size_int = v_int.size();
	
	vector<double> v_double = {8.4, 15.3, 23.2, 51.6};
	double x_double = 23.2;
	int size_double = v_double.size();
	
	vector<char> v_char = {'a', 'e', 'h', 'v'};
	char x_char = 'v';
	int size_char = v_char.size();	
	
	cout << "Vector original int:";
	print(v_int, size_int);
	cout << endl << endl;
	
	cout << "Se va a buscar el número " << x_int << " dentro del vector y se devolverá su posición." << endl << endl;
	
	cout << "Búsqueda binaria: " << BusquedaBinaria(x_int, v_int, 0, size_int - 1) << endl << endl;
	
	cout << "Vector original double:";
	print(v_double, size_double);
	cout << endl << endl;
		
	cout << "Se va a buscar el número " << x_double << " dentro del vector y se devolverá su posición." << endl << endl;
		
	cout << "Búsqueda binaria: " << BusquedaBinaria(x_double, v_double, 0, size_double - 1) << endl << endl;
	
	cout << "Vector original char:";
	print(v_char, size_char);
	cout << endl << endl;
	
	cout << "Se va a buscar la letra " << x_char << " dentro del vector y se devolverá su posición." << endl << endl;
	
	cout << "Búsqueda binaria: " << BusquedaBinaria(x_char, v_char, 0, size_char - 1) << endl << endl;

	//// QUICK SORT ÚLTIMO ////

	cout << "		>> " << "QUICK SORT ÚLTIMO" << " <<		" << endl << endl;
	
	//inicializamos las variables con valores desordenados y manteniendo el tamaño
	Inicializar_variables(v_int, v_double, v_char);
	
	cout << "Se va a ordenar el vector: ";
	print(v_int, size_int);
	cout << endl << endl;

	QuickSort_ultElem(v_int, 0, size_int - 1);

	cout << "Vector ordenado: ";
	print(v_int, size_int);
	cout << endl << endl;

	cout << "Se va a ordenar el vector: ";
	print(v_double, size_double);
	cout << endl << endl;

	QuickSort_ultElem(v_double, 0, size_double - 1);

	cout << "Vector ordenado: ";
	print(v_double, size_double);
	cout << endl << endl;
		
	cout << "Se va a ordenar el vector: ";
	print(v_char, size_char);
	cout << endl << endl;

	QuickSort_ultElem(v_char, 0, size_char - 1);

	cout << "Vector ordenado: ";
	print(v_char, size_char);
	cout << endl << endl;

	//// QUICK SORT PRIMERO ////

	cout << "		>> " << "QUICK SORT PRIMERO" << " <<		" << endl << endl;
	
	Inicializar_variables(v_int, v_double, v_char);
	
	cout << "Se va a ordenar el vector: ";
	print(v_int, size_int);
	cout << endl << endl;

	QuickSort_primElem(v_int, 0, size_int - 1);

	cout << "Vector ordenado: ";
	print(v_int, size_int);
	cout << endl << endl;

	cout << "Se va a ordenar el vector: ";
	print(v_double, size_double);
	cout << endl << endl;

	QuickSort_primElem(v_double, 0, size_double - 1);

	cout << "Vector ordenado: ";
	print(v_double, size_double);
	cout << endl << endl;
		
	cout << "Se va a ordenar el vector: ";
	print(v_char, size_char);
	cout << endl << endl;

	QuickSort_primElem(v_char, 0, size_char - 1);

	cout << "Vector ordenado: ";
	print(v_char, size_char);
	cout << endl << endl;

	//// QUICK SORT CENTRAL ////

	cout << "		>> " << "QUICK SORT CENTRAL" << " <<		" << endl << endl;
	
	Inicializar_variables(v_int, v_double, v_char);
	
	cout << "Se va a ordenar el vector: ";
	print(v_int, size_int);
	cout << endl << endl;

	QuickSort_midElem(v_int, 0, size_int - 1);

	cout << "Vector ordenado: ";
	print(v_int, size_int);
	cout << endl << endl;

	cout << "Se va a ordenar el vector: ";
	print(v_double, size_double);
	cout << endl << endl;

	QuickSort_midElem(v_double, 0, size_double - 1);

	cout << "Vector ordenado: ";
	print(v_double, size_double);
	cout << endl << endl;
		
	cout << "Se va a ordenar el vector: ";
	print(v_char, size_char);
	cout << endl << endl;

	QuickSort_midElem(v_char, 0, size_char - 1);

	cout << "Vector ordenado: "; 
	print(v_char, size_char);
	cout << endl << endl;

	//// QUICK SORT ALEATORIO ////

	cout << "		>> " << "QUICK SORT ALEATORIO" << " <<		" << endl << endl;
	
	Inicializar_variables(v_int, v_double, v_char);

	cout << "Se va a ordenar el vector: ";
	print(v_int, size_int);
	cout << endl << endl;

	QuickSort_randElem(v_int, 0, size_int - 1);

	cout << "Vector ordenado: ";
	print(v_int, size_int);
	cout << endl << endl;

	cout << "Se va a ordenar el vector: ";
	print(v_double, size_double);
	cout << endl << endl;

	QuickSort_randElem(v_double, 0, size_double - 1);

	cout << "Vector ordenado: ";
	print(v_double, size_double);
	cout << endl << endl;
		
	cout << "Se va a ordenar el vector: ";
	print(v_char, size_char);
	cout << endl << endl;

	QuickSort_randElem(v_char, 0, size_char - 1);

	cout << "Vector ordenado: ";
	print(v_char, size_char);
	cout << endl << endl;

	cout << "		>> " << "MEDICIÓN DE TIEMPOS" << " <<		" << endl << endl;

	Medicion_Tiempos();

	return 0;

}
