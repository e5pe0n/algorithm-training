#include <bits/stdc++.h>
#define MAX_A 100'000
#define MAX_B 100'000
#define MAX_C 100'000
using namespace std;
typedef long long ll;

ll X, Y, A, B, C;
ll P[MAX_A], Q[MAX_B], R[MAX_C];

void solve() {
  sort(P, P + A);
  sort(Q, Q + B);
  vector<ll> V;
  for (ll i = A - 1; i >= A - X; --i) {
    V.push_back(P[i]);
  }
  for (ll i = B - 1; i >= B - Y; --i) {
    V.push_back(Q[i]);
  }
  priority_queue<ll, vector<ll>, greater<vector<ll>::value_type>> q;
  for (ll i = 0; i < X + Y; ++i) {
    q.push(V[i]);
  }
  for (ll i = 0; i < C; ++i) {
    ll p = q.top();
    q.pop();
    if (p < R[i]) {
      q.push(R[i]);
    } else {
      q.push(p);
    }
  }
  ll res = 0;
  while (q.size()) {
    res += q.top();
    q.pop();
  }
  printf("%lld\n", res);
}

int main() {
  cin >> X >> Y >> A >> B >> C;
  for (ll i = 0; i < A; ++i) {
    cin >> P[i];
  }
  for (ll i = 0; i < B; ++i) {
    cin >> Q[i];
  }
  for (ll i = 0; i < C; ++i) {
    cin >> R[i];
  }
  solve();
}