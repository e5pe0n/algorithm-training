#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

bool dfs(ll i, ll bit, ll n, ll m) {
  if (i == n * m) return bit == -1;
  if (bit & (1 << i)) return dfs(i + 1, bit, n, m);
  bool res = false;
  if (i % m != m - 1 && (~bit & (1 << (i + 1))))
    res |= dfs(i + 1, bit | (1 << i) | (1 << (i + 1)), n, m);
  if (i + m < n * m && (~bit & (1 << (i + m))))
    res |= dfs(i + 1, bit | (1 << i) | (1 << (i + m)), n, m);
  return res;
}

// ll cnt0 = 0, cnt1 = 0, cnt2 = 0;

// bool dfs(ll i, ll bit, ll n, ll m) {
//   if (i == 0) cnt0 = 0, cnt1 = 0, cnt2 = 0;
//   if (i == n * m) return bit == -1;
//   if (bit & (1 << i)) ++cnt0;
//   if (bit & (1 << i)) return dfs(i + 1, bit, n, m);
//   bool res = false;
//   if (i % m != m - 1 && (~bit & (1 << (i + 1)))) ++cnt1;
//   if (i % m != m - 1 && (~bit & (1 << (i + 1))))
//     res |= dfs(i + 1, bit | (1 << i) | (1 << (i + 1)), n, m);
//   if (i + m < n * m && (~bit & (1 << (i + m)))) ++cnt2;
//   if (i + m < n * m && (~bit & (1 << (i + m))))
//     res |= dfs(i + 1, bit | (1 << i) | (1 << (i + m)), n, m);
//   if (i == 0) printf("cnt0=%lld, cnt1=%lld, cnt2=%lld\n", cnt0, cnt1, cnt2);
//   return res;
// }

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  ll bit = 0;
  for (ll i = 0; i < n; ++i) {
    string line;
    ifs >> line;
    for (ll j = 0; j < m; ++j) {
      if (line[j] == 'x') bit |= 1 << (m * i + j);
    }
  }
  printf("%s\n\n", dfs(0, bit, n, m) ? "possible" : "impossible");
}

int main() {
  // solve("../testcases/06_02/01.txt");
  solve("../testcases/06_02/02.txt");
  // solve("../testcases/06_02/03.txt");
}