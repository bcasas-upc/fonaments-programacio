#include <iostream>

using namespace std;

int main() {
	
	bool continuo_llegint = true;

	int contador = 0;
	/*
		si c == h => contador = 1;
		si c == o i contador == 1 => contador = 2;
		si c == l i contador == 2 => contador = 3;
		si c == a i contador == 3 => contador = 4;		
	*/
	while(continuo_llegint) {
		char c;
		//cin >> noskipws >> c; //d'aquesta manera no ignora els espais en blanc
		cin >> c;
		
		if (c == 'h') {
			contador = 1;
		} else if (c == 'o' && contador == 1) {
			contador = 2;
		} else if (c == 'l' && contador == 2) {
			contador = 3;
		} else if (c == 'a' && contador == 3) {
			contador = 4;
			continuo_llegint = false;
		} else {
			contador = 0; //reset!
		}
		
		if (c == '.') {
			continuo_llegint = false;
		}
	}
	
	if (contador == 4) {
		cout << "hola" << endl;
	} else {
		cout << "adeu" << endl;
	}
}
