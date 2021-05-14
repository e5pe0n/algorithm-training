// WA: after_contest_03.txt
// I do not know what is wrong
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 200;
ll N;
vector<ll> A;
vector<vector<ll>> M{MAX_N + 1};

void show(const vector<ll> &B, const vector<ll> &C) {
  puts("Yes");
  printf("%ld ", B.size());
  for (ll i = 0; i < B.size(); ++i) {
    printf("%lld%c", B[i] + 1, i == B.size() - 1 ? '\n' : ' ');
  }
  printf("%ld ", C.size());
  for (ll i = 0; i < C.size(); ++i) {
    printf("%lld%c", C[i] + 1, i == C.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  cin >> N;
  A = vector<ll>(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    ll j = A[i] % 200;
    if (M[j].size()) {
      show(M[j], {i});
      return 0;
    }
    M[j].push_back(i);
  }
  for (ll i = 1; i < N; ++i) {
    for (ll j = 0; j < MAX_N; ++j) {
      if (M[j].size() != i) continue;
      for (ll k = 0; k < N; ++k) {
        if (M[j].back() >= k) continue;
        ll dst = (j + A[k] % 200) % 200;
        if (M[dst].size()) {
          M[j].push_back(k);
          show(M[dst], M[j]);
          return 0;
        }
        M[dst] = M[j];
        M[dst].push_back(k);
      }
    }
  }
  puts("No");
}