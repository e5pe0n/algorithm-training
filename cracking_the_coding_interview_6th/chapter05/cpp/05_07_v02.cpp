#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

__int128_t pairwise_swap(__int128_t n, int bits) {
  int k = (bits + 4 - 1) / 4;
  __int128_t even_mask = stoll(string(k, 'a'), nullptr, 16);
  __int128_t odd_mask = stoll(string(k, '5'), nullptr, 16);
  return ((n & even_mask) >> 1) | ((n & odd_mask) << 1);
}

int pairwise_swap(int n) {
  return pairwise_swap(n, 32);
}

int64_t pairwise_swap(int64_t n) {
  return pairwise_swap(n, 64);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int n;
  ifs >> n;
  bitset<32> b(n);
  bitset<32> res(pairwise_swap(n));
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
