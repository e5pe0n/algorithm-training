#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int main() {
  int N;
  cin >> N;
  int x = MAX_N + 1;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int p;
    cin >> p;
    if (p < x) {
      ++cnt;
      x = p;
    }
  }
  printf("%d\n", cnt);
}