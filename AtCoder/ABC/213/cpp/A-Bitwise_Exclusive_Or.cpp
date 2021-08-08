#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B;

int main() {
  cin >> A >> B;
  for (ll C = 0; C <= 255; ++C) {
    if ((A ^ C) == B) {
      printf("%lld\n", C);
      return 0;
    }
  }
}