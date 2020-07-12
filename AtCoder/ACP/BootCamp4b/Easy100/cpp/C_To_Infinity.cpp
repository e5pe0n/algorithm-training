#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  string S;
  ll K;
  cin >> S >> K;
  if (S[0] == '1') {
    if (K == 1) {
      printf("1\n");
    } else {
      int idx = 1;
      for (int i = 1; i < S.size(); ++i) {
        if (S[i] != '1') {
          idx = i;
          break;
        }
      }
      if (idx <= K - 1) {
        printf("%c\n", S[idx]);
      } else {
        printf("1\n");
      }
    }
  } else {
    printf("%c\n", S[0]);
  }
}