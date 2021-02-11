#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, X, Y;

int main() {
  cin >> N >> M >> X >> Y;
  vector<pll> VA;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    VA.push_back({A + X, A});
  }
  vector<pll> VB;
  for (ll i = 0; i < M; ++i) {
    ll B;
    cin >> B;
    VB.push_back({B + Y, B});
  }
  sort(VA.begin(), VA.end());
  sort(VB.begin(), VB.end());
  ll t = 0;
  ll idx_a = 0;
  ll idx_b = 0;
  ll n = 0;
  while (true) {
    if (n % 2 == 0) {
      if (idx_a >= N) break;
      if (t <= VA[idx_a].second) {
        t = VA[idx_a].first;
        ++n;
      }
      ++idx_a;
    } else {
      if (idx_b >= M) break;
      if (t <= VB[idx_b].second) {
        t = VB[idx_b].first;
        ++n;
      }
      ++idx_b;
    }
  }
  printf("%lld\n", n / 2);
}