#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll T[MAX_N + 1], X[MAX_N + 1], Y[MAX_N + 1];

void solve() {
  for (int i = 1; i <= N; ++i) {
    ll dt = T[i] - T[i - 1];
    ll dd = abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
    if (!(dt >= dd && dt % 2 == dd % 2)) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  cin >> N;
  T[0] = X[0] = Y[0] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> T[i] >> X[i] >> Y[i];
  }
  solve();
}