#include <iostream>
#include <vector>

using namespace std;

// funció auxiliar que comprova si puc afegir un element al vector revisant
// el darrer element ficat. És suficient pq el vector està ordenat i fico
// els elements en ordre
void fica_element_si_no_repetit(vector<double>& v, double e) {
	int size = v.size();
	
	if (size > 0) {
		if (e != v[size - 1]) {
			v.push_back(e);
		}
	} else {
		v.push_back(e);
	}
}

// retorna els elements de v1 que no es troben a v2, i sense repetits
vector<double> diferencia(const vector<double>& v1, const vector<double>& v2) {
	
	vector<double> diferents;
	
	int size_v1 = v1.size();
	int size_v2 = v2.size();
	
	double e1; //element del v1
	double e2; //element del v2

	int i = 0;
	int j = 0;
	bool continua_buscant = true;
	while (continua_buscant) {
		if (i >= size_v1) {
			// ja no cal buscar més
			continua_buscant = false;
		} else if (j >= size_v2) {
			//afegim tots els de v1 i acabem
			while( i < size_v1) {
				e1 = v1[i];
				fica_element_si_no_repetit(diferents, e1);
				i++;
			}
			continua_buscant = false;
		} else {
			e1 = v1[i];
			e2 = v2[j];

			if(e1 == e2) {
				//avanço els indexes fins a trobar un element diferent
				while (i < size_v1 && v1[i] == e1) i++;
				while (j < size_v2 && v2[j] == e2) j++;
			} else if (e1 < e2) {
				fica_element_si_no_repetit(diferents, e1);
				i++;
			} else { // e2 < e1
				j++;
			}
		}
	}

	return diferents;
}

int main()
{
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(4);

	cout << "Introdueix el primer vector, primer la mida i desprès els elements ordenats" << endl;
  int n1;
  cin >> n1;

  vector<double> V1(n1);
  for (int i = 0; i < n1; ++i)
      cin >> V1[i];
  int n2;
  
  cout << "Introdueix el segon vector, primer la mida i desprès els elements ordenats" << endl;
  cin >> n2;
  vector<double> V2(n2);
  for (int i = 0; i < n2; ++i)
      cin >> V2[i];

  vector<double> res = diferencia(V1, V2);
		
	int size = res.size();
	cout << "La diferencia és";
	for (int i=0;i<size;i++) {
		cout << " " << res[i];
	}
	cout << endl;
}


