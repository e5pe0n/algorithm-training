#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_H 10
using namespace std;

int H, W, K;
string S[MAX_H];

void solve() {
  int res = INF;
  for (int h = 0; h < 1 << (H - 1); ++h) {
    int c = 0;
    for (int i = 0; i < H; ++i) {
      if (h >> i & 1) {
        ++c;
      }
    }
    vector<int> sum(c + 1);
    int div = 0;
    // printf("h=%d\n", h);
    for (int j = 0; j < W; ++j) {
      vector<int> cnt(c + 1);
      int t = 0;
      int idx = 0;
      for (int i = 0; i < H; ++i) {
        if (S[i][j] == '1') {
          t += 1;
        }
        if (h >> i & 1) {
          // printf("(%d, %d) t=%d : ", i, j, t);
          // for (int k = 0; k < c + 1; ++k) {
          //   printf("%d%c", cnt[k], k == c ? '\n' : ' ');
          // }
          if (t > K) {
            div = INF;
            break;
          }
          cnt[idx++] += t;
          t = 0;
        }
      }
      if (t > K || div == INF) {
        div = INF;
        break;
      }
      cnt[idx] += t;
      bool f = false;
      for (int i = 0; i < c + 1; ++i) {
        if (sum[i] + cnt[i] > K) {
          f = true;
          break;
        }
      }
      if (f) {
        ++div;
        sum = cnt;
      } else {
        for (int i = 0; i < c + 1; ++i) {
          sum[i] += cnt[i];
        }
      }
    }
    // printf("c=%d div=%d\n", c, div);
    res = min(res, div + c);
  }
  printf("%d\n", res);
}

int main() {
  cin >> H >> W >> K;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}

// int main() {
//   ifstream ifs("random_01_in");
//   ifs >> H >> W >> K;
//   for (int i = 0; i < H; ++i) {
//     ifs >> S[i];
//   }
//   solve();
// }