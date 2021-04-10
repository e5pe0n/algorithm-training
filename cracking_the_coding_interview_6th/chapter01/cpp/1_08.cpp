#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<string> mat;

void zero_row(mat &m, ll row) {
  for (ll j = 0; j < m[0].size(); ++j) {
    m[row][j] = '0';
  }
}

void zero_col(mat &m, ll col) {
  for (ll i = 0; i < m.size(); ++i) {
    m[i][col] = '0';
  }
}

mat zero_mat1(mat m) {
  ll N = m.size();
  ll M = m[0].size();
  vector<bool> rows(N), cols(M);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < M; ++j) {
      if (m[i][j] == '0') { rows[i] = cols[j] = true; }
    }
  }
  for (ll i = 0; i < N; ++i) {
    if (rows[i]) zero_row(m, i);
  }
  for (ll j = 0; j < M; ++j) {
    if (cols[j]) zero_col(m, j);
  }
  return m;
}

mat zero_mat2(mat m) {
  ll N = m.size();
  ll M = m[0].size();
  bool row0zero = false, col0zero = false;
  for (ll j = 0; j < M; ++j) {
    if (m[0][j] == '0') {
      row0zero = true;
      break;
    }
  }
  for (ll i = 0; i < N; ++i) {
    if (m[i][0] == '0') {
      col0zero = true;
      break;
    }
  }
  for (ll i = 1; i < N; ++i) {
    for (ll j = 1; j < M; ++j) {
      if (m[i][j] == '0') m[i][0] = m[0][j] = '0';
    }
  }
  for (ll i = 1; i < N; ++i) {
    if (m[i][0] == '0') zero_row(m, i);
  }
  for (ll j = 1; j < M; ++j) {
    if (m[0][j] == '0') zero_col(m, j);
  }
  if (row0zero) zero_row(m, 0);
  if (col0zero) zero_col(m, 0);
  return m;
}

void show(const function<mat(mat)> &f, const string &fn, const mat &m) {
  printf("# %s\n", fn.c_str());
  mat res = f(m);
  for (auto s : res)
    puts(s.c_str());
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_08_1.txt");
  ll N, M;
  ifs >> N >> M;
  mat m(N);
  for (ll i = 0; i < N; ++i) {
    ifs >> m[i];
  }
  show(zero_mat1, "zero_mat1", m);
  show(zero_mat2, "zero_mat2", m);
}