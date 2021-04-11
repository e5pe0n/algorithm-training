#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  vector<ll> V;
  for (ll i = 0; i < 10; ++i) {
    V.push_back(i);
  }
  ll cnt = 0;
  do {
    // for (auto v : V) {
    //   printf("%lld ", v);
    // }
    // puts("");
    ++cnt;
  } while (next_permutation(V.begin(), V.end()));
  printf("%lld\n", cnt);
}