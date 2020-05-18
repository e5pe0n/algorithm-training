#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct El {
  El *p;
  int id;
  int rank;
  El(int id) : id(id) {}
  string to_str() { return "el" + to_string(id); }
};

void make_set(El *x) {
  x->p = x;
  x->rank = 0;
}

void uni(El *x, El *y) {
  if (x == y)
    return;
  if (x->rank > y->rank) {
    y->p = x;
  } else {
    x->p = y;
    if (x->rank == y->rank) {
      ++y->rank;
    }
  }
}

El *find_set(El *x) {
  if (x->p == x) {
    return x;
  } else {
    x->p = find_set(x->p);
    return x->p;
  }
}

int main() {
  El el1(1);
  El el2(2);
  El el3(3);
  El el4(4);
  El el5(5);

  vector<El *> els{&el1, &el2, &el3, &el4, &el5};
  for (auto el : els) {
    make_set(el);
  }

  for (auto el : els) {
    printf("%s: p=%s, rank=%d\n", el->to_str().c_str(), el->p->to_str().c_str(), el->rank);
  }
  printf("\n");

  uni(&el1, &el2);
  uni(&el3, &el4);
  uni(&el2, &el5);
  uni(&el2, &el4);

  for (auto el : els) {
    printf("%s: p=%s, rank=%d\n", el->to_str().c_str(), el->p->to_str().c_str(), el->rank);
  }
}
