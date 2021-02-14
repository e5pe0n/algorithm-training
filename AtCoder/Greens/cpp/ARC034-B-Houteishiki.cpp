#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  string S = to_string(N);
  vector<ll> res;
  for (ll i = 1; i <= S.size() * 9; ++i) {
    ll x = N - i;
    if (x <= 0) continue;
    ll s = x;
    ll t = 0;
    while (s > 0) {
      t += s % 10;
      s /= 10;
    }
    if (t == i) res.push_back(x);
  }
  sort(res.begin(), res.end());
  printf("%ld\n", res.size());
  for (auto r : res) {
    printf("%lld\n", r);
  }
}