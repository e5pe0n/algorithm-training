#include <bits/stdc++.h>
#define MOD 2019
#define MAX_N 200'000
using namespace std;

string S;
int sum[MAX_N + 1];

void solve() {
  sum[0] = 0;
  int N = S.size();
  int d = 1;
  for (int i = 0; i < N; ++i) {
    sum[i + 1] = (sum[i] + (S[N - 1 - i] - '0') * d) % MOD;
    d = (d * 10) % MOD;
  }
  map<int, int> cnt;
  for (int i = 0; i <= N; ++i) {
    ++cnt[sum[i]];
  }
  int res = 0;
  for (auto c : cnt) {
    res += c.second * (c.second - 1) / 2; // nC2
  }
  printf("%d\n", res);
}

int main() {
  cin >> S;
  solve();
}