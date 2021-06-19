#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 3 * 1e5;

ll N;
vector<ll> A(MAX_N);

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  map<ll, ll> C;
  for (ll i = 0; i < N; ++i) {
    ++C[A[i]];
  }
  vector<ll> V;
  for (auto [k, v] : C) {
    V.push_back(v);
  }
  ll M = V.size();
  vector<ll> S(M + 1);
  for (ll i = 0; i < M; ++i) {
    S[i + 1] = S[i] + V[i];
  }
  ll res = 0;
  for (ll i = 0; i < M; ++i) {
    res += V[i] * (S[M] - S[i + 1]);
  }
  printf("%lld\n", res);
}