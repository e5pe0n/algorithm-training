#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 1000;
ll N, K;
ll A[MAX_N], B[MAX_N];

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> B[i];
  }
  for (ll i = 0; i < N; ++i) {
    K -= abs(A[i] - B[i]);
    if (K < 0) {
      puts("No");
      return 0;
    }
  }
  if (K % 2 == 0)
    puts("Yes");
  else
    puts("No");
}