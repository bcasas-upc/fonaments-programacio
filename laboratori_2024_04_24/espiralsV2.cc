#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Matriu;

void esquerra(Matriu& m, int& x, int& y, int d) {
    for (; d > 1; d--) {
        y = y - 1;
        m[x][y] = 'X';
    }
}

void dreta(Matriu& m, int& x, int& y, int d) {
    for (; d > 1; d--) {
        y = y + 1;
        m[x][y] = 'X';
    }
}

void amunt(Matriu& m, int& x, int& y, int d) {
    for (; d > 1; d--) {
        x = x - 1;
        m[x][y] = 'X';
    }
}

void abaix(Matriu& m, int& x, int& y, int d) {
    for (; d > 1; d--) {
        x = x + 1;
        m[x][y] = 'X';
    }
}

int main() {
    int n, n_menys_u, i, j, d, x, y;
    while (cin >> n and n > 0) {

        Matriu m(n, vector<char>(n));

        // omplo la matriu de punts, menys la darrera fila i la darrera columna que són creus
        n_menys_u = n - 1;
        for (i = 0; i < n_menys_u; i++) {
            for (j = 0; j < n_menys_u; j++) {
                m[i][j] = '.';
            }
            // darrera columna de creus
            m[i][n_menys_u] = 'X';

            // darrera fila de creus
            m[n_menys_u][i] = 'X';
        }
        m[n_menys_u][n_menys_u] = 'X';

		// començo a pintar Xs a la part superior dreta
        x = 0;
        y = n_menys_u;

        d = n;
        while (d >= 2) {
            esquerra(m, x, y, --d);
            abaix(m, x, y, --d);
            dreta(m, x, y, --d);
            amunt(m, x, y, --d);
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << m[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
