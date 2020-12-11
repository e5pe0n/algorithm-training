#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, K;
ll H[MAX_N];

void solve() {
  sort(H, H + N);
  ll res = 0;
  for (int i = 0; i < max(0LL, N - K); ++i) {
    res += H[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  solve();
}