#include <iostream>

using namespace std;

int valencia(int n) {

	int d;
	int pos = 0;
	int suma_parells = 0;
	int suma_senars = 0; 
	
	bool continua = true;
	while(continua) {
		
		d = n % 10;
		if(pos % 2) { 
			//posició parell
			suma_parells += d;
		} else {
			//posició senar
			suma_senars += d;
		}
		
		if (n == d) {
			//he acabat
			continua = false;
		}	else {
			//seguim!
			pos++;
			n = n / 10; //redueixo n
		}	
	}

	int v = 0;
	if(suma_parells > suma_senars) {
		v = suma_parells - suma_senars;
	} else {
		v = suma_senars - suma_parells;
	}

	return v;
}

int main()
{
	int valencia_maxima = 0;
	int valencia_actual = 0;
	int primer_equilibrat = -1;
	bool segueixo_llegint = true;

	int n;
	while (segueixo_llegint && cin >> n) {

		valencia_actual = valencia(n);
		//cout << "La valencia de " << n << " és " << valencia_actual << endl;
		
		if(valencia_actual == 0) {
			//he trobat un equilibrat, paro de llegir
			primer_equilibrat = n;
			segueixo_llegint = false;
		} else {
			//miro si és. la valencia màxima
			if(valencia_actual > valencia_maxima) {
				valencia_maxima = valencia_actual;
			}
		}
	}

	if(primer_equilibrat >= 0) {
		//he trobat un equilibrat, el mostro
		cout << "El primer nombre equilibrat es " << primer_equilibrat << "." << endl;
	} else {
		cout << "La valencia maxima es " << valencia_maxima << "." << endl;
	}
    
  return 0;
}
