#include <math.h>
#include <memory>
#include <stdio.h>
#include <vector>

using namespace std;

struct vEBTree {
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

  int vEB_tree_predecessor(int x) {
    if (u == 2) {
      if (x == 1 && min == 0) {
        return 0;
      } else {
        return -1;
      }
    } else if (max != -1 && x > max) {
      return max;
    } else {
      int min_low = cluster[high(x)]->vEB_tree_minimum();
      if (min_low != -1 && low(x) > min_low) {
        int offset = cluster[high(x)]->vEB_tree_predecessor(low(x));
        return index(high(x), offset);
      } else {
        int pred_cluster = summary->vEB_tree_predecessor(high(x));
        if (pred_cluster == -1) {
          if (min != -1 && x > min) {
            return min;
          } else {
            return -1;
          }
        } else {
          int offset = cluster[pred_cluster]->vEB_tree_maximum();
          return index(pred_cluster, offset);
        }
      }
    }
  }

  void vEB_empty_tree_insert(int x) {
    min = x;
    max = x;
  }

  void vEB_tree_insert(int x) {
    if (min == -1) {
      vEB_empty_tree_insert(x);
    } else {
      if (x < min) {
        swap(x, min);
      }
      if (u > 2) {
        if (cluster[high(x)]->vEB_tree_minimum() == -1) {
          summary->vEB_tree_insert(high(x));
          cluster[high(x)]->vEB_empty_tree_insert(low(x));
        } else {
          cluster[high(x)]->vEB_tree_insert(low(x));
        }
      }
      if (x > max) {
        max = x;
      }
    }
  }

  void vEB_tree_delete(int x) {
    if (min == max) {
      min = -1;
      max = -1;
    } else if (u == 2) {
      if (x == 0) {
        min = 1;
      } else {
        min = 0;
      }
      max = min;
    } else {
      if (x == min) {
        int first_cluster = summary->vEB_tree_minimum();
        x = index(first_cluster, cluster[first_cluster]->vEB_tree_minimum());
        min = x;
      }
      cluster[high(x)]->vEB_tree_delete(low(x));
      if (cluster[high(x)]->vEB_tree_minimum() == -1) {
        summary->vEB_tree_delete(high(x));
        if (x == max) {
          int summary_max = summary->vEB_tree_maximum();
          if (summary_max == -1) {
            max = min;
          } else {
            max = index(summary_max, cluster[summary_max]->vEB_tree_maximum());
          }
        }
      } else if (x == max) {
        max = index(high(x), cluster[high(x)]->vEB_tree_maximum());
      }
    }
  }
};

int main() {}