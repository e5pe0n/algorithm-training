#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Edge {
  ll u, v;
  bool used;
};

vector<ll>
get_build_order(const ll &n, vector<vector<ll>> graph, vector<Edge> edges) {
  vector<ll> build_order(n, -1);
  ll ord = 0;
  for (ll i = 0; i < n; ++i) {
    queue<ll> q;
    q.push(i);
    while (!q.empty()) {
      ll u = q.front();
      q.pop();
      if (build_order[u] >= 0) continue;
      bool buildable = true;
      for (auto &j : graph[u]) {
        if (edges[j].v == u && !edges[j].used) buildable = false;
      }
      if (buildable) {
        build_order[u] = ord++;
        for (auto &j : graph[u]) {
          if (edges[j].u == u) {
            edges[j].used = true;
            q.push(edges[j].v);
          }
        }
      }
    }
  }
  vector<ll> res(n);
  for (ll i = 0; i < n; ++i) {
    if (build_order[i] < 0) return vector<ll>{};
    res[build_order[i]] = i;
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  vector<vector<ll>> graph(n);
  vector<Edge> edges(m);
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    ifs >> u >> v;
    --u, --v;
    edges[i] = Edge{u, v, false};
    graph[u].push_back(i);
    graph[v].push_back(i);
  }
  vector<ll> res = get_build_order(n, graph, edges);
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
// 5 6 2 1 4 3

// # ../testcases/04_07/02.txt
// error

// # ../testcases/04_07/03.txt
// 2 1 3 5 12 9 8 4 7 6 10 11

// # ../testcases/04_07/04.txt
// error

// # ../testcases/04_07/05.txt
// 1 2

// # ../testcases/04_07/06.txt
// error
