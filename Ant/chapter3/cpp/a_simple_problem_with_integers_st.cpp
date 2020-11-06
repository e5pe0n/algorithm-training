#include <algorithm>
#include <fstream>
#include <stdio.h>

#define MAX_N 100'000
#define MAX_Q 100'000

using namespace std;

typedef long long ll;

const int DATA_SIZE = (1 << 18) - 1;

int N, Q;

ll data[DATA_SIZE], datb[DATA_SIZE];

void add(int a, int b, int diff, int k, int left, int right) {
  if (a <= left && right <= b) {
    data[k] += diff;
  } else if (left < b && a < right) {
    datb[k] += (min(right, b) - max(a, left)) * diff;
    add(a, b, diff, k * 2 + 1, left, (left + right) / 2);
    add(a, b, diff, k * 2 + 2, (left + right) / 2, right);
  }
}

ll sum(int a, int b, int k, int left, int right) {
  // return sum of vals in [a, b)
  if (b <= left || right <= a) {
    return 0;
  } else if (a <= left && right <= b) {
    return data[k] * (right - left) + datb[k];
  } else {
    ll res = (min(b, right) - max(a, left)) * data[k];
    res += sum(a, b, k * 2 + 1, left, (left + right) / 2);
    res += sum(a, b, k * 2 + 2, (left + right) / 2, right);
    return res;
  }
}

int main() {
  ifstream ifs("../testset/a_simple_problem_with_integers/test2.txt");
  ifs >> N >> Q;
  for (int i = 0; i < N; ++i) {
    int a;
    ifs >> a;
    add(i, i + 1, a, 0, 0, N);
  }
  for (int i = 0; i < Q; ++i) {
    char t;
    int left, right, x;
    ifs >> t >> left >> right;
    --left;
    --right;
    if (t == 'C') {
      ifs >> x;
      add(left, right + 1, x, 0, 0, N);
    } else {
      printf("%lld\n", sum(left, right + 1, 0, 0, N));
    }
  }
}