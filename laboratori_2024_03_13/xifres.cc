#include <iostream>

using namespace std;

void pinta_les_xifres(int n) {

	bool segueix = true;
	
	while(segueix) {
		
		int d = n % 10; //d és la darrera xifra
		
		cout << "N: " << n << " d: " << d << endl;
		
		n = n / 10; //faig mes petit n per a seguir buscant les xifres
		
		if (n == 0) {
			cout << "Se acabó!" << endl;
			segueix = false;
		}
	}
}

int main() {
	int n;
	while(cin >> n) {
		pinta_les_xifres(n);
	}
}
