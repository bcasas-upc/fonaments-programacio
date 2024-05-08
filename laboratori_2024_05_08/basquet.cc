#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

struct Jugador {
    string nom;
    int salari;
    int punts;
};

typedef vector<Jugador> Jugadors;

// Llegeix el nom, el salari i els punts d'un jugador de l'entrada estandar,
// crea el jugador amb aquestes dades i el retorna.
Jugador llegirJugador() {
    Jugador j;
    cin >> j.nom >> j.salari >> j.punts;
    return j;
}

// Retorna cert sii el jugador que és rep com a paràmetre té un nombre de punts
// dins de l'interval [p1,p2].
bool pertanyAInterval(const Jugador &jugador, int p1, int p2) {
    return p1 <= jugador.punts and jugador.punts <= p2;
}

int main() {
    int n;
    cin >> n;

    Jugadors jugadors(n);

    for (int i = 0; i < n; i++) {
        jugadors[i] = llegirJugador();
    }

    int m, p1, p2;
    cin >> m;

    vector<string> noms;

    for (int j = 0; j < m; j++) {
        cin >> p1 >> p2;

        int suma_salaris = 0;

        // per treure el 10
        // si ja he trobat un, segueixo mirant, i a la que trobi un jugador fora
        // de l'interval he de deixar de buscar. Per tant, cal un while enlloc
        // d'aquest for
        for (int i = 0; i < n; i++) {
            bool hi_pertany = pertanyAInterval(jugadors[i], p1, p2);
            if (hi_pertany) {
                suma_salaris += jugadors[i].salari;
                noms.push_back(jugadors[i].nom);
            }
        }

        cout << suma_salaris;
        int quants_noms = noms.size();
        for (int k = 0; k < quants_noms; k++) {
            cout << ' ' << noms[k];
        }
        cout << endl;

        noms.clear();
    }
}
