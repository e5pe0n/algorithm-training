#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 10

typedef long long ll;

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  ll _a = 1;
  ll res = 0;
  for (int i = 1; i <= N; ++i) {
    int a;
    cin >> a;
    res += _a * (a % 2 + 1) * pow(3, N - i);
    if (a % 2 == 0) {
      _a *= 2;
    }
  }
  printf("%lld\n", res);
}