#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;
typedef long long ll;

ll N;
ll A[1 << MAX_N];

ll rec(ll left, ll right) {
  if (left == right) return left;
  ll mid = (left + right) / 2;
  ll left_res = rec(left, mid);
  ll right_res = rec(mid + 1, right);
  if (left == 0 && right == N - 1) {
    if (A[left_res] > A[right_res])
      return right_res;
    else
      return left_res;
  }
  if (A[left_res] > A[right_res])
    return left_res;
  else
    return right_res;
}

void solve() {
  printf("%lld\n", rec(0, N - 1) + 1);
}

int main() {
  cin >> N;
  N = 1 << N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}