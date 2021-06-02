#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> make_alt_seq(vector<ll> v) {
  if (v.size() <= 2) return v;
  vector<ll> res;
  sort(v.begin(), v.begin() + 3);
  res.push_back(v[0]);
  res.push_back(v[2]);
  res.push_back(v[1]);
  for (ll i = 3; i < v.size(); ++i) {
    res.push_back(v[i]);
    if (i % 2 != 0 && res[i - 1] > res[i]) { // seek peek
      swap(res[i - 1], res[i]);
    }
    if (i % 2 == 0 && res[i - 1] < res[i]) { // seek valley
      swap(res[i - 1], res[i]);
    }
  }
  return res;
}

void solve(const string &fp) {
  ifstream ifs(fp);
  printf("# %s\n", fp.c_str());
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i)
    ifs >> v[i];
  vector<ll> res = make_alt_seq(v);
  for (ll i = 0; i < n; ++i) {
    printf("%lld%c", res[i], i == n - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/10_11/01.txt");
  solve("../testcases/10_11/02.txt");
}

// # ../testcases/10_11/01.txt
// 1 5 2 3 3

// # ../testcases/10_11/02.txt
// 3 20 1 11 5 22 0 14 8 29 9 26 19 24 2 23 6 10 4 27 18 25 12 16 7 28 15 21 13
// 17
