#include <bits/stdc++.h>
#define INF 1'000'000'000'000'000'001
using namespace std;
typedef long long ll;

string X;
ll M;

bool is_less(ll b) {
  __int128 x = 0;
  for (ll i = 0; i < X.size(); ++i) {
    x = x * b + X[i] - '0';
    if (x > M) return false;
  }
  return true;
}

int main() {
  cin >> X >> M;
  if (X.size() == 1) {
    if (X[0] - '0' > M) {
      puts("0");
      return 0;
    } else {
      puts("1");
      return 0;
    }
  }
  ll d = 0;
  for (ll i = 0; i < X.size(); ++i) {
    d = max(d, (ll)(X[i] - '0'));
  }
  if (!is_less(d + 1)) {
    puts("0");
    return 0;
  }
  ll ub = INF;
  ll lb = d + 1;
  while (ub - lb > 1) {
    ll md = (ub + lb) / 2;
    if (is_less(md)) {
      lb = md;
    } else {
      ub = md;
    }
  }
  printf("%lld\n", lb - d);
}