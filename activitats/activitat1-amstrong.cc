#include <iostream>
#include <cmath>

using namespace std;

// Calcula la longitud, és a dir, el nombre de caràcters que té un nombre n.
// Pre: n és un nombre natural
// Post: retorna la longitud de n
int longitud(int n) {
	int l = 1;
	while(n > 9) {
		// Inv: "l" conté la quantitat de xifres de “n" que s’han processat fins al moment;
		//    “n" conté l’entrada original sense les “l” xifres menys significatives
		n /= 10;
		++l;
	}
	return l;
}

// Calcula la suma d'armstrong d'un nombre n. La suma d'armstrong és la suma 
// de les potències n-èsimes dels seus dígits on n és la longitud del nombre.
// Pre: n és un nombre natural
// Post: retorna la suma d'armstrong de n
int suma_armstrong(int n) {
	int suma = 0;
	int l = longitud(n);

	while(n != 0) {
		// Inv: suma conté la suma d'armstrong del nombre n
		int d = n % 10;
		suma += pow(d, l);
		n = n / 10;
	}

	return suma;
}

int main() {
	int n;
	bool continua_llegint = true;
	bool algun_amstrong = false;
	cin >> n;
	while (n != 0) {
		// Inv: algun_amstrong indica si s'ha trobat un nombre amstrong o no
		int s = suma_armstrong(n);
		if (n == s) {
			if(algun_amstrong) {
				//vol dir que no és el primer, per tant, 
				//poso un espai en blanc de separador
				cout << " ";
			} else {
				algun_amstrong = true;
			}
			cout << n;
		}
		cin >> n;
	}

	if(not algun_amstrong) {
		cout << "NO";
	}
	cout << endl;
}
