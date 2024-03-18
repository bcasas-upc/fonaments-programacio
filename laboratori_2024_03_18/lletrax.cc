#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int dim = 2*n;
	
	for(int i=0;i<=dim;i++) {
		for(int j=0;j<=dim;j++) {
			if (i == j || (i+j) == dim) {
				cout << 'X';
			}	else {
				cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}


