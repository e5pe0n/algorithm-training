// Cracking the Coding Interview p.266
#include <fstream>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using tllc = tuple<ll, ll, char>;

struct Node {
  ll x;
  shared_ptr<Node> left, right;
  Node(ll _x) : Node(_x, nullptr, nullptr) {}
  Node(ll _x, shared_ptr<Node> _left, shared_ptr<Node> _right)
      : x(_x), left(_left), right(_right) {}
  string to_str() {
    return "(" + (left ? left->to_str() : "null") + " " + to_string(x) + " "
           + (right ? right->to_str() : "null") + ")";
  }
};

struct Tree {
  shared_ptr<Node> root;
  Tree(shared_ptr<Node> _root) : root(_root) {}
  string to_str() {
    return root ? root->to_str() : "null";
  }
};

shared_ptr<Tree> make_bt(const ll &root,
                         const vector<ll> &node_idxs,
                         const vector<tllc> &edges) {
  map<ll, shared_ptr<Node>> nodes;
  for (auto &idx : node_idxs) {
    nodes[idx] = make_shared<Node>(idx);
  }
  for (auto &e : edges) {
    if (get<2>(e) == 'l') {
      nodes[get<0>(e)]->left = nodes[get<1>(e)];
    } else {
      nodes[get<0>(e)]->right = nodes[get<1>(e)];
    }
  }
  return make_shared<Tree>(nodes[root]);
}

void get_order_string(shared_ptr<Node> node, string &s) {
  if (node == nullptr) {
    s += 'X';
    return;
  }
  s += to_string(node->x);
  s += ' ';
  get_order_string(node->left, s);
  get_order_string(node->right, s);
}

bool contains_tree(shared_ptr<Tree> t1, shared_ptr<Tree> t2) {
  string s1{}, s2{};
  get_order_string(t1->root, s1);
  get_order_string(t2->root, s2);
  return s1.find(s2) != string::npos;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, a;
  ifs >> n >> a;
  vector<ll> node_idxs1 = vector<ll>(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> node_idxs1[i];
  }
  vector<tllc> edges1 = vector<tllc>(n - 1);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    edges1[i] = make_tuple(u, v, c);
  }
  ll m, b;
  ifs >> m >> b;
  vector<ll> node_idxs2 = vector<ll>(m);
  for (ll i = 0; i < m; ++i) {
    ifs >> node_idxs2[i];
  }
  vector<tllc> edges2 = vector<tllc>(m - 1);
  for (ll i = 0; i < m - 1; ++i) {
    ll p, q;
    char c;
    ifs >> p >> q >> c;
    edges2[i] = make_tuple(p, q, c);
  }
  shared_ptr<Tree> t1 = make_bt(a, node_idxs1, edges1);
  shared_ptr<Tree> t2 = make_bt(b, node_idxs2, edges2);
  puts(contains_tree(t1, t2) ? "true" : "false");
  puts("");
}

int main() {
  solve("../testcases/04_10/01.txt");
  solve("../testcases/04_10/02.txt");
  solve("../testcases/04_10/03.txt");
  solve("../testcases/04_10/04.txt");
  solve("../testcases/04_10/05.txt");
  solve("../testcases/04_10/06.txt");
  solve("../testcases/04_10/07.txt");
  solve("../testcases/04_10/08.txt");
  solve("../testcases/04_10/09.txt");
}

// # ../testcases/04_10/01.txt
// true

// # ../testcases/04_10/02.txt
// true

// # ../testcases/04_10/03.txt
// true

// # ../testcases/04_10/04.txt
// true

// # ../testcases/04_10/05.txt
// true

// # ../testcases/04_10/06.txt
// false

// # ../testcases/04_10/07.txt
// false

// # ../testcases/04_10/08.txt
// false

// # ../testcases/04_10/09.txt
// false
