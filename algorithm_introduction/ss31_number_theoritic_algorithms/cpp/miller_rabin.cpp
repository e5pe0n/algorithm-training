#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

default_random_engine generator;

int modular_exponentiation(int a, int b, int n) {}

bool witness(int a, int n) {
  int u = n - 1;
  int t = 0;
  while ((u & 1) != 1) {
    ++t;
    u = u >> 1;
  }
  int _x = modular_exponentiation(a, u, n);
  int x;
  for (int i = 1; i <= t; ++i) {
    x = (_x * _x) % n;
    if (x == 1) {
      if (_x != 1 && _x != n - 1)
        return true;
      else
        return false;
    }
    _x = x;
  }
  return x != 1;
}

int miller_rabin(int n, int s) {
  // Return true if n is a prime, return false if n is a composite number.
  // The case returning true includes error that n is actually a composite number; base-a
  // pseudoprime.

  if (n <= 2)
    throw "n must be >= 3";

  uniform_int_distribution<int> distribution(1, n - 1);
  for (int i = 0; i < s; ++i) {
    int a = distribution(generator);
    if (witness(a, n))
      return false;
  }
  return true;
}

int main() {}
