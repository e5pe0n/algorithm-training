#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll N;
string S;
map<char, ll> cnt;

void solve() {
  for (auto s : S) {
    ++cnt[s - 'a'];
  }
  ll res = 1;
  for (auto p : cnt) {
    res = res * (p.second + 1) % MOD;
  }
  printf("%lld\n", (res - 1 + MOD) % MOD);
}

int main() {
  cin >> N >> S;
  solve();
}