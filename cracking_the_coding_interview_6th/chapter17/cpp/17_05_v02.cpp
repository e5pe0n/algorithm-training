// Cracking the Coding Interview p.538
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template <typename T, typename U> using umap = unordered_map<T, U>;

vector<ll> compute_delta_arr(string s) {
  vector<ll> deltas(s.size());
  ll d = 0;
  for (ll i = 0; i < s.size(); ++i) {
    if (isalpha(s[i]))
      ++d;
    else
      --d;
    deltas[i] = d;
  }
  return deltas;
}

pll find_longest_match(vector<ll> deltas) {
  umap<ll, ll> m;
  m[0] = -1;
  pll lr;
  for (ll i = 0; i < deltas.size(); ++i) {
    if (m.find(deltas[i]) == m.end()) {
      m[deltas[i]] = i;
    } else {
      ll left = m[deltas[i]];
      ll dist = i - left;
      ll longest = lr.second - lr.first;
      if (longest < dist) {
        lr.first = left;
        lr.second = i;
      }
    }
  }
  return lr;
}

string find_longest_subarr(string s) {
  vector<ll> deltas = compute_delta_arr(s);
  pll lr = find_longest_match(deltas);
  return s.substr(lr.first + 1, lr.second - lr.first);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string s;
  ifs >> s;
  string res = find_longest_subarr(s);
  puts(res.c_str());
  puts("");
}

int main() {
  solve("../testcases/17_05/01.txt");
  solve("../testcases/17_05/02.txt");
  solve("../testcases/17_05/03.txt");
  solve("../testcases/17_05/04.txt");
}

// # ../testcases/17_05/01.txt
// c2de34

// # ../testcases/17_05/02.txt
// 1tu6aoi007g9

// # ../testcases/17_05/03.txt
// aaaaaaaaaa0000000000

// # ../testcases/17_05/04.txt
// a0000a000a000aaaaaaa
