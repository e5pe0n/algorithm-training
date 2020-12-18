#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K;

void solve() {
  if (K % N == 0 || K % M == 0) {
    puts("Yes");
    return;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      ll n = (N - (i + 1)) * (j + 1) + (M - (j + 1)) * (i + 1);
      if (K == n) {
        puts("Yes");
        return;
      }
    }
  }
  puts("No");
}

int main() {
  cin >> N >> M >> K;
  solve();
}