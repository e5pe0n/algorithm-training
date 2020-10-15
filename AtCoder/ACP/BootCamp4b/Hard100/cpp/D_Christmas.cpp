#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 50

typedef long long ll;

using namespace std;

ll N, X;
ll P[MAX_N + 1]{};
ll L[MAX_N + 1]{};

int main() {
  cin >> N >> X;
  P[0] = 1;
  L[0] = 0;
  for (int i = 1; i <= N; ++i) {
    P[i] = P[i - 1] * 2 + 1;
    L[i] = P[i] * 2 - 1;
  }
  ll layer_cnt = 0;
  ll p_cnt = 0;
  while (N >= 0) {
    if (N == 0) {
      ++p_cnt;
      break;
    }
    if (layer_cnt + 1 == X) {
      break;
    }
    if (layer_cnt + (L[N] + 1) / 2 == X) {
      p_cnt += P[N - 1] + 1;
      break;
    }
    if (layer_cnt + L[N] == X) {
      p_cnt += P[N];
      break;
    }
    if (X < layer_cnt + (L[N] + 1) / 2) {
      ++layer_cnt;
    } else {
      layer_cnt += L[N - 1] + 2;
      p_cnt += P[N - 1] + 1;
    }
    --N;
  }
  printf("%lld\n", p_cnt);
}