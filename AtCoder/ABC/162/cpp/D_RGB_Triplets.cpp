#include <bits/stdc++.h>
#define MAX_N 4000
using namespace std;
typedef long long ll;

ll N;
string S;
ll sum_R[MAX_N + 1];
ll sum_B[MAX_N + 1];
ll sum_G[MAX_N + 1];

void solve() {
  for (int i = 0; i < N; ++i) {
    sum_R[i + 1] = sum_R[i] + (S[i] == 'R');
    sum_B[i + 1] = sum_B[i] + (S[i] == 'B');
    sum_G[i + 1] = sum_G[i] + (S[i] == 'G');
  }
  ll res = 0;
  for (int i = 0; i < N - 2; ++i) {
    for (int j = i + 1; j < N - 1; ++j) {
      if (S[i] == S[j]) {
        continue;
      }
      ll t = 0;
      if (S[i] != 'R' && S[j] != 'R') {
        t = sum_R[N] - sum_R[j + 1];
        if (S[j + (j - i)] == 'R') {
          t -= 1;
        }
      } else if (S[i] != 'B' && S[j] != 'B') {
        t = sum_B[N] - sum_B[j + 1];
        if (S[j + (j - i)] == 'B') {
          t -= 1;
        }
      } else if (S[i] != 'G' && S[j] != 'G') {
        t = sum_G[N] - sum_G[j + 1];
        if (S[j + (j - i)] == 'G') {
          t -= 1;
        }
      }
      res += max(0LL, t);
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> S;
  solve();
}