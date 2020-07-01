#include <bitset>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_S 10

using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int64_t s = 0;
  for (int i = 0; i < (1 << (N - 1)); ++i) {
    bitset<MAX_S> b(i);
    string u;
    u += S[0];
    for (int j = 0; j < N - 1; ++j) {
      if (b.test(j)) {
        s += stoll(u);
        u = S[j + 1];
      } else {
        u += S[j + 1];
      }
    }
    s += stoll(u);
  }
  printf("%lld\n", s);
}