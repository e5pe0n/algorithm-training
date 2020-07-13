#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 500'000

typedef long long ll;

using namespace std;

ll A[MAX_N]{};

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '<') {
      A[i + 1] = A[i] + 1;
    }
  }
  for (int i = S.size() - 1; i >= 0; --i) {
    int a = A[i + 1] + 1;
    if (S[i] == '>' && a > A[i]) {
      A[i] = A[i + 1] + 1;
    }
  }
  ll res = 0;
  for (int i = 0; i <= S.size(); ++i) {
    res += A[i];
  }
  printf("%lld\n", res);
}