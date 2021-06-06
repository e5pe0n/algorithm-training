#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 1000;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i)
    cin >> A[i];
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (A[i] > 10) res += A[i] - 10;
  }
  printf("%lld\n", res);
}