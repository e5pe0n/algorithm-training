#include <fstream>
#include <stdio.h>

using namespace std;

int N;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return n != 1;
}

int main() {
  ifstream ifs("../testset/primality_test/test2.txt");
  ifs >> N;
  if (is_prime(N)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}