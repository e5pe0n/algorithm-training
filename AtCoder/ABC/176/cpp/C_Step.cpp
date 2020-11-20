#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll res = 0;
  for (int i = 1; i < N; ++i) {
    if (A[i - 1] > A[i]) {
      ll d = A[i - 1] - A[i];
      res += d;
      A[i] = A[i - 1];
    }
  }
  printf("%lld\n", res);
}