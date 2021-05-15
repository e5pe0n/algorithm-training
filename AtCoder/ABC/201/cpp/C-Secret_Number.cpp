#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S;

int main() {
  cin >> S;
  ll must = 0;
  for (auto c : S) {
    if (c == 'o') ++must;
  }
  ll res = 0;
  for (ll i = 0; i < 10000; ++i) {
    stringstream ss;
    ss << setfill('0') << setw(4) << i;
    string s = ss.str();
    set<ll> must_set;
    bool ok = true;
    for (auto c : s) {
      ll j = c - '0';
      if (S[j] == 'o') must_set.insert(j);
      if (S[j] == 'x') ok = false;
    }
    if (must == must_set.size() && ok) ++res;
  }
  cout << res << endl;
}