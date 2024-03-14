#include <iostream>

using namespace std;

// Comprova si un text és palindròmic o no. Un text és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un text
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool es_palindrom(const string& s) {

	// miro la longitud de la string
	int longitud_string = s.length();
	
	int j; // contindrà la posició contraria a la i
	
	// cout << "Avaluo " << s << ": " << endl;

	// inicialment suposo que és palindròmic
	bool s_es_palindromic = true;
	
	// recorro el nombre com string
	for(int i = 0; i < longitud_string && s_es_palindromic; i++) {
	
		j = longitud_string - 1 - i;
		
		if(s[i] != s[j]) {
			// no és palindròmic!
			// cout << "[" << i << "] " << s[i] << " no és igual a " << s[j] << endl;
			// registro que no és palindròmic
			s_es_palindromic = false;
		// } else {
		// 	cout << "[" << i << "] " << s[i] << " és igual a " << s[j] << endl;
		}
	}

	return s_es_palindromic;
}

int main() {
	string s;

	cin >> s;

	bool resultat = es_palindrom(s);
	
	if(resultat) {
		cout << "SÍ! " << s << " és palindromic" << endl;
	} else {
		cout << "NO! " << s << " no és palindromic" << endl;
	}
}
