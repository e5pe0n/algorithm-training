#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int K, S;
  cin >> K >> S;
  int res = 0;
  for (int i = 0; i <= K; ++i) {
    for (int j = 0; j <= K; ++j) {
      int k = S - i - j;
      if (k >= 0 && k <= K) {
        ++res;
      }
    }
  }
  printf("%d\n", res);
}