#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> find_smallest_kth_nums(vector<ll> v, const ll k) {
  // this function is only appliable for distinct elements
  if (v.size() <= k) return v;
  ll left = 0, right = v.size();
  ll cnt = 0;
  while (cnt != k) {
    // should use randomized idx, otherwise may loop infinitely if no swap occur
    // by chosen pivot.
    // moreover, falls into infinite loop when all elements in [left, right] is
    // equal even if use randomized idx.
    ll mid = (left + right) / 2;
    ll pivot = v[mid];
    swap(v[left], v[mid]);
    ll last_less = left - 1;
    for (ll i = left; i < right; ++i) {
      if (v[i] < pivot) { swap(v[i], v[++last_less]); }
    }
    if (last_less + 1 <= k) {
      cnt += last_less + 1 - left;
      left = last_less + 1;
    } else {
      right = last_less + 1;
    }
  }
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
  sort(res.begin(), res.end());
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/17_14/04.txt"); // not terminate
}
