#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll K;

void solve() {
  ll N = S.size();
  ll res = 0;
  if (K == 1) {
    ll cnt = 0;
    for (int i = 0; i < N - 1; ++i) {
      if (S[i] == S[i + 1]) {
        ++cnt;
      } else {
        res += (cnt + 1) / 2;
        cnt = 0;
      }
    }
    res += (cnt + 1) / 2;
  } else {
    S += S;
    ll cnt = 0;
    ll sum1 = 0;
    for (int i = 0; i < N - 1; ++i) {
      if (S[i] == S[i + 1]) {
        ++cnt;
      } else {
        sum1 += (cnt + 1) / 2;
        cnt = 0;
      }
    }
    bool same = cnt + 1 == N;
    sum1 += (cnt + 1) / 2;
    ll sum2 = 0;
    cnt = 0;
    for (int i = 0; i < N * 2 - 1; ++i) {
      if (S[i] == S[i + 1]) {
        ++cnt;
      } else {
        sum2 += (cnt + 1) / 2;
        cnt = 0;
      }
    }
    sum2 += (cnt + 1) / 2;
    if (same) {
      res = sum2 * (K / 2) + sum1 * (K % 2);
    } else {
      res = (sum2 - sum1) * (K - 1) + sum1;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S >> K;
  solve();
}