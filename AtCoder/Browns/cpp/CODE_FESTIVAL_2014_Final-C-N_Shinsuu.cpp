#include <bits/stdc++.h>
#define MAX_K 10000
using namespace std;
typedef long long ll;

ll A;

int main() {
  cin >> A;
  for (ll k = 10; k <= MAX_K; ++k) {
    string sk = to_string(k);
    ll N = sk.size();
    ll t = 0;
    for (ll i = 0; i < N; ++i) {
      t += (sk[N - i - 1] - '0') * (ll)pow(k, i);
    }
    if (t == A) {
      printf("%lld\n", k);
      return 0;
    }
  }
  puts("-1");
}