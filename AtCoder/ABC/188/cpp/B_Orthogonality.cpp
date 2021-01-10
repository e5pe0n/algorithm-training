#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N], B[MAX_N];

void solve() {
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    res += A[i] * B[i];
  }
  if (res)
    puts("No");
  else
    puts("Yes");
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B[i];
  }
  solve();
}