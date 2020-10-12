#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000
#define MAX_A 1'000'000'000

typedef long long ll;

using namespace std;

ll S[MAX_N + 2]{};

int main() {
  int N;
  cin >> N;
  S[0] = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    S[i + 1] = S[i] + a;
  }
  sort(S, S + N + 1);
  ll ans = 0;
  ll cnt = 1;
  S[N + 1] = S[N] + 1;
  for (int i = 0; i < N + 1; ++i) {
    if (S[i] == S[i + 1]) {
      ++cnt;
    } else {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  printf("%lld\n", ans);
}