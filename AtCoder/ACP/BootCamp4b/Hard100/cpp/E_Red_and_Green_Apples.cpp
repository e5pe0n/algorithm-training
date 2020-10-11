#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<vector<int>> V{};
  for (int i = 0; i < A; ++i) {
    int p;
    cin >> p;
    V.push_back(vector<int>{p, 'B'});
  }
  for (int i = 0; i < B; ++i) {
    int q;
    cin >> q;
    V.push_back(vector<int>{q, 'G'});
  }
  for (int i = 0; i < C; ++i) {
    int r;
    cin >> r;
    V.push_back(vector<int>{r, 'N'});
  }
  sort(V.begin(), V.end(), [](const vector<int> &left, const vector<int> &right) { return left > right; });
  int cnt_B = 0;
  int cnt_G = 0;
  vector<int> _V{};
  for (auto v : V) {
    if (v[1] == 'B' && cnt_B < X) {
      _V.push_back(v[0]);
      ++cnt_B;
    } else if (v[1] == 'G' && cnt_G < Y) {
      _V.push_back(v[0]);
      ++cnt_G;
    } else if (v[1] == 'N') {
      _V.push_back(v[0]);
    }
    if (cnt_B == X && cnt_G == Y) {
      break;
    }
  }
  ll ans = 0;
  for (int i = 0; i < X + Y; ++i) {
    ans += _V[i];
  }
  printf("%lld\n", ans);
}