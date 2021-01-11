#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll K;

void solve() {
  ll N = S.size();
  for (ll i = 0; i < N; ++i) {
    ll t = (26 - (S[i] - 'a')) % 26;
    if (t <= K) {
      K -= t;
      S[i] = 'a';
    }
  }
  S[N - 1] = (S[N - 1] + (K % 26));
  printf("%s\n", S.c_str());
}

int main() {
  cin >> S >> K;
  solve();
}