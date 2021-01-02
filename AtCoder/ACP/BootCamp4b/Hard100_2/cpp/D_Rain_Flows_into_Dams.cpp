#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    res += i % 2 == 0 ? A[i] : -A[i];
  }
  printf("%lld ", res);
  for (int i = 1; i < N; ++i) {
    res = -res + A[i - 1] * 2;
    printf("%lld%c", res, i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}