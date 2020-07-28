#include <iostream>
#include <math.h>
#include <stdio.h>

#define INF 1'000'000'007

typedef long long ll;

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  if (abs(N - M) > 1) {
    printf("0\n");
  } else {
    ll a = 1;
    for (ll i = 2; i <= N; ++i) {
      a = (a * i) % INF;
    }
    ll b = 1;
    for (ll i = 2; i <= M; ++i) {
      b = (b * i) % INF;
    }
    printf("%lld\n", (a * b * (1 + (N == M))) % INF);
  }
}