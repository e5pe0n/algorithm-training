// Cracking the Coding Interview p.252
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Project {
private:
  vector<shared_ptr<Project>> children;
  map<ll, shared_ptr<Project>> m;
  ll name;
  ll dependencies = 0;

public:
  Project(ll _name) : name(_name) {}

  void add_neighbor(shared_ptr<Project> node) {
    if (m.find(node->get_name()) == m.end()) {
      children.push_back(node);
      m[node->get_name()] = node;
      node->increment_dependencies();
    }
  }

  void increment_dependencies() {
    ++dependencies;
  }

  void decrement_dependencies() {
    --dependencies;
  }

  ll get_name() {
    return name;
  }

  vector<shared_ptr<Project>> get_children() {
    return children;
  }

  ll get_number_dependencies() {
    return dependencies;
  }
};

class Graph {
private:
  vector<shared_ptr<Project>> nodes;
  map<ll, shared_ptr<Project>> m;

public:
  shared_ptr<Project> get_or_create_node(ll name) {
    if (m.find(name) == m.end()) {
      nodes.emplace_back(make_shared<Project>(name));
      m[name] = nodes.back();
    }
    return m[name];
  }

  void add_edge(ll start_name, ll end_name) {
    shared_ptr<Project> start = get_or_create_node(start_name);
    shared_ptr<Project> end = get_or_create_node(end_name);
    start->add_neighbor(end);
  }

  vector<shared_ptr<Project>> get_nodes() {
    return nodes;
  }
};

ll add_non_dependent(vector<shared_ptr<Project>> &order,
                     vector<shared_ptr<Project>> &projects,
                     ll offset) {
  for (auto project : projects) {
    if (project->get_number_dependencies() == 0) {
      order[offset] = project;
      ++offset;
    }
  }
  return offset;
}

vector<shared_ptr<Project>>
order_project(vector<shared_ptr<Project>> projects) {
  vector<shared_ptr<Project>> order(projects.size());
  ll end_of_list = add_non_dependent(order, projects, 0);
  ll to_be_processed = 0;
  while (to_be_processed < order.size()) {
    shared_ptr<Project> current = order[to_be_processed];

    if (current == nullptr) return vector<shared_ptr<Project>>{};

    vector<shared_ptr<Project>> children = current->get_children();
    for (auto child : children) {
      child->decrement_dependencies();
    }

    end_of_list = add_non_dependent(order, children, end_of_list);
    ++to_be_processed;
  }

  return order;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  Graph graph;
  for (ll i = 0; i < n; ++i) {
    graph.get_or_create_node(i);
  }
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    ifs >> u >> v;
    graph.add_edge(--u, --v);
  }
  vector<shared_ptr<Project>> res = order_project(graph.get_nodes());
  if (res.size() == 0) {
    puts("error");
  } else {
    for (ll i = 0; i < res.size(); ++i) {
      printf(
          "%lld%c", res[i]->get_name() + 1, i == res.size() - 1 ? '\n' : ' ');
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
// 2 3 8 1 5 12 9 4 7 6 10 11

// # ../testcases/04_07/04.txt
// error

// # ../testcases/04_07/05.txt
// 1 2

// # ../testcases/04_07/06.txt
// error
