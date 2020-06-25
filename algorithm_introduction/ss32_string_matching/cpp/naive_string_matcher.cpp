#include <stdio.h>
#include <string>

using namespace std;

void naive_string_matcher(string T, string P) {
  const char *T_arr = T.c_str();
  const char *P_arr = P.c_str();

  int n = (int)T.size();
  int m = (int)P.size();

  for (int i = 0; i <= n - m; ++i) {
    bool matched = true;
    for (int j = 0; j < m; ++j) {
      if (P_arr[j] != T_arr[i + j]) {
        matched = false;
        break;
      }
    }
    if (matched) {
      printf("pattern occurs with s = %d\n", i);
    }
  }
}

int main() {
  string T = "abcabaabcabac";
  string P = "abaa";

  naive_string_matcher(T, P);
}