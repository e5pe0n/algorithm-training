#include <future>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> mat_vec(vector<vector<int>> A, vector<int> x) {
  int N = A.size();
  vector<int> y(N, 0);
  for (int i = 0; i < N; ++i) {
    async([i, &N, &y, &A, &x] {
      for (int j = 0; j < N; ++j) {
        y[i] += A[i][j] * x[j];
      }
    });
  }
  return y;
}

int main() {
  int N = 3;
  vector<vector<int>> A(N, vector<int>(N, 1));
  vector<int> x(N, 1);
  vector<int> y = mat_vec(A, x);
  for (int i = 0; i < N; ++i) {
    printf("%d, ", y[i]);
  }
  printf("\n");
}