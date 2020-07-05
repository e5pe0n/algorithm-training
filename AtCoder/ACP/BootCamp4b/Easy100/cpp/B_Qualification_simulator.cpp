#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, A, B;
  string S;
  cin >> N >> A >> B >> S;
  int a = 0;
  int b = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'a') {
      if (a + b < A + B) {
        printf("Yes\n");
        ++a;
      } else {
        printf("No\n");
      }
    } else if (S[i] == 'b') {
      if (a + b < A + B && b < B) {
        printf("Yes\n");
        ++b;
      } else {
        printf("No\n");
      }
    } else {
      printf("No\n");
    }
  }
}