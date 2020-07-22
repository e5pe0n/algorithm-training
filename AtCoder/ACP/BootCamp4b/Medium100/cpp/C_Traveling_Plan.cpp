#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'002

typedef long long ll;

using namespace std;

int A[MAX_N];

int main() {
  int N;
  cin >> N;
  A[0] = 0;
  A[N + 1] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  ll t = 0;
  for (int i = 0; i < N + 1; ++i) {
    t += abs(A[i] - A[i + 1]);
  }
  for (int i = 1; i < N + 1; ++i) {
    if ((A[i - 1] >= A[i] && A[i] >= A[i + 1]) || (A[i - 1] <= A[i] && A[i] <= A[i + 1])) {
      printf("%lld\n", t);
    } else {
      printf("%lld\n", t - abs(A[i - 1] - A[i]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]));
    }
  }
}
