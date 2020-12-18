#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;
ll A[MAX_N], B[MAX_N];

void solve() {
  map<ll, ll> C;
  for (int i = 0; i < N; ++i) {
    C[A[i]] += B[i];
  }
  ll cnt = 0;
  for (auto p : C) {
    cnt += p.second;
    if (cnt >= K) {
      printf("%lld\n", p.first);
      return;
    }
  }
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}