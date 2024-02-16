#include <iostream>

using namespace std;

// Comprova si un text és palindròmic o no. Un text és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un text
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool is_string_palindromic(string s) {
	return true;
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
