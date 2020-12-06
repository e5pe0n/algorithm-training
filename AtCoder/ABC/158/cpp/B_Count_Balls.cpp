#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, A, B;

void solve() {
  ll p = N / (A + B);
  ll q = N % (A + B);
  ll res = p * A + min(q, A);
  printf("%lld\n", res);
}

int main() {
  cin >> N >> A >> B;
  solve();
}