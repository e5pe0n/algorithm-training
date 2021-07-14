#include <algorithm>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class MedianMaintainer {
  priority_queue<ll> _smaller;
  priority_queue<ll, vector<ll>, greater<vector<ll>::value_type>> _larger;

public:
  MedianMaintainer() {}
  string repr() {
    priority_queue sm = _smaller;
    priority_queue la = _larger;
    string res = "me: " + to_string(median()) + ", ";
    res += "sm: [";
    while (sm.size()) {
      res += to_string(sm.top());
      res += ", ";
      sm.pop();
    }
    res.pop_back();
    res.pop_back();
    res += "]\nla: [";
    while (la.size()) {
      res += to_string(la.top());
      res += ", ";
      la.pop();
    }
    res.pop_back();
    res.pop_back();
    return res += "]";
  }
  double median() {
    if (_smaller.size() == _larger.size())
      return (_smaller.top() + _larger.top()) / 2.0;
    else if (_smaller.size() > _larger.size())
      return _smaller.top();
    else
      return _larger.top();
  }
  void push(vector<ll> arr) {
    for (auto v : arr)
      _larger.push(v);
    while (_smaller.size() < _larger.size()) {
      _smaller.push(_larger.top());
      _larger.pop();
    }
  }
};

vector<double> medians(vector<vector<ll>> arrs) {
  MedianMaintainer mm;
  vector<double> res;
  for (auto arr : arrs) {
    mm.push(arr);
    res.push_back(mm.median());
    // puts(mm.repr().c_str());
    // puts("");
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n_rounds;
  ifs >> n_rounds;
  vector<ll> rounds(n_rounds);
  for (ll i = 0; i < n_rounds; ++i) {
    ifs >> rounds[i];
  }
  vector<vector<ll>> arrs(n_rounds);
  for (ll i = 0; i < n_rounds; ++i) {
    arrs[i] = vector<ll>(rounds[i]);
    for (ll j = 0; j < rounds[i]; ++j) {
      ifs >> arrs[i][j];
    }
  }
  vector<double> res = medians(arrs);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%.2f%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/17_20/01.txt");
  solve("../testcases/17_20/02.txt");
  solve("../testcases/17_20/03.txt");
  solve("../testcases/17_20/04.txt");
  solve("../testcases/17_20/05.txt");
}

// # ../testcases/17_20/01.txt
// 7.00 6.50 5.50

// # ../testcases/17_20/02.txt
// 0.00 1.50 -1.00

// # ../testcases/17_20/03.txt
// 0.00 0.00 0.00

// # ../testcases/17_20/04.txt
// 12.50 19.50 15.50

// # ../testcases/17_20/05.txt
// 13.50 20.50 29.00
