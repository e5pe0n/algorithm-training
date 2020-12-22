#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, M;
ll A[MAX_N];

void solve() {
  priority_queue<ll, vector<ll>, less<vector<ll>::value_type>> q;
  for (int i = 0; i < N; ++i) {
    q.push(A[i]);
  }
  for (int i = 0; i < M; ++i) {
    ll a = q.top();
    q.pop();
    a >>= 1;
    q.push(a);
  }
  ll res = 0;
  while (!q.empty()) {
    res += q.top();
    q.pop();
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}