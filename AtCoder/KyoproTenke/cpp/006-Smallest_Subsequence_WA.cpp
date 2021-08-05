// WA
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using plc = pair<ll, char>;

const ll INF = 1e18;
const ll MAX_N = 1 << 18;
ll N, K;
string S;
ll n;
plc dat[MAX_N * 2 - 1];
vector<ll> idxs;

void init() {
  n = 1;
  while (n < N) {
    n *= 2;
  }
  for (ll i = 0; i < n * 2 - 1; ++i) {
    dat[i] = {INF, 'z'};
  }
}

void update(ll k, char c) {
  ll i = k;
  k += n - 1;
  dat[k] = {i, c};
  while (k > 0) {
    k = (k - 1) / 2;
    auto lc = dat[k * 2 + 1];
    auto rc = dat[k * 2 + 2];
    if (lc.second <= rc.second) {
      dat[k] = lc;
    } else {
      dat[k] = rc;
    }
  }
}

plc query(ll a, ll b, ll k, ll left, ll right) {
  if (right <= a || b <= left) return {INF, 'z'};
  if (a <= left && right <= b)
    return dat[k];
  else {
    auto lc = query(a, b, k * 2 + 1, left, (left + right) / 2);
    auto rc = query(a, b, k * 2 + 2, (left + right) / 2, right);
    if (lc.second <= rc.second)
      return lc;
    else
      return rc;
  }
}

void rec(ll left, ll right) {
  auto [i, c] = query(left, right, 0, 0, n);
  if (i == INF) return;
  idxs.push_back(i);
  if (idxs.size() == K) return;
  rec(i + 1, right);
  if (idxs.size() == K) return;
  rec(left, i);
}

int main() {
  cin >> N >> K >> S;
  init();
  for (ll i = 0; i < N; ++i) {
    update(i, S[i]);
  }
  rec(0, N);
  sort(idxs.begin(), idxs.end());
  for (auto idx : idxs) {
    printf("%c", S[idx]);
  }
  puts("");
}