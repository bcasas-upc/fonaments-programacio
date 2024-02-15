#include <iostream>

using namespace std;

// Comprova si un número és palindròmic o no. Un número és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un número natural
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool is_palindromic(int n) {
	
	// paso a string el nombre
	string n_string = to_string(n);
	
	// miro la longitud de la string
	int longitud_n_string = n_string.length();
	
	cout << "Avaluo " << n_string << ": " << endl;

	// inicialment suposo que és palindròmic
	bool n_es_palindromic = true;
	
	// flag: controlo si segueixo comprovant o no 
	bool continuar_comprovant = true;
	
	int i = 0;
	int j; // contindrà la posició contraria a la i
	
	// recorro el nombre com string
	while (continuar_comprovant) {

		// posició contraria a i 
		j = longitud_n_string - 1 - i;
		
		if(n_string[i] != n_string[j]) {
			// no és palindròmic!
			cout << "[" << i << "] " << n_string[i] << " no és igual a " << n_string[j] << endl;
			// registro que no és palindròmic
			n_es_palindromic = false;
			// surto del bucle pq ja he vist que no ho és
			continuar_comprovant = false;
		}	else {
			cout << "[" << i << "] " << n_string[i] << " és igual a " << n_string[j] << endl;
		}
		
		i = i + 1;
		if (i >= longitud_n_string) {
			// surto del bucle pq ja he acabat de recorrer tots els caràcters
			continuar_comprovant = false;
		}
		
	}

	return n_es_palindromic;
}

int main() {

	bool resultat = is_palindromic(625411245);
	
	cout << "El resultat és " << resultat << endl;
}
