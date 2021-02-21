#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;
typedef long long ll;

string s;
ll N;
string T[MAX_N];

int main() {
  vector<string> S;
  getline(cin, s);
  istringstream iss(s);
  for (string word; iss >> word;)
    S.push_back(word);
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> T[i];
  }
  for (ll i = 0; i < S.size(); ++i) {
    string s = S[i];
    for (ll j = 0; j < N; ++j) {
      string t = T[j];
      if (s.size() != t.size()) continue;
      bool f = true;
      for (ll k = 0; k < s.size(); ++k) {
        if (s[k] != t[k] && t[k] != '*') {
          f = false;
          break;
        }
      }
      if (f) {
        S[i] = string(S[i].size(), '*');
        break;
      }
    }
  }
  for (ll i = 0; i < S.size(); ++i) {
    printf("%s%c", S[i].c_str(), i == S.size() - 1 ? '\n' : ' ');
  }
}