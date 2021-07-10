#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll shortest_superseq(const vector<ll> &longer, const vector<ll> &shorter) {
  map<ll, ll> cnt;
  for (auto v : shorter) {
    cnt[v] = 0;
  }
  ll left = 0;
  ll right = 0;
  pll res{0, (ll)longer.size()};
  ll unique_nums = 0;
  bool found = false;
  while (right < longer.size()) {
    while (right < longer.size() && unique_nums < shorter.size()) {
      if (cnt.find(longer[right]) != cnt.end()) {
        if (cnt[longer[right]] == 0) ++unique_nums;
        ++cnt[longer[right]];
      }
      ++right;
    }
    found |= unique_nums >= shorter.size();
    while (unique_nums >= shorter.size()) {
      if (cnt.find(longer[left]) != cnt.end()) {
        --cnt[longer[left]];
        if (cnt[longer[left]] == 0) --unique_nums;
      }
      ++left;
    }
    if (right - left < res.second - res.first) {
      res.second = right - 1;
      res.first = left - 1;
    }
  }
  if (!found) res = {-1, -1};
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, m;
  ifs >> n >> m;
  vector<ll> longer(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> longer[i];
  }
  vector<ll> shorter(m);
  for (ll i = 0; i < m; ++i) {
    ifs >> shorter[i];
  }
  pll res = shortest_superseq(longer, shorter);
  printf("%lld, %lld\n", res.first, res.second);
  puts("");
}

int main() {
  solve("../testcases/17_18/01.txt");
  solve("../testcases/17_18/02.txt");
  solve("../testcases/17_18/03.txt");
}
