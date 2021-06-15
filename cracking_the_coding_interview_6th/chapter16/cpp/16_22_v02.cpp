// Cracking the Coding Interview p.516
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template <typename T> using uset = unordered_set<T>;

enum class Orientation { left, right, up, down };

struct Pos {
  ll row, col;
};

struct Ant {
  Pos pos;
  Orientation orientation = Orientation::right;
  Ant() : pos(Pos{0, 0}) {}
  void turn(bool clockwise) {
    switch (orientation) {
    case Orientation::left:
      orientation = clockwise ? Orientation::up : Orientation::down;
      break;
    case Orientation::right:
      orientation = clockwise ? Orientation::down : Orientation::up;
      break;
    case Orientation::up:
      orientation = clockwise ? Orientation::right : Orientation::left;
      break;
    case Orientation::down:
      orientation = clockwise ? Orientation::left : Orientation::right;
      break;
    }
  }
  void move() {
    switch (orientation) {
    case Orientation::left:
      --pos.col;
      break;
    case Orientation::right:
      ++pos.col;
      break;
    case Orientation::up:
      --pos.row;
      break;
    case Orientation::down:
      ++pos.row;
    }
  }
};

template <> struct std::equal_to<Pos> {
  bool operator()(const Pos &p1, const Pos &p2) const {
    return p1.row == p2.row && p1.col == p2.col;
  }
};

template <> struct std::hash<Pos> {
  size_t operator()(const Pos &p) const {
    return (p.row * 31) ^ p.col;
  }
};

class Board {
  uset<Pos> _black_cells;
  Ant _ant;
  Pos _topleft;
  Pos _btmright;
  void flip(Pos pos) {
    if (_black_cells.find(pos) != _black_cells.end()) {
      _black_cells.erase(pos);
    } else {
      _black_cells.insert(pos);
    }
  }
  void ensure_fit(Pos pos) {
    _topleft.row = min(_topleft.row, pos.row);
    _topleft.col = min(_topleft.col, pos.col);

    _btmright.row = max(_btmright.row, pos.row);
    _btmright.col = max(_btmright.col, pos.col);
  }
  bool is_black(Pos pos) {
    return _black_cells.find(pos) != _black_cells.end();
  }

public:
  Board() : _topleft(Pos{0, 0}), _btmright(Pos{0, 0}) {}
  void move() {
    _ant.turn(!is_black(_ant.pos));
    flip(_ant.pos);
    _ant.move();
    ensure_fit(_ant.pos);
  }
  string repr() {
    string res;
    for (ll i = _topleft.row; i <= _btmright.row; ++i) {
      for (ll j = _topleft.col; j <= _btmright.col; ++j) {
        if (is_black(Pos{i, j}))
          res += 'X';
        else
          res += '_';
      }
      res += '\n';
    }
    res.pop_back();
    return res;
  }
};

void print_K_moves(ll K) {
  Board board;
  while (K--) {
    board.move();
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

// # K=3
// _X
// XX

// # K=5
// __
// X_
// XX

// # K=10
// __X
// XXX
// XX_

// # K=20
// __X_
// _X_X
// ___X
// _XX_

// # K=50
// __XX__
// _X__X_
// X____X
// X_X__X
// _X_XX_