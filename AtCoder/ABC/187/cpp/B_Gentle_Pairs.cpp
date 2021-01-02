#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
typedef long long ll;

ll N;
ll X[MAX_N], Y[MAX_N];

void solve() {
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (abs(Y[j] - Y[i]) <= abs(X[j] - X[i])) { ++res; }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  solve();
}