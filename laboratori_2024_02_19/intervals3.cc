#include <iostream>

using namespace std;

int main() {

	int a1, b1, a2, b2;
	
	cin >> a1 >> b1 >> a2 >> b2;
	
	// comprovo si són iguals
	if (a1 == a2 && b1 == b2) {
		// són iguals
		cout << "= , [" << a1 << "," << b1 << "]" << endl;
	}	else if (a1 <= a2 && b2 <= b1) {
		// interval 2 dins de l'interval 1
		cout << "2 , [" << a2 << "," << b2 << "]" << endl;
	} else if (a2 <= a1 && b1 <= b2) {
		// interval 1 dins de l'interval 2
		cout << "1 , [" << a1 << "," << b1 << "]" << endl;
	} else if (b1 < a2 || b2 < a1) {
		// no es toquen
		cout << "? , []" << endl;
	} else if (a1 <= a2) {
		// interseccionen 
		cout << "? , [" << a2 << "," << b1 << "]" << endl;
	} else {
		// també intereseccionen
		cout << "? , [" << a1 << "," << b2 << "]" << endl;
	}
}
