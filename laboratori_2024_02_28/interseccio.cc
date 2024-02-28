#include <iostream>
#include <vector>

using namespace std;

vector<double> interseccio(const vector<double>& v1, const vector<double>& v2) {
	
	vector<double> comuns;
	
	int size_v1 = v1.size();
	int size_v2 = v2.size();
	int size_comuns; // com aquest vector va creixent, la calculo quan ho necessito
	
	double e1; //element del v1
	double e2; //element del v2
	
	int j = 0;
	for(int i=0;i<size_v1;i++) {
		e1 = v1[i];
		
		//recorro v2, si el trobo, el fico a comuns
		bool segueixo_mirant_v2 = true;
	
		while(segueixo_mirant_v2) {
			if(j < size_v2) {
				e2 = v2[j];
				if(e2 == e1) {
					//genial, són iguals, ara comprovo que no l'he ficat ja
					size_comuns = comuns.size();
					if (size_comuns > 0) {
						if (e1 != comuns[size_comuns - 1]) {
							// comprovo si és igual al darrer element ficat a comuns, si no ho és, el fico
							comuns.push_back(e1);
						}					
					} else {
						comuns.push_back(e1);
					}

					segueixo_mirant_v2 = false;
				} else if (e2 > e1) {
					//paro de mirar, no el trobaré MAIIIII
					segueixo_mirant_v2 = false;
				} else {
					//he de seguir mirant ;(
					j++;
				}	
			} else {
				segueixo_mirant_v2 = false;
			}
		}
	}

	return comuns;
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

  vector<double> res = interseccio(V1, V2);
		
	int size = res.size();
	cout << "La intersecció és";
	for (int i=0;i<size;i++) {
		cout << " " << res[i];
	}
	cout << endl;
}


