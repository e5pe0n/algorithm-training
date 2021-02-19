#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_R 50
#define MAX_C 50
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll dy[] = {1, 0, -1, 0};
const ll dx[] = {0, 1, 0, -1};

ll R, C;
ll sy, sx, gy, gx;
string c[MAX_R];
ll d[MAX_R][MAX_C];

void bfs() {
  for (ll i = 0; i < R; ++i) {
    fill(d[i], d[i] + C, INF);
  }
  d[sy][sx] = 0;
  queue<pll> q;
  q.push({sy, sx});
  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for (ll k = 0; k < 4; ++k) {
      ll _y = y + dy[k];
      ll _x = x + dx[k];
      if (0 <= _y && _y < R && 0 <= _x && _x < C && c[_y][_x] == '.'
          && d[_y][_x] > d[y][x] + 1) {
        d[_y][_x] = d[y][x] + 1;
        q.push({_y, _x});
      }
    }
  }
}

int main() {
  cin >> R >> C >> sy >> sx >> gy >> gx;
  --sy;
  --sx;
  --gy;
  --gx;
  for (ll i = 0; i < R; ++i) {
    cin >> c[i];
  }
  bfs();
  printf("%lld\n", d[gy][gx]);
}