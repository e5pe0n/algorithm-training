#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Res {
  string spaced;
  ll cnt_unrec;
};

Res _re_space(const string &s,
              map<char, vector<string>> &words,
              ll idx,
              vector<string> &tmp_spaced,
              ll cnt_unrec,
              string prv) {
  if (idx == s.size()) {
    if (tmp_spaced.size() == 0) return {s, (ll)s.size()};
    string res;
    for (auto w : tmp_spaced) {
      if (w.size()) {
        res += w;
        res += " ";
      }
    }
    if (res.size()) res.pop_back();
    return Res{res, cnt_unrec};
  }
  Res res{"", (ll)s.size()};
  for (auto w : words[s[idx]]) {
    tmp_spaced.push_back(prv);
    if (cnt_unrec < res.cnt_unrec && w == s.substr(idx, w.size())) {
      tmp_spaced.push_back(w);
      Res r = _re_space(s, words, idx + w.size(), tmp_spaced, cnt_unrec, "");
      if (res.cnt_unrec > r.cnt_unrec) {
        res.cnt_unrec = r.cnt_unrec;
        res.spaced = r.spaced;
        if (res.cnt_unrec == 0) break;
      }
      tmp_spaced.pop_back();
    }
    tmp_spaced.pop_back();
  }
  Res r = _re_space(s, words, idx + 1, tmp_spaced, cnt_unrec + 1, prv + s[idx]);
  return res.cnt_unrec < r.cnt_unrec ? res : r;
}

Res re_space(const string &s, map<char, vector<string>> &words) {
  vector<string> tmp_spaced;
  return _re_space(s, words, 0, tmp_spaced, 0, "");
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string s;
  ifs >> s;
  ll n;
  ifs >> n;
  map<char, vector<string>> words;
  for (ll i = 0; i < n; ++i) {
    string w;
    ifs >> w;
    words[w[0]].push_back(w);
  }
  Res res = re_space(s, words);
  printf("%lld, %s\n", res.cnt_unrec, res.spaced.c_str());
  puts("");
}

int main() {
  solve("../testcases/17_13/01.txt");
  solve("../testcases/17_13/02.txt");
  solve("../testcases/17_13/03.txt");
}