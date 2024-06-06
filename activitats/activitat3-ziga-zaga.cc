#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matriu;

// Comprova si la matriu és estrictament creixent
// Pre: f és el nombre de files, c de columnes i m és la matriu
// Post: un bool que indica si és estrictament creixent o no
bool es_estrictament_creixent(int f, int c, const Matriu& m) {
    bool creixent = true;
    int anterior;
    int i, j;

    j = 0;  // recorro per columnes, no per files
    while (j < c and creixent) {
        //Inv: creixent indica si la matriu és estrictament creixent
        if (j == 0) {            // primera columna
            anterior = m[0][0];  // cas especial, primer element!

            i = 1;  // començo pel segon element i baig de dalt a baix
            while (i < f and creixent) {
                if (m[i][j] <= anterior) {
                    creixent = false;
                } else {
                    anterior = m[i][j];
                }
                ++i;
            }
        } else if (j % 2 == 0) {  // columna parell
            i = 0;                // de dalt a baix
            while (i < f and creixent) {
                if (m[i][j] <= anterior) {
                    creixent = false;
                } else {
                    anterior = m[i][j];
                }
                ++i;
            }
        } else {        // columna senar
            i = f - 1;  // de baix a dalt
            while (i >= 0 and creixent) {
                if (m[i][j] <= anterior) {
                    creixent = false;
                } else {
                    anterior = m[i][j];
                }
                --i;
            }
        }
        ++j;
    }

    return creixent;
}

int main() {
    int f, c;
    int n = 1;
    while (cin >> f >> c) {
        vector<vector<int>> m(f, vector<int>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> m[i][j];
            }
        }

        cout << "matriu " << n << ": ";
        if (es_estrictament_creixent(f, c, m)) {
            cout << "si";
        } else {
            cout << "no";
        }
        cout << endl;
        ++n;
    }
    return 0;
}