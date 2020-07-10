#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int cnt = 0;
  int n = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (a - 1 == n) {
      ++n;
    } else {
      ++cnt;
    }
  }
  if (cnt == N) {
    printf("-1\n");
  } else {
    printf("%d\n", cnt);
  }
}