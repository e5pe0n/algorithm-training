#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

class Piece {
  ll left_shape, right_shape, top_shape, btm_shape; // 0 means a straight side
};

class Jigsaw {
  vector<vector<Piece>> _pieces;
  vector<vector<bool>> _used;
  bool valid_coord(ll row, ll col) {
    return 0 <= row && row <= size() && 0 <= col && col <= size();
  }
  bool fits_with(Piece, Piece);
  bool fits_side(Piece);

public:
  Jigsaw(ll size) {
    _pieces = vector<vector<Piece>>(size, vector<Piece>(size));
    _used = vector<vector<bool>>(size, vector<bool>(size));
  }
  ll size() {
    return _pieces.size();
  }
  bool put(ll row, ll col, Piece p) {
    if (!valid_coord(row, col) || _used[row][col]) return false;

    vector<pll> neighbors{
        {row - 1, col}, {row, col - 1}, {row + 1, col}, {row, col + 1}};
    for (const auto [r, c] : neighbors) {
      if (valid_coord(r, c)) {
        if (_used[r][c] && !fits_with(_pieces[r][c], p)) return false;
      } else {
        if (!fits_side(p)) return false;
      }
    }
    _pieces[row][col] = p;
    _used[row][col] = true;
    return true;
  }
  Piece remove(ll row, ll col) {
    if (!valid_coord(row, col))
      throw out_of_range{"row and col must be in [0, " + to_string(size())
                         + "]."};
    if (!_used[row][col])
      throw runtime_error{"no piece at (" + to_string(row) + ", "
                          + to_string(col) + ")."};
    _used[row][col] = false;
    return _pieces[row][col];
  }
  bool completed() {
    return all_of(_used.begin(), _used.end(), [](const auto &v) {
      return all_of(v.begin(), v.end(), true);
    });
  }
};

int main() {}