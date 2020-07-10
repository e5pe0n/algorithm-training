#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int main() {
  int N;
  cin >> N;
  int h;
  cin >> h;
  int res = 0;
  int cnt = 0;
  for (int i = 1; i < N; ++i) {
    int _h;
    cin >> _h;
    if (h >= _h) {
      ++cnt;
    } else {
      res = max(res, cnt);
      cnt = 0;
    }
    h = _h;
  }
  printf("%d\n", max(res, cnt));
}