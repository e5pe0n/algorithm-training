#include <deque>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000
#define MAX_Q 100'000

typedef long long ll;

using namespace std;

struct Edge {
  ll u, v, w;
  Edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
};

ll N, Q, K;
vector<Edge> E[MAX_N]{};
bool used[MAX_N]{};
ll D[MAX_N]{};
int X[MAX_Q]{};
int Y[MAX_Q]{};

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    E[a].emplace_back(a, b, c);
    E[b].emplace_back(b, a, c);
  }
  cin >> Q >> K;
  for (int i = 0; i < Q; ++i) {
    int x, y;
    cin >> x >> y;
    X[i] = --x;
    Y[i] = --y;
  }
  deque<ll> q{K - 1};
  while (!q.empty()) {
    ll u = q.front();
    q.pop_front();
    used[u] = true;
    for (auto e : E[u]) {
      if (!used[e.v]) {
        D[e.v] = D[e.u] + e.w;
        q.push_back(e.v);
      }
    }
  }
  for (int i = 0; i < Q; ++i) {
    printf("%lld\n", D[X[i]] + D[Y[i]]);
  }
}