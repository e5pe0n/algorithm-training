#include <chrono>
#include <stdio.h>
#include <thread>
#include <vector>

using namespace std;

vector<int> mat_vec(vector<vector<int>> A, vector<int> x) {
  int N = A.size();
  vector<int> y(N, 0);
  vector<thread> threads;
  for (int i = 0; i < N; ++i) {
    threads.emplace_back([i, &N, &y, &A, &x] {
      for (int j = 0; j < N; ++j) {
        y[i] += A[i][j] * x[j];
      }
    });
  }
  for (int i = 0; i < N; ++i) {
    threads[i].join();
  }
  return y;
}

int main() {
  int n[] = {100, 200, 400, 800, 1600};
  for (int i = 0; i < 5; ++i) {
    vector<vector<int>> A(n[i], vector<int>(n[i], 1));
    vector<int> x(n[i], 1);
    auto start = chrono::high_resolution_clock::now();
    mat_vec(A, x);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    printf("n: %d, duration: %lld\n", n[i], duration);
  }
}

// n: 100, duration: 2303
// n: 200, duration: 5038
// n: 400, duration: 15065
// n: 800, duration: 39064
// n: 1600, duration: 137289