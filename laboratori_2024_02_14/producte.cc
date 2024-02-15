#include <iostream>

using namespace std;

int main() {

	cout << "Introdueix 3 números" << endl;
	
	int x, y, z;
	
	cin >> x >> y >> z;
	
	int product = x*y*z;
	
	cout << "El producte de " << x << ", " << y << " i " << z << " és " << product << endl;
}
