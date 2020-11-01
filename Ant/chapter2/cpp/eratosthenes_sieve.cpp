#include <fstream>
#include <stdio.h>

#define MAX_N 1'000'000

using namespace std;

int N;
int primes[MAX_N];
bool is_prime[MAX_N + 1];

int sieve(int n) {
  int p = 0;
  fill(is_prime, is_prime + N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      primes[p++] = i;
      for (int j = i * 2; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return p;
}

int main() {
  ifstream ifs("../testset/eratosthenes_sieve/test2.txt");
  ifs >> N;
  int res = sieve(N);
  printf("%d\n", res);
}