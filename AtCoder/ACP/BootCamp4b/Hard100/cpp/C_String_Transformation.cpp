#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

char C_S[26]{};
char C_T[26]{};

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  bool ok = true;
  for (int i = 0; i < N; ++i) {
    if (C_S[S[i] - 'a'] == 0) {
      C_S[S[i] - 'a'] = T[i];
    } else {
      if (C_S[S[i] - 'a'] != T[i]) {
        ok = false;
        break;
      }
    }
    if (C_T[T[i] - 'a'] == 0) {
      C_T[T[i] - 'a'] = S[i];
    } else {
      if (C_T[T[i] - 'a'] != S[i]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}