#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
ll H, W, N;
ll A[MAX_N], B[MAX_N];

int main() {
  cin >> H >> W >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  set<ll> SA, SB;
  for (ll i = 0; i < N; ++i) {
    SA.insert(A[i]);
    SB.insert(B[i]);
  }
  vector<ll> VA(SA.begin(), SA.end()), VB(SB.begin(), SB.end());
  map<ll, ll> MA, MB;
  for (ll i = 0; i < VA.size(); ++i) {
    MA[VA[i]] = i + 1;
  }
  for (ll i = 0; i < VB.size(); ++i) {
    MB[VB[i]] = i + 1;
  }
  for (ll i = 0; i < N; ++i) {
    printf("%lld %lld\n", MA[A[i]], MB[B[i]]);
  }
}