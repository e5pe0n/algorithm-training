#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll const MAX_N = 1000;

ll N;

int main() {
  cin >> N;
  set<ll> S;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    S.insert(A);
  }
  if (S.size() == N)
    puts("Yes");
  else
    puts("No");
}