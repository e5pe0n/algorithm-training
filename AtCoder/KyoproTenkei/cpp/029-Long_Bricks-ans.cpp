#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_W = 500'000;
const ll MAX_N = 250'000;
ll W, N;
ll L[MAX_N], R[MAX_N];

ll n;
ll dat[1 << 21], lazy[1 << 21];

void init(ll n_) {
  n = 1;
  while (n < n_)
    n *= 2;
}

void push(ll k) {
  if (k * 2 + 2 < n * 2) {
    lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
    lazy[k * 2 + 2] = max(lazy[k * 2 + 2], lazy[k]);
  }
  dat[k] = max(dat[k], lazy[k]);
  lazy[k] = 0;
}

void update(ll a, ll b, ll x, ll k, ll left, ll right) {
  // update values in range [a, b)
  push(k);
  if (right <= a || b <= left)
    return;
  else if (a <= left && right <= b) {
    lazy[k] = x;
    push(k);
    return;
  } else {
    update(a, b, x, k * 2 + 1, left, (left + right) / 2);
    update(a, b, x, k * 2 + 2, (left + right) / 2, right);
    dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

ll range_max(ll a, ll b, ll k, ll left, ll right) {
  // get the max value in range [a, b)
  push(k);
  if (right <= a || b <= left) return 0;
  if (a <= left && right <= b) return dat[k];
  ll lc = range_max(a, b, k * 2 + 1, left, (left + right) / 2);
  ll rc = range_max(a, b, k * 2 + 2, (left + right) / 2, right);
  return max(lc, rc);
}

int main() {
  cin >> W >> N;
  init(W);
  for (ll i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }
  for (ll i = 0; i < N; ++i) {
    ll h = range_max(L[i], R[i] + 1, 0, 0, n) + 1;
    update(L[i], R[i] + 1, h, 0, 0, n);
    printf("%lld\n", h);
  }
}