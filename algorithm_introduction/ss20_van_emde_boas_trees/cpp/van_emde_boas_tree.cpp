#include <math.h>
#include <memory>
#include <stdio.h>
#include <vector>

using namespace std;

struct vEB_Tree {
  int u = -1;
  int min = -1;
  int max = -1;
  int sqrt_u_upper = -1;
  int sqrt_u_lower = -1;
  shared_ptr<vEB_Tree> summary = nullptr;
  unique_ptr<shared_ptr<vEB_Tree>[]> cluster = nullptr;
  vEB_Tree(int u) : u(u) {
    sqrt_u_upper = int(ceil(sqrt(u)));
    sqrt_u_lower = int(sqrt(u));
    if (u == 2)
      return;
    summary = make_shared<vEB_Tree>(sqrt_u_upper);
    cluster = unique_ptr<shared_ptr<vEB_Tree>[]>(new shared_ptr<vEB_Tree>[sqrt_u_upper]);
    for (int i = 0; i < sqrt_u_upper; ++i) {
      cluster[i] = make_shared<vEB_Tree>(sqrt_u_lower);
    }
  }

  int high(int x) { return x / sqrt_u_lower; }

  int low(int x) { return x % sqrt_u_lower; }

  int index(int x, int y) { return x * sqrt_u_lower + y; }

  int vEB_tree_minimum() { return min; }

  int vEB_tree_maximum() { return max; }

  bool vEB_tree_member(int x) {
    if (x == min || x == max)
      return true;
    else if (u == 2)
      false;
    else
      return cluster[high(x)]->vEB_tree_member(low(x));
  }

  int vEB_tree_successor(int x) {
    if (u == 2) {
      if (x == 0 && max == 1)
        return 1;
      else
        return -1;
    } else if (min != -1 && x < min) {
      return min;
    } else {
      int max_low = cluster[high(x)]->vEB_tree_maximum();
      if (max_low != -1 && low(x) < max_low) {
        int offset = cluster[high(x)]->vEB_tree_successor(low(x));
        return index(high(x), offset);
      } else {
        int succ_cluster = summary->vEB_tree_successor(high(x));
        if (succ_cluster == -1)
          return -1;
        else {
          int offset = cluster[succ_cluster]->vEB_tree_minimum();
          return index(succ_cluster, offset);
        }
      }
    }
  }
};

int main() {}