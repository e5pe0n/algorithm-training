#include <algorithm>
#include <bitset>
#include <iostream>
#include <stdio.h>

#define MAX_N 100
#define INF 2'000'000'000

typedef long long ll;

using namespace std;

int N;
int F[MAX_N][10]{};
int P[MAX_N][11]{};

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> F[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 11; ++j) {
      cin >> P[i][j];
    }
  }
  ll ans = -INF;
  for (int i = 1; i < (1 << 10); ++i) {
    bitset<10> B(i);
    ll t = 0;
    for (int j = 0; j < N; ++j) {
      int cc = 0;
      for (int k = 0; k < 10; ++k) {
        if (B.test(k) && F[j][k]) {
          ++cc;
        }
      }
      t += P[j][cc];
    }
    ans = max(ans, t);
  }
  printf("%lld\n", ans);
}