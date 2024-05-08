#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

struct Provincia {
    string nom;
    string capital;
    int habitants;
    int area;
    double pib;
};

struct Pais {
    string nom;
    string capital;
    vector<Provincia> provs;
};

typedef vector<Pais> Paisos;

// suma dels productes interiors bruts
// de totes les províncies amb densitat estrictament superior a d
// de tots els paisos en p que comencin per la lletra c.
double pib(const Paisos& p, char c, double d) {
    // 0 : creo una variable anomenada pib_total amb valor 0
    double pib_total = 0;
    // 1r: busco paisos que comencin per la lletra 'c' => FOR AMB UN IF DINS
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (p[i].nom[0] == c) {
            // 2n: d'aquests paisos, busco les provincies que tinguin densitat
            // superior a 'd' => FOR AMB UN IF DINS
            int np = p[i].provs.size();
            for (int j = 0; j < np; j++) {
                double h = p[i].provs[j].habitants;
                double a = p[i].provs[j].area;
                double densitat = h / a;

                if (densitat > d) {
                    // 3r: sumo el pib d'aquestes provincies a la variable
                    // pib_total
                    pib_total += p[i].provs[j].pib;
                }
            }
        }
    }

    return pib_total;
}

// suma de tots els habitants d’aquelles paisos en p
// que tinguin almenys 2 províncies amb producte interior brut inferior o igual
// a x.
int habitants(const Paisos& p, double x) {
    // 0: variable habitants_total = 0;
    // 1: for per tots els paisos
    // 2: for per totes les provincies de cada pais
    // 3: sumar quantes provincies de cada pais tenen pib <= x
    // 4: si la suma és major de 1, sumo els seus habitants a la variable total

    int habitants_total = 0;
    int num_provs_aptes;
    int habitants_pais;

    int n = p.size();
    for (int i = 0; i < n; i++) {
        // comptador de provincies amb pib <= x
        num_provs_aptes = 0;
        // habitants d'aquest pais en concret
        habitants_pais = 0;

        int np = p[i].provs.size();
        for (int j = 0; j < np; j++) {
            if (p[i].provs[j].pib <= x) {
                num_provs_aptes++;
            }
            // sumo els habitants de totes les provincies d'aquest pais
            habitants_pais += p[i].provs[j].habitants;
        }

        if (num_provs_aptes >= 2) {
            habitants_total += habitants_pais;
        }
    }

    return habitants_total;
}

int main() {
    int n;
    cin >> n;  // nombre de paisos
    Paisos p(n);
    for (int i = 0; i < n; ++i) {
        int np;
        // dades del pais
        cin >> p[i].nom >> p[i].capital >> np;

        // np és el nombre de provincies
        p[i].provs = vector<Provincia>(np);
        for (int j = 0; j < np; ++j) {
            // dades de la provincia
            cin >> p[i].provs[j].nom >> p[i].provs[j].capital >>
                p[i].provs[j].habitants >> p[i].provs[j].area >>
                p[i].provs[j].pib;
        }
    }
    cout << pib(p, 'A', 10) << endl;
    cout << pib(p, 'A', 20) << endl;
    cout << pib(p, 'A', 30) << endl;
    cout << pib(p, 'A', 40) << endl;
    cout << pib(p, 'E', 10) << endl;
    cout << pib(p, 'E', 20) << endl;
    cout << pib(p, 'E', 30) << endl;
    cout << pib(p, 'E', 40) << endl;
    cout << pib(p, 'C', 40) << endl;
    return 0;
}
