#include <chrono>
#include <stdio.h>

typedef long long ll;

using namespace std;

ll fib(int n) {
  if (n < 2) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

int main() {
  for (int i = 1; i <= 5; ++i) {
    int n = i * 10;
    auto start = chrono::high_resolution_clock::now();
    ll res = fib(n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    printf("n: %d, res: %lld, duration: %lld\n", n, res, duration);
  }
}

// n: 10, res: 89, duration: 1
// n: 20, res: 10946, duration: 56
// n: 30, res: 1346269, duration: 6901
// n: 40, res: 165580141, duration: 860369
// n: 50, res: 20365011074, duration: 9846558