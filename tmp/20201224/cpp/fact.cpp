#include <iostream>
using namespace std;
typedef long long ll;

ll fact(ll n) {
  ll res = 1;
  for (ll i = n; i > 0; --i) {
    res *= i;
  }
  return res;
}

int main() {
  cout << fact(0) << endl;
  cout << fact(5) << endl;
  cout << fact(19) << endl;
  cout << fact(20) << endl;
  cout << fact(21) << endl;
}