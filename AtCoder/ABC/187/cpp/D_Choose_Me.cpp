#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll A[MAX_N], B[MAX_N];

void solve() {
  vector<pll> V;
  ll sum_A = 0;
  for (int i = 0; i < N; ++i) {
    V.push_back({A[i], B[i]});
    sum_A += A[i];
  }
  auto cmp = [](const pll &p1, const pll &p2) { return p1.first * 2 + p1.second > p2.first * 2 + p2.second; };
  sort(V.begin(), V.end(), cmp);
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    sum_A -= 2 * V[i].first + V[i].second;
    ++res;
    if (sum_A < 0) { break; }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}