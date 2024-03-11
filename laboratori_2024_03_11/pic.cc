#include <iostream>

using namespace std;

int main() {
	
	bool segueix_llegint = true;
	int n_actual = 0;
	int n_anterior = 0;
	int n_anterior_del_anterior = 0;
	
	bool he_trobat_un_pic = false;
	int maxim_pic = 0;
	int maxim_pic_posicio = 0;
	
	int posicio_actual = 0;
	
	while (segueix_llegint) {
	
		n_anterior_del_anterior = n_anterior;
		n_anterior = n_actual;
	
		cin >> n_actual;
		posicio_actual = posicio_actual + 1;
		
		if( n_actual == -10000) {
			segueix_llegint = false;
		}	else {
			if (posicio_actual >= 3) {
				//comprovo si la posició anterior és un pic
				//cout << "Comprovo pic: " << n_anterior_del_anterior << " < " << n_anterior << " > " << n_actual << endl;
				
				if ( n_anterior_del_anterior < n_anterior && n_actual < n_anterior) {
					//n_anterior és un pic!!!
					//cout << "És un pic: " << n_anterior << " a la posició " << (posicio_actual - 1) << endl;
					
					if(he_trobat_un_pic) {
						//miro si és mes gran que el que he trobat
						if(n_anterior > maxim_pic) {
							maxim_pic = n_anterior;
							maxim_pic_posicio = posicio_actual - 1;
						}			
					} else {
						//el meu primer pic
						maxim_pic = n_anterior;
						maxim_pic_posicio = posicio_actual - 1;
						he_trobat_un_pic = true;
					}
				}
			}
		}	
	}
	
	if(he_trobat_un_pic) {
		cout << maxim_pic_posicio << " " << maxim_pic << endl;
	} else {
		cout << "NO" << endl;
	}
}
