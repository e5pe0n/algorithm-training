#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int res = 1000;
  for (int i = 0; i < S.size() - 2; ++i) {
    res = min(res, abs(753 - stoi(S.substr(i, 3))));
  }
  printf("%d\n", res);
}