#include <deque>
#include <iostream>
#include <string>

using namespace std;

int modular_exponentiation(int a, int b, int n) {
  // int c = 0;
  int d = 1;
  int b_quo = b;
  deque<int> b_bits;
  while (b_quo > 0) {
    b_bits.push_back(b_quo % 2); // bit array as reversed 2-base b
    b_quo /= 2;
  }
  while (!b_bits.empty()) {
    int b_i = b_bits.back();
    b_bits.pop_back();
    // c *= 2;
    d = (d * d) % n;
    if (b_i == 1) {
      // c += 1;
      d = (d * a) % n;
    }
  }
  return d;
}

int main() {
  int res = modular_exponentiation(7, 560, 561);
  cout << "res(7, 560, 561): " << to_string(res) << "\n";

  res = modular_exponentiation(3, 3, 7);
  cout << "res(3, 3, 7): " << to_string(res) << "\n";
}