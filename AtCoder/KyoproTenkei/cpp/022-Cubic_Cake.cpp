#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, C;

int main() {
  cin >> A >> B >> C;
  ll gcd = __gcd(A, __gcd(B, C));
  ll res = (A / gcd - 1) + (B / gcd - 1) + (C / gcd - 1);
  printf("%lld\n", res);
}