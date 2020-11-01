#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000
#define MAX_M 200'000
#define INF 1'000'000'000'000'000'000

using namespace std;

typedef long long ll;

int N, M;
int H[MAX_N + 1], W[MAX_M];
ll d_odd[MAX_N / 2 + 1]{}, d_even[MAX_N / 2 + 1]{};

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> W[i];
  }
  sort(H, H + N);
  for (int i = 0; i < N - 1; i += 2) {
    d_even[i / 2 + 1] = d_even[i / 2] + H[i + 1] - H[i];
  }
  for (int i = 1; i < N - 1; i += 2) {
    d_odd[i / 2 + 1] = d_odd[i / 2] + H[i + 1] - H[i];
  }
  ll ans = INF;
  for (int i = 0; i < M; ++i) {
    int idx;
    if (H[N - 1] < W[i]) {
      idx = N;
    } else {
      idx = lower_bound(H, H + N, W[i]) - H;
    }
    ll diff = d_even[idx / 2] + d_odd[N / 2] - d_odd[idx / 2];
    if (idx % 2 == 0) {
      diff += H[idx] - W[i];
    } else {
      diff += W[i] - H[idx - 1];
    }
    ans = min(ans, diff);
  }
  printf("%lld\n", ans);
}