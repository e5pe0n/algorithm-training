#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll left = 0;
  ll right = 1;
  ll res = 0;
  while (right < N) {
    while (right < N && A[right - 1] < A[right]) {
      ++right;
    }
    ll t = right - left;
    res += t * (t - 1) / 2;
    while (right < N && A[right - 1] >= A[right]) {
      ++right;
    }
    left = right - 1;
  }
  printf("%lld\n", res + N);
}