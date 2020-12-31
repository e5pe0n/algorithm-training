#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
typedef long long ll;

ll N;
ll C[MAX_N], S[MAX_N], F[MAX_N];

void solve() {
  for (int i = 0; i < N; ++i) {
    ll t = 0;
    for (int j = i; j < N - 1; ++j) {
      if (t <= S[j]) {
        t = S[j] + C[j];
      } else {
        t = S[j] + ((t - S[j]) + F[j] - 1) / F[j] * F[j] + C[j];
      }
    }
    printf("%lld\n", t);
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    cin >> C[i] >> S[i] >> F[i];
  }
  solve();
}