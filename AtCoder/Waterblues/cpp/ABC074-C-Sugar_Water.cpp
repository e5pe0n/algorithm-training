#include <bits/stdc++.h>
#define MAX_F 3000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll A, B, C, D, E, F;

int main() {
  cin >> A >> B >> C >> D >> E >> F;
  vector<pll> V;
  for (ll a = 0; a <= F; a += 100 * A) {
    for (ll b = 0; b <= F; b += 100 * B) {
      for (ll c = 0; c <= F; c += C) {
        for (ll d = 0; d <= F; d += D) {
          ll water = a + b;
          ll sugar = c + d;
          if (water + sugar > F || water / 100 * E < sugar) continue;
          V.push_back({water, sugar});
        }
      }
    }
  }
  auto cmp = [](const pll &p1, const pll &p2) {
    return 100 * p1.second * (p2.first + p2.second)
           < 100 * p2.second * (p1.first + p1.second);
  };
  sort(V.begin(), V.end(), cmp);
  auto p = --V.end();
  printf("%lld %lld\n", p->first + p->second, p->second);
}