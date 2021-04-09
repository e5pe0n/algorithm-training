#include <fstream>
#include <functional>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<string, string> pss;

bool is_one_way1(string s, string t) {
  if (abs((ll)(s.size() - t.size())) > 1) return false;
  if (s.size() == t.size()) {
    ll diff = 0;
    for (ll i = 0; i < s.size(); ++i) {
      if (s[i] != t[i]) ++diff;
      if (diff >= 2) return false;
    }
    return true;
  } else {
    if (s.size() < t.size()) swap(s, t);
    ll diff = s.size();
    for (ll i = 0; i < s.size(); ++i) {
      ll d = 0;
      for (ll j = 0; j < i; ++j) {
        if (s[j] != t[j]) ++d;
      }
      for (ll j = i + 1; j < s.size(); ++j) {
        if (s[j] != t[j - 1]) ++d;
      }
      diff = min(diff, d);
    }
    return diff <= 1;
  }
}

bool is_one_way2(string s, string t) {
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1));
  for (ll i = 0; i < s.size(); ++i) {
    for (ll j = 0; j < t.size(); ++j) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  ll n = max((ll)s.size(), (ll)t.size());
  return n - dp[s.size()][t.size()] <= 1;
}

bool insertable(string s, string t) {
  ll is = 0, it = 0;
  while (is < s.size() && it < t.size()) {
    if (s[is] != t[it]) {
      ++it;
      if (it - is >= 2) return false;
    } else {
      ++is, ++it;
    }
  }
  return true;
}

bool editable(string s, string t) {
  ll diff = 0;
  for (ll i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) ++diff;
    if (diff >= 2) return false;
  }
  return true;
}

bool is_one_way3(string s, string t) {
  if (s.size() > t.size()) swap(s, t);
  ll d = t.size() - s.size();
  if (d >= 2)
    return false;
  else if (d == 1)
    return insertable(s, t);
  else
    return editable(s, t);
}

bool is_one_way4(string s, string t) {
  if (s.size() > t.size()) swap(s, t);
  ll d = t.size() - s.size();
  if (d >= 2) return false;
  ll is = 0, it = 0;
  ll diff = 0;
  while (is < s.size() && it < t.size()) {
    if (s[is] != t[it]) {
      ++diff;
      if (diff >= 2) return false;
      if (d == 0) {
        ++is, ++it;
      } else {
        ++it;
      }
    } else {
      ++is, ++it;
    }
  }
  return true;
}

void show(const function<bool(string, string)> &f,
          const string &fn,
          const vector<pss> &ss) {
  printf("# %s\n", fn.c_str());
  for (auto p : ss) {
    string s = p.first, t = p.second;
    printf("%s, %s -> %s\n",
           s.c_str(),
           t.c_str(),
           is_one_way1(s, t) ? "true" : "false");
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_05.txt");
  ll n;
  ifs >> n;
  vector<pss> ss;
  for (ll i = 0; i < n; ++i) {
    string s, t;
    ifs >> s >> t;
    ss.push_back({s, t});
  }
  show(is_one_way1, "is_one_way1", ss);
  show(is_one_way2, "is_one_way2", ss);
  show(is_one_way3, "is_one_way3", ss);
  show(is_one_way4, "is_one_way4", ss);
}