#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_set>

#define MAX_N 100'000
#define INF 1'000'000'007

typedef long long ll;

using namespace std;

int C[26]{};

int main() {
  int N;
  string S;
  cin >> N >> S;
  for (int i = 0; i < N; ++i) {
    ++C[S[i] - 'a'];
  }

  ll res = 1;
  for (int i = 0; i < 26; ++i) {
    if (C[i] > 0) {
      res = (res * (C[i] + 1)) % INF;
    }
  }
  printf("%lld\n", res - 1);
}
