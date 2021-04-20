#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

bool bfs(const vector<vector<ll>> &graph, ll num_of_vertices, ll src, ll dst) {
  vector<bool> visited(num_of_vertices);
  queue<ll> q;
  q.push(src);
  visited[src] = true;
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (const auto &v : graph[u]) {
      if (!visited[v]) {
        visited[v] = true;
        if (v == dst) return true;
        q.push(v);
      }
    }
  }
  return false;
}

void solve(const string &path) {
  ifstream ifs(path);
  ll n, m, s, t;
  ifs >> n >> m >> s >> t;
  vector<vector<ll>> graph(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    ifs >> u >> v;
    graph[--u].push_back(--v);
  }
  printf("%s\n", bfs(graph, n, --s, --t) ? "true" : "false");
}

int main() {
  solve("../testcases/04_01_01.txt");
  solve("../testcases/04_01_02.txt");
  solve("../testcases/04_01_03.txt");
}

// true
// false
// true
