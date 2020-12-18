#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll X[5];

void solve() {
  ll min_x = *min_element(X, X + 5);
  ll res = 5 + (N - 1) / min_x;
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < 5; ++i) {
    cin >> X[i];
  }
  solve();
}