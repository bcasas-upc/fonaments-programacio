#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vector_char;
typedef vector<vector_char> matriu_char;

typedef vector<int> vector_int;
typedef vector<vector_int> matriu_int;

int comprova_horitzontal(matriu_char& lletres, matriu_int& punts, int f, int c, int i, int j, string& paraula) {
	int longitud_paraula = paraula.length();
	int puntuacio = 0;
	
	//hi cap la paraula?
	if(j + longitud_paraula <= c) {
		int k = 0;
		bool segueixo_comprovant = true;
		while(segueixo_comprovant) {
			if (k >= longitud_paraula) {
				segueixo_comprovant = false;
			} else if(lletres[i][j+k] == paraula[k]) {
				puntuacio = puntuacio + punts[i][j+k];
				//voy bien
			} else {
				//lletres diferents
				segueixo_comprovant = false;
				puntuacio = -1;
			}
			k++;
		}
	} else {
		// no hi cap ;(
		puntuacio = -1;
	}
	
	return puntuacio;
}

int comprova_vertical(matriu_char& lletres, matriu_int& punts, int f, int c, int i, int j, string& paraula) {
	int longitud_paraula = paraula.length();
	int puntuacio = 0;
	
	//hi cap la paraula?
	if(i + longitud_paraula <= f) {
		int k = 0;
		bool segueixo_comprovant = true;
		while(segueixo_comprovant) {
			if (k >= longitud_paraula) {
				segueixo_comprovant = false;
			} else if(lletres[i+k][j] == paraula[k]) {
				puntuacio = puntuacio + punts[i+k][j];
				//voy bien
			} else {
				//lletres diferents
				segueixo_comprovant = false;
				puntuacio = -1;
			}
			k++;
		}
	} else {
		// no hi cap ;(
		puntuacio = -1;
	}
	
	return puntuacio;
}

int calcula_puntuacio(matriu_char& lletres, matriu_int& punts, int f, int c, string& paraula) {
	int puntuacio_maxima = -1;
	for(int i=0;i<f;i++) {
		for (int j=0;j<c;j++) {	
			// comprovo les línies horitzontal i vertical
			int puntuacio_horitzontal = comprova_horitzontal(lletres, punts, f, c, i, j, paraula);
			if(puntuacio_horitzontal > puntuacio_maxima) {
				puntuacio_maxima = puntuacio_horitzontal;
			}
		
			int puntuacio_vertical = comprova_vertical(lletres, punts, f, c, i, j, paraula);
			if(puntuacio_vertical > puntuacio_maxima) {
				puntuacio_maxima = puntuacio_vertical;
			}
		}
	}
			
	return puntuacio_maxima;
}

int main() {
	
	int f, c;
		
	// llegeix files i columnes
	while(cin >> f >> c) {
	
		matriu_char lletres = matriu_char(f, vector_char(c));
		for(int i=0;i<f;i++) {
			for (int j=0;j<c;j++) {
				cin >> lletres[i][j];		
			}
		}
		
		matriu_int punts = matriu_int(f, vector_int(c));
		for(int i=0;i<f;i++) {
			for (int j=0;j<c;j++) {
				cin >> punts[i][j];		
			}
		}
		
		int n;
		
		// llegeix quantes paraules ficarem
		cin >> n;
	
		for(int k = 0; k < n; k++) {
			string paraula;
			cin >> paraula;
			
			// calculo la puntuació
			int puntuacio = calcula_puntuacio(lletres, punts, f, c, paraula);
			
			if(puntuacio < 0) {
				cout << "no" << endl;
			} else {
				cout << puntuacio << endl;
			}
		}
	}
}

