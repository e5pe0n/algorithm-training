#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_N = 1 << 22;
ll Q;
ll N;
ll n;
ll dat[MAX_N * 2 - 1];

void init() {
  n = 1;
  while (n < N)
    n *= 2;
}

void update(ll k, ll a) {
  k += n - 1;
  dat[k] ^= a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = dat[k * 2 + 1] ^ dat[k * 2 + 2];
  }
}

ll query(ll a, ll b, ll k, ll left, ll right) {
  if (right <= a || b <= left) return 0;
  if (a <= left && right <= b)
    return dat[k];
  else {
    ll vl = query(a, b, k * 2 + 1, left, (left + right) / 2);
    ll vr = query(a, b, k * 2 + 2, (left + right) / 2, right);
    return vl ^ vr;
  }
}

int main() {
  cin >> N >> Q;
  init();
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    update(i, A);
  }
  vector<ll> res;
  for (ll _ = 0; _ < Q; ++_) {
    ll T, X, Y;
    cin >> T >> X >> Y;
    if (T == 1) {
      --X;
      update(X, Y);
    } else {
      --X;
      res.push_back(query(X, Y, 0, 0, n));
    }
  }
  for (auto v : res)
    printf("%lld\n", v);
}