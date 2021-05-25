#include <algorithm>
#include <chrono>
#include <queue>
#include <random>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using hrc = chrono::high_resolution_clock;
using pll = pair<ll, ll>;

class Block {
  bool _is_bomb = false;
  ll _num;

public:
  Block() {}
  Block(bool is_bomb, ll num) : _is_bomb(is_bomb), _num(num) {}
  bool is_bomb() {
    return _is_bomb;
  }
  ll num() {
    return _num;
  }
};

class Board {
  using rep = decltype(hrc::now().time_since_epoch().count());
  ll _size;
  vector<vector<Block>> _board;
  vector<vector<bool>> _used;
  rep _seed = hrc::now().time_since_epoch().count();
  default_random_engine _generator;
  ll _bombs;
  ll _opens;

  ll rand_ll(ll lb, ll ub) {
    // return a random number in [lb, ub];
    uniform_int_distribution<ll> distribution(lb, ub);
    return distribution(_generator);
  }

  pll rand_pll(ll lb, ll ub) {
    // return pair or random numbers in [lb, ub];
    return {rand_ll(lb, ub), rand_ll(lb, ub)};
  }

  bool valid_coord(ll i, ll j) {
    return 0 <= i && i < _size && 0 <= j && j < _size;
  }
  void _open(ll row, ll col) {
    queue<pll> q;
    q.push({row, col});
    _used[row][col] = true;
    ++_opens;
    while (q.size()) {
      auto [i, j] = q.front();
      q.pop();
      if (_board[i][j].num() != 0) continue;
      for (ll _i = -1; _i <= 1; ++_i) {
        for (ll _j = -1; _j <= 1; ++_j) {
          ll x = i + _i;
          ll y = j + _j;
          if (_i == _j || _used[x][y]) continue;
          _used[i][j] = true;
          ++_opens;
          q.push({x, y});
        }
      }
    }
  }

public:
  Board(ll size, ll bombs)
      : _size(size),
        _generator(_seed),
        _board(vector<vector<Block>>(_size, vector<Block>(_size))),
        _used(vector<vector<bool>>(_size, vector<bool>(_size))),
        _bombs(bombs),
        _opens(0) {
    vector<pll> v;
    for (ll i = 0; i < _size; ++i) {
      for (ll j = 0; j < _size; ++j) {
        v.push_back({i, j});
      }
    }
    shuffle(v.begin(), v.end(), _generator);
    for (ll i = 0; i < _bombs; ++i) {
      auto [x, y] = v[i];
      _board[x][y] = Block(true, -1);
    }
    for (ll i = 0; i < _size; ++i) {
      for (ll j = 0; j < _size; ++j) {
        if (_board[i][j].is_bomb()) continue;
        ll cnt = 0;
        for (ll _i = -1; _i <= 1; ++_i) {
          for (ll _j = -1; _j <= 1; ++_j) {
            ll x = i + _i;
            ll y = j + _j;
            if (valid_coord(x, y) && (_i != _j) && _board[x][y].is_bomb())
              ++cnt;
          }
        }
        _board[i][j] = Block(false, cnt);
      }
    }
  }
  Board(ll size) : Board(size, rand_ll(1, size * size - 1)) {}
  ll size() {
    return _size;
  }
  ll bombs() {
    return _bombs;
  }
  ll opens() {
    return _opens;
  }
  bool openable(ll row, ll col) {
    return valid_coord(row, col) && !_used[row][col];
  }
  bool open(ll row, ll col) {
    // return false if bomb block is opened
    if (!valid_coord(row, col))
      throw out_of_range{"invalid row and col, got row=" + to_string(row)
                         + ", col=" + to_string(col)
                         + ". row and col must be in [" + to_string(_size)
                         + ", " + to_string(_size) + "]."};
    if (_used[row][col])
      throw runtime_error{"Board[" + to_string(row) + "][" + to_string(col)
                          + "] is alrady _used."};

    if (_board[row][col].is_bomb()) return false;
    _open(row, col);
    return true;
  }
};

class Game {
  Board board;

public:
  Game(ll size, ll bombs) : board(Board{size, bombs}) {}
  Game(ll size) : board(Board{size}) {}

  bool is_completed() {
    return board.size() * board.size() - board.opens() == board.bombs();
  }
};

int main() {}