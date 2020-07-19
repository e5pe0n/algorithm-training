#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int cnt_a = 0;
  int cnt_b = 0;
  int cnt_c = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'a') {
      ++cnt_a;
    } else if (S[i] == 'b') {
      ++cnt_b;
    } else {
      ++cnt_c;
    }
  }
  if (abs(cnt_a - cnt_b) <= 1 && abs(cnt_b - cnt_c) <= 1 && abs(cnt_c - cnt_a) <= 1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}