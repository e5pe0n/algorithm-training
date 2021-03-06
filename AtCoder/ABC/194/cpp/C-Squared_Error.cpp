#include <bits/stdc++.h>
#define MAX_N 300'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  ll sumA = 0;
  ll sum_squareA = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    sumA += A[i];
    sum_squareA += A[i] * A[i];
  }
  ll res = sum_squareA * (N - 1);
  for (ll i = 0; i < N; ++i) {
    sumA -= A[i];
    res -= 2 * A[i] * sumA;
  }
  printf("%lld\n", res);
}