#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_M 200'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_N], B[MAX_N];
ll C[MAX_M], D[MAX_M];

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

bool same(ll x, ll y) {
  return find(x) == find(y);
}

int main() {
  cin >> N >> M;
  init();
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B[i];
  }
  for (ll i = 0; i < M; ++i) {
    cin >> C[i] >> D[i];
    --C[i];
    --D[i];
    unite(C[i], D[i]);
  }
  map<ll, vector<ll>> C;
  for (ll i = 0; i < N; ++i) {
    C[find(i)].push_back(i);
  }
  for (auto p : C) {
    ll sumA = 0;
    ll sumB = 0;
    for (auto v : p.second) {
      sumA += A[v];
      sumB += B[v];
    }
    if (sumA != sumB) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}