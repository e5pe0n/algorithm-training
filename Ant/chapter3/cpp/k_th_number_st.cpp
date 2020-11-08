#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000
#define MAX_M 5000

using namespace std;

const int ST_SIZE = (1 << 18) - 1;

int N, M;
int A[MAX_N], _A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];
vector<int> dat[ST_SIZE]{};

void init(int k, int left, int right) {
  if (right - left == 1) {
    dat[k].push_back(A[left]);
  } else {
    int lch = k * 2 + 1;
    int rch = k * 2 + 2;
    init(lch, left, (left + right) / 2);
    init(rch, (left + right) / 2, right);
    dat[k].resize(right - left);
    merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
  }
}

int query(int i, int j, int x, int k, int left, int right) {
  if (j <= left || right <= i) {
    return 0;
  } else if (i <= left && right <= j) {
    return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
  } else {
    int lc = query(i, j, x, k * 2 + 1, left, (left + right) / 2);
    int rc = query(i, j, x, k * 2 + 2, (left + right) / 2, right);
    return lc + rc;
  }
}

int main() {
  ifstream ifs("../testset/k_th_number/test1.txt");
  ifs >> N >> M;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    ifs >> I[i] >> J[i] >> K[i];
    --I[i];
    --J[i];
  }

  for (int i = 0; i < N; ++i) {
    _A[i] = A[i];
  }
  sort(_A, _A + N);
  init(0, 0, N);
  for (int i = 0; i < M; ++i) {
    int left = I[i];
    int right = J[i] + 1;
    int k = K[i];

    int lb = -1;
    int ub = N - 1;
    while (ub - lb > 1) {
      int md = (lb + ub) / 2;
      int c = query(left, right, _A[md], 0, 0, N);
      if (c >= k) {
        ub = md;
      } else {
        lb = md;
      }
    }
    printf("%d\n", _A[ub]);
  }
}