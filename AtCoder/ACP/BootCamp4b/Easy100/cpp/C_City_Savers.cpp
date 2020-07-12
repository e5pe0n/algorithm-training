#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef long long ll;

#define MAX_N 100'001

using namespace std;

int A[MAX_N];
int B[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i <= N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  ll cnt = 0;
  for (int i = N - 1; i >= 0; --i) {
    cnt += (ll)min(B[i], A[i + 1]);
    B[i] = max(0, B[i] - A[i + 1]);
    cnt += (ll)min(B[i], A[i]);
    A[i] = max(0, A[i] - B[i]);
  }
  printf("%lld\n", cnt);
}