#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N], B[MAX_N], C[MAX_N];
ll AB[MAX_N], BC[MAX_N];

void solve() {
  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);
  ll j = N - 1;
  for (ll i = N - 1; i >= 0; --i) {
    while (j >= 0 && C[i] <= B[j]) {
      --j;
      if (j >= 0) { BC[j] = BC[j + 1]; }
    }
    if (j >= 0 && C[i] > B[j]) { ++BC[j]; }
  }
  for (; j > 0; --j) {
    BC[j - 1] = BC[j];
  }
  j = 0;
  for (ll i = 0; i < N; ++i) {
    while (j < N && A[i] >= B[j]) {
      ++j;
      if (j < N) { AB[j] = AB[j - 1]; }
    }
    if (j < N && A[i] < B[j]) { ++AB[j]; }
  }
  for (; j < N - 1; ++j) {
    AB[j + 1] = AB[j];
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += AB[i] * BC[i];
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> C[i];
  }
  solve();
}