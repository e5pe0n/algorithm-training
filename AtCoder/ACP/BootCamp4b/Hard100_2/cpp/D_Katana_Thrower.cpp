#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, H;
ll A[MAX_N], B[MAX_N];

void solve() {
  ll max_a = *max_element(A, A + N);
  sort(B, B + N);
  ll res = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (H <= 0 || B[i] < max_a) { break; }
    H -= B[i];
    ++res;
  }
  if (H > 0) { res += (H + max_a - 1) / max_a; }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> H;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}