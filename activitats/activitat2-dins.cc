#include <iostream>

using namespace std;

// Comprova si la paraula a és dins de la paraula b començant a la
// posició pos_b de b
// Pre: a i b són les paraules, size_a és la mida de la paraula a i 
//      pos_b la posició de b on començar a comprovar
// Post: un bool que indica si a és dins de b o no a la posició indicada
bool es_dins_at(const string& a, int size_a, const string& b, int pos_b) {
    bool es_dins = true;
    int i = 0;
    while(i < size_a and es_dins) {
        //Inv: es_dins indica si la paraula a és dins de la paraula b
        if(a[i] != b[i + pos_b]) {
            es_dins = false;
        }
        i++;
    }
    return es_dins;
}

// Comprova si la paraula a és dins de la paraula b
// Pre: a i b són les paraules
// Post: un bool que indica si a és dins de b
bool es_dins(const string& a, const string& b) {
    bool es_dins = false;
    int size_a = a.size();
    int size_b = b.size();

    int pos_b = 0;
    int darrer_pos_b = size_b - size_a;
    while(pos_b <= darrer_pos_b and not es_dins) {
        //Inv: es_dins indica si la paraula a és dins de la paraula b
        es_dins = es_dins_at(a, size_a, b, pos_b);
        pos_b++;
    }

    return es_dins;
}

int main() {

    string a, b;

    while(cin >> a) {
        cin >> b;

        if(es_dins(a, b)) {
            cout << '+' << endl;
        } else {
            cout << '-' << endl;
        }
    }
}
