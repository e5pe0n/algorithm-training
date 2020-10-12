#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 10'000

typedef long long ll;

using namespace std;

int A[MAX_N]{};
int B[MAX_N]{};

int main() {
  int N;
  cin >> N;
  ll a = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    a += A[i];
  }
  ll b = 0;
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
    b += B[i];
  }
  ll n = b - a;
  ll _n = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] - B[i] < 0) {
      _n += (B[i] - A[i] + 1) / 2;
    }
  }
  if (_n <= n) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}