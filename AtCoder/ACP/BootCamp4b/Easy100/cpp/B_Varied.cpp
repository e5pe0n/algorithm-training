#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool B[26]{};

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); ++i) {
    if (B[S[i] - 'a']) {
      printf("no\n");
      return 0;
    } else {
      B[S[i] - 'a'] = true;
    }
  }
  printf("yes\n");
}