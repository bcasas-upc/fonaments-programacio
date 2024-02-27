#include <iostream>

using namespace std;

bool es_perfecte(int n) {

	bool resposta = false;
	
	// si n = 0 o 1, no és perfecte
	if ( n >= 2 ) {
		int suma_acumulada = 1;
		int possible_divisor = 2;
		int divisor_complementari;
		
		bool continuo_sumant = true;
		while(continuo_sumant) {
			
			if ( n % possible_divisor == 0) {
				// sumo aquest divisor
				suma_acumulada = suma_acumulada + possible_divisor;
				
				// aquest és l'altre divisor, i també el sumo
				// per exemple, si n = 100, 2 és un divisor, però també 50 pq 2*50 = 100
				divisor_complementari = n / possible_divisor;
				suma_acumulada = suma_acumulada + divisor_complementari;
				
				//cout << "d1: " << possible_divisor << ", d2: " << divisor_complementari << ", suma: " << suma_acumulada << endl;
				
				if (suma_acumulada > n) {
					// ja m'he passat, no cal seguir mirant
					continuo_sumant = false;
				}
			}
			
			possible_divisor = possible_divisor + 1;
			// com quan trobo un divisor també sumo l'altre, acabo quan he arribat a la meitat dels divisors
			if (possible_divisor*possible_divisor > n) {
				continuo_sumant = false;
			}
		}
		
		if(suma_acumulada == n) {
			resposta = true;
		}
	}

	return resposta;
}

int main() {
	int n;
	
	cin >> n;
	
	bool ho_es = es_perfecte(n);
	
	cout << "N és perfecte? " << (ho_es? "Sí!": "No ;(") << endl;
}
