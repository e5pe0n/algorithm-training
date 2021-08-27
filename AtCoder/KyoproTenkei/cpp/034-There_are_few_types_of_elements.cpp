#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
ll N, K;
ll A[MAX_N];

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll left = 0, right = 0;
  ll res = 0;
  map<ll, ll> cnter;
  while (right < N) {
    while (right < N
           && (cnter.size() < K || cnter.find(A[right]) != cnter.end())) {
      ++cnter[A[right++]];
    }
    res = max(res, right - left);
    while (cnter.size() == K) {
      if (--cnter[A[left]] == 0) cnter.erase(A[left]);
      ++left;
    }
  }
  printf("%lld\n", res);
}