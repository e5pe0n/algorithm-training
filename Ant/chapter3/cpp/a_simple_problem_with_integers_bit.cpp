#include <fstream>
#include <stdio.h>

#define MAX_N 100'000
#define MAX_Q 100'000

using namespace std;

typedef long long ll;

int N, Q;
ll bit0[MAX_N + 1], bit1[MAX_N + 1];

ll sum(ll *b, int i) {
  ll s = 0;
  while (i > 0) {
    s += b[i];
    i -= i & -i;
  }
  return s;
}

void add(ll *b, int i, int diff) {
  while (i <= N) {
    b[i] += diff;
    i += i & -i;
  }
}

int main() {
  ifstream ifs("../testset/a_simple_problem_with_integers/test2.txt");
  ifs >> N >> Q;
  for (int i = 1; i <= N; ++i) {
    int a;
    ifs >> a;
    add(bit0, i, a);
  }
  for (int i = 0; i < Q; ++i) {
    char t;
    int left, right, x;
    ifs >> t >> left >> right;
    if (t == 'C') {
      ifs >> x;
      add(bit0, left, -x * (left - 1));
      add(bit1, left, x);
      add(bit0, right + 1, x * right);
      add(bit1, right + 1, -x);
    } else {
      ll res = 0;
      res += sum(bit0, right) + sum(bit1, right) * right;
      res -= sum(bit0, left - 1) + sum(bit1, left - 1) * (left - 1);
      printf("%lld\n", res);
    }
  }
}