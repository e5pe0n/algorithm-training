#include <bits/stdc++.h>
#define MAX_N 5000
#define INF 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N, K;
ll P[MAX_N], C[MAX_N];
bool used[MAX_N];
ll sum[MAX_N + 1];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }
  ll res = -INF;
  for (int i = 0; i < N; ++i) {
    memset(used, false, N);
    memset(sum, 0, N + 1);
    int k = 0;
    for (int j = i; !used[j] && k < K; j = P[j]) {
      sum[k + 1] = sum[k] + C[j];
      ++k;
      used[j] = true;
    }
    ll max_sum = -INF;
    for (int j = 1; j <= k; ++j) {
      max_sum = max(max_sum, sum[j]);
    }
    if (sum[k] <= 0) {
      res = max(res, max_sum);
      continue;
    }
    ll score = sum[k] * max(0LL, K / k - 1) + max_sum;
    for (int j = 1; j <= K % k; ++j) {
      score = max(score, sum[k] * (K / k) + sum[j % k]);
    }
    res = max(res, score);
  }
  printf("%lld\n", res);
}