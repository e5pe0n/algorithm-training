#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 500
#define MAX_M 500
using namespace std;
typedef long long ll;

const ll di[] = {0, 1, 0, -1};
const ll dj[] = {1, 0, -1, 0};

ll N, M;
ll B[MAX_N][MAX_M];
ll res[MAX_N][MAX_M];

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    string b;
    cin >> b;
    for (ll j = 0; j < M; ++j) {
      B[i][j] = b[j] - '0';
    }
  }
  for (ll i = 1; i < N - 1; ++i) {
    for (ll j = 1; j < M - 1; ++j) {
      ll mi = INF;
      ll cnt = 0;
      for (ll k = 0; k < 4; ++k) {
        ll _i = i + di[k];
        ll _j = j + dj[k];
        if (B[_i][_j] > 0) {
          mi = min(mi, B[_i][_j]);
          ++cnt;
        }
      }
      if (cnt == 4) {
        for (ll k = 0; k < 4; ++k) {
          ll _i = i + di[k];
          ll _j = j + dj[k];
          B[_i][_j] -= mi;
        }
        res[i][j] = mi;
      }
    }
  }
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < M; ++j) {
      printf("%lld", res[i][j]);
    }
    puts("");
  }
}