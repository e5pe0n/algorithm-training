#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;
ll fs[3];

int main() {
  cin >> A >> B;
  fs[A - 1] = fs[B - 1] = true;
  for (ll i = 0; i < 3; ++i) {
    if (!fs[i]) {
      printf("%lld\n", i + 1);
      return 0;
    }
  }
}