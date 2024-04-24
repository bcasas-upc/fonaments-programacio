#include <iostream>
#include <vector>

using namespace std;

struct Cotxe {
    string nom;
    int distancia;
    int preu;
};

typedef vector<Cotxe> Cotxes;

// Llegeix el nom, la distància i el preu d'un cotxe de l'entrada estandar,
// crea el cotxe amb aquestes dades i el retorna.
Cotxe llegirCotxe() {
	Cotxe c;
	cin >> c.nom;
	cin >> c.distancia;
	cin >> c.preu;
	
	return c;
}

// Retorna cert sii el cotxe que és rep com a paràmetre té una distància
// dins de l'interval [p1,p2].
bool pertanyAInterval(const Cotxe &cotxe, int p1, int p2) {
	return p1 <= cotxe.distancia and cotxe.distancia <= p2;
}

int buscarCotxes(const Cotxes& cotxes, int n, Cotxes& cotxes_seleccionats, int p1, int p2) {
	int j = 0;
	bool continua_cercant = true;
	bool trobat_un = false;
	int preu = 0;
	
	// es podria optimitzar mes fent servir un algoritme de cerca d'un element en una llista ordenada,
	// com per exemple: https://es.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
	while(continua_cercant) {
		if(pertanyAInterval(cotxes[j], p1, p2)) {
			cotxes_seleccionats.push_back(cotxes[j]);
			preu += cotxes[j].preu;
			trobat_un = true;
		} else if(trobat_un) {
			//aquest no hi pertany i sé que els següents tampoc, paro de buscar
			continua_cercant = false;
		}
	
		j++;
		if (j == n) {
			continua_cercant = false;
		}
	}

	return preu;
}

int main() {
	int n, m, p1, p2;
	
	cin >> n;
	Cotxes cotxes(n);
	for(int i=0;i<n;i++) {
		cotxes[i] = llegirCotxe();
	}
	
	cin >> m;
	Cotxes cotxes_seleccionats;
	int preu, l;

	for(int i=0;i<m;i++) {
		cin >> p1 >> p2;
		
		preu = buscarCotxes(cotxes, n, cotxes_seleccionats, p1, p2);
		
		cout << preu;
		
		//mostro els cotxes en ordre invers
		l = cotxes_seleccionats.size();
		for(int j=l-1;j>=0;j--) {
			cout << ' ' << cotxes_seleccionats[j].nom;
		}
		cout << endl;
		
		// resetejo aquestes variables reutilitzables
		cotxes_seleccionats.clear();
		preu = 0;
	}
}
