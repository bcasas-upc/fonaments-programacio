#include <iostream>
#include <vector>

using namespace std;

// Comprova si un número és palindròmic o no. Un número és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un número natural
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool is_palindromic(int n) {

	//guardo el número original per comparar-lo desprès
	int n_original = n;

	// construeixo un nou número que serà n a l'inrevés
	int n_capgirat = 0;

	// guardaré la darrera xifra de n per afegir-la a n_capgirat
	int xifra;

	// aquest flag indicarà quan he de deixar de capgirar el número
	bool continua_capgirant_n = true;
	while (continua_capgirant_n) {

		//agafo la darrera xifra
		xifra = n % 10;

		//l'afegeixo al n_capgirat
		n_capgirat += xifra;

		cout << "xifra = " << xifra << endl;
		cout << "n = " << n << " i n_capgirat = " << n_capgirat << endl;
		
		if(xifra == n) {
			//vol dir que ja no cal que segueixi agafant xifres, ja he acabat
			continua_capgirant_n = false;
		} else {
			//redueixo n
			n = n / 10;
			//avanço n_capgirat
			n_capgirat = n_capgirat * 10;
		}
	}

	// si són iguals, és palindromic
	bool n_es_palindromic = (n_original == n_capgirat);

	return n_es_palindromic;
}

int main() {
	int n;

	cin >> n;

	bool resultat = is_palindromic(n);
	
	if(resultat) {
		cout << "SÍ! " << n << " és palindromic" << endl;
	} else {
		cout << "NO! " << n << " no és palindromic" << endl;
	}
}
