#include <iostream>

using namespace std;

// Comprova si un número és palindròmic o no. Un número és palindròmic quan 
// es llegeix igual d'esquerra a dreta o viceversa.
// Pre: un número natural
// Pro: un boolean que val true si l'entrada és palindròmica o fals en cas contrari
bool is_palindromic(int n) {
	return true;
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
