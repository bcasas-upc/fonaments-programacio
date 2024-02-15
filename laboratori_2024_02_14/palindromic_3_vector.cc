#include <iostream>
#include <vector>

using namespace std;

// Comprova si un número és palindròmic o no. Un número és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un número natural
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool is_palindromic(int n) {

	vector<int> xifres;

	bool continua_afegint_xifres = true;
	while (continua_afegint_xifres) {

		int xifra = n % 10;
		xifres.push_back(xifra);
		
		cout << "n = " << n << " i xifra = " << xifra << endl;

		if(xifra == n) {
			//vol dir que ja no cal que segueixi agafant xifres, ja he acabat
			continua_afegint_xifres = false;
		} else {
			//redueixo n
			n = n / 10;
		}
	}

	// miro quantes xifres tinc
	int num_xifres = xifres.size();

	// inicialment suposo que és palindròmic
	bool n_es_palindromic = true;

	// flag: controlo si segueixo comprovant o no 
	bool continuar_comprovant = true;

	int i = 0;
	int j; // contindrà la posició contraria a la i

	//ara faig un bucle per a comprovar si les xifres coincideixen
	while (continuar_comprovant) {

		j = num_xifres - 1 - i;

		cout << "xifres[" << i << "]=" << xifres[i] << " és igual a xifres[" << j << "]=" << xifres[j] << "?" << endl;

		if(xifres[i] != xifres[j]) {
			n_es_palindromic = false;
			continuar_comprovant = false;
		}

		i = i + 1;
		if ( i >= num_xifres / 2) {
			//no cal comprovar-les totes, sols cal comprovar la meitat
			continuar_comprovant = false;
		}
	}

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
