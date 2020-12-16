#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
string S[MAX_N];

void solve() {
  map<string, ll> cnt;
  for (int i = 0; i < N; ++i) {
    sort(S[i].begin(), S[i].end());
    ++cnt[S[i]];
  }
  ll res = 0;
  for (auto p : cnt) {
    res += p.second * (p.second - 1) / 2;
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}