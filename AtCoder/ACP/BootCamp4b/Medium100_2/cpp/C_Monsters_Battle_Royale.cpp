#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  ll res = __gcd(A[0], A[1]);
  for (int i = 2; i < N; ++i) {
    res = __gcd(res, A[i]);
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