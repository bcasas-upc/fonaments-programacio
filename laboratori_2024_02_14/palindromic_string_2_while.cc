#include <iostream>

using namespace std;

// Comprova si un text és palindròmic o no. Un text és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un text
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool is_string_palindromic(string s) {
	
	// miro la longitud de la string
	int longitud_string = s.length();
	
	cout << "Avaluo " << s << ": " << endl;

	// inicialment suposo que és palindròmic
	bool s_es_palindromic = true;
	
	// flag: controlo si segueixo comprovant o no 
	bool continuar_comprovant = true;
	
	int i = 0;
	int j; // contindrà la posició contraria a la i
	
	// recorro el nombre com string
	while (continuar_comprovant) {

		// posició contraria a i 
		j = longitud_string - 1 - i;
		
		if(s[i] != s[j]) {
			// no és palindròmic!
			cout << "[" << i << "] " << s[i] << " no és igual a " << s[j] << endl;
			// registro que no és palindròmic
			s_es_palindromic = false;
			// surto del bucle pq ja he vist que no ho és
			continuar_comprovant = false;
		}	else {
			cout << "[" << i << "] " << s[i] << " és igual a " << s[j] << endl;
		}
		
		i = i + 1;
		if (i >= longitud_string / 2) {
			//no cal comprovar-les totes, sols cal comprovar la meitat
			continuar_comprovant = false;
		}
	}

	return s_es_palindromic;
}

int main() {
	string s;

	cin >> s;

	bool resultat = is_string_palindromic(s);
	
	if(resultat) {
		cout << "SÍ! " << s << " és palindromic" << endl;
	} else {
		cout << "NO! " << s << " no és palindromic" << endl;
	}
}
