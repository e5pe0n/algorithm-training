#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct Node {
  ll x;
  Node *left, *right;
  Node(ll _x, Node *_left, Node *_right) : x(_x), left(_left), right(_right) {}
  ~Node() {
    delete left;
    delete right;
  }
  string to_str() {
    return "(" + (left == nullptr ? "null" : left->to_str()) + " "
           + to_string(x) + " " + (right == nullptr ? "null" : right->to_str())
           + ")";
  }
};

struct Tree {
  Node *root;
  Tree(Node *_root) : root(_root) {}
  ~Tree() {
    delete root;
  }
  string to_str() {
    return root == nullptr ? "null" : root->to_str();
  }
};

Node *rec(const vector<ll> &v, ll left, ll right) {
  if (right - left == 0) return nullptr;
  if (right - left == 1) return new Node(v[left], nullptr, nullptr);
  ll mid = (right + left) / 2;
  Node *lc = rec(v, left, mid);
  Node *rc = rec(v, mid + 1, right);
  Node *par = new Node(v[mid], lc, rc);
  return par;
}

Tree *make_min_bst(const vector<ll> &v) {
  return new Tree(rec(v, 0, v.size()));
}

void solve(const string &fp) {
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  Tree *res = make_min_bst(v);
  printf("%s\n", res->to_str().c_str());
  delete res;
}

int main() {
  solve("../testcases/04_02/01.txt");
  solve("../testcases/04_02/02.txt");
  solve("../testcases/04_02/03.txt");
  solve("../testcases/04_02/04.txt");
}

// (((null 1 null) 2 (null 3 null)) 4 ((null 5 null) 6 (null 7 null)))
// ((((null 1 null) 2 null) 3 (null 4 null)) 5 ((null 6 null) 7 (null 8 null)))
// ((((null 1 null) 2 null) 3 ((null 4 null) 5 null)) 6 (((null 7 null) 8 null)
// 9 (null 10 null)))
// ((null 1 null) 2 null)