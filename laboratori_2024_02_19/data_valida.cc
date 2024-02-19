#include <iostream>

using namespace std;

bool es_any_traspas(int any) {
	bool traspas = false;
	if (any % 4 == 0) {
		// és multiple de 4
		if (any % 100 == 0) {
			// és múltiple de 100
			if (any % 400 == 0) {
				// el nombre que queda després de treure els dos zeros finals és divisible per quatre
				traspas = true;
			}
		} else {
			// és any de traspàs
			traspas = true;
		}
	}
	
	return traspas;
}

bool es_un_mes_de_30_dies_o_menys(int mes) {
	bool te_30_dies_o_menys = false;
	if(mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		te_30_dies_o_menys = true;
	}
	
	return te_30_dies_o_menys;
}

bool es_data_valida(int d, int m, int a) {
	
	bool data_valida = true;
	
	if (m < 1 || m > 12) {
		data_valida = false;
	} else if (d < 1 || d > 31) {
		data_valida = false;
	} else if (d == 31 && es_un_mes_de_30_dies_o_menys(m)) {
		data_valida = false;
	} else if (d == 30 && m == 2) {
		//no existeix 30 de febrer
		data_valida = false;
	} else if (d == 29 && m == 2 && !es_any_traspas(a)) { //NO és any de traspàs
		//no existeix 29 de febrer
		data_valida = false;
	}	
		
	return data_valida;
}

int main() {
	int d, m, a;
	cin >> d >> m >> a;
	
	bool v = es_data_valida(d,m,a);
	
	cout << "Es data vàlida? " << (v?"SI!":"NO ;(") << endl;
}
