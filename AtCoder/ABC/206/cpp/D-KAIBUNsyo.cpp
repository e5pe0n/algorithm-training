#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 2 * 1e5;
const ll MAX_A = 2 * 1e5;

ll N;
vector<ll> A(MAX_N);
vector<ll> par(MAX_A + 1), rnk(MAX_A + 1);

void init() {
  for (ll i = 0; i <= MAX_A; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y])
    par[y] = x;
  else {
    par[x] = y;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
}

bool same(ll x, ll y) {
  return find(x) == find(y);
}

int main() {
  cin >> N;
  init();
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll left = 0, right = N - 1;
  ll res = 0;
  while (left < right) {
    if (!same(A[left], A[right])) {
      ++res;
      unite(A[left], A[right]);
    }
    ++left, --right;
  }
  printf("%lld\n", res);
}