#include <bits/stdc++.h>
#define MAX_H 100
#define MAX_W 100
using namespace std;
typedef long long ll;

ll H, W, X, Y;
string S[MAX_H];

int main() {
  cin >> H >> W >> X >> Y;
  --X, --Y;
  for (ll i = 0; i < H; ++i) {
    cin >> S[i];
  }
  ll res = 0;
  for (ll i = X; i >= 0; --i) {
    if (S[i][Y] == '#') break;
    ++res;
  }
  for (ll i = X; i < H; ++i) {
    if (S[i][Y] == '#') break;
    ++res;
  }
  for (ll i = Y; i >= 0; --i) {
    if (S[X][i] == '#') break;
    ++res;
  }
  for (ll i = Y; i < W; ++i) {
    if (S[X][i] == '#') break;
    ++res;
  }
  printf("%lld\n", res - 3);
}