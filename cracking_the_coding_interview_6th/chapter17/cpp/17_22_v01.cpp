#include <fstream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
template <typename T, typename U> using umap = unordered_map<T, U>;

umap<string, vector<string>> create_graph(const set<string> &words) {
  umap<string, vector<string>> graph;
  for (const auto &w : words) {
    for (const auto &_w : words) {
      if (w.size() != _w.size()) continue;
      ll diff = 0;
      for (ll i = 0; i < w.size(); ++i) {
        if (w[i] != _w[i]) ++diff;
      }
      if (diff == 1) {
        graph[w].push_back(_w);
        graph[_w].push_back(w);
      }
    }
  }
  return graph;
}

// vector<string> _transform(const string &u,
//                           const string &t,
//                           umap<string, vector<string>> &graph,
//                           umap<string, bool> &used) {
//   if (u == t) {
//     vector<string> res{u};
//     return res;
//   }
//   used[u] = true;
//   for (const auto &v : graph[u]) {
//     if (!used[v]) {
//       used[v] = true;
//       vector<string> r = _transform(v, t, graph, used);
//       if (r.size()) {
//         r.push_back(u);
//         return r;
//       }
//       used[v] = false;
//     }
//   }
//   return {};
// }

vector<string> _transform(const string &s,
                          const string &t,
                          umap<string, vector<string>> &graph) {
  umap<string, string> prv;
  umap<string, ll> dist;
  for (const auto [w, _] : graph) {
    dist[w] = graph.size() + 1;
  }
  dist[s] = 0;
  queue<string> q;
  q.push(s);
  while (q.size()) {
    string u = q.front();
    q.pop();
    if (u == t) break;
    for (const auto &v : graph[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        prv[v] = u;
        q.push(v);
      }
    }
  }
  string u = t;
  vector<string> r_res;
  while (prv.find(u) != prv.end()) {
    r_res.push_back(prv[u]);
    u = prv[u];
  }
  if (r_res.size() == 0) return r_res;
  vector<string> res(r_res.rbegin(), r_res.rend());
  return res;
}

vector<string>
transform(const string &s, const string &t, const set<string> &words) {
  umap<string, vector<string>> graph = create_graph(words);
  return _transform(s, t, graph);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string s, t;
  ifs >> s >> t;
  ll n;
  ifs >> n;
  set<string> words;
  for (ll i = 0; i < n; ++i) {
    string w;
    ifs >> w;
    words.insert(w);
  }
  vector<string> res = transform(s, t, words);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%s%s", res[i].c_str(), i == res.size() - 1 ? "\n" : "->");
  }
  puts("");
}

int main() {
  solve("../testcases/17_22/01.txt");
  solve("../testcases/17_22/02.txt");
}