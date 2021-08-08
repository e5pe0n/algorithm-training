#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 200'000;
ll N;
pll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    A[i] = {a, i + 1};
  }
  sort(A, A + N);
  printf("%lld\n", A[N - 2].second);
}