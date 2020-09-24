#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll b_num = b / x;
  ll a_num = (a - 1) >= 0 ? (a - 1) / x : -1;
  printf("%lld\n", b_num - a_num);
}