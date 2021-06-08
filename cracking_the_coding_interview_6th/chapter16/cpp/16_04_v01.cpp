#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const ll L = 3;

struct Res {
  bool finished;
  char player;
};

Res judge(const vector<vector<char>> &v, const char p1, const char p2) {
  vector<ll> cnt(8);
  for (ll i = 0; i < L; ++i) {
    for (ll j = 0; j < L; ++j) {
      ll score;
      if (v[i][j] == p1)
        score = 1;
      else
        score = -1;
      cnt[i] += score;
      cnt[j + 3] += score;
      if (i == j) cnt[6] += score;
      if (i + j == L - 1) cnt[7] += score;
    }
  }
  for (auto n : cnt) {
    if (n >= 3) return Res{true, p1};
    if (n <= -3) return Res{true, p2};
  }
  return Res{false};
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  char p1, p2;
  ifstream ifs(fp);
  ifs >> p1 >> p2;
  vector<vector<char>> v(L, vector<char>(L));
  for (ll i = 0; i < L; ++i) {
    for (ll j = 0; j < L; ++j) {
      ifs >> v[i][j];
    }
  }
  Res res = judge(v, p1, p2);
  if (res.finished) {
    printf("%c wins\n", res.player);
  } else {
    puts("draw");
  }
  puts("");
}

int main() {
  solve("../testcases/16_04/01.txt");
  solve("../testcases/16_04/02.txt");
  solve("../testcases/16_04/03.txt");
  solve("../testcases/16_04/04.txt");
}

// # ../testcases/16_04/01.txt
// x wins

// # ../testcases/16_04/02.txt
// x wins

// # ../testcases/16_04/03.txt
// o wins

// # ../testcases/16_04/04.txt
// draw