#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  S = S.erase(S.size() - 2, 2);
  while (S.size() > 0) {
    if (S.substr(0, S.size() / 2) == S.substr(S.size() / 2)) {
      printf("%d\n", (int)S.size());
      return 0;
    }
    S = S.erase(S.size() - 2, 2);
  }
}