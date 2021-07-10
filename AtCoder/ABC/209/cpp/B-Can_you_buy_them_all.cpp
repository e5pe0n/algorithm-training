#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, X;

int main() {
  cin >> N >> X;
  ll sum = 0;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    a -= i % 2 != 0;
    sum += a;
  }
  if (sum <= X)
    puts("Yes");
  else
    puts("No");
}