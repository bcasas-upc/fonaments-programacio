#include <iostream>

using namespace std;

struct Temps {
    int hora, minut, segon;
};

void suma_un_segon(const Temps& t, Temps& r) {
    r.hora = t.hora;
    r.minut = t.minut;
    r.segon = t.segon + 1;

    if (r.segon >= 60) {
        // salt de minut
        r.minut++;
        r.segon = 0;

        if (r.minut >= 60) {
            // salt d'hora
            r.hora++;
            r.minut = 0;

            if (r.hora >= 24) {
                r.hora = 0;
            }
        }
    }
}

void resta_un_segon(const Temps& t, Temps& r) {
    r.hora = t.hora;
    r.minut = t.minut;
    r.segon = t.segon - 1;

    if (r.segon < 0) {
        // salt de minut
        r.minut--;
        r.segon = 59;

        if (r.minut < 0) {
            // salt d'hora
            r.hora--;
            r.minut = 59;

            if (r.hora < 0) {
                r.hora = 23;
            }
        }
    }
}

void un_segon(const Temps& t, Temps& t1, Temps& t2) {
    suma_un_segon(t, t1);
    resta_un_segon(t, t2);
}

void mostra(const Temps& t) {
    cout << t.hora << ' ' << t.minut << ' ' << t.segon << endl;
}

int main() {
    int hora, minut, segon;

    while (cin >> hora >> minut >> segon) {
        Temps t = {hora, minut, segon};

        Temps t1, t2;

        un_segon(t, t1, t2);

        mostra(t1);
        mostra(t2);
    }
}
