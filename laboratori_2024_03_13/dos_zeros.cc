#include <iostream>

using namespace std;

bool si_acaba_amb_dos_zeros(int n) {

	int resta_de_la_divisio = n % 100;
	
	bool acaba_amb_dos_zeros = false;
	if (resta_de_la_divisio == 0) {
		acaba_amb_dos_zeros = true;
	}
	
	return acaba_amb_dos_zeros;
}

int main() {
	int n;
	while(cin >> n) {
		bool dos_zeros = si_acaba_amb_dos_zeros(n);

		cout << "El nombre " << n << " acaba amb dos zeros? " << (dos_zeros? "SÍ!": "No ;(") << endl;
	}
}
