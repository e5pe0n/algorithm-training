#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];
ll ord[MAX_N];

void solve() {
  vector<ll> all, cycle;
  memset(ord, -1, sizeof(ord));
  int x = 0;
  for (int i = 0; i <= K; ++i) {
    if (ord[x] > 0) {
      for (int j = ord[x]; j < i; ++j) {
        cycle.push_back(all[j]);
      }
      break;
    }
    ord[x] = all.size();
    all.push_back(x);
    x = A[x];
  }
  int n = all.size();
  if (K == n - 1) {
    printf("%lld\n", all[K] + 1);
    return;
  }
  K -= n;
  int freq = cycle.size();
  ll q = K % freq;
  printf("%lld\n", cycle[q] + 1);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    --A[i];
  }
  solve();
}