#include <iostream>
#include <string>
#include <vector>

using namespace std;

int extended_gcd(int a, int b) {
  if (b == 0)
    return a;
  return extended_gcd(b, a % b);
}

int modular_exponentiation(int a, int b, int n) {
  int d = 1;
  vector<int> b_bits;
  int b_quo = b;
  while (b_quo != 0) {
    b_bits.push_back(b_quo % 2);
    b_quo /= 2;
  }
  while (!b_bits.empty()) {
    int b_i = b_bits.back();
    b_bits.pop_back();
    d = (d * d) % n;
    if (b_i == 1) {
      d = (d * a) % n;
    }
  }
  return d;
}

// Return true if n is determined as prime.
// (This res contains an error that returning true when n is a base-2 pseudoprime; not a prime)
bool psuedoprime(int n) { return (modular_exponentiation(2, n - 1, n) % n) == 1; }

int main() {
  // 2 is a prime but not in Z_2
  cout << "psuedoprime(2): " << psuedoprime(2) << "\n";
  cout << "\n";

  // primes
  cout << "psuedoprime(11): " << psuedoprime(11) << "\n";
  cout << "psuedoprime(1229): " << psuedoprime(1229) << "\n";
  cout << "psuedoprime(2801): " << psuedoprime(2801) << "\n";
  cout << endl;

  // composite numbers
  cout << "psuedoprime(1): " << psuedoprime(1) << "\n";
  cout << "psuedoprime(22): " << psuedoprime(22) << "\n";
  cout << "psuedoprime(3013): " << psuedoprime(3013) << "\n";
  cout << endl;

  // base-2 psuedoprimes; psuedoprime(n) returns true even n is not a prime.
  cout << "psuedoprime(341): " << psuedoprime(341) << "\n";
  cout << "psuedoprime(561): " << psuedoprime(561) << "\n";
  cout << "psuedoprime(645): " << psuedoprime(645) << "\n";
  cout << "psuedoprime(1105): " << psuedoprime(1105) << "\n";
  cout << endl;
}