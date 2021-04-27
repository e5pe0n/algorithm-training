#include <chrono>
#include <fstream>
#include <iomanip>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using tllc = tuple<ll, ll, char>;
using hrc = chrono::high_resolution_clock;

struct Node {
  ll id, x;
  shared_ptr<Node> par, left, right;
  Node(ll _id, ll _x) : Node(_id, _x, nullptr, nullptr, nullptr) {}
  Node(ll _id,
       ll _x,
       shared_ptr<Node> _par,
       shared_ptr<Node> _left,
       shared_ptr<Node> _right)
      : id(_id), x(_x), par(_par), left(_left), right(_right) {}
  string to_str() {
    return "(" + (left ? left->to_str() : "null") + " [" + to_string(id) + "] "
           + to_string(x) + " " + (right ? right->to_str() : "null") + ")";
  }
};

class Tree {
private:
  ll num_of_node;

  void _indexing(shared_ptr<Node> node, const ll &idx) {
    if (node == nullptr) return;
    node->id = idx;
    _indexing(node->left, idx * 2 + 1);
    _indexing(node->right, idx * 2 + 2);
  }

  void indexing() {
    _indexing(root, 0);
  }

  ll cnt_node(shared_ptr<Node> node) {
    if (node == nullptr) return 0;
    return 1 + cnt_node(node->left) + cnt_node(node->right);
  }

  void set_num_of_node() {
    num_of_node = cnt_node(root);
  }

  shared_ptr<Node> _find(shared_ptr<Node> node, const ll &value) {
    if (node == nullptr) return nullptr;
    if (node->x == value) return node;
    if (value < node->x)
      return _find(node->left, value);
    else
      return _find(node->right, value);
  }

  void _insert(shared_ptr<Node> node,
               shared_ptr<Node> par,
               const bool &is_left_child,
               const ll &value) {
    if (node == nullptr) {
      if (is_left_child)
        par->left =
            make_shared<Node>(par->id * 2 + 1, value, par, nullptr, nullptr);
      else
        par->right =
            make_shared<Node>(par->id * 2 + 2, value, par, nullptr, nullptr);
      return;
    }
    if (value <= node->x)
      _insert(node->left, node, true, value);
    else
      _insert(node->right, node, false, value);
  }

  shared_ptr<Node> walk_through(shared_ptr<Node> node, ll &cnt, const ll &end) {
    if (node == nullptr) return nullptr;
    if (cnt == end) return node;
    ++cnt;
    shared_ptr<Node> res_l = walk_through(node->left, cnt, end);
    if (res_l) return res_l;
    shared_ptr<Node> res_r = walk_through(node->right, cnt, end);
    return res_r;
  }

  shared_ptr<Node> most_left(shared_ptr<Node> node) {
    while (node->left) {
      node = node->left;
    }
    return node;
  }

public:
  shared_ptr<Node> root;
  Tree(shared_ptr<Node> _root) : root(_root) {
    indexing();
    set_num_of_node();
  }

  string to_str() {
    return root ? root->to_str() : "null";
  }

  ll size() {
    return num_of_node;
  }

  shared_ptr<Node> find(const ll &value) {
    return _find(root, value);
  }

  void insert(const ll &value) {
    if (root == nullptr)
      root = make_shared<Node>(0, value);
    else
      _insert(root, nullptr, false, value);
    ++num_of_node;
  }

  bool del(const ll &value) {
    shared_ptr<Node> node = find(value);
    if (!node) return false;
    if (node == root) {
      if (!root->left && !root->right) {
        root = nullptr;
      } else if (!root->right) {
        shared_ptr<Node> left = root->left;
        root->left = nullptr;
        left->par = nullptr;
        root = left;
      } else {
        shared_ptr<Node> right = root->right;
        shared_ptr<Node> left = root->left;
        right->par = nullptr;
        root = right;
        right = most_left(right);
        right->left = left;
        if (left) left->par = right;
      }
    } else if (node->par->left == node) {
      if (!node->left && !node->right) {
        node->par->left = nullptr;
      } else if (!node->right) {
        shared_ptr<Node> par = node->par;
        shared_ptr<Node> left = node->left;
        par->left = left;
        left->par = par;
      } else {
        shared_ptr<Node> par = node->par;
        shared_ptr<Node> left = node->left;
        shared_ptr<Node> right = node->right;
        par->left = right;
        right->par = par;
        right = most_left(right);
        right->left = left;
        if (left) left->par = right;
      }
    } else {
      if (!node->left && !node->right) {
        node->par->right = nullptr;
      } else if (!node->right) {
        shared_ptr<Node> par = node->par;
        shared_ptr<Node> left = node->left;
        par->right = left;
        left->par = par;
      } else {
        shared_ptr<Node> par = node->par;
        shared_ptr<Node> left = node->left;
        shared_ptr<Node> right = node->right;
        par->right = right;
        right->par = par;
        right = most_left(right);
        right->left = left;
        if (left) left->par = right;
      }
    }
    node.reset();
    --num_of_node;
    indexing();
    return true;
  }

  shared_ptr<Node> get_random_node() {
    // O(n); slow
    auto seed = hrc::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<ll> distribution(0, num_of_node - 1);
    ll x = distribution(generator);
    ll cnt = 0;
    printf("x=%lld\n", x);
    return walk_through(root, cnt, x);
  }
};

void print_node(shared_ptr<Node> node) {
  if (node)
    printf("[%lld] %lld\n", node->id, node->x);
  else
    puts("null");
}

void _solve_delete(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, s, x;
  ifs >> n >> s >> x;
  --s;
  vector<shared_ptr<Node>> nodes(n);
  for (ll i = 0; i < n; ++i) {
    ll v;
    ifs >> v;
    nodes[i] = make_shared<Node>(i, v);
  }
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    --u, --v;
    if (c == 'l')
      nodes[u]->left = nodes[v];
    else
      nodes[u]->right = nodes[v];
    nodes[v]->par = nodes[u];
  }
  shared_ptr<Tree> tree = make_shared<Tree>(nodes[s]);
  puts(tree->to_str().c_str());
  puts("");
  tree->del(x);
  puts(tree->to_str().c_str());
  puts("");
}

void _solve_find(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, s, x;
  ifs >> n >> s >> x;
  --s;
  vector<shared_ptr<Node>> nodes(n);
  for (ll i = 0; i < n; ++i) {
    ll v;
    ifs >> v;
    nodes[i] = make_shared<Node>(i, v);
  }
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    --u, --v;
    if (c == 'l')
      nodes[u]->left = nodes[v];
    else
      nodes[u]->right = nodes[v];
    nodes[v]->par = nodes[u];
  }
  shared_ptr<Tree> tree = make_shared<Tree>(nodes[s]);
  puts(tree->find(x) ? "true" : "false");
  puts("");
}

void _solve_insert(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, s, x;
  ifs >> n >> s >> x;
  --s;
  vector<shared_ptr<Node>> nodes(n);
  for (ll i = 0; i < n; ++i) {
    ll v;
    ifs >> v;
    nodes[i] = make_shared<Node>(i, v);
  }
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    char c;
    ifs >> u >> v >> c;
    --u, --v;
    if (c == 'l')
      nodes[u]->left = nodes[v];
    else
      nodes[u]->right = nodes[v];
    nodes[v]->par = nodes[u];
  }
  shared_ptr<Tree> tree = make_shared<Tree>(nodes[s]);
  puts(tree->to_str().c_str());
  puts("");
  tree->insert(x);
  puts(tree->to_str().c_str());
  puts("");
}

void solve_delete() {
  for (ll i = 1; i < 16; ++i) {
    stringstream ss;
    ss << setfill('0') << right << setw(2) << i;
    _solve_delete("../testcases/04_11/delete/" + ss.str() + ".txt");
  }
}

void solve_find() {
  for (ll i = 1; i < 9; ++i) {
    stringstream ss;
    ss << setfill('0') << right << setw(2) << i;
    _solve_find("../testcases/04_11/find/" + ss.str() + ".txt");
  }
}

void solve_insert() {
  for (ll i = 1; i < 8; ++i) {
    stringstream ss;
    ss << setfill('0') << right << setw(2) << i;
    _solve_insert("../testcases/04_11/insert/" + ss.str() + ".txt");
  }
}

int main() {
  // solve_delete();
  // solve_find();
  solve_insert();
}