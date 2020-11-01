#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string S;
bool res = false;
int cnt[10]{};
int _cnt[10]{};

int main() {
  cin >> S;
  if (S.size() == 1) {
    res = S == "8";
  } else if (S.size() == 2) {
    if (stoi(S) % 8 == 0) {
      res = true;
    } else {
      swap(S[0], S[1]);
      res = stoi(S) % 8 == 0;
    }
  } else {
    for (auto c : S) {
      ++cnt[c - '0'];
    }
    for (int i = 112; i < 1000; i += 8) {
      for (int j = 0; j < 10; ++j) {
        _cnt[j] = cnt[j];
      }
      string s = to_string(i);
      for (auto c : s) {
        --_cnt[c - '0'];
      }
      if (all_of(_cnt, _cnt + 10, [](int x) { return x >= 0; })) {
        res = true;
        break;
      }
    }
  }
  if (res) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}