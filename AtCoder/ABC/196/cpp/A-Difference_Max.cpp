#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d;

int main() {
  cin >> a >> b >> c >> d;
  printf("%lld\n", max(a, b) - min(c, d));
}