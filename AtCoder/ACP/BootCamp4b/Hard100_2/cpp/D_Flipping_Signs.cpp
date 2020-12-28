#include <bits/stdc++.h>
#define MAX_A 1'000'000'000
using namespace std;
typedef long long ll;

ll N;
vector<ll> A;

void solve() {
  ll cnt = 0;
  ll sum = 0;
  ll min_a = MAX_A;
  for (int i = 0; i < N; ++i) {
    if (A[i] < 0) {
      ++cnt;
    }
    ll a = abs(A[i]);
    sum += a;
    min_a = min(min_a, a);
  }
  if (cnt % 2 != 0) {
    sum -= min_a * 2;
  }
  printf("%lld\n", sum);
}

int main() {
  cin >> N;
  A =vector<ll>(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}