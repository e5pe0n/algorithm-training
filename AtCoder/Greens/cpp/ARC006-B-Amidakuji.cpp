#include <bits/stdc++.h>
#define MAX_L 20
using namespace std;
typedef long long ll;

ll N, L;
string S[MAX_L];

int main() {
  string line;
  getline(cin, line);
  istringstream iss(line);
  string s;
  iss >> s;
  N = stoll(s);
  iss >> s;
  L = stoll(s);
  for (ll i = 0; i < L; ++i) {
    getline(cin, S[i]);
  }
  getline(cin, s);
  ll y = L - 1;
  ll x = 0;
  for (ll i = 0; i < s.size(); ++i) {
    if (s[i] == 'o') {
      x = i;
      break;
    }
  }
  ll W = S[0].size();
  for (ll i = L - 1; i >= 0; --i) {
    for (ll j = 0; j < W; ++j) {
      if (i != y || j != x) continue;
      ll left = x - 1;
      ll right = x + 1;
      if (left >= 0 && S[i][left] == '-') {
        x -= 2;
        break;
      }
      if (right < S[0].size() && S[i][right] == '-') {
        x += 2;
        break;
      }
    }
    --y;
  }
  printf("%lld\n", x / 2 + 1);
}