#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<string> noms(n);
	vector<int> preus(n);

	for(int i = 0; i < n; i++) {
		cin >> noms[i];
		cin >> preus[i];
	}
	
	int preu_exacte;
	cin >> preu_exacte;
	
	int posicio_guanyadora = -1;
	
	for(int i = 0; i < n; i++) {
		if(preus[i] <= preu_exacte) {
			//és un candidat...
			if(posicio_guanyadora == -1) {
				//és el primer candidat, me lo quedo
				posicio_guanyadora = i;
			}	else {
				//miro a veure quin és millor dels dos candidats
				if(preus[i] > preus[posicio_guanyadora]) {
					posicio_guanyadora = i;
				}
			}
		}
	}
		
	if(posicio_guanyadora == -1) {
		cout << "CAP GUANYADOR" << endl;
	} else {
		cout << "guanyador/a: " << noms[posicio_guanyadora] << endl;
	}

  return 0;
}






