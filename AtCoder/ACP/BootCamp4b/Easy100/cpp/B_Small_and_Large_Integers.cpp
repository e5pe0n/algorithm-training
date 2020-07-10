#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  for (int i = A; i <= min(B, A + K - 1); ++i) {
    printf("%d\n", i);
  }
  for (int i = max(A + K, B - K + 1); i <= B; ++i) {
    printf("%d\n", i);
  }
}