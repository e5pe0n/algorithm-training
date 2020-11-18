#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int N;

int main() {
  cin >> N;
  int cnt = 0;
  bool found = false;
  for (int i = 0; i < N; ++i) {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2) {
      ++cnt;
      if (cnt >= 3) {
        found = true;
      }
    } else {
      cnt = 0;
    }
  }
  if (found) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}