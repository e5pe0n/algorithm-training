#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll A[MAX_N];

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    A[i] = N - 1 - i;
  }
  for (ll i = 0; i < M; ++i) {
    ll a;
    cin >> a;
    A[a - 1] = N + i;
  }
  vector<pll> V;
  for (ll i = 0; i < N; ++i) {
    V.push_back({A[i], i});
  }
  sort(V.begin(), V.end());
  for (ll i = N - 1; i >= 0; --i) {
    printf("%lld\n", V[i].second + 1);
  }
}