#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS = 1e-10;

ll A;
double B;

void solve() {
  ll b = (ll)(B * 100 + EPS);
  ll res = A * b / 100;
  printf("%lld\n", res);
}

int main() {
  cin >> A >> B;
  solve();
}