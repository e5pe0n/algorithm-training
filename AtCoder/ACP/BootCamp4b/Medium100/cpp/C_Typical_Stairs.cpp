#include <algorithm>
#include <iostream>
#include <memory>
#include <stdio.h>

#define MOD 1'000'000'007
#define MAX_N 100'001

typedef long long ll;

using namespace std;

bool B[MAX_N]{};
ll D[MAX_N]{};

int main() {
  int N, M;
  cin >> N >> M;
  memset(B, 1, N + 1);
  for (int i = 0; i < M; ++i) {
    int a;
    cin >> a;
    B[a] = false;
  }
  D[0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j <= min(N, i + 2); ++j) {
      if (B[j]) {
        D[j] = (D[j] + D[i]) % MOD;
      }
    }
  }
  printf("%lld\n", D[N]);
}
