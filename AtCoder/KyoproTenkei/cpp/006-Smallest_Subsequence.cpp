#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
ll N, K;
string S;
ll nxts[MAX_N + 1][26];

int main() {
  cin >> N >> K >> S;

  for (ll i = 0; i < 26; ++i)
    nxts[S.size()][i] = S.size();
  for (ll i = S.size() - 1; i >= 0; --i) {
    for (ll j = 0; j < 26; ++j) {
      if (S[i] - 'a' == j)
        nxts[i][j] = i;
      else
        nxts[i][j] = nxts[i + 1][j];
    }
  }

  string res;
  ll curr = 0;
  for (ll i = 0; i < K; ++i) {
    for (ll j = 0; j < 26; ++j) {
      ll nxt = nxts[curr][j];
      ll remain = (S.size() - nxt - 1) + (i + 1);
      if (remain >= K) {
        res += j + 'a';
        curr = nxt + 1;
        break;
      }
    }
  }

  puts(res.c_str());
}