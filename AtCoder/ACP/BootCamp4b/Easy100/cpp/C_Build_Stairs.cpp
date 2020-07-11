#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int _h;
  cin >> _h;
  bool flg = true;
  for (int i = 1; i < N; ++i) {
    int h;
    cin >> h;
    if (_h < h) {
      _h = --h;
    } else if (_h > h) {
      flg = false;
    }
  }
  if (flg) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}