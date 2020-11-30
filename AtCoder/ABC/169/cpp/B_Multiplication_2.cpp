#include <bits/stdc++.h>
#define MAX_N 100'000
#define THRE 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  ll res = 1;
  sort(A, A + N);
  for (int i = 0; i < N; ++i) {
    if ((long double)res * A[i] <= THRE) {
      res *= A[i];
    } else {
      res = -1;
      break;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}