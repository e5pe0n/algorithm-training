#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  sort(A, A + N);
  ll res = 0;
  for (int i = 0; i < N - 1; ++i) {
    res += (A[i + 1] - A[i]) * (N - (i + 1)) * (i + 1);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}