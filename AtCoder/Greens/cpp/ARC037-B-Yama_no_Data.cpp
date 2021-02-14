#include <bits/stdc++.h>
#define MAX_N 300'000
using namespace std;
typedef long long ll;

ll N;
ll H[MAX_N + 2];

int main() {
  cin >> N;
  H[0] = 0;
  H[N + 1] = 0;
  for (ll i = 1; i <= N; ++i) {
    cin >> H[i];
  }
  vector<ll> T;
  for (ll i = 1; i <= N; ++i) {
    if (H[i - 1] < H[i] && H[i] > H[i + 1]) T.push_back(i);
  }
  ll res = 0;
  for (auto t : T) {
    ll s = t;
    ll u = t;
    while (s > 1 && H[s - 1] < H[s])
      --s;
    while (u < N && H[u + 1] < H[u])
      ++u;
    res = max(res, u - s + 1);
  }
  printf("%lld\n", res);
}