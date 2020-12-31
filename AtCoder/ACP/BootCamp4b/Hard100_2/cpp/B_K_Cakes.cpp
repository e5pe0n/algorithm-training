#include <bits/stdc++.h>
#define MAX_T 100
using namespace std;
typedef long long ll;

ll K, T;
ll A[MAX_T];

void solve() {
  sort(A, A + T);
  ll res = A[T - 1] - 1;
  for (int i = 0; i < T - 1; ++i) {
    res = max(0LL, res - A[i]);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> K >> T;
  for (int i = 0; i < T; ++i) {
    cin >> A[i];
  }
  solve();
}