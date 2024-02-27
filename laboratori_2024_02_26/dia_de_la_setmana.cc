#include <iostream>

using namespace std;

int piso(float f) {
	// Atenció, els símbols ⌊ i ⌋ signifiquen floor: https://en.wiktionary.org/wiki/%E2%8C%8A_%E2%8C%8B
	// en castellà es diu piso: https://www.disfrutalasmatematicas.com/conjuntos/funcion-piso-techo.html
		
	int petit = (int) f;
	//si f = 0.5 => petit = 0
	//si f = 2.9 => petit = 2
	if (f < petit) {
		//si f = -4.4 => petit = -5 
		petit = petit - 1;
	}
	return petit;
}

string dia_de_la_setmana (int d, int m, int a) {

	//Se li resta dos al mes m, i si dóna zero o menys se li suma 12 al mes i se li resta u a l’any. El nou mes obtingut l’anomenem m′ i el nou any a′.
	int m_prima = m - 2;
	int a_prima = a;
	if (m_prima <= 0) {
		m_prima = m_prima + 12;
		a_prima = a_prima - 1;
	}
	
	//Es calcula la centúria c (els dos primers dígits de l’any) a partir de l’any ‍a′.
	int c = a_prima / 100; // és divisió entera!!!
	
	//Es calcula l’any y dins de la centúria (els dos darrers dígits de l’any) a partir de l’any ‍a′.
	int y = a_prima % 100;
	
	//f = ⌊ 2.6m′−0.2 ⌋ + d + y + ⌊ y/4 ⌋ + ⌊ c/4 ⌋ − 2c.
	int f = piso(2.6*m_prima - 0.2) + d + y + piso(y/4.0) + piso(c/4.0) - 2*c;

	int num_dia = f % 7;
	
	// Compte amb els mòduls de nombres negatius!
	if (num_dia < 0) {
		num_dia = num_dia + 7;
	}

	string dia;
	switch (num_dia) {
		case 0:
		  dia = "diumenge";
		  break;
		case 1:
		  dia = "dilluns";
		  break;
		case 2:
		  dia = "dimarts";
		  break;
		case 3:
		  dia = "dimecres";
		  break;
		case 4:
		  dia = "dijous";
		  break;
		case 5:
		  dia = "divendres";
		  break;
		case 6:
		  dia = "dissabte";
		  break;
	}
	return dia;
}

int main() {
	int d, m, a;
	
	cin >> d >> m >> a;
	
	string dia = dia_de_la_setmana(d, m, a);
	
	cout << "La data " << d << "/" << m << "/" << a << " és " << dia << endl;
}
