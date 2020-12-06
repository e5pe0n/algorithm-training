#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
map<ll, ll> cnt;

void solve() {
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  ll res = 0;
  for (auto c : cnt) {
    res += c.second * (c.second - 1) / 2;
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld\n", res - (cnt[A[i]] - 1));
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}