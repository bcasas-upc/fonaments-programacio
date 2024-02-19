#include <iostream>

using namespace std;

int main() {

	int a1, b1, a2, b2;
	
	cin >> a1 >> b1 >> a2 >> b2;
	
	// jo faré servir intervals anomenats [a,b] i [c, d] de manera que a<=c
	
	//int a; // l'a no es fa servir
	int b, c, d;
	
	if(a1 <= a2) {
		//a = a1;
		b = b1;
		c = a2;
		d = b2;
	} else {
		// me'ls ha donat desordenats
		//a = a2;
		b = b2;
		c = a1;
		d = b1;	
	}
	
	/* 
	Casos possibles:
		1) Que no es toquin => a... b ... c ... d => []
		2) Que hi hagi intersecció => a ... c ... b ... d => [c, b] 
	  	3) Que un sigui dins de l'altre => a ... c ... d ... b => [c, d]
	*/
	if (b < c ) {
		//cas 1
		cout << "[]" << endl;
	} else if (d > b) {
		// cas 2
		cout << "[" << c << "," << b << "]" << endl;
	} else {
		// cas 3
		cout << "[" << c << "," << d << "]" << endl;
	}
}
