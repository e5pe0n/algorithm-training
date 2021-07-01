#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pss = pair<string, string>;

ll cnt_synonyms(map<string, vector<string>> &G,
                map<string, ll> &name_freq,
                map<string, bool> &used,
                const string &s) {
  queue<string> q;
  q.push(s);
  used[s] = true;
  ll cnt = name_freq[s];
  while (q.size()) {
    string u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (!used[v]) {
        used[v] = true;
        q.push(v);
        cnt += name_freq[v];
      }
    }
  }
  return cnt;
}

map<string, ll> cnt_real_freq(map<string, ll> name_freq, vector<pss> synonyms) {
  map<string, vector<string>> G;
  for (auto [name1, name2] : synonyms) {
    G[name1].push_back(name2);
    G[name2].push_back(name1);
  }
  map<string, bool> used;
  map<string, ll> res;
  for (auto [name, freq] : name_freq) {
    if (!used[name]) res[name] = cnt_synonyms(G, name_freq, used, name);
  }
  return res;
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
  ifstream ifs_names{fp_names};
  ll n;
  ifs_names >> n;
  map<string, ll> name_freq;
  for (ll i = 0; i < n; ++i) {
    string name;
    ll freq;
    ifs_names >> name >> freq;
    name_freq[name] = freq;
  }
  ifstream ifs_synonyms{fp_synonyms};
  ifs_synonyms >> n;
  vector<pss> synonyms(n);
  for (ll i = 0; i < n; ++i) {
    string name1, name2;
    ifs_synonyms >> name1 >> name2;
    synonyms[i] = {name1, name2};
  }
  map<string, ll> res = cnt_real_freq(name_freq, synonyms);
  puts(repr_map(res).c_str());
  puts("");
}

int main() {
  solve("../testcases/17_07/names01.txt", "../testcases/17_07/synonyms01.txt");
  solve("../testcases/17_07/names02.txt", "../testcases/17_07/synonyms02.txt");
}

// # ../testcases/17_07/names01.txt
// [(Chris, 36), (John, 27)]

// # ../testcases/17_07/names02.txt
// [(abundant, 396), (body, 41), (close, 348), (dictate, 178), (embark, 52),
// (feature, 318), (gallon, 7), (horn, 74), (identity, 92), (jet, 55),
// (magazine, 184), (occupy, 97), (pardon, 242), (release, 249), (seem, 269),
// (tenant, 28), (utter, 8), (value, 42), (wild, 129), (zone, 96)]
