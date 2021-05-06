#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int pairwise_swap(int n, int bits) {
  int right = n >> 1;
  int left = n << 1;
  int res = 0;
  int mask = 1;
  while (bits--) {
    res |= right & mask;
    if (!bits) break;
    mask <<= 1;
    res |= left & mask;
    mask <<= 1;
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int n;
  ifs >> n;
  bitset<32> b(n);
  bitset<32> res(pairwise_swap(n, 32));
  cout << b << " -> " << res << '\n' << endl;
}

int main() {
  solve("../testcases/05_07/01.txt");
  solve("../testcases/05_07/02.txt");
}

// # ../testcases/05_07/01.txt
// 00111011000010010010011000011000 -> 00110111000001100001100100100100

// # ../testcases/05_07/02.txt
// 00011101100001001001001100001100 -> 00101110010010000110001100001100
