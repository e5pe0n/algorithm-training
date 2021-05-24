#include <vector>
using namespace std;
using ll = long long;

enum class Color { white, black };

class Board {
  const ll SIZE = 10;
  vector<vector<Color>> _board =
      vector<vector<Color>>(SIZE, vector<Color>(SIZE));
  vector<vector<bool>> _used = vector<vector<bool>>(SIZE, vector<bool>(SIZE));
  bool is_within(ll row, ll col) {
    return 0 <= row && row <= size() && 0 <= col && col <= size();
  }
  bool exists_neighbor(ll row, ll col, Color color) {
    for (ll i = row - 1; i <= row + 1; ++i) {
      for (ll j = col - 1; j <= col + 1; ++j) {
        if (is_within(i, j) && _used[i][j] && _board[i][j] != color)
          return true;
      }
    }
    return false;
  }

public:
  ll size() {
    return SIZE;
  }
  bool put(ll row, ll col, Color color) {
    if (!is_within(row, col) || _used[row][col]
        || !exists_neighbor(row, col, color))
      return false;
    rev(row, col, color); // reverse colors
    return true;
  }
  void rev(ll row, ll col, Color color);
};

class Player {
  Color _color;

public:
  Player(Color color) : _color(color) {}
  Color color() {
    return _color;
  }
  bool put(ll row, ll col, Board board) {
    return board.put(row, col, _color);
  };
};

class Game {
  vector<Player> players = {Player{Color::white}, Player{Color::black}};
  Board board;
};

int main() {}