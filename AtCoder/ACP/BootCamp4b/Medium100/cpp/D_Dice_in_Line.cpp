#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

typedef long long ll;

using namespace std;

double E[MAX_N];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    int p;
    cin >> p;
    E[i] = (double)(p + 1) / 2;
  }
  double res = 0;
  for (int i = 0; i < K; ++i) {
    res += E[i];
  }
  double t = res;
  for (int i = K; i < N; ++i) {
    t += -E[i - K] + E[i];
    res = max(res, t);
  }
  printf("%f\n", res);
}