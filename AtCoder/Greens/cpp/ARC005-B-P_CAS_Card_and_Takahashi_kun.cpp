#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y;
ll dx = 0, dy = 0;
string W;
string C[10];

int main() {
  cin >> X >> Y >> W;
  --X;
  --Y;
  for (ll i = 0; i < 9; ++i) {
    cin >> C[i];
  }
  if (W == "R") dx = 1, dy = 0;
  if (W == "L") dx = -1, dy = 0;
  if (W == "U") dx = 0, dy = -1;
  if (W == "D") dx = 0, dy = 1;
  if (W == "RU") dx = 1, dy = -1;
  if (W == "RD") dx = 1, dy = 1;
  if (W == "LU") dx = -1, dy = -1;
  if (W == "LD") dx = -1, dy = 1;
  string res;
  for (ll i = 0; i < 4; ++i) {
    res += C[Y][X];
    ll _x = X + dx;
    ll _y = Y + dy;
    if (_x < 0 || 9 <= _x) {
      dx *= -1;
      _x = X + dx;
    }
    if (_y < 0 || 9 <= _y) {
      dy *= -1;
      _y = Y + dy;
    }
    X = _x, Y = _y;
  }
  printf("%s\n", res.c_str());
}