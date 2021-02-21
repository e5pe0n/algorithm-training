#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
bool H[13][32];
ll D[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    string s;
    cin >> s;
    ll idx = s.find('/');
    string m = s.substr(0, idx);
    string d = s.substr(idx + 1);
    H[stoll(m)][stoll(d)] = true;
  }
  ll d = 0;
  ll cnt = 0;
  ll stock = 0;
  ll res = 0;
  for (ll i = 1; i < 13; ++i) {
    for (ll j = 1; j <= D[i]; ++j) {
      if (d == 0 || d == 6) {
        ++cnt;
        if (H[i][j]) ++stock;
      } else {
        if (H[i][j])
          ++cnt;
        else if (stock > 0) {
          ++cnt;
          --stock;
        } else
          cnt = 0;
      }
      d = (d + 1) % 7;
      res = max(res, cnt);
    }
  }
  printf("%lld\n", res);
}