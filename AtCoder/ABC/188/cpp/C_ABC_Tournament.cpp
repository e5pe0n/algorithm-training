#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;
typedef long long ll;

ll N;
ll A[1 << MAX_N];
ll n;

void solve() {
  ll left = max_element(A, A + n / 2) - A;
  ll right = max_element(A + n / 2, A + n) - A;
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
  n = 1 << N;
  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
  }
  solve();
}