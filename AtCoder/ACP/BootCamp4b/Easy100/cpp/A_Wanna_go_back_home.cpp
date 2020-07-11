#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int n = 0;
  int w = 0;
  int s = 0;
  int e = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'N') {
      ++n;
    }
    if (S[i] == 'W') {
      ++w;
    }
    if (S[i] == 'S') {
      ++s;
    }
    if (S[i] == 'E') {
      ++e;
    }
  }
  if ((n > 0 && s > 0 && w > 0 && e > 0) || (n > 0 && s > 0 && w == 0 & e == 0) ||
      (n == 0 && s == 0 && w > 0 && e > 0)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}