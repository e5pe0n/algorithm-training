#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

enum class Color { white, black };

Color flip(Color color) {
  switch (color) {
  case Color::white:
    return Color::black;
  case Color::black:
    return Color::white;
  }
}

char repr(Color color) {
  switch (color) {
  case Color::white:
    return 'w';
  case Color::black:
    return 'b';
  }
}

class Board {
  vector<vector<Color>> _v;

public:
  Board(ll size)
      : _v(vector<vector<Color>>(size, vector<Color>(size, Color::white))) {}
  ll size() {
    return _v.size();
  }
  void flip(ll row, ll col) {
    _v[row][col] = ::flip(_v[row][col]);
  }
  Color color(ll row, ll col) {
    return _v[row][col];
  }
  string repr() {
    string res;
    for (ll i = 0; i < _v.size(); ++i) {
      for (ll j = 0; j < _v.size(); ++j) {
        res += ::repr(_v[i][j]);
      }
      res += '\n';
    }
    res.pop_back();
    return res;
  }
};

class Ant {
  ll _direction = 0;
  const ll D = 4;
  vector<pll> _delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  ll _row, _col;

public:
  Ant(ll row, ll col) : _row(row), _col(col) {}
  pll pos() {
    return {_row, _col};
  }
  void rotate(Color color) {
    switch (color) {
    case Color::black:
      _direction = ((_direction - 1) % D + D) % D;
      break;
    case Color::white:
      _direction = (_direction + 1) % D;
    }
  }
  void move() {
    auto [dx, dy] = _delta[_direction];
    _row += dx;
    _col += dy;
  }
};

void print_K_moves(ll K) {
  Board board{K * 2 + 1};
  Ant ant(K, K);
  ll timer = K;
  while (K--) {
    auto [x, y] = ant.pos();
    ant.rotate(board.color(x, y));
    board.flip(x, y);
    ant.move();
  }
  puts(board.repr().c_str());
}

void solve(const ll K) {
  printf("# K=%lld\n", K);
  print_K_moves(K);
  puts("");
}

int main() {
  solve(3);
  solve(5);
  solve(10);
  solve(20);
  solve(50);
}