#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> find_smallest_kth_nums(vector<ll> v, const ll k) {
  if (v.size() <= k) return v;
  priority_queue<ll> q;
  for (ll i = 0; i < k; ++i) {
    q.push(v[i]);
  }
  for (ll i = k; i < v.size(); ++i) {
    ll u = q.top();
    if (u > v[i]) {
      q.pop();
      q.push(v[i]);
    }
  }
  vector<ll> res(k);
  for (ll i = 0; i < k; ++i) {
    res[i] = q.top();
    q.pop();
  }
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
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/17_14/01.txt");
  solve("../testcases/17_14/02.txt");
  solve("../testcases/17_14/03.txt");
}