#include <chrono>
#include <future>
#include <stdio.h>

using namespace std;

int p_fib(int n) {
  if (n < 2) {
    return 1;
  } else {
    future<int> fu = async(p_fib, n - 1);
    int n2 = p_fib(n - 2);
    int n1 = fu.get();
    return n1 + n2;
  }
}

int main() {
  for (int i = 1; i <= 5; ++i) {
    int n = i * 10;
    auto start = chrono::high_resolution_clock::now();
    int res = p_fib(n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    printf("n: %d, res: %d, duration: %lld\n", n, res, duration);
  }
}

// n: 10, res: 89, duration: 1554
// n: 20, res: 10946, duration: 517355
// n: 30, did not come back