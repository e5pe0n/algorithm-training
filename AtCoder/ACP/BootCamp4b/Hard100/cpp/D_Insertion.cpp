#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  string ans = S;
  int start = 0;
  int left_cnt = 0;
  int right_cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '(') {
      ++left_cnt;
    } else {
      if (left_cnt == 0) {
        ++right_cnt;
      } else {
        --left_cnt;
      }
    }
  }
  string left_s = "";
  for (int i = 0; i < right_cnt; ++i) {
    left_s += '(';
  }
  string right_s = "";
  for (int i = 0; i < left_cnt; ++i) {
    right_s += ')';
  }
  S = left_s + S + right_s;
  printf("%s\n", S.c_str());
}