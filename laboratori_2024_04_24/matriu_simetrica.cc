#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

// Comprova si una matriu és simètrica
// Pre: m és una matriu quadrada d'enters
// Post: returna un booleà que val true si és quadrada
bool es_simetrica(const Matriu& m) {

	int n = m.size();
	bool es_simetrica = true;
	
	int i = 0;
	int j;
	while(i<n and es_simetrica) {
	
		//Inv: es_simetrica indica si la matriu és simètrica o no
		
		j = i + 1; //optimitzo per no mirar la diagonal principal i tan sols el triangle superior
		while(j<n and es_simetrica) {

			//Inv: es_simetrica indica si la matriu és simètrica o no
		
			if(m[i][j] != m[j][i]) {
				es_simetrica = false;
			}
			j++;
		}
		i++;
	}

	return es_simetrica;
}

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> M(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> M[i][j];

        cout << es_simetrica(M) << endl;
    }
    return 0;
}
