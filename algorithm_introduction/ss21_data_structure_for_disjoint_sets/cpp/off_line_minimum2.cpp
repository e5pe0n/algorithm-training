#include <stdio.h>
#include <string>

using namespace std;

int extracted[5];

struct El {
  El *p = nullptr;
  int rank = 0;
  int id;
  El() {}
  El(int id) : id(id) {}
  string to_str() {
    return "el(id: " + to_string(id) + ", rank: " + to_string(rank) + " , p: " + to_string(p->id) + ")";
  }
};

El els[11];
El *K[6];

void make_set(El *x) { x->p = x; }

El *find(El *x) {
  if (x->p == x) {
    return x;
  } else {
    x->p = find(x->p);
    return x->p;
  }
}

void uni(El *x, El *y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }

  if (x->rank > y->rank) {
    y->p = x;
  } else {
    x->p = y;
    if (x->rank == y->rank) {
      ++y->rank;
    }
  }
}

bool same(El *x, El *y) { return find(x) == find(y); }

void off_line_minimum(int m, int n, El *els, El **K) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (K[j] != nullptr) {
        if (same(&els[i], K[j])) {
          extracted[j] = i;
          int l = j + 1;
          while (K[l] == nullptr) {
            ++l;
          }
          uni(K[j], K[l]);
          K[j] = nullptr;
          break;
        }
      }
    }
  }
}

int main() {
  int m = 5;
  int n = 9;

  // K = {{8, 2}, {4, 5}, {}, {3, 6, 9}, {1, 0}, {7}}
  // id=10 is not a member but represents empty set.

  for (int i = 0; i < 11; ++i) {
    els[i] = El(i);
    // "this" pointer used in the constructor points the same object in for loop.
    // I don't know why.
    make_set(&els[i]);
  }

  uni(&els[8], &els[2]);
  uni(&els[4], &els[5]);
  uni(&els[3], &els[6]);
  uni(&els[6], &els[9]);
  uni(&els[1], &els[0]);

  K[0] = &els[8];
  K[1] = &els[4];
  K[2] = &els[10]; // empty set is not nullptr because nullptr is assigned to broken set.
  K[3] = &els[3];
  K[4] = &els[1];
  K[5] = &els[7];

  off_line_minimum(m, n, els, K);

  for (int i = 0; i < m; ++i) {
    printf("%d, ", extracted[i]); // 2, 4, 5, 3, 0,
  }
  printf("\n");
}