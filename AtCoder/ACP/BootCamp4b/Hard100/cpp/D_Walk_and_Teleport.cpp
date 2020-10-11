#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int X[MAX_N]{};

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  ll ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    ans += min((ll)(X[i + 1] - X[i]) * A, (ll)B);
  }
  printf("%lld\n", ans);
}