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
	
	int j; // contindrà la posició contraria a la i
	
	cout << "Avaluo " << n_string << ": " << endl;

	// inicialment suposo que és palindròmic
	bool n_es_palindromic = true;
	
	// recorro el nombre com string
	for(int i = 0; i < longitud_n_string && n_es_palindromic; i++) {
	
		j = longitud_n_string - 1 - i;
		
		if(n_string[i] != n_string[j]) {
			// no és palindròmic!
			cout << "[" << i << "] " << n_string[i] << " no és igual a " << n_string[j] << endl;
			// registro que no és palindròmic
			n_es_palindromic = false;
		}	else {
			cout << "[" << i << "] " << n_string[i] << " és igual a " << n_string[j] << endl;
		}
	}

	return n_es_palindromic;
}

int main() {

	bool resultat = is_palindromic(625411245);
	
	cout << "El resultat és " << resultat << endl;
}
