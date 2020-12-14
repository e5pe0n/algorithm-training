#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  map<ll, ll> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  ll sum = 0;
  for (auto p : cnt) {
    sum += p.second * (p.second - 1) / 2;
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld\n", sum - (cnt[A[i]] - 1));
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}