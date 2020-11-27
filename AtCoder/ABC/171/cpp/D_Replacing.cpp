#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_Q 100'000
using namespace std;
typedef long long ll;

int N, Q;
ll A[MAX_N];
ll B[MAX_Q], C[MAX_Q];

void solve() {
  map<ll, ll> cnt;
  ll sum = 0;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
    sum += A[i];
  }
  for (int i = 0; i < Q; ++i) {
    sum += (C[i] - B[i]) * cnt[B[i]];
    printf("%lld\n", sum);
    cnt[C[i]] += cnt[B[i]];
    cnt[B[i]] = 0;
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> B[i] >> C[i];
  }
  solve();
}