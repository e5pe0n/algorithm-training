#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int S[MAX_N];

int main() {
  int N;
  cin >> N;
  int t = 0;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
    t += S[i];
  }
  if (t % 10 != 0) {
    printf("%d\n", t);
    return 0;
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    if ((t - S[i]) % 10 != 0) {
      res = max(res, t - S[i]);
    }
  }
  printf("%d\n", res);
}