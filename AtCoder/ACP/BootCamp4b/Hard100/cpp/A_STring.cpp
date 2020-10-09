#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string X;
  cin >> X;
  int s = 0;
  int cnt = 0;
  for (auto x : X) {
    if (x == 'S') {
      ++s;
    } else if (s > 0) {
      cnt += 2;
      --s;
    }
  }
  printf("%d\n", (int)X.size() - cnt);
}