#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> find_smallest_kth_nums(vector<ll> v, const ll k) {
  if (v.size() <= k) return v;
  sort(v.begin(), v.end());
  vector<ll> res(v.begin(), v.begin() + k);
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, k;
  ifs >> n >> k;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  vector<ll> res = find_smallest_kth_nums(v, k);
  for (ll i = 0; i < k; ++i) {
    printf("%lld%c", res[i], i == k - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/17_14/01.txt");
  solve("../testcases/17_14/02.txt");
  solve("../testcases/17_14/03.txt");
}

// # ../testcases/17_14/01.txt
// -5 -2 -1

// # ../testcases/17_14/02.txt
// -9 -7 -7 -3 -2 0 1 3 5 6

// # ../testcases/17_14/03.txt
// -6 -6 -5 -5 -4 -4 -2 -1 -1 -1 0 0 2 3 3 4 4 4 8 8 9 11 12 12 13 13 16 16 17
// 17 18 21 22 23 23 24 24 24 24 25 26 28 28 29 30 31 32 33 35 40 41 41 42 43 48
// 49 49 50 51 51 55 55 57 58 59 59 59 61 62 62 63 64 65 65 66 67 67 68 68 70 71
// 71 72 75 75 75 77 77 77 78 78 79 79 80 80 80 81 83 87 89
