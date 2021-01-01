#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_Q 200'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, Q;
ll A[MAX_N], B[MAX_N];
ll P[MAX_Q], X[MAX_Q];

vector<ll> G[MAX_N];
ll res[MAX_N];
ll passed[MAX_N];

void bfs() {
  queue<pll> q;
  q.push({0, res[0]});
  passed[0] = true;
  while (!q.empty()) {
    ll i, d;
    tie(i, d) = q.front();
    q.pop();
    for (auto ni : G[i]) {
      if (!passed[ni]) {
        passed[ni] = true;
        res[ni] += d;
        q.push({ni, res[ni]});
      }
    }
  }
}

void solve() {
  for (int i = 0; i < N - 1; ++i) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  for (int i = 0; i < Q; ++i) {
    res[P[i]] += X[i];
  }
  bfs();
  for (int i = 0; i < N; ++i) {
    printf("%lld\n", res[i]);
  }
}

int main() {
  cin >> N >> Q;
  for (int i = 0; i < N - 1; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  for (int i = 0; i < Q; ++i) {
    cin >> P[i] >> X[i];
    --P[i];
  }
  solve();
}