#include <bits/stdc++.h>
#define MAX_M 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_M], B[MAX_M];

void solve() {
  map<ll, ll> C;
  for (ll i = 0; i < M; ++i) {
    ++C[A[i]];
    ++C[B[i]];
  }
  for (auto p : C) {
    if (p.second % 2 != 0) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}