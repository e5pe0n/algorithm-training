#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 200'000;

ll N, P, Q, U, D;
vector<ll> G[MAX_N];
ll in[MAX_N], out[MAX_N];
vector<vector<ll>> mat;

ll cnt = 0;

void dfs(ll u, ll d) {
  in[u] = cnt++;
  mat[d].push_back(in[u]);
  for (auto v : G[u]) {
    dfs(v, d + 1);
  }
  out[u] = cnt++;
}

int main() {
  cin >> N;
  mat = vector<vector<ll>>(N);
  for (ll i = 1; i < N; ++i) {
    cin >> P;
    G[P - 1].push_back(i);
  }
  dfs(0, 0);
  for (ll i = 0; i < N; ++i) {
    cout << in[i] << ' ';
  }
  cout << endl;

  for (ll i = 0; i < N; ++i) {
    cout << out[i] << ' ';
  }
  cout << endl;

  cin >> Q;
  while (Q--) {
    cin >> U >> D;
    --U;
    vector<ll> &v = mat[D];
    cout << lower_bound(v.begin(), v.end(), out[U])
                - lower_bound(v.begin(), v.end(), in[U])
         << endl;
  }
}