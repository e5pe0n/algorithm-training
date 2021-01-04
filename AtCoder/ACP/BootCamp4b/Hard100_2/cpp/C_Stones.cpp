#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

void solve() {
  ll w = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '.') ++w;
  }
  ll b = 0;
  ll res = w;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '#')
      ++b;
    else
      --w;
    res = min(res, b + w);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> S;
  solve();
}