#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/********************************* FUNCIONES AUXILIARES **************************************/

void error(vector<vector<int>> aux, int m, int size){ //hecho para comprobar errores

	for (int i = 0; i < size + 1; i++){

		for (int j = 0; j < m + 1; j++){
			cout << "Aux[" << i << "][" << j << "] = " << aux[i][j] << endl;
		}

		cout << endl;
	}
}

/*------------------------------------- MOCHILA --------------------------------------------*/

int mochila(vector<int> &p, vector<int> &b, vector<int> &v, int m){ 

	int size = p.size(); //n

	// matriz int con tamaño de fila = n + 1 y tamaño de columna = m + 1 iniciado a 0
	vector<vector<int>> aux (size + 1, vector<int>(m + 1 , 0));  
	
	for (int i = 1 ; i < size + 1 ; i++){
		
		for ( int j = 1 ; j < m + 1 ; j++ ){

				if ( j >= p[i - 1] ){ 
				//objeto <= peso del requerido

					if (aux[i - 1][j] == 0){
						//está vacío
						aux[i][j] = b[i - 1];
					}

					aux[i][j] = max( aux[i - 1][j], b[i - 1] + aux[i - 1][j - p[i - 1]] ); //j - p[i] indica el espacio sobrante
								   //b anterior     b actual + b anterior si peso lo permite
				}

				else{ 
				//objeto > peso del requerido
					aux[i][j] = aux[i - 1][j];
				}
		}
	}


	// 2a PARTE 
	
	int i = size, j = m; 

	while (i > 0 && j > 0){ 

		if (aux[i][j] != aux[i - 1][j] ){ //se incluye el objeto actual
			v[i - 1] = 1;
			j = j - p[i - 1]; //se elimina el peso del objeto incluido
		}

		i--;
	}

	return aux[size][m];

}

/*------------------------------------------- MAIN -------------------------------------------*/

int main(int argc, char** argv){
	
	int m, n;
	vector<int> p;
	vector<int> b; 

 	cout << ">> Ingresa la cantidad de objetos: ";
   	cin >> n;
	cout << endl;

   	vector<int> v(n, 0); //2a Parte

	if (n <= 0){ //comprobamos que peso > 0
		    
		cout << ">> Error a la hora de ingresar la cantidad de objetos. Debe ser un número mayor a 0 <<	" << endl << endl;
		return 1;
	}

	cout << ">> Ingresa el peso máximo: ";
   	cin >> m;
   	cout << endl;

	if (m <= 0){ //comprobamos que peso > 0

		cout << ">> Error a la hora de ingresar el peso máximo. Debe ser un número mayor a 0 <<	" << endl << endl;
		return 1;
	}

   	cout << ">> Ingresa los pesos uno por uno (siendo estos menores al peso máximo):" << endl;

   	for (int i = 0; i < n; i++){ 

		int valor;

		cout << "Peso " << i + 1 << ": ";
		cin >> valor;

		while (valor <= 0){ //comprobamos que peso > 0

			cout << "Peso " << i + 1 << ": ";
			cin >> valor;
		}

		p.push_back(valor);
    	}

	cout << endl;

	cout << ">> Ingresa los beneficios uno por uno:" << endl;

   	for (int i = 0; i < n; i++){ 

		int valor;

		cout << "Beneficio " << i + 1 << ": ";
		cin >> valor;

		while (valor <= 0){ //comprobamos que beneficio > 0

			cout << "Beneficio " << i + 1 << ": ";
			cin >> valor;
		}

		b.push_back(valor);
    	}

	cout << endl;

    	cout << ">> Los (pesos-beneficios) ingresados son: ";

    	for (int i = 0; i < n; i++){
        	cout << "(" << p[i] << "-" << b[i] << ") ";
    	}

    	cout << endl << endl;

    	int beneficio_maximo = mochila(p, b, v, m);

    	if (beneficio_maximo == 0){
    		cout << ">> Los pesos son mayores que el peso máximo <<	" << endl << endl;
    	}

    	else{
    		cout << ">> Máximo beneficio: " << beneficio_maximo << endl << endl;
    	}

    	//2a Parte

    	for (int i = 0; i < n; i++){
    		cout << "Objeto [ " << i << " ]: " << ( (v[i] == 1) ? "1" : "0" ) << endl << endl;    	
	}

	return 0;

}
