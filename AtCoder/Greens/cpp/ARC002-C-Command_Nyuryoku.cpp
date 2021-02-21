#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
typedef long long ll;

const char cmd[] = {'A', 'B', 'X', 'Y'};

ll N;
string C;
ll dp[MAX_N + 1];

int main() {
  cin >> N >> C;
  ll res = MAX_N;
  for (ll i = 0; i < 4; ++i) {
    for (ll j = 0; j < 4; ++j) {
      for (ll _i = 0; _i < 4; ++_i) {
        for (ll _j = 0; _j < 4; ++_j) {
          string L, R;
          L += cmd[i];
          L += cmd[j];
          R += cmd[_i];
          R += cmd[_j];
          fill(dp, dp + N + 1, MAX_N);
          dp[0] = 0;
          for (ll k = 1; k <= N; ++k) {
            if (k - 1 >= 0) { dp[k] = min(dp[k], dp[k - 1] + 1); }
            if (k - 2 >= 0) {
              string _C = C.substr(k - 2, 2);
              if (_C == L || _C == R) { dp[k] = min(dp[k], dp[k - 2] + 1); }
            }
          }
          res = min(res, dp[N]);
        }
      }
    }
  }
  printf("%lld\n", res);
}