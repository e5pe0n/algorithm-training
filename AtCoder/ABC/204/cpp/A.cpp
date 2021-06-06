#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, y;

int main() {
  cin >> x >> y;
  if (x == y)
    printf("%lld\n", x);
  else {
    if (x != 0 && y != 0)
      puts("0");
    else if (x != 1 && y != 1)
      puts("1");
    else
      puts("2");
  }
}