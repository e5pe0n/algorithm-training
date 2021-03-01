#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, T;
ll D[MAX_N];

int main() {
  cin >> N >> T;
  ll sumA = 0;
  ll sumB = 0;
  for (ll i = 0; i < N; ++i) {
    ll A, B;
    cin >> A >> B;
    sumA += A;
    sumB += B;
    D[i] = A - B;
  }
  if (sumB > T) {
    puts("-1");
    return 0;
  }
  sumA -= T;
  sort(D, D + N);
  ll i = N;
  while (sumA > 0) {
    sumA -= D[--i];
  }
  printf("%lld\n", N - i);
}