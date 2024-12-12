#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int cambio(vector<int>& v, vector<int>& b, int m){
	
	int size = v.size();

	//matriz con tamaño de fila = size y tamaño de coluimna = m + 1
	vector<vector<int>> aux (size, vector<int>(m + 1 , -1)); 

	aux[0][0] = 0;

	//rellenamos primera fila con 0s
	for ( int j = 0 ; j < m + 1 ; j++ ){

		 if ( j >= v[0] && aux[0][j - v[0]] != -1 ){
			aux[0][j] = 1 + aux[0][j - v[0]];			
		}
	}

	for ( int i = 1 ; i < size ; i++ ){

		aux[i][0] = 0;

		for ( int j = 1 ; j < m + 1 ; j++ ){

			if ( j < v[i] || aux[i][j - v[i]] == -1 )
				aux[i][j] = aux[i - 1][j];
			

			else if ( aux[i - 1][j] != -1 )
				aux[i][j] = min( aux[i - 1][j], 1 + aux[i][j - v[i]] );
			

			else
				aux[i][j] = 1 + aux[i][j - v[i]];
			
		}
	}

	//2º Apartado
	
	int i = size - 1;
	int j = m;

	while ( i >= 0 && j != 0){

		if ( i == 0 || aux[i][j] != aux[i - 1][j] ){

			b[i] = b[i] + 1;
			j = j - v[i];
		}

		else
			i--;

	}

	return ( ( aux[size - 1][m] != -1 ) ? aux[size - 1][m] : -1 ); //si devuelve -1 tarda en cargar

}

int main(int argc, char** argv){

	vector<int> v;
	int m, n;

	cout << ">> Ingresa la cantidad de monedas: ";
	cin >> n;

	vector<int> b(n, 0); //vector nuevo
	
	cout << ">> Ingresa las monedas una por una: " << endl;

	for (int i = 0; i < n; i++){

		int valor;
		cout << "Moneda" << i + 1 << ": ";
		cin >> valor;
		v.push_back(valor);
	}

	cout << "<< Las monedas ingresadas son: ";

	int size_v = v.size();

	for (int i = 0; i < size_v; i++){
		cout << v[i] << " ";
	}

	cout << endl;

	cout << ">> Ingresa la cantidad a devolver: ";
	cin >> m;

	int monedas = cambio(v, b, m);

	if (monedas == -1)
		cout << ">> No hay solución valida " << m << "uds." << endl;

	else{
		cout << ">> La cantidad minima de monedas necesarias a devolver " << m << "uds. es de: " << endl;
		cout << " " << monedas << " monedas " << endl;

		cout << ">> Cantidad de cada tipo de moneda:" << endl;

		int size_b = b.size();

		for (int i = 0; i < size_b; i++){
			cout << "Moneda" << i + 1 << "[" << v[i] << "]: " << b[i] << " monedas" << endl;
		}
	}
	
	return 0;

	
}
