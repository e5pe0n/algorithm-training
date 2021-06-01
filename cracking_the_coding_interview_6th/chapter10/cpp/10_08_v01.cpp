#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BitSet {
  vector<int> v;

public:
  BitSet() : v(32000) {}
  bool get(int i) {
    int idx = i >> 32;
    int rem = i & 0x1F;
    return v[idx] & (1 << rem);
  }
  void set(int i) {
    int idx = i >> 32;
    int rem = i & 0x1F;
    v[idx] |= (1 << rem);
  }
};

void print_dup(const vector<int> &v) {
  BitSet bs;
  for (auto n : v) {
    if (bs.get(n - 1))
      cout << n << endl;
    else
      bs.set(n - 1);
  }
}

int main() {}