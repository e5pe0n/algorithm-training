#include <fstream>
#include <map>
#include <stdio.h>

using namespace std;

int N;

map<int, int> prime_factor(int n) {
  map<int, int> res;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) {
    res[n] = 1;
  }
  return res;
}

int main() {
  ifstream ifs("../testset/primality_test/test2.txt");
  ifs >> N;
  map<int, int> fs = prime_factor(N);
  for (auto f : fs) {
    printf("%d^%d ", f.first, f.second);
  }
  printf("\n");
}
// 541^1 547^1