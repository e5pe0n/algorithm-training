#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;
typedef long long ll;

ll N;
ll A[1 << MAX_N];

void solve() {
  ll left = max_element(A, A + N / 2) - A;
  ll right = max_element(A + N / 2, A + N) - A;
  ll res = 0;
  if (A[left] > A[right]) {
    res = right;
  } else {
    res = left;
  }
  printf("%lld\n", res + 1);
}

int main() {
  cin >> N;
  N = 1 << N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}