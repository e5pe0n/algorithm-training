#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
map<ll, ll> cnt1;
map<ll, ll> cnt2;

void solve() {
  ll max_a = 0;
  for (int i = 0; i < N; ++i) {
    ++cnt1[i + A[i]];
    ++cnt2[i - A[i]];
    max_a = max(max_a, A[i]);
  }
  ll res = 0;
  for (int x = 1; x < N; ++x) {
    res += cnt1[x] * cnt2[x];
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