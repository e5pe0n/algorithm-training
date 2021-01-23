#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
typedef long long ll;

ll N, X;
ll V[MAX_N], P[MAX_N];

void solve() {
  X *= 100;
  for (ll i = 0; i < N; ++i) {
    X -= V[i] * P[i];
    if (X < 0) {
      printf("%lld\n", i + 1);
      return;
    }
  }
  puts("-1");
}

int main() {
  cin >> N >> X;
  for (ll i = 0; i < N; ++i) {
    cin >> V[i] >> P[i];
  }
  solve();
}