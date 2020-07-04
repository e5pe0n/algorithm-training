#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int cnt = 0;
  for (int i = 0; i < 3; ++i) {
    char s;
    cin >> s;
    cnt += s == '1';
  }
  printf("%d\n", cnt);
}