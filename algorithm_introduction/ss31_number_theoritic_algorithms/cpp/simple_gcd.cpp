#include <iostream>
#include <string>

using namespace std;

int simple_gcd(int a, int b) {
  if (b == 0)
    return a;
  return simple_gcd(b, a % b);
}

int main() {
  cout << "simple_gcd(12, 13): " << simple_gcd(12, 13) << "\n";
  cout << "simple_gcd(12, 6): " << simple_gcd(12, 6) << "\n";
  cout << "simple_gcd(12, 18): " << simple_gcd(12, 18) << "\n";
}