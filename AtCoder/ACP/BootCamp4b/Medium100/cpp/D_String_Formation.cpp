#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_Q 500'001
#define OFFSET 200'000

using namespace std;

char C[MAX_Q];

int main() {
  string S;
  cin >> S;
  int N = S.size();
  for (int i = 0; i < N; ++i) {
    C[OFFSET + i] = S[i];
  }
  int Q;
  cin >> Q;
  bool flg = false;
  int left = OFFSET - 1;
  int right = N + OFFSET;
  for (int i = 0; i < Q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      flg = !flg;
    } else {
      int f;
      char c;
      cin >> f >> c;
      if ((!flg && f == 1) || (flg && f == 2)) {
        C[left--] = c;
      } else {
        C[right++] = c;
      }
    }
  }
  if (flg) {
    for (int i = right - 1; i > left; --i) {
      printf("%c", C[i]);
    }
    printf("\n");
  } else {
    for (int i = left + 1; i < right; ++i) {
      printf("%c", C[i]);
    }
    printf("\n");
  }
}