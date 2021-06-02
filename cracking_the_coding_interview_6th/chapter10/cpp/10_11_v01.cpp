#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> make_alt_seq(vector<ll> v) {
  vector<ll> res;
  sort(v.begin(), v.end());
  ll mid = v.size() / 2;
  if (v.size() % 2 == 0) {
    for (ll i = 0; i < mid; ++i) {
      res.push_back(v[i]);
      res.push_back(v[i + mid]);
    }
  } else {
    res.push_back(v[mid]);
    for (ll i = 0; i < mid; ++i) {
      res.push_back(v[i]);
      res.push_back(v[i + mid + 1]);
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i)
    ifs >> v[i];
  vector<ll> res = make_alt_seq(v);
  for (ll i = 0; i < n; ++i) {
    printf("%lld%c", res[i], i == n - 1 ? '\n' : ' ');
  }
  cout << endl;
}

int main() {
  solve("../testcases/10_11/01.txt");
  solve("../testcases/10_11/02.txt");
}

// # ../testcases/10_11/01.txt
// 3 1 3 2 5

// # ../testcases/10_11/02.txt
// 0 15 1 16 2 17 3 18 4 19 5 20 6 21 7 22 8 23 9 24 10 25 11 26 12 27 13 28 14
// 29