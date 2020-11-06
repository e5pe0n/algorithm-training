#include <algorithm>
#include <climits>
#include <fstream>
#include <stdio.h>

using namespace std;

const int MAX_N = 1 << 17;
int n;
int dat[MAX_N * 2 - 1];

void init(int n_) {
  n = 1;
  while (n < n_)
    n *= 2;
  for (int i = 0; i < n * 2 - 1; ++i) {
    dat[i] = INT_MAX;
  }
}

void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

int query(int a, int b, int k, int left, int right) {
  // return min val in [a, b)
  if (right <= a || b <= left) {
    return INT_MAX;
  }
  if (a <= left && right <= b) {
    return dat[k];
  } else {
    int vl = query(a, b, k * 2 + 1, left, (left + right) / 2);
    int vr = query(a, b, k * 2 + 2, (left + right) / 2, right);
    return min(vl, vr);
  }
}

int main() {
  ifstream ifs("../testset/segment_tree_rmq/test1.txt");
  int N;
  ifs >> N;
  init(N);
  for (int i = 0; i < N; ++i) {
    int x;
    ifs >> x;
    update(i, x);
  }
  printf("%d\n", query(0, 7, 0, 0, n)); // 1
  printf("%d\n", query(2, 6, 0, 0, n)); // 4
  printf("%d\n", query(7, 8, 0, 0, n)); // 2
}