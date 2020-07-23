#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N, A, B, C, D;
  string S;
  cin >> N >> A >> B >> C >> D >> S;
  A = A - 1;
  B = B - 1;
  C = C - 1;
  D = D - 1;
  if (C < D) {
    int i = A;
    while (i < C) {
      while (i < C && S[i] == '.') {
        ++i;
      }
      int _cnt_r = 0;
      while (i < C && S[i] == '#') {
        ++i;
        ++_cnt_r;
      }
      if (_cnt_r > 1) {
        printf("No\n");
        return 0;
      }
    }
    i = B;
    while (i < D) {
      while (i < D && S[i] == '.') {
        ++i;
      }
      int _cnt_r = 0;
      while (i < D && S[i] == '#') {
        ++i;
        ++_cnt_r;
      }
      if (_cnt_r > 1) {
        printf("No\n");
        return 0;
      }
    }
    printf("Yes\n");
  } else {
    int i = B - 1;
    int cnt_s = 0;
    while (i <= D + 1) {
      int _cnt_s = 0;
      while (i <= D + 1 && S[i] == '.') {
        ++i;
        ++_cnt_s;
      }
      cnt_s = max(cnt_s, _cnt_s);
      int _cnt_r = 0;
      while (i <= D + 1 && S[i] == '#') {
        ++i;
        ++_cnt_r;
      }
      if (_cnt_r > 1) {
        printf("No\n");
        return 0;
      }
    }
    if (cnt_s <= 2) {
      printf("No\n");
      return 0;
    }
    i = A;
    while (i < C) {
      while (i < C && S[i] == '.') {
        ++i;
      }
      int _cnt_r = 0;
      while (i < C && S[i] == '#') {
        ++i;
        ++_cnt_r;
      }
      if (_cnt_r > 1) {
        printf("No\n");
        return 0;
      }
    }
    printf("Yes\n");
  }
}