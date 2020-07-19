#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;
  int N10 = min((int)(Y / 10000), N);
  int N5 = min((int)(Y / 5000), N);
  for (int i = 0; i <= N10; ++i) {
    for (int j = 0; j <= N5; ++j) {
      int t = 10000 * i + 5000 * j + 1000 * (N - i - j);
      if (t == Y && N - i - j >= 0) {
        printf("%d %d %d\n", i, j, N - i - j);
        return 0;
      }
    }
  }
  printf("-1 -1 -1\n");
}