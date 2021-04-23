#include <string>
#include <vector>
using namespace std;

struct Node {
  int id;
  Node(int _id) : id(_id) {}
};

struct Graph {
  vector<Node> nodes;
  vector<Node> get_nodes() {
    return nodes;
  }
};

int main() {
  Graph g;
  g.nodes.push_back(Node(0));
  vector<Node> _nodes = g.get_nodes();
  _nodes[0].id = 100;
  printf("%d\n", g.nodes[0].id); // 0
}