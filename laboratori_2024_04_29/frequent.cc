#include <iostream>
#include <vector>

using namespace std;

// Llegeix un vector del cin
// Pre: n és la mida del vector i v el vector a omplir
// Post: retorna el vector v ple
void llegir_vector(int n, vector<int>& v) {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

// Comprova si la nova ratxa és millor que la ratxa màxima
// Pre: la ratxa màxima actual (valor i quantes), la ratxa candidata (valor i
// quantes) i l'inici de la nova ratxa (valor i quantes)
// Pro: actualitza la ratxa màxima (si s'escau) i la nova ratxa
void comprova_millor_ratxa(int& max_valor, int& max_quantes,
                           int& candidat_valor, int& candidat_quantes,
                           int proper_candidat_valor,
                           int proper_candidat_quantes) {
    // candidat_valor és més gran SEGUR que max_valor
    if (candidat_quantes >= max_quantes) {
        max_quantes = candidat_quantes;
        max_valor = candidat_valor;
    }
    candidat_valor = proper_candidat_valor;
    candidat_quantes = proper_candidat_quantes;
}

// Mostra el nombre que apareix més vegades
// Pre: vectors ordenats v1 i v2 de mida n1 i n2 respectivament
// Pro: mostra pel cout el nombre més comú i quantes vegades apareix
void mostra_frequent(int n1, vector<int>& v1, int n2, vector<int>& v2) {
    // posició dins dels vectors v1 i v2
    int p1 = 0, p2 = 0;

    // guarda els valors a les posicions p1 i p2
    int valor1, valor2;

    // valor màxim i quantes vegades apareix
    int max_valor = -1, max_quantes = -1;

    // valor que estic comprovant si serà el nou màxim o no
    int candidat_valor = -1, candidat_quantes = -1;

    while (p1 < n1 or p2 < n2) {
        if (p1 >= n1) {
            // recorro v2
            while (p2 < n2) {
                valor2 = v2[p2];
                if (valor2 == candidat_valor) {
                    candidat_quantes += 1;
                } else {
                    comprova_millor_ratxa(max_valor, max_quantes,
                                          candidat_valor, candidat_quantes,
                                          valor2, 1);
                }
                p2++;
            }
        } else if (p2 >= n2) {
            // recorro v1
            while (p1 < n1) {
                valor1 = v1[p1];
                if (valor1 == candidat_valor) {
                    candidat_quantes += 1;
                } else {
                    comprova_millor_ratxa(max_valor, max_quantes,
                                          candidat_valor, candidat_quantes,
                                          valor1, 1);
                }
                p1++;
            }
        } else {
            valor1 = v1[p1];
            valor2 = v2[p2];

            if (valor1 == valor2) {
                // incremento p1 i p2
                p1++;
                p2++;
                if (candidat_valor == valor1) {
                    // ok, he trobat dos mes, incremento comptador
                    candidat_quantes += 2;
                } else {
                    // s'ha acabat la ratxa moment de veure si és la millor
                    comprova_millor_ratxa(max_valor, max_quantes,
                                          candidat_valor, candidat_quantes,
                                          valor1, 2);
                }
            } else if (valor1 < valor2) {
                // incremento p1
                p1++;
                if (candidat_valor == valor1) {
                    // ok, he trobat un mes
                    candidat_quantes += 1;
                } else {
                    // s'ha acabat la ratxa moment de veure si és la millor
                    comprova_millor_ratxa(max_valor, max_quantes,
                                          candidat_valor, candidat_quantes,
                                          valor1, 1);
                }
            } else {  // valor2 < valor1
                // incremento p2
                p2++;
                if (candidat_valor == valor2) {
                    // ok, he trobat un mes
                    candidat_quantes += 1;
                } else {
                    // s'ha acabat la ratxa moment de veure si és la millor
                    comprova_millor_ratxa(max_valor, max_quantes,
                                          candidat_valor, candidat_quantes,
                                          valor2, 1);
                }
            }
        }
    }

    // comprovació final per si la ratxa del final és la bona
    comprova_millor_ratxa(max_valor, max_quantes, candidat_valor,
                          candidat_quantes, -1, -1);

    cout << max_valor << ' ' << max_quantes << endl;
}

int main() {
    int n1, n2;

    while (cin >> n1) {
        vector<int> v1(n1);
        llegir_vector(n1, v1);

        cin >> n2;
        vector<int> v2(n2);
        llegir_vector(n2, v2);

		mostra_frequent(n1, v1, n2, v2);
    }
}
