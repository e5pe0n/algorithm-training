#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_A 1'000'000'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll sum[MAX_N + 1];

void solve() {
  for (ll i = 0; i < N; ++i) {
    sum[i + 1] = sum[i] + A[i];
  }
  sort(sum, sum + N + 1);
  sum[N + 1] = MAX_A + 1;
  ll cnt = 0;
  ll res = 0;
  for (ll i = 0; i < N + 1; ++i) {
    if (sum[i + 1] == sum[i])
      ++cnt;
    else {
      res += cnt * (cnt + 1) / 2;
      cnt = 0;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}