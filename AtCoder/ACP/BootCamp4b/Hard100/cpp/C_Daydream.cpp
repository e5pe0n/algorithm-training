#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int i = N - 1;
  string T;
  while (i >= 0) {
    if (S[i] == 'r') {
      T += "re";
      i -= 2;
      if (i < 0) {
        T += "0";
        break;
      }
      if (S[i] == 'm') {
        T += "maerd";
        i -= 5;
      } else if (S[i] == 's') {
        T += "sare";
        i -= 4;
      } else {
        T += "0";
        break;
      }
    } else if (S[i] == 'e') {
      T += "esare";
      i -= 5;
    } else if (S[i] == 'm') {
      T += "maerd";
      i -= 5;
    } else {
      T += "0";
      break;
    }
  }

  reverse(T.begin(), T.end());
  if (S == T) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}