#include <chrono>
#include <future>
#include <stdio.h>
#include <thread>

typedef long long ll;

using namespace std;

void _p_fib(int n, promise<ll> &p);
ll p_fib(int n);

void _p_fib(int n, promise<ll> &p) {
  if (n < 2) {
    p.set_value(1);
    return;
  } else {
    auto prom = promise<ll>();
    auto fu = prom.get_future();
    auto prod = thread(_p_fib, n - 1, ref(prom));
    ll n2 = p_fib(n - 2);
    ll n1 = fu.get();
    prod.join();
    p.set_value(n1 + n2);
    return;
  }
}

ll p_fib(int n) {
  if (n < 2) {
    return 1;
  } else {
    auto prom = promise<ll>();
    auto fu = prom.get_future();
    auto prod = thread(_p_fib, n - 1, ref(prom));
    ll n2 = p_fib(n - 2);
    ll n1 = fu.get();
    prod.join();
    return n1 + n2;
  }
}

int main() {
  for (int i = 1; i <= 4; ++i) {
    int n = i * 10;
    auto start = chrono::high_resolution_clock::now();
    ll res = p_fib(n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    printf("n: %d, res: %lld, duration: %lld\n", n, res, duration);
  }
}

// n: 10, res: 89, duration: 2100
// n: 20, res: 10946, duration: 1375497
// seems max thread num...
// libc++abi.dylib: terminating with uncaught exception of type std::__1::system_error: thread constructor
// failed: Resource temporarily unavailable