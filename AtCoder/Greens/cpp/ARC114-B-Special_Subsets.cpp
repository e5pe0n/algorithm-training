#include <bits/stdc++.h>
#define MAX_N 200'000
#define MOD 998244353
using namespace std;
typedef long long ll;

ll N;
ll F[MAX_N];

ll par[MAX_N], rnk[MAX_N];

void init() {
  for (ll i = 0; i < N; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y])
    par[x] = y;
  else {
    par[y] = x;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
}

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

int main() {
  cin >> N;
  init();
  for (ll i = 0; i < N; ++i) {
    cin >> F[i];
    --F[i];
    unite(i, F[i]);
  }
  set<ll> st;
  for (ll i = 0; i < N; ++i) {
    st.insert(find(i));
  }
  ll res = mod_pow(2, st.size()) - 1;
  printf("%lld\n", res);
}