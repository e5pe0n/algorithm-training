// WA
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_H = 2000;
const ll MAX_W = 2000;
const ll INF = 1e9;
ll H, W;
ll A[MAX_H][MAX_W];

ll dp[MAX_H][MAX_W][2];

bool valid(ll i, ll j) {
  return 0 <= i && i < H && 0 <= j && j < W;
}

int main() {
  cin >> H >> W;
  for (ll i = 0; i < H; ++i) {
    string a;
    cin >> a;
    for (ll j = 0; j < W; ++j) {
      if (a[j] == '-')
        A[i][j] = -1;
      else
        A[i][j] = 1;
    }
  }
  dp[0][0][0] = dp[0][0][1] = 0;
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      if ((i + j) % 2 == 0) {
        // Aoki
        if (valid(i - 1, j) && valid(i, j - 1)) {
          ll diff1 = dp[i - 1][j][0] - dp[i - 1][j][1];
          ll diff2 = dp[i][j - 1][0] - dp[i][j - 1][1];
          if (diff1 > diff2) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1] + A[i][j];
          } else {
            dp[i][j][0] = dp[i][j - 1][0];
            dp[i][j][1] = dp[i][j - 1][1] + A[i][j];
          }
        } else if (valid(i - 1, j)) {
          dp[i][j][0] = dp[i - 1][j][0];
          dp[i][j][1] = dp[i - 1][j][1] + A[i][j];
        } else if (valid(i, j - 1)) {
          dp[i][j][0] = dp[i][j - 1][0];
          dp[i][j][1] = dp[i][j - 1][1] + A[i][j];
        }
      } else {
        // Takahashi
        if (valid(i - 1, j) && valid(i, j - 1)) {
          ll diff1 = dp[i - 1][j][1] - dp[i - 1][j][0];
          ll diff2 = dp[i][j - 1][1] - dp[i][j - 1][0];
          if (diff1 > diff2) {
            dp[i][j][1] = dp[i - 1][j][1];
            dp[i][j][0] = dp[i - 1][j][0] + A[i][j];
          } else {
            dp[i][j][1] = dp[i][j - 1][1];
            dp[i][j][0] = dp[i][j - 1][0] + A[i][j];
          }
        } else if (valid(i - 1, j)) {
          dp[i][j][1] = dp[i - 1][j][1];
          dp[i][j][0] = dp[i - 1][j][0] + A[i][j];
        } else if (valid(i, j - 1)) {
          dp[i][j][1] = dp[i][j - 1][1];
          dp[i][j][0] = dp[i][j - 1][0] + A[i][j];
        }
      }
    }
  }
  ll t = dp[H - 1][W - 1][0];
  ll a = dp[H - 1][W - 1][1];
  if (t == a)
    puts("Draw");
  else if (t > a)
    puts("Takahashi");
  else
    puts("Aoki");
}