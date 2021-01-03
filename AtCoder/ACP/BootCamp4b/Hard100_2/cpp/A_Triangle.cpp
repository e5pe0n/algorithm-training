#include <bits/stdc++.h>
#define MAX_X 1'000'000'000
using namespace std;
typedef long long ll;

ll S;
ll X1, X2, X3, Y1, Y2, Y3;

void solve() {
  X1 = 0, Y1 = 0;
  X2 = MAX_X, Y2 = 1;
  Y3 = (S + MAX_X - 1) / MAX_X;
  X3 = MAX_X * Y3 - S;
  printf("%lld %lld %lld %lld %lld %lld\n", X1, Y1, X2, Y2, X3, Y3);
}

int main() {
  cin >> S;
  solve();
}