#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
const string d = "dict";
const string s = "set";

int main() {
  cin >> S;
  vector<ll> V;
  if (S == "{}") {
    puts(d.c_str());
    return 0;
  }
  for (ll i = 0; i < S.size(); ++i) {
    if (S[i] == '{') V.push_back(S[i]);
    if (S[i] == '}') V.pop_back();
    if (S[i] == ':' && V.size() == 1) {
      puts(d.c_str());
      return 0;
    }
  }
  puts(s.c_str());
}