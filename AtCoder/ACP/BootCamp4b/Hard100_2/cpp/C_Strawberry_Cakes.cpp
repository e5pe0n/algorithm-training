#include <bits/stdc++.h>
#define MAX_H 300
#define MAX_W 300
using namespace std;
typedef long long ll;

ll H, W, K;
string S[MAX_H];
int res[MAX_H][MAX_W];

void solve() {
  vector<int> V;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        V.push_back(i);
        break;
      }
    }
  }
  int prv_i = 0;
  for (auto v : V) {
    vector<int> V2;
    for (int j = 0; j < W; ++j) {
      for (int i = prv_i; i <= v; ++i) {
        if (S[i][j] == '#') { V2.push_back(j); }
      }
    }
    int prv_j = 0;
    for (auto v2 : V2) {
      for (int j = prv_j; j <= v2; ++j) {
        for (int i = prv_i; i <= v; ++i) {
          res[i][j] = K;
        }
      }
      --K;
      prv_j = v2 + 1;
    }
    for (int j = V2[V2.size() - 1] + 1; j < W; ++j) {
      for (int i = prv_i; i <= v; ++i) {
        res[i][j] = res[i][V2[V2.size() - 1]];
      }
    }
    prv_i = v + 1;
  }
  for (int i = V[V.size() - 1] + 1; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      res[i][j] = res[V[V.size() - 1]][j];
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      printf("%d%c", res[i][j], j == W - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  cin >> H >> W >> K;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  solve();
}