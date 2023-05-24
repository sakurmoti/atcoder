#include <bits/stdc++.h>
using namespace std;

int main() {
  int p,price,N;
  string text;
  cin >> p;

  // パターン1
  if (p == 1) {
    cin >> price;
    cin >> N;
    cout << price * N << endl;
  }

  // パターン2
  if (p == 2) {
    cin >> text >> price >> N;
    cout << text << "!" << endl;
    cout << price * N << endl;
  }

}
