#include <iostream>

using namespace std;

int main() {
	
	int n;
	char guanyador = '=';
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		
		for(int j=0; j < 10; j++) {
			string paraula;
			cin >> paraula;
			
			/*
			La idea és guardar el darrer caràcter de la paraula anterior i comprovar
			si la paraula actual comença o no per aquest caràcter
			
			Per saber qui perd, miro la j... si la j és parell, es una paraula del jugador A, si és senar,
			és del jugador B.
			
			S'ha de vigilar pq quan perd un, ja no cal seguir mirant les paraules. És a dir, sols comprovo 
			si guanyador != '='...
			*/
		}
		cout << guanyador << endl;
	}
}










