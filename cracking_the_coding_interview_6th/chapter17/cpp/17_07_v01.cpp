#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pss = pair<string, string>;

template <typename T> class FindUnionTree {
  map<T, T> par;
  map<T, ll> rnk;

public:
  FindUnionTree(vector<T> v) {
    for (auto _v : v)
      par[_v] = _v;
  }
  T find(T u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
  }
  void unite(T u, T v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rnk[u] < rnk[v]) {
      par[u] = v;
    } else {
      par[v] = u;
      if (rnk[u] == rnk[v]) ++rnk[u];
    }
  }
  bool same(T u, T v) {
    return find(u) == find(v);
  }
};

map<string, ll> cnt_real_freq(map<string, ll> name_freq, vector<pss> synonyms) {
  vector<string> names;
  for (auto [name, _] : name_freq) {
    names.push_back(name);
  }
  FindUnionTree<string> fut{names};
  for (auto [name1, name2] : synonyms) {
    fut.unite(name1, name2);
  }
  map<string, ll> cnt;
  for (auto [name, freq] : name_freq) {
    cnt[fut.find(name)] += freq;
  }
  return cnt;
}

string repr_map(map<string, ll> m) {
  string res = "[";
  for (auto [k, v] : m) {
    res += "(";
    res += k;
    res += ", ";
    res += to_string(v);
    res += "), ";
  }
  res.pop_back();
  res.pop_back();
  return res += "]";
}

void solve(const string &fp_names, const string &fp_synonyms) {
  printf("# %s\n", fp_names.c_str());
  ifstream ifs_name{fp_names};
  ll n;
  ifs_name >> n;
  map<string, ll> names;
  for (ll i = 0; i < n; ++i) {
    string name;
    ll num;
    ifs_name >> name >> num;
    names[name] = num;
  }
  ifstream ifs_synonyms{fp_synonyms};
  ifs_synonyms >> n;
  vector<pss> synonyms(n);
  for (ll i = 0; i < n; ++i) {
    string name1, name2;
    ifs_synonyms >> name1 >> name2;
    synonyms[i] = {name1, name2};
  }
  map<string, ll> res = cnt_real_freq(names, synonyms);
  puts(repr_map(res).c_str());
  puts("");
}

int main() {
  solve("../testcases/17_07/names01.txt", "../testcases/17_07/synonyms01.txt");
  solve("../testcases/17_07/names02.txt", "../testcases/17_07/synonyms02.txt");
}

// # ../testcases/17_07/names01.txt
// [(Chris, 36), (Jon, 27)]

// # ../testcases/17_07/names02.txt
// [(authorise, 396), (body, 41), (community, 348), (dictate, 178), (embark,
// 52), (fortune, 318), (gallon, 7), (horn, 74), (identity, 92), (jet, 55),
// (mislead, 184), (offer, 97), (pardon, 242), (report, 249), (swallow, 269),
// (tenant, 28), (utter, 8), (value, 42), (wild, 129), (zone, 96)]