#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

void solve() {
  int N = S.size();
  vector<ll> V(N + 1);
  for (int i = 0; i < N; ++i) {
    if (S[i] == '<') {
      V[i + 1] = V[i] + 1;
    }
  }
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == '>') {
      V[i] = max(V[i + 1] + 1, V[i]);
    }
  }
  ll res = 0;
  for (int i = 0; i <= N; ++i) {
    res += V[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S;
  solve();
}