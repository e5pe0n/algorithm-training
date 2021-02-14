#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_M 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_M], B[MAX_M];

ll par[MAX_N], rnk[MAX_N];

void init() {
  for (ll i = 0; i < N; ++i) {
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
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
}

int main() {
  cin >> N >> M;
  init();
  for (ll i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    unite(A[i] - 1, B[i] - 1);
  }
  set<ll> st;
  for (ll i = 0; i < N; ++i) {
    st.insert(find(i));
  }
  printf("%ld\n", st.size() - 1);
}