#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N], B[MAX_N];

void solve() {
  ll res = 0;
  for (int i = N - 1; i >= 0; --i) {
    res += (B[i] - (A[i] + res) % B[i]) % B[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}