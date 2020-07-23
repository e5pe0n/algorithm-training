#include <algorithm>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int S[5]{};
bool B[5]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    if (s[0] == 'M') {
      ++S[0];
    } else if (s[0] == 'A') {
      ++S[1];
    } else if (s[0] == 'R') {
      ++S[2];
    } else if (s[0] == 'C') {
      ++S[3];
    } else if (s[0] == 'H') {
      ++S[4];
    }
  }
  memset(B, 1, 3);
  ll res = 0;
  do {
    ll t = 1;
    for (int i = 0; i < 5; ++i) {
      if (B[i]) {
        t *= S[i];
      }
    }
    res += t;
  } while (prev_permutation(B, B + 5));
  printf("%lld\n", res);
}