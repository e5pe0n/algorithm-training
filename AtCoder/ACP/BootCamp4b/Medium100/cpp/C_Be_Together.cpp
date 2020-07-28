#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 100
#define INF 1'000'000'000'000'000'000

typedef long long ll;

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  int up = -100;
  int low = 100;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    up = max(up, A[i]);
    low = min(low, A[i]);
  }
  ll res = INF;
  for (int i = low; i <= up; ++i) {
    ll t = 0;
    for (int j = 0; j < N; ++j) {
      t += (i - A[j]) * (i - A[j]);
    }
    res = min(res, t);
  }
  printf("%lld\n", res);
}