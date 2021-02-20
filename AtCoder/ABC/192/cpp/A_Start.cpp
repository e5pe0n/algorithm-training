#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X;

int main() {
  cin >> X;
  ll Y = (X + 100) / 100 * 100;
  printf("%lld\n", Y - X);
}