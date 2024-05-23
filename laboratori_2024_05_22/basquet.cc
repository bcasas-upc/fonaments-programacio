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
        bool continuar = true;
        int trobats = 0;
        int i = 0;

        while (continuar) {
            if (i < n) {
                bool hi_pertany = pertanyAInterval(jugadors[i], p1, p2);
                if (hi_pertany) {
                    trobats++;
                    suma_salaris += jugadors[i].salari;
                    noms.push_back(jugadors[i].nom);
                } else {
                    if (trobats > 0) {
                        // el primer no desprès d'un si
                        continuar = false;
                    }
                }
                i++;
            } else {
                continuar = false;
            }
        }

        cout << suma_salaris;
        for (int k = 0; k < trobats; k++) {
            cout << ' ' << noms[k];
        }
        cout << endl;

        noms.clear();
    }
}
