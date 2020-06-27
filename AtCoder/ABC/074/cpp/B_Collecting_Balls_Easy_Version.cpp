#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    cnt += min(x, K - x);
  }
  printf("%d\n", 2 * cnt);
}