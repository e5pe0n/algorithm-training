#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<string> mat;

mat rotate1(mat m) {
  // ccw
  ll n = m.size();
  mat res(n, string(n, ' '));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      res[n - j - 1][i] = m[i][j];
    }
  }
  return res;
}

void rotate2(mat &m) {
  // ccw
  // in place
  // O(n^2)
  ll n = m.size();
  for (ll i = 0; i < n / 2; ++i) {
    ll w = n - i - 1;
    for (ll j = i; j < w; ++j) {
      ll src_i = i, src_j = j;
      char src = m[src_i][src_j];
      for (ll k = 0; k < 4; ++k) {
        ll dst_i = w - (src_j - i);
        ll dst_j = src_i;
        char dst = m[dst_i][dst_j];
        m[dst_i][dst_j] = src;
        src = dst;
        src_i = dst_i, src_j = dst_j;
      }
    }
  }
}

bool rotate3(mat &m) {
  // this is equivalent to rotate2 except for the rotation direction
  // cw
  // in place
  // O(n^2)
  if (m.size() == 0 || m.size() != m[0].size()) return false;
  ll n = m.size();
  for (ll layer = 0; layer < n / 2; ++layer) {
    ll fst = layer;
    ll lst = n - 1 - layer;
    for (ll i = fst; i < lst; ++i) {
      ll offset = i - fst;
      ll top = m[fst][i]; // save top

      // left -> top
      m[fst][i] = m[lst - offset][fst];

      // bottom -> left
      m[lst - offset][fst] = m[lst][lst - offset];

      // right -> bottom
      m[lst][lst - offset] = m[i][lst];

      // top -> right
      m[i][lst] = top;
    }
  }
  return true;
}

void show1(const function<mat(mat)> &f, const string &fn, const mat &m) {
  printf("# %s\n", fn.c_str());
  mat res = f(m);
  for (auto s : res)
    puts(s.c_str());
  puts("");
}

void show2(const function<void(mat &)> &f, const string &fn, const mat &m) {
  printf("# %s\n", fn.c_str());
  mat m2 = m;
  f(m2);
  for (auto s : m2)
    puts(s.c_str());
  puts("");
}

void show3(const function<bool(mat &)> &f, const string &fn, const mat &m) {
  printf("# %s\n", fn.c_str());
  mat m2 = m;
  f(m2);
  for (auto s : m2)
    puts(s.c_str());
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_07_2.txt");
  ll h, w;
  ifs >> h >> w;
  mat m(h);
  for (ll i = 0; i < h; ++i) {
    ifs >> m[i];
  }
  show1(rotate1, "rotate1", m);
  show2(rotate2, "rotate2", m);
  show3(rotate3, "rotate3", m);
}