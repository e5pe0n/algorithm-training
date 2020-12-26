#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
vector<ll> A;
vector<ll> sum;

void solve() {
  ll res = 0;
  sum = vector<ll>(N + 1);
  for (int i = 0; i < N; ++i) {
    sum[i + 1] = sum[i] + A[i];
  }
  ll left = 0;
  ll right = 1;
  while (right <= N && left < N) {
    while (right <= N && sum[right] - sum[left] < K) {
      ++right;
    }
    if (right > N) break;
    res += N - right + 1;
    ++left;
    while (left < N && sum[right] - sum[left] >= K) {
      res += N - right + 1;
      ++left;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  A = vector<ll>(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}