#include <algorithm>
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

vector<string> _transform(const string &s,
                          const string &t,
                          umap<string, vector<string>> graph) {
  umap<string, string> prv1, prv2;
  umap<string, ll> dist1, dist2;
  ll inf = graph.size() + 1;
  for (const auto &[w, _] : graph) {
    dist1[w] = dist2[w] = inf;
  }
  dist1[s] = dist2[t] = 0;
  queue<string> q;
  q.push(s);
  q.push(t);
  string collision;
  while (q.size()) {
    string u = q.front();
    q.pop();
    if (dist1[u] < inf && dist2[u] < inf) {
      collision = u;
      break;
    }
    for (const auto &v : graph[u]) {
      if (dist1[v] > dist1[u] + 1) {
        dist1[v] = dist1[u] + 1;
        prv1[v] = u;
        q.push(v);
      }
      if (dist2[v] > dist2[u] + 1) {
        dist2[v] = dist2[u] + 1;
        prv2[v] = u;
        q.push(v);
      }
    }
  }
  if (collision == "") return {};
  vector<string> r_from_a;
  string u = collision;
  while (prv1.find(u) != prv1.end()) {
    r_from_a.push_back(prv1[u]);
    u = prv1[u];
  }
  vector<string> from_b;
  u = collision;
  while (prv2.find(u) != prv1.end()) {
    from_b.push_back(prv2[u]);
    u = prv2[u];
  }
  vector<string> res;
  for (ll i = r_from_a.size() - 1; i >= 0; --i) {
    res.push_back(r_from_a[i]);
  }
  res.push_back(collision);
  for (const auto &w : from_b) {
    res.push_back(w);
  }
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

// # ../testcases/17_22/01.txt
// DAMP->LAMP->LIMP->LIME->LIKE

// # ../testcases/17_22/02.txt
// DAMP->TAMP->TIMP->TIME->LIME->LIKE
