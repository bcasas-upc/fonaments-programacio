#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Matriu;

void esquerra(Matriu& m, int& x, int& y, int d) {
    if (d >= 2) {
        for (int i = 1; i < d; i++) {
            y = y - 1;
            m[x][y] = 'X';
        }
    }
}

void dreta(Matriu& m, int& x, int& y, int d) {
    if (d >= 2) {
        for (int i = 1; i < d; i++) {
            y = y + 1;
            m[x][y] = 'X';
        }
    }
}

void amunt(Matriu& m, int& x, int& y, int d) {
    if (d >= 2) {
        for (int i = 1; i < d; i++) {
            x = x - 1;
            m[x][y] = 'X';
        }
    }
}

void abaix(Matriu& m, int& x, int& y, int d) {
    if (d >= 2) {
        for (int i = 1; i < d; i++) {
            x = x + 1;
            m[x][y] = 'X';
        }
    }
}

int main() {
    int n;
    while (cin >> n and n > 0) {

        Matriu m(n, vector<char>(n));

        // omplo la matriu de punts, menys la darrera fila, que són creus
        int n_menys_u = n - 1;
        for (int i = 0; i < n_menys_u; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = '.';
            }
        }

		// darrera fila de creus
        for (int j = 0; j < n; j++) {
            m[n_menys_u][j] = 'X';
        }

		// començo a pintar Xs a la part inferior dreta
        int x = n_menys_u;
        int y = n_menys_u;

        int d = n;
        while (d >= 2) {
            amunt(m, x, y, d);
            esquerra(m, x, y, d - 1);
            abaix(m, x, y, d - 2);
            dreta(m, x, y, d - 3);

            d = d - 4;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
