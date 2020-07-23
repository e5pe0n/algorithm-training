#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  if (S[0] != T[0]) {
    printf("-1\n");
    return 0;
  }
  ll L = (ll)N * (M / gcd(N, M));
  if (N > M) {
    swap(N, M);
    swap(S, T);
  }
  ll n = L / N;
  ll m = L / M;
  ll l = n * m / gcd(n, m);
  for (ll i = l; i < L; i += l) {
    if (S[i / n] != T[i / m]) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%lld\n", L);
}