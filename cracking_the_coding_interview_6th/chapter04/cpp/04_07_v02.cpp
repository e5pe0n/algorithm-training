#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

bool dfs(ll u,
         vector<vector<ll>> &graph,
         deque<ll> &q,
         vector<bool> &added,
         vector<bool> &used) {
  bool res = true;
  for (auto &v : graph[u]) {
    if (used[v]) return false; // loop detected
    if (added[v]) continue;
    used[v] = true;
    res &= dfs(v, graph, q, added, used);
    used[v] = false;
  }
  q.push_front(u);
  added[u] = true;
  return res;
}

vector<ll> get_build_order(const ll &n, vector<vector<ll>> graph) {
  deque<ll> q;
  vector<bool> added(n);
  for (ll u = 0; u < n; ++u) {
    if (added[u]) continue;
    vector<bool> used(n);
    used[u] = true;
    bool no_loop = dfs(u, graph, q, added, used);
    if (!no_loop) return vector<ll>{};
  }
  added = vector<bool>(n);
  vector<ll> res(n);
  ll idx = n - 1;
  while (!q.empty()) {
    ll u = q.back();
    q.pop_back();
    if (!added[u]) {
      res[idx--] = u;
      added[u] = true;
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  vector<vector<ll>> graph(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    ifs >> u >> v;
    --u, --v;
    graph[u].push_back(v);
  }
  vector<ll> res = get_build_order(n, graph);
  if (res.size() == 0)
    puts("error");
  else {
    for (ll i = 0; i < n; ++i) {
      printf("%lld%c", res[i] + 1, i == n - 1 ? '\n' : ' ');
    }
  }
  puts("");
}

int main() {
  solve("../testcases/04_07/01.txt");
  solve("../testcases/04_07/02.txt");
  solve("../testcases/04_07/03.txt");
  solve("../testcases/04_07/04.txt");
  solve("../testcases/04_07/05.txt");
  solve("../testcases/04_07/06.txt");
}

// # ../testcases/04_07/01.txt
// 6 5 2 1 4 3

// # ../testcases/04_07/02.txt
// error

// # ../testcases/04_07/03.txt
// 8 3 2 1 5 12 9 4 7 6 10 11

// # ../testcases/04_07/04.txt
// error

// # ../testcases/04_07/05.txt
// 2 1

// # ../testcases/04_07/06.txt
// error
