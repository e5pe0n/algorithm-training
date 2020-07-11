#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 200'000

using namespace std;

string A[MAX_N];

int main() {
  string S;
  cin >> S;
  A[0] = S[0];
  string s = "";
  int cnt = 1;
  for (int i = 1; i < S.size(); ++i) {
    s += S[i];
    if (s != A[cnt - 1]) {
      A[cnt++] = s;
      s = "";
    }
  }
  printf("%d\n", cnt);
}