#include <iostream>
using namespace std;
typedef long long ll;

ll com(ll n, ll k) {
  if (n < 0 || k < 0 || n < k) {
    return 0;
  }
  if (k == 0) {
    return 1;
  }
  ll x = 1;
  for (ll i = n; i > n - k; --i) { // 分子
    x *= i;
  }
  ll y = 1;
  for (ll i = k; i > 0; --i) { // 分母
    y *= i;
  }
  return x / y;
}

int main() {
  cout << com(5, 0) << endl; // 1
  cout << com(5, 2) << endl; // 10
}