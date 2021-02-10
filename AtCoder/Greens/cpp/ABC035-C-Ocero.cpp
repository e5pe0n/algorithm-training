#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, Q;
ll L[MAX_N], R[MAX_N + 1];

int main() {
  cin >> N >> Q;
  for (ll i = 0; i < Q; ++i) {
    ll left, right;
    cin >> left >> right;
    ++L[left - 1];
    ++R[right];
  }
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += L[i] - R[i];
    printf("%lld", res % 2);
  }
  puts("");
}