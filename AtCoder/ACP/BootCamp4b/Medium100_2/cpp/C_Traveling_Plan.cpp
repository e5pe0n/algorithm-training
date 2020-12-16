#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N + 2];

void solve() {
  ll sum = 0;
  for (int i = 0; i < N + 1; ++i) {
    sum += abs(A[i + 1] - A[i]);
  }
  for (int i = 1; i <= N; ++i) {
    ll res;
    if (A[i - 1] <= A[i] && A[i] <= A[i + 1] || A[i - 1] >= A[i] && A[i] >= A[i + 1]) {
      res = sum;
    } else {
      res = sum - abs(A[i + 1] - A[i]) - abs(A[i] - A[i - 1]) + abs(A[i + 1] - A[i - 1]);
    }
    printf("%lld\n", res);
  }
}

int main() {
  cin >> N;
  A[0] = A[N + 1] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  solve();
}