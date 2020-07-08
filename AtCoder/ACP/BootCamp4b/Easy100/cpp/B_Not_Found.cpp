#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool C[26];

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); ++i) {
    C[S[i] - 'a'] = true;
  }
  for (int i = 0; i < 26; ++i) {
    if (!C[i]) {
      printf("%c\n", (char)(i + 'a'));
      return 0;
    }
  }
  printf("None\n");
}