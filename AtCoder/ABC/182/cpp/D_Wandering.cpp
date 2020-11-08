#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

typedef long long ll;

ll N;
ll A[MAX_N];
ll C[MAX_N + 1];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll t = 0;
  ll res = 0;
  ll m = 0;
  for (int i = 0; i < N; ++i) {
    C[i + 1] = C[i] + A[i];
    m = max(m, C[i + 1]);
    res = max(res, t + m);
    t += C[i + 1];
  }
  printf("%lld\n", res);
}