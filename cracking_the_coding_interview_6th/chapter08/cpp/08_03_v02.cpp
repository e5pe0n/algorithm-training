// if almost all elements in the array are distinct,
// the complexity is almost O(n).
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll search(const vector<ll> &v, ll start, ll end) {
  if (end < start) return -1;

  ll mid_idx = (start + end) / 2;
  ll mid_val = v[mid_idx];

  if (mid_val == mid_idx) return mid_idx;

  ll left_end = min(mid_idx - 1, mid_val);
  ll left_idx = search(v, start, left_end);
  if (left_idx >= 0) return left_idx;

  ll right_start = max(mid_idx + 1, mid_val);
  ll right_idx = search(v, right_start, end);
  return right_idx;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  ll res = search(v, 0, v.size() - 1);
  if (res >= 0)
    cout << res << endl;
  else
    cout << "no exists" << endl;
  cout << endl;
}

int main() {
  solve("../testcases/08_03/03.txt");
}

// # ../testcases/08_03/03.txt
// 7
