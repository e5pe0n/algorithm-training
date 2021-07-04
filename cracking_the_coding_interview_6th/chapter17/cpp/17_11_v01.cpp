#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pss = pair<string, string>;

class DistCalculator {
  map<string, vector<ll>> _word_pos_map;

public:
  DistCalculator(const vector<string> words) {
    for (ll i = 0; i < words.size(); ++i) {
      _word_pos_map[words[i]].push_back(i);
    }
  }
  ll dist(const string w1, const string w2) {
    if (_word_pos_map.find(w1) == _word_pos_map.end()
        || _word_pos_map.find(w2) == _word_pos_map.end())
      return -1;
    ll idx1 = 0, idx2 = 0;
    vector<ll> *pos1 = &_word_pos_map[w1];
    vector<ll> *pos2 = &_word_pos_map[w2];
    ll d = abs(pos1->at(idx1) - pos2->at(idx2));
    while (idx1 < pos1->size() && idx2 < pos2->size()) {
      d = min(d, abs(pos1->at(idx1) - pos2->at(idx2)));
      if (pos1->at(idx1) < pos2->at(idx2))
        ++idx1;
      else
        ++idx2;
    }
    return d;
  }
};

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<string> words(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> words[i];
  }
  ll m;
  ifs >> m;
  vector<pss> pairs(m);
  for (ll i = 0; i < m; ++i) {
    string w1, w2;
    ifs >> w1 >> w2;
    pairs[i] = {w1, w2};
  }
  DistCalculator dc{words};
  for (auto [w1, w2] : pairs) {
    printf("d(%s, %s)=%lld\n", w1.c_str(), w2.c_str(), dc.dist(w1, w2));
  }
  puts("");
}

int main() {
  solve("../testcases/17_11/01.txt");
}

// # ../testcases/17_11/01.txt
// d(fixed, bake)=1
// d(jam, turkey)=15
// d(concerned, small)=99
// d(fixed, fixed)=0
