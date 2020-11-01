#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

typedef long long ll;

ll N, ans;

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    ll A, B;
    cin >> A >> B;
    ans += B * (B + 1) / 2 - (A - 1) * A / 2;
  }
  printf("%lld\n", ans);
}