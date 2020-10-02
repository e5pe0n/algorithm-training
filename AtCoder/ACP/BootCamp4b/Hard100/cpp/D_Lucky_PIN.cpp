#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_V 999

typedef long long ll;

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  string n_str = "000";
  int n_str_len = n_str.size();
  ll cnt = 0;
  for (int i = 0; i <= MAX_V; ++i) {
    string _i_str = to_string(i);
    string i_str = n_str;
    int _i_str_len = _i_str.size();
    for (int j = 0; j < _i_str_len; ++j) {
      i_str[j + 3 - _i_str_len] = _i_str[j];
    }
    int idx = 0;
    for (int j = 0; j < N; ++j) {
      if (S[j] == i_str[idx]) {
        ++idx;
        if (idx == n_str_len) {
          break;
        }
      }
    }
    if (idx == n_str_len) {
      ++cnt;
    }
  }
  printf("%lld\n", cnt);
}