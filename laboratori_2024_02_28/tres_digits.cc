#include <iostream>

using namespace std;


bool tres_digits_seguits_iguals_recursiu(int n, int b, int digit_anterior, int repeticions) {
  bool en_portem_tres = false;

  int digit_actual = n % b;
  if (digit_actual == digit_anterior) {
    repeticions++;
  } else {
    repeticions = 1; //tornam a iniciar el contador pq són diferents
  }

  if (repeticions >= 3) {
    en_portem_tres = true;
  } else if (n < b) {
    //hem arribat al final i no n'hi ha tres ;(
    en_portem_tres = false;
  } else {
    n = n / b;
    en_portem_tres = tres_digits_seguits_iguals_recursiu(n, b, digit_actual, repeticions);
  }
    
  return en_portem_tres;
}

bool tres_digits_seguits_iguals(int n, int b) {
  return tres_digits_seguits_iguals_recursiu(n, b, -1, 0);
}

int main() {
  int n, b;
  while (cin >> n >> b) {
    cout << n << ' ' << b << ' ' << tres_digits_seguits_iguals(n, b) << endl;
  }
}
