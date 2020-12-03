#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X;

int main() {
  cin >> X;
  ll x0 = 100;
  int res = 0;
  while (x0 < X) {
    x0 += x0 / 100;
    ++res;
  }
  printf("%d\n", res);
}