#include <iostream>
#include <vector>
using namespace std;

vector<double> fusio(const vector<double>& v1, const vector<double>& v2) {
	
	int i = 0, j = 0; //posicions del v1 i v2
	bool seguim_fussionant = true;
	
	int v1_size = v1.size();
	int v2_size = v2.size();
	
	double v1_element, v2_element; //guardo l'element actual de v1 i v2
	
	vector<double> resultat; //creo el vector que retornaré amb tots els elements
	
	while(seguim_fussionant) {
		
		if(i == v1_size) {
			seguim_fussionant = false;
			
			//fico tots els que queden de v2 al resultat
			for( ; j < v2_size; j++) {
				v2_element = v2[j];
				resultat.push_back(v2_element);
			}
		
		} else if (j == v2_size) {
			seguim_fussionant = false;
			
			//fico tots els que queden de v1 al resultat
			while(i < v1_size) {
				v1_element = v1[i];
				resultat.push_back(v1_element);
				i++;
			}
			
		} else {
			v1_element = v1[i];
			v2_element = v2[j];
			
			if(v1_element < v2_element) {
				//guardo l'element de v1 i incremento la i
				resultat.push_back(v1_element);
				i = i + 1;
			} else if (v2_element < v1_element) {
				//guardo l'element de v2 i incremento la j
				resultat.push_back(v2_element);
				j = j + 1;
			} else {
				//són iguals... els guardo els dos i incremento i & j
				resultat.push_back(v1_element);
				i = i + 1;
				
				resultat.push_back(v2_element);
				j = j + 1;
			}
		}
	}
	
	return resultat;
}

int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(1);

    int n1;
    while (cin >> n1) {
        vector<double> V1(n1);
        for (int i = 0; i < n1; ++i)
            cin >> V1[i];
        int n2;
        cin >> n2;
        vector<double> V2(n2);
        for (int i = 0; i < n2; ++i)
            cin >> V2[i];

        vector<double> res = fusio(V1, V2);
        int n3 = res.size();
        cout << n3 << endl;
        for (int i = 0; i < n3; ++i)
            cout << " " << res[i];
        cout << endl
             << endl;
    }
    return 0;
}
