// Cracking the Coding Interview p.275
#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;

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

void inc_hash_table(unordered_map<ll, ll> &m, const ll &key, const ll &delta) {
  ll new_cnt = m[key] + delta;
  if (new_cnt == 0 && m.count(key))
    m.erase(key);
  else
    m[key] = new_cnt;
}

ll cnt_paths_with_sum(shared_ptr<Node> node,
                      ll target_sum,
                      ll running_sum,
                      unordered_map<ll, ll> &path_cnt) {
  if (!node) return 0;

  running_sum += node->x;
  ll sum = running_sum - target_sum;
  ll total_paths = path_cnt[sum];

  if (running_sum == target_sum) ++total_paths;

  inc_hash_table(path_cnt, running_sum, 1);
  total_paths +=
      cnt_paths_with_sum(node->left, target_sum, running_sum, path_cnt);
  total_paths +=
      cnt_paths_with_sum(node->right, target_sum, running_sum, path_cnt);
  inc_hash_table(path_cnt, running_sum, -1);

  return total_paths;
}

ll cnt_paths_with_sum(shared_ptr<Tree> tree, const ll &target_sum) {
  unordered_map<ll, ll> m;
  return cnt_paths_with_sum(tree->root, target_sum, 0, m);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, s, x;
  ifs >> n >> s >> x;
  --s;
  vector<shared_ptr<Node>> nodes(n);
  for (ll i = 0; i < n; ++i) {
    ll v;
    ifs >> v;
    nodes[i] = make_shared<Node>(v);
  }
  for (ll i = 0; i < n - 1; ++i) {
    ll a, b;
    char c;
    ifs >> a >> b >> c;
    --a, --b;
    if (c == 'l')
      nodes[a]->left = nodes[b];
    else
      nodes[a]->right = nodes[b];
  }
  shared_ptr<Tree> tree = make_shared<Tree>(nodes[s]);
  printf("%lld\n", cnt_paths_with_sum(tree, x));
  puts("");
}

int main() {
  solve("../testcases/04_12/01.txt");
}

// # ../testcases/04_12/01.txt
// 10