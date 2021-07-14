#include <algorithm>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class MedianMaintener {
  priority_queue<ll> _smaller;
  priority_queue<ll, vector<ll>, greater<vector<ll>::value_type>> _larger;
  ll _median;

public:
  MedianMaintener() {}
  string repr() {
    priority_queue sm = _smaller;
    priority_queue la = _larger;
    string res = "me: " + to_string(_median) + ", ";
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
  ll median() {
    return _median;
  }
  ll push(vector<ll> arr) {
    if (arr.size() == 0) return _median;
    if (_smaller.size() == 0 && _larger.size() == 0) {
      sort(arr.begin(), arr.end());
      ll median_idx = (arr.size() - 1) / 2;
      _median = arr[median_idx];
      for (ll i = 0; i < median_idx; ++i) {
        _smaller.push(arr[i]);
      }
      for (ll i = median_idx + 1; i < arr.size(); ++i) {
        _larger.push(arr[i]);
      }
    } else {
      for (auto v : arr) {
        if (v < _median)
          _smaller.push(v);
        else
          _larger.push(v);
      }
      if (_smaller.size() == _larger.size())
        return _median;
      else if (_smaller.size() < _larger.size()) {
        _smaller.push(_median);
        while (_smaller.size() < _larger.size()) {
          _smaller.push(_larger.top());
          _larger.pop();
        }
      } else {
        _larger.push(_median);
        while (_smaller.size() > _larger.size()) {
          _larger.push(_smaller.top());
          _smaller.pop();
        }
      }
      if (_smaller.size() >= _larger.size()) {
        _median = _smaller.top();
        _smaller.pop();
      } else {
        _median = _larger.top();
        _larger.pop();
      }
      return _median;
    }
    return _median;
  }
};

vector<ll> medians(vector<vector<ll>> arrs) {
  MedianMaintener mm;
  vector<ll> res;
  for (auto arr : arrs) {
    res.push_back(mm.push(arr));
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
  vector<ll> res = medians(arrs);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
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
// 7 6 5

// # ../testcases/17_20/02.txt
// -1 1 -1

// # ../testcases/17_20/03.txt
// 0 0 0

// # ../testcases/17_20/04.txt
// 12 19 16

// # ../testcases/17_20/05.txt
// 12 19 28
