#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  sort(A, A + N);
  ll n = A[N - 1];
  ll k = A[0];
  for (int i = 0; i < N - 1; ++i) {
    if (abs(k - n / 2) >= abs(A[i] - n / 2)) {
      k = A[i];
    }
  }
  printf("%lld %lld\n", n, k);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}