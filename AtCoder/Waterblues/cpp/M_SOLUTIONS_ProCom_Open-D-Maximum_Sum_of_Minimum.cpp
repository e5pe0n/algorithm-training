#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
typedef long long ll;

ll N;
ll C[MAX_N];
vector<ll> G[MAX_N];
ll res[MAX_N];

void bfs() {
  queue<ll> q;
  q.push(0);
  ll i = N - 1;
  res[0] = C[i--];
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (!res[v]) {
        res[v] = C[i--];
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    ll A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  for (ll i = 0; i < N; ++i) {
    cin >> C[i];
  }
  sort(C, C + N);
  bfs();
  ll score = 0;
  for (ll i = 0; i < N; ++i) {
    score += C[i];
  }
  score -= C[N - 1];
  printf("%lld\n", score);
  for (ll i = 0; i < N; ++i) {
    printf("%lld%c", res[i], i == N - 1 ? '\n' : ' ');
  }
}