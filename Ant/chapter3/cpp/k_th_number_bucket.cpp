#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000
#define MAX_M 5'000
#define B 1000

using namespace std;

int N, M;
int A[MAX_N];
int _A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];
vector<int> bucket[MAX_N / B];

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
    bucket[i / B].push_back(A[i]);
    _A[i] = A[i];
  }
  sort(_A, _A + N);
  for (int i = 0; i < N / B; ++i) {
    sort(bucket[i].begin(), bucket[i].end());
  }
  for (int i = 0; i < M; ++i) {
    // find k-th num in [left, right)
    int left = I[i];
    int right = J[i] + 1;
    int k = K[i];

    int lb = -1;
    int ub = N - 1;
    while (ub - lb > 1) {
      int md = (lb + ub) / 2;
      int x = _A[md];

      int tl = left;
      int tr = right;
      int c = 0;
      while (tl < tr && tl % B != 0) {
        if (A[tl++] <= x) {
          ++c;
        }
      }
      while (tl < tr && tr % B != 0) {
        if (A[--tr] <= x) {
          ++c;
        }
      }
      while (tl < tr) {
        int b = tl / B;
        c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
        tl += B;
      }
      if (c >= k) {
        ub = md;
      } else {
        lb = md;
      }
    }
    printf("%d\n", _A[ub]);
  }
}