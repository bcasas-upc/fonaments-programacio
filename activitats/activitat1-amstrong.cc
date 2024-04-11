#include <iostream>
#include <cmath>

using namespace std;

// Calcula la longitud, és a dir, el nombre de caràcters que té un nombre n.
// Pre: n és un nombre natural
// Post: retorna la longitud de n
int longitud(int n) {
	int l = 0;
	bool continua = true;

	while(continua) {
		// Inv: l conté la longitud del nombre n
		n = n / 10;
		l++;
		if (n == 0) {
			continua = false;
		}
	}
	return l;
}

// Calcula la suma d'amstrong d'un nombre n. La suma d'amstrong és la suma 
// de les potències n-èsimes dels seus dígits on n és la longitud del nombre.
// Pre: n és un nombre natural
// Post: retorna la suma d'amnstrong de n
int suma_amstrong(int n) {
	int d;
	int suma = 0;
	bool continua = true;
	int l = longitud(n);

	while(continua) {
		// Inv: suma conté la suma d'amnstrong del nombre n
		d = n % 10;
		suma = suma + pow(d, l);
		n = n / 10;
		if(n == 0) {
			continua = false;
		}
	}

	return suma;
}

int main() {
	int n;
	bool continua_llegint = true;
	bool algun_amstrong = false;

	while(continua_llegint) {
		// Inv: algun_amstrong indica si s'ha trobat un nombre amstrong o no
		cin >> n;
		if (n > 0) {
			int s = suma_amstrong(n);
			if ( n == s) {
				if(algun_amstrong) {
					//vol dir que no és el primer, per tant, 
					//poso un espai en blanc de separador
					cout << " ";
				} else {
					algun_amstrong = true;
				}
				cout << n;
			}
		} else {
			continua_llegint = false;
		}
	}

	if(not algun_amstrong) {
		cout << "NO";
	}
	cout << endl;
}
