#include <chrono>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> mat_vec(vector<vector<int>> A, vector<int> x) {
  int N = A.size();
  vector<int> y(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      y[i] += A[i][j] * x[j];
    }
  }
  return y;
}

int main() {
  int n[] = {400, 800, 1600, 3200, 6400};
  for (int i = 0; i < 5; ++i) {
    int N = n[i];
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<int> x(N, 1);
    auto start = chrono::high_resolution_clock::now();
    mat_vec(A, x);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    printf("n: %d, duration: %lld\n", N, duration);
  }
}

// n: 400, duration: 5185
// n: 800, duration: 19940
// n: 1600, duration: 80044
// n: 3200, duration: 328016
// n: 6400, duration: 1244826