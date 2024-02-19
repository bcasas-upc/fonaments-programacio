#include <iostream>

using namespace std;

int main() {
    int any;
	cin >> any;

	bool traspas = false;
	if (any % 4 == 0) {
		// és multiple de 4
		if (any % 100 == 0) {
			// és múltiple de 100
			if (any % 400 == 0) {
				// el nombre que queda després de treure els dos zeros finals és divisible per quatre
				traspas = true;
			}
		} else {
			// és any de traspàs
			traspas = true;
		}
	}
	
    if (traspas) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
