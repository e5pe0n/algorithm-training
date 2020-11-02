#include <fstream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n;

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ifstream ifs("../testset/carmichael_numbers/test2.txt");
  ifs >> n;
  for (ll i = 2; i < n; ++i) {
    if (mod_pow(i, n, n) != i) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}