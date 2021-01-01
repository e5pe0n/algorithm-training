#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];

void solve() {
  bool res = false;
  if (N == 1) {
    res = A[0] == K;
  } else {
    ll g = __gcd(A[0], A[1]);
    for (int i = 2; i < N; ++i) {
      g = __gcd(g, A[i]);
    }
    ll max_a = *max_element(A, A + N);
    res = max_a >= K && (max_a % K) % g == 0;
  }
  if (res) {
    puts("POSSIBLE");
  } else {
    puts("IMPOSSIBLE");
  }
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}