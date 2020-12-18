#include <bits/stdc++.h>
#define MAX_N 10'000'000
using namespace std;
typedef long long ll;

ll N;

void solve() {
  ll lb = 0;
  ll ub = MAX_N + 1;
  while (ub - lb > 1) {
    ll md = (ub + lb) / 2;
    if (md * (md + 1) / 2 >= N) {
      ub = md;
    } else {
      lb = md;
    }
  }
  for (int i = 1; i <= ub; ++i) {
    if (i == ub * (ub + 1) / 2 - N) {
      continue;
    }
    printf("%d\n", i);
  }
}

int main() {
  cin >> N;
  solve();
}