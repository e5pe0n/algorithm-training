#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;

ll N;
ll A[MAX_N], B[MAX_N], C[MAX_N];
ll CA[MAX_N + 1];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> C[i];
  }

  for (ll i = 0; i < N; ++i) {
    ++CA[A[i]];
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += CA[B[C[i] - 1]];
  }
  cout << res << endl;
}