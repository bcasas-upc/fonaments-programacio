#include <iostream>

using namespace std;

int compta_digits(int n) {
	//versió alternativa amb string
	//string s = to_string(n);
	//return s.length();
	
	int l = 0;
	bool keep_going = true;

	while(keep_going) {
		n = n / 10;
		l = l + 1;
		if (n == 0) {
			keep_going = false;
		}
	}
	return l;
}

// retorna el digit central o -1 si el n té un nombre parell de dígits
int digit_central(int n) {

	int d = -1; // al final del bucle contindrà el dígit central
	int length = compta_digits(n);

	// si és parell, retorno -1
	if (length % 2 == 1) {
		int posicio_final = length / 2;
		for (int p = 0; p <= posicio_final; p++) {
			d = n % 10;
			n = n / 10;	
		}
	}
	return d;
}

int main() {
	// inicialment, empat
	char resultat = '='	;
	
	int quantitat;
	cin >> quantitat;

	bool llegeix_nombres = true;
	
	int n, central;
	int central_anterior = -1;
	
	int contador = 0;
	while(llegeix_nombres) {
		cin >> n;
		
		central = digit_central(n);
		
		// if (central == -1) {
		// 	//algú perd
		// } else if (central_anterior == -1) {
		// 	//seguim, és el primer número
		// } else if (central != central_anterior) {
		// 	//algú perd
		// } else {
		// 	//seguim, tenen el mateix central
		// }
		if ((central == -1) || (central_anterior != -1 && central != central_anterior)) {
			// algú perd
			if (contador % 2 == 0) {
				resultat = 'B'; //guanya el B
			} else {
				resultat = 'A'; //guanya el A
			}
				
			llegeix_nombres = false;
		}
		
		// guardo el central per la seguent interació
		central_anterior = central;
		
		//cout << "n = " << n << " central = " << central << endl;
		
		contador = contador + 1;
		if (contador == 2*quantitat) {
			llegeix_nombres = false;
		}
	}

	cout << resultat << endl;
}
