#include <bits/stdc++.h>
#define MAX_N 10'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll B[MAX_N];

void solve() {
  ll diff = 0;
  ll t = 0;
  for (ll i = 0; i < N; ++i) {
    diff += B[i] - A[i];
    if (B[i] > A[i]) t += (B[i] - A[i] + 1) / 2;
  }
  if (t <= diff)
    puts("Yes");
  else
    puts("No");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  solve();
}
