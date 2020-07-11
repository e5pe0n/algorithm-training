#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 100

using namespace std;

string S[MAX_N];

int main() {
  int N, L;
  cin >> N >> L;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  sort(S, S + N);
  for (int i = 0; i < N; ++i) {
    printf("%s", S[i].c_str());
  }
  printf("\n");
}