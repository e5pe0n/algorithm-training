#include <math.h>
#include <stdio.h>
#include <string>

#define d 10
#define q 11

using namespace std;

int c2i(char c) { return c - '0'; }

void rabin_karp_matcher(string T, string P) {
  const char *T_arr = T.c_str();
  const char *P_arr = P.c_str();

  int n = (int)T.size();
  int m = (int)P.size();

  int h = (int)pow(d, m - 1) % q;
  int t = 0;
  int p = 0;

  for (int i = 0; i < m; ++i) {
    t = (d * t + c2i(T_arr[i])) % q;
    p = (d * p + c2i(P_arr[i])) % q;
  }
  for (int i = 0; i <= n - m; ++i) {
    if (p == t) {
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
    if (i < n - m) {
      t = (d * (t + c2i(T_arr[i]) * h) + c2i(T_arr[i + m])) % q;
    }
  }
}

int main() {
  string T = "3141592653589793";
  string P = "26";

  rabin_karp_matcher(T, P);
}