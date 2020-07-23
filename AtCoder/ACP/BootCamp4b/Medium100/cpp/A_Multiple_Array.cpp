#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int A[MAX_N];
int B[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  ll res = 0;
  for (int i = N - 1; i >= 0; --i) {
    res += (B[i] - (A[i] + res) % B[i]) % B[i];
  }
  printf("%lld\n", res);
}