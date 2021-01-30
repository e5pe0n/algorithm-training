#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N, S, D;
ll X[MAX_N], Y[MAX_N];

void solve() {
  bool f = false;
  for (ll i = 0; i < N; ++i) {
    if (X[i] < S && Y[i] > D) f = true;
  }
  if (f)
    puts("Yes");
  else
    puts("No");
}

int main() {
  cin >> N >> S >> D;
  for (ll i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  solve();
}