#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 2 * 1e5;
ll N, K;

int main() {
  cin >> N >> K;
  vector<vector<ll>> A(N, vector<ll>(3));
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    A[i] = {a, i};
  }
  sort(A.begin(), A.end());
  ll t = K / N;
  for (ll i = 0; i < N; ++i) {
    A[i].push_back(t);
    if (i < K % N) { ++A[i][2]; }
  }
  sort(A.begin(), A.end(), [](const vector<ll> &left, const vector<ll> &right) {
    return left[1] < right[1];
  });
  for (auto a : A)
    printf("%lld\n", a[2]);
}