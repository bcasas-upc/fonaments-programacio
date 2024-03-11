#include <iostream>

using namespace std;

bool es_gras(int n) {

	int digit_gras = 0;
	int digit_prim = 0;
		
	bool segueixo_buscant = true;
	// un nombre és gras si més de la meitat dels dígits d’aquest nombre són 6, 8, 9 o 0.
	
	while(segueixo_buscant) {
		
		int d = n % 10;
		
		if (d == 6 || d == 8 || d == 9 || d == 0) {
			//cout << "Es gras " << d << endl;
			digit_gras = digit_gras + 1;
		} else {
			//cout << "Es prim " << d << endl;
			digit_prim = digit_prim + 1;
		}
		
		if ( n < 10) {
			segueixo_buscant = false;
		}
		
		n = n / 10;
	}
	
	bool n_es_gras = false;
	if (digit_gras > digit_prim) {
		n_es_gras = true;
	}
	
	return n_es_gras;
}

int main() {

	int contador = 0;
	int nombre_parells_consecutius_gras = 0;
	bool numero_actual_es_gras = false;
	bool numero_anterior_es_gras = false;
	
	int n;
	while (cin >> n) {
		numero_actual_es_gras = es_gras(n);
		
		if (contador > 0) {	
			// comprovo a partir de la posició 1
			if(numero_actual_es_gras || numero_anterior_es_gras) {
				nombre_parells_consecutius_gras = nombre_parells_consecutius_gras + 1;
			}
		}
		
		contador = contador + 1;
		
		numero_anterior_es_gras = numero_actual_es_gras;
	}
	
	int nombre_parelles = contador - 1;
	cout << nombre_parelles << " " << nombre_parells_consecutius_gras << endl;
}










