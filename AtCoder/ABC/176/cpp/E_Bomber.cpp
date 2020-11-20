#include <algorithm>
#include <iostream>
#include <map>
#include <memory.h>
#include <set>
#include <stdio.h>
#include <vector>

#define MAX_M 300'000
#define MAX_H 300'000
#define MAX_W 300'000

using namespace std;
typedef pair<int, int> pii;

int H, W, M;
set<pii> s;
map<int, int> mh, mw;

void solve() {
  int max_h = 0;
  for (auto m : mh) {
    max_h = max(max_h, m.second);
  }
  vector<int> hs;
  for (auto m : mh) {
    if (m.second == max_h) {
      hs.push_back(m.first);
    }
  }
  int max_w = 0;
  for (auto m : mw) {
    max_w = max(max_w, m.second);
  }
  vector<int> ws;
  for (auto m : mw) {
    if (m.second == max_w) {
      ws.push_back(m.first);
    }
  }
  for (auto h : hs) {
    for (auto w : ws) {
      if (s.find({h, w}) == s.end()) {
        printf("%d\n", max_h + max_w);
        return;
      }
    }
  }
  printf("%d\n", max_h + max_w - 1);
}

int main() {
  cin >> H >> W >> M;
  for (int i = 0; i < M; ++i) {
    int h, w;
    cin >> h >> w;
    s.insert(pii(--h, --w));
    ++mh[h];
    ++mw[w];
  }
  solve();
}