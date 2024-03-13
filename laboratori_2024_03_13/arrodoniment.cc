#include <iostream>

using namespace std;

double distancia(double a, double b) {
	double d = a - b;
	if( d < 0) {
		d = -d;
	}
	return d;
}

void arrodoniment(double d) {
	
	int n = (int) d;
	
	//cout << "La part entera de " << d << " és " << n << endl;
	
	int inf, sup;
	
	if (n < d) {
		inf = n;
		sup = n + 1;
	}	else if (n == d) {
		inf = n;
		sup = n;
	} else {
		//n > d
		sup = n;
		inf = n - 1;
	}
	
	
	int proper;
	
	double distancia_inf = distancia(d, inf); // la distancia ha de ser un valor positiu!!
	double distancia_sup = distancia(d, sup); 
	
	if(distancia_inf < distancia_sup) {
		proper = inf;
	} else {
		proper = sup;
	}
	
	cout << inf << " " << sup << " " << proper << endl;
}

int main() {

	double d;
	cin >> d;
	
	arrodoniment(d);
}
