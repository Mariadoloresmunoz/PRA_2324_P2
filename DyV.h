#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>
#include <ostream>

#include <cstdlib>
#include <ctime>

/*------------------------- BUSQUEDA BINARIA -----------------------------*/

template <typename T>

T BusquedaBinaria (T x, std::vector<T>& v, int ini, int fin){

	if (ini > fin){
		std::cout << "No se encuentra en el array" << std::endl;	
		return -1;
	}

	int medio = (ini + fin) / 2;

	if (v[medio] == x)
		return medio;
	else if (v[medio] > x)
		return BusquedaBinaria(x, v, ini, medio - 1);
	else
		return BusquedaBinaria(x, v, medio + 1, fin);

}

/*************************************************************************/
/*************************************************************************/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNCIONES DE AYUDA ~~~~~~~~~~~~~~~~~~~~~~~~~*/

//INTERCAMBIAR

template <typename W>

void intercambiar(std::vector<W>& v, int i, int j){

	W aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//IMPRIMIR

template <typename X>

void print(std::vector<X>& v, int size){

	for(int i = 0; i < size; i++){
		std::cout<< " " << v[i] << std::endl;
	}

}

/*------------------------------ PARTITION ------------------------------*/

//ÚLTIMO ELEMENTO

template <typename U>

int Partition_ultElem (std::vector<U>& v, int ini, int fin){

        U x = v[fin];
        int i = ini;

        for (int j = ini; j < fin; j++){
                if (v[j] <= x){
                        intercambiar(v, i, j);
                        i++;
                }
        }

        intercambiar(v, i, fin);

        return i;
}

//PRIMER ELEMENTO

template <typename Y>

int Partition_primElem (std::vector<Y>& v, int ini, int fin){

	Y x = v[ini];
	int i = ini;

	for (int j = ini + 1; j <= fin; j++){

		if (v[j] <= x){
			i++;
			intercambiar(v, i, j);
		}
	}

	intercambiar(v, i, ini);

	return i;
}

//ELEMENTO CENTRAL

template <typename A>

int Partition_midElem (std::vector<A>& v, int ini, int fin){

	int mid = (ini + fin) / 2;
	A x = v[mid];

	int i = ini, j = fin;

	while (i <= j){

		while (v[i] < x){
			i++;
		}

		while (v[j] > x){
			j--;
		}

		if (i <= j){
			intercambiar(v, i, j);
			i++;
			j--;
		}

	}

	return i;
}

//ELEMENTO ALEATORIO

template <typename C>

int Partition_randElem (std::vector<C>& v, int ini, int fin){

	srand( time(nullptr) );

	C x = v[ini + rand() % (fin - ini + 1)];

	int i = ini, j = fin;

	while (i < j){

        	while (v[i] < x){
            		i++;
		}

        	while (v[j] > x){
            		j--;
		}

        	if (i < j){
			intercambiar(v, i, j);
		}

    	}

    	return j;

}



/*------------------------------ QUICKSORT -------------------------------*/

//ÚLTIMO ELEMENTO

template <typename V>

void QuickSort_ultElem (std::vector<V>& v, int ini, int fin){
	
	if (ini < fin){
		int pivot = Partition_ultElem(v, ini, fin);
		QuickSort_ultElem(v, ini, pivot - 1);
		QuickSort_ultElem(v, pivot + 1, fin);
	}
}

//PRIMER ELEMENTO

template <typename Z>

void QuickSort_primElem (std::vector<Z>& v, int ini, int fin){

	if (ini < fin){
                int pivot = Partition_primElem(v, ini, fin);
                QuickSort_primElem(v, ini, pivot - 1);
                QuickSort_primElem(v, pivot + 1, fin);
        }

}

//ELEMENTO CENTRAL

template <typename B>

void QuickSort_midElem (std::vector<B>& v, int ini, int fin){

	if (ini < fin){
		int pivot = Partition_midElem(v, ini, fin);
                QuickSort_midElem(v, ini, pivot - 1);
                QuickSort_midElem(v, pivot, fin);
	}
}

//ELEMENTO ALEATORIO

template <typename D>

void QuickSort_randElem (std::vector<D>& v, int ini, int fin){

        if (ini < fin){
                int pivot = Partition_randElem(v, ini, fin);
                QuickSort_randElem(v, ini, pivot - 1);
                QuickSort_randElem(v, pivot + 1, fin);
        }
}


#endif
