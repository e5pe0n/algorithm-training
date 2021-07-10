#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll M = 52 * 52 * 52;

ll N;
ll cnt[M];
vector<pll> E;
vector<ll> G[M];
ll res[M];

ll chr2ll(char c) {
  if (isupper(c))
    return c - 'A';
  else
    return c - 'a' + 26;
}

ll str2ll(char c1, char c2, char c3) {
  return chr2ll(c1) * 52 * 52 + chr2ll(c2) * 52 + chr2ll(c3);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    string s;
    cin >> s;
    ll u = str2ll(s[0], s[1], s[2]);
    ll v = str2ll(s[s.size() - 3], s[s.size() - 2], s[s.size() - 1]);
    ++cnt[u];
    G[v].push_back(u);
    E.push_back({u, v});
  }
  fill(res, res + M, -1);
  queue<ll> q;
  for (ll i = 0; i < M; ++i) {
    if (cnt[i] == 0) {
      res[i] = 0;
      q.push(i);
    }
  }
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (res[v] != -1) continue;
      --cnt[v];
      if (res[u] == 0) {
        res[v] = 1;
        q.push(v);
      } else if (cnt[v] == 0) {
        res[v] = 0;
        q.push(v);
      }
    }
  }
  for (ll i = 0; i < N; ++i) {
    ll r = res[E[i].second];
    if (r == -1)
      puts("Draw");
    else if (r == 0)
      puts("Takahashi");
    else
      puts("Aoki");
  }
}