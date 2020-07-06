#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    int j = 1;
    int d = 1;
    while (d <= D) {
      ++cnt;
      d = j++ * a + 1;
    }
  }
  printf("%d\n", cnt + X);
}