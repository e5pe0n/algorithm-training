#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, N;

void solve() {
  ll res = 0;
  ll x;
  if (N < B) {
    x = N;
  } else {
    x = N / B * B - 1;
  }
  res = A * x / B - A * (x / B);
  printf("%lld\n", res);
}

int main() {
  cin >> A >> B >> N;
  solve();
}