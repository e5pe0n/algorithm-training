#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define MOD 1'000'000'007

typedef long long ll;

using namespace std;

int N;
string S1, S2;

int main() {
  cin >> N >> S1 >> S2;
  int idx = 0;
  ll ans = 1;
  if (S1[idx] == S2[idx]) {
    ans *= 3;
    ++idx;
  } else {
    ans *= 6;
    idx += 2;
  }
  while (idx < N) {
    if (S1[idx] == S2[idx]) {
      if (S1[idx - 1] == S2[idx - 1]) {
        ans = (ans * 2) % MOD;
      }
      ++idx;
    } else {
      if (S1[idx - 1] == S2[idx - 1]) {
        ans = (ans * 2) % MOD;
      } else {
        ans = (ans * 3) % MOD;
      }
      idx += 2;
    }
  }
  printf("%lld\n", ans);
}