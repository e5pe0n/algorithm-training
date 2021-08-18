#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 300'000;
const ll MAX_Q = 300'000;
ll N, Q;
ll A[MAX_N];
ll B[3];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  cin >> Q;
  while (Q--) {
    ll B;
    cin >> B;
    ll idx = lower_bound(A, A + N, B) - A;
    ll res;
    if (idx == N)
      res = abs(A[idx - 1] - B);
    else if (idx == 0)
      res = abs(A[idx] - B);
    else
      res = min(abs(A[idx] - B), abs(A[idx - 1] - B));
    printf("%lld\n", res);
  }
}