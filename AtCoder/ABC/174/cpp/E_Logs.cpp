#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_A 1'000'000'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];

void solve() {
  double ub = MAX_A;
  double lb = 0;
  for (int i = 0; i < 100; ++i) {
    double md = (ub + lb) / 2;
    ll t = 0;
    for (int j = 0; j < N; ++j) {
      t += (ll)ceil(A[j] / md) - 1;
    }
    if (t <= K) {
      ub = md;
    } else {
      lb = md;
    }
  }
  printf("%d\n", (int)ceil(ub));
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}