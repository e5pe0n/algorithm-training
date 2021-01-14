#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  for (ll i = 0; i < N; ++i) {
    if (A[i] % 2 != 0) {
      puts("first");
      return;
    }
  }
  puts("second");
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}