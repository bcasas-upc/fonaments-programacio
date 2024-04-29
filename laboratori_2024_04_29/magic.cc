#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matriu;

int main() {
    int n, d;
    bool repe;

    while (cin >> n) {
        Matriu m(n, vector<int>(n));
        vector<bool> numeros(n * n, false);  // s'inicialitza tot a false
        repe = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> d;
                if (numeros[d]) {
                    // repe!!!
                    repe = true;
                } else {
                    numeros[d] = true;
                }

                m[i][j] = d;
            }
        }

        if (repe) {
            // hi ha elements repetits, segur no és un quadrat màgic
            cout << "no" << endl;
        } else {
            // TODO: comprovar que totes les files, columnes i les dues
            // diagonals sumen el mateix
            cout << "potser" << endl;
        }
    }
}
