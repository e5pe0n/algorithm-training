#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
ll T[MAX_N];

void solve() {
  if (N == 1) {
    printf("%lld\n", T[0]);
    return;
  }
  ll lcm = T[0] / __gcd(T[0], T[1]) * T[1];
  for (int i = 2; i < N; ++i) {
    lcm = lcm / __gcd(lcm, T[i]) * T[i];
  }
  printf("%lld\n", lcm);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }
  solve();
}